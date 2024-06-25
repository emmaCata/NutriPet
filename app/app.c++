#define BLYNK_TEMPLATE_ID "TMPL2sl0CtJyI"
#define BLYNK_TEMPLATE_NAME "Emma"
#define BLYNK_AUTH_TOKEN "SbZmXWaOwlEubBGXB8Le4oeHUi99zmiQ"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <HCSR04.h>
#include "HX711.h"

// Credenciales WiFi
char ssid[] = "Chistian2022";
char pass[] = "emmaXBOX5030.";

// Autenticación Blynk
char auth[] = BLYNK_AUTH_TOKEN;

// Pines de conexión
HCSR04 hc(12, 14);
#define RELAY_PIN 5 // Pin del relé (D1 en ESP8266)
#define LED_PIN 2
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 0;

HX711 scale;
bool noHayComida = false;
float pesoActual = 0;
int cantidadPorciones = 1;

void setup() { 
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Conectando a Blynk...");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  Blynk.virtualWrite(V2, "Calibrando balanza, seguir intrucciones");
  delay(2000);
  Blynk.virtualWrite(V2, "Retira el peso de la balanza en los próximos 5 seg.");
  delay(5000); // Espera 5 segundos para retirar el peso
  scale.tare(); // Realiza la tara
  Blynk.virtualWrite(V2, "Coloca un peso conocido en los próximos 10 seg.");
  delay(10000); // Espera 10 segundos para colocar el peso conocido

  if (scale.is_ready()) {
    long reading = scale.get_units(10);
    Serial.print("Lectura: ");
    Serial.println(reading);
    float peso_conocido = 50; // Peso conocido en gramos
    float factor_calibracion = reading / peso_conocido;

    Serial.print("Factor de calibración calculado: ");
    Serial.println(factor_calibracion);
    scale.set_scale(factor_calibracion);

    reading = scale.get_units(10);
    Serial.print("Lectura calibrada: ");
    Blynk.virtualWrite(V2, "La balanza queda calibrada con exito!");
    delay(2000);
    Serial.println(reading);

    String readingStr = String(reading) + " g";
    Blynk.virtualWrite(V3, readingStr);
  } else {
    Serial.println("HX711 no encontrado.");
  }
}

void loop() {
  Blynk.run();
  medirDistanciaYActualizarBlynk();
  leerPesoYActualizarBlynk();
  delay(1000); // 1 segundo de delay entre lecturas para dar tiempo a Blynk de procesar
}

void medirDistanciaYActualizarBlynk() {
  float distancia = hc.dist(); // Obtener la distancia
  float porcentaje = map(distancia, 2, 10, 100, 0); // Mapear la distancia a porcentaje
  porcentaje = constrain(porcentaje, 0, 100);

  Serial.print("Distancia medida: ");
  Serial.print(distancia);
  Serial.print(" cm, Porcentaje: ");
  Serial.print(porcentaje);
  Serial.println("%");

  Blynk.virtualWrite(V1, porcentaje);

  if (porcentaje == 0 && !noHayComida) {
    Blynk.virtualWrite(V2, "No hay comida, recargar!");
    noHayComida = true;
  } else if (porcentaje > 1) {
    noHayComida = false;
    Blynk.virtualWrite(V2, " ");
  }
}

void leerPesoYActualizarBlynk() {
  if (scale.is_ready()) {
    long reading = scale.get_units(10);
    Serial.print("Result: ");
    Serial.println(reading);
    pesoActual = reading; // Actualiza el estado de pesoActual basado en la lectura
    String readingStr = String(reading) + " g";
    Blynk.virtualWrite(V3, readingStr);
  } else {
    Serial.println("HX711 no encontrado.");
  }
}

BLYNK_WRITE(V0) {
  if (pesoActual < 15 && !noHayComida) {
    int value = param.asInt(); // Obtener el valor del botón
    if (value == 1) {
      activarRele();
    }
  } else if(pesoActual > 15 && !noHayComida) {
    Blynk.virtualWrite(V2, "Hay comida en el plato");
    delay(2000);
  }
}

BLYNK_WRITE(V4) {
  cantidadPorciones = param.asInt(); // Obtener la cantidad de porciones del slider
}

void activarRele() {
  for (int i = 0; i < cantidadPorciones; i++) {
    digitalWrite(RELAY_PIN, HIGH); // Encender el relé
    digitalWrite(LED_PIN, HIGH);   // Encender el LED
    delay(2000); // Esperar 2 segundos
    digitalWrite(RELAY_PIN, LOW); // Apagar el relé
    digitalWrite(LED_PIN, LOW);   // Apagar el LED
    delay(1000); // Esperar 1 segundo entre cada porción
  }
}

