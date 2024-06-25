# NutriPet
# NutriPet

NutriPet es un sistema de alimentación inteligente para gatos, diseñado para facilitar la gestión de la alimentación de tu mascota. Con NutriPet, puedes controlar la alimentación de tu gato a través de tu celular, verificar cuánto alimento le queda y pesar la comida en el plato.

## Características

- **Distribución Remota de Alimento**: Controla la alimentación de tu gato desde tu celular, programando porciones de comida.
- **Monitoreo de Alimento Restante**: Verifica en tiempo real cuánto alimento queda en el recipiente.
- **Pesaje de la Comida**: Pesa la cantidad de comida que está en el plato para un control preciso de la dieta de tu mascota.

## Instalación

Para clonar y ejecutar esta aplicación, sigue estos pasos:

1. Clona el repositorio:
   ```sh
   git clone https://github.com/tu-usuario/nutriPet.git


## Objetivo General del Proyecto
SMART:
Specific (Específico): Desarrollar un sistema de alimentación inteligente para gatos que permita a los usuarios controlar remotamente la distribución de alimento, monitorear la cantidad de alimento restante y pesar la comida en el plato.
Measurable (Medible): El sistema debe permitir la programación de al menos tres porciones diarias, la verificación del nivel de alimento restante en tiempo real, y la medición precisa de la comida en el plato con un margen de error del 5%.
Achievable (Alcanzable): Utilizando tecnología existente como microcontroladores ESP8266/ESP32, sensores de peso y aplicaciones móviles.
Relevant (Relevante): Facilitar la vida de los dueños de gatos proporcionando una herramienta que asegure la alimentación adecuada de sus mascotas, incluso cuando no están en casa.
Time-bound (Con límite de tiempo): Completar el desarrollo del sistema en un plazo de 6 meses, con hitos mensuales para la evaluación del progreso.

## Nuevos OKRs
Objective: Desarrollar un sistema de alimentación inteligente para gatos.
Key Result 1: Hablar con los stakeholders y realizar el kanban en Trello y recopilar los requerimientos.
Key Result 2: Desarrollo del prototipo inicial.
## Key Result 3: rediseño de la extrusora y la tolva de Almacenado, y pruebas correspondientes para el MVP
Key Result 4: Realizar el desarrollo de una App y una landing page inicial.
Key Result 5: Realizar el desarrollo de la conectividad del dispositivo con una APP.
Key Result 6: Desarrollo y pruebas de la aplicación.

## Análisis de Interesados(StakeHolders)
Dueños de Gatos (Usuarios Finales)
Intereses: Asegurar que sus gatos estén bien alimentados y monitoreados incluso cuando no están en casa. Facilitar la alimentación de sus mascotas con una herramienta confiable y fácil de usar.
Influencias: Alta, ya que son los principales usuarios del sistema y su satisfacción es crucial para el éxito del proyecto.
Expectativas:
Interfaz de usuario intuitiva y amigable.
Funcionalidad confiable y precisa para la programación de comidas y monitoreo del nivel de alimento.
Notificaciones oportunas sobre el nivel de alimento y el estado del sistema.
Rol: Usuarios y validadores del sistema.

Veterinarios y Expertos en Nutrición Animal
Intereses: Promover la salud y el bienestar de los gatos a través de una alimentación adecuada y controlada.
Influencias: Media, ya que pueden recomendar el uso del sistema a sus clientes y proporcionar validación técnica y científica sobre los beneficios del sistema.
Expectativas:
Precisión en el pesaje de la comida y en la programación de las porciones.
Información detallada sobre los hábitos alimenticios de los gatos que pueda ser utilizada para ajustes dietéticos.
Datos fiables y consistentes para su análisis y recomendaciones.
Rol: Asesores y promotores del sistema.

Inversionistas y Accionistas
Intereses: Rentabilidad del proyecto, retorno de inversión, y crecimiento en el mercado de productos para mascotas.
Influencias: Alta, ya que proporcionan los fondos necesarios para el desarrollo y expansión del proyecto.
Expectativas:
Progresos medibles y reportes regulares sobre el desarrollo del proyecto.
Estrategias claras de monetización y expansión de mercado.
Garantía de que el proyecto cumple con los plazos y objetivos establecidos.
Rol: Financistas y supervisores del proyecto.

## Metodología Ágil Elegida
Para el desarrollo de NutriPet, se opta por utilizar una combinación de las metodologías Scrum y Kanban:
Scrum:
Características:
Iteraciones cortas y repetitivas llamadas sprints (3 semanas).
Roles definidos: Product Owner, Scrum Master, Equipo de Desarrollo.
Eventos de Scrum: Sprint Planning, Daily Scrum, Sprint Review, Sprint Retrospective.
Artefactos: Product Backlog, Sprint Backlog, Increment.
Justificación: Permite una planificación estructurada y revisión constante del progreso, asegurando que el proyecto se mantenga en el camino correcto.
Kanban:
Características:
Visualización del flujo de trabajo mediante un tablero Kanban.
Limitación del trabajo en progreso (WIP).
Mejora continua basada en la visualización de los cuellos de botella y optimización del flujo.
Justificación: Proporciona flexibilidad para ajustar las prioridades en tiempo real, mejora la eficiencia del flujo de trabajo y permite una rápida adaptación a los cambios.



## Requerimientos
Los Requerimientos se encuentran Detallados con su nomenclatura correspondiente en el KanBan de trello en el que se lleva a cabo las iteraciones del proyecto.
https://trello.com/b/pUGB93sF/nutripet


## **Modificaciones en la Planificación y Reajuste de la Metodología

# Reajuste de la Metodología Ágil
Para asegurar el cumplimiento de los objetivos del proyecto NutriPet, se ha decidido realizar un reajuste en la metodología ágil inicialmente seleccionada y extender un mes más el tiempo estimado de entrega para garantizar un producto viable

# Problemas Encontrados Durante el Desarrollo del MVP
Durante el desarrollo del MVP del prototipo inicial, nos encontramos con varios contratiempos significativos:
Atascos en la Extrusora de Alimento: Algunas versiones de alimento para mascotas, especialmente aquellas con un tamaño inferior al considerado inicialmente, se atascan en la extrusora. Esto ocurre porque los pellets de comida pequeños quedan atorados en el mecanismo de distribución, lo que impide un flujo continuo de alimento.
Solución Propuesta: Rediseñar la extrusora para manejar diferentes tamaños de pellets y realizar pruebas adicionales con varios tipos de alimentos para garantizar un funcionamiento suave.
Fallas en el Movimiento de la Tolva del Reservorio de Alimento: Cuando la tolva del reservorio de alimento está completamente cargada, el peso del alimento genera fallas en el movimiento del sistema. Esto puede deberse tanto al diseño de la tolva como al torque del motor del dispensador.
Solución Propuesta:
Reforzar el diseño de la tolva para soportar mejor el peso del alimento.
Utilizar un motor con mayor torque que pueda manejar el peso adicional sin problemas.

# Ajustes en la Planificación
Debido a estos contratiempos, hemos realizado los siguientes ajustes en la planificación:
   Sprint Adicional para Rediseño y Pruebas: Se añadirá un sprint adicional dedicado exclusivamente al rediseño de la extrusora y la tolva del reservorio, así como a las pruebas con diferentes tipos de alimentos para asegurar que los problemas se han resuelto.

   Incremento en la Iteración de Pruebas: Aumentaremos la cantidad de pruebas y ajustes en cada sprint para identificar y resolver posibles problemas antes de avanzar a la siguiente fase del desarrollo.

   Revisión y Actualización del Kanban en Trello: El tablero Kanban en Trello será actualizado con las nuevas tareas y ajustes necesarios para abordar los problemas encontrados. Se priorizarán las tareas críticas para asegurar que el MVP esté completamente funcional antes de pasar al desarrollo de la aplicación y la conectividad.

Con estas modificaciones, el proyecto NutriPet está mejor posicionado para alcanzar sus objetivos, asegurando un sistema de alimentación inteligente y confiable para gatos.

