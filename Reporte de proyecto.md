
# Proyecto_3_semestre_2023-1
# Implementación de un control de un robot serial 5R con motores dynamixel

| Código | Description |
| ------:| ----------- |
| ***Asignatura*** | Robótica *2135* | 
| **Robotica-2023-I**  | Proyecto Robot Dynamixel |
| **IT102321-C002** | Proyecto - Juntas rotacionales - Robót  |

# Contenido

- [Objetivo](#Objetivo)
- [Introducción](#Introducción)
- [Desarrollo](#Desarrollo)
- [Conclusiones](#Conclusiones)
- [Autor](#Autores)
- [Referencias](#Referencias)


# Productos
- Repositorio con los archivos generados durante la realización del proyecto.
- Banco de pruebas del robot para ser utilizado en prácticas de la asignatura de robótica.

# Objetivo
Implementar una interfase de control de un robot serial 5R con actuadores dynamixel para el desarrollo de prácticas de robótica.
## METAS
- Establecer el modelo cinemático del robot e implementarlo en un simulación.
- Modificar CAD y Crear el modelo URDF del robot para la generación de la simulación en Simscape y/o en ROS2.
- Interfaz de control del robot que permite programar para realizar tareas de manipulación de objetos, 
  mediante esquemas de planeación de movimientos.
- Plantear el desarrollo de una tarea programada.
# Introducción

Para entrar en contexto con el root dynamixel es necesario entender el porque recibe este nombre, como menciona su propio 
sitio web, Dynamixel es un sistema actuador inteligente desarrollado exclusivamente para conectar juntas para un robot o
una estructura mecánica; estos están diseñados para ser modulares y fáciles de montar en cualquier robot o diseño mecánico
para movimientos roboticos poderosos y flexibles. [[1]](#1).

Los Dynamixel tienen un elevado desempeño como actuador ya que contienen un Motor de corriente directa completamente 
integrado con un reductor, un controlador interno y un driver para su conexión. 

Tambien es bueno tomar en cuenta que este tipo de robot es de los robots clásicos que presentan una arquitectura antropomórfica serial, semejante al brazo humano. Consisten de una serie de barras rígidas unidas entre sí a través de articulaciones de un grado de libertad del tipo rotacional o prismática. En general cada articulación logra su movimiento a través de un accionamiento de potencia e incluye otros dispositivos como reductores de velocidad, frenos y sensores de posición o velociad.

Al definir las relaciones cinemáticas de un robot no se suelen consideran los aspectos dinámicos, nada más alejado de la realidad cuando se quiere diseñar un robot ya que existe una inevitable relación causa-efecto entre la cinemática y la dinámica. Nada más claro resulta que al pensar en las dimensiones de un robot, la longitud de un brazo afecta al cuadrado la inercia de los eslabones y por lo tanto el peso del robot y la potencia requerida en los actuadores. [[2]](#2)

# Desarrollo

Para el desarollo de este proyecto, lo primero que hicimos fue ponernos en contexto para conocer las necesidades
que presentaba el prototipo, asi como las actividades que necesitamos realizar para llegar a las metas que se nos 
fueron establecidas al inicio.

Después de estar inmersos en este contexto, iniciamos con la primer actividad o meta, que es establecer el modelo 
cinemático del robot para poder realizar simulaciones como material de ayuda para en esta asignatura.
Lo primero que se hizo para cumplir con esta meta fue desarrollar el diagrama de cuerpo libre para establecer
los ejes de referencia inicial de nuestro robot y a partir de lo aprendido durante el curso de robótica
buscar los ejes de referenia para cada junta rotacional y así encontrar el modelo cinemático del robot.

A continuación se muestra el diagrama que cuerpo libre en donde mostramos todos los ejes de referencia que 
marcamos para realizar nuestro análisis de este robot.

![Analisis cinematico del robot](https://github.com/mrg-mex/Proyecto_3_semestre_2023-1/blob/main/SmartSelect_20230109_203057_Adobe%20Acrobat.jpg)

Una vez realizado esto, el ingeniero Erick Peña Medina nos ayudo a realizar el modelo cinemático del robot, 
para posteriormente iniciar con las demas actividades o metas establecidas.

Como continuación del proyecto, la siguiente meta o actividad por realizar era llevar a cabo la modificación 
del CAD del brazo robótico debido a que éste contenia errores en manejo de software que eran de gran importancia
arreglar ya que estas imperfecciones que contenia el CAD interferían para poder realizar el archivo URDF que es 
necesario para poder utilizar este CAD para simulaciones en Matlab.

Como primer paso en la modificación de estas piezas lo que hicimos fue en primer lugar, examinar cuales eran
las piezas afectadas o que contenian error de manejo de software para poder actuar sobre estas, el primer 
descubrimiento que encontramos fue que el griper estaba montado de manera superficial en el brazo, es decir,
no habia conexión entre ambas piezas y por lo tanto no iban a funcionar para la simulación, al momento de 
intentar realizar la conexion entre ambas, descubrimos otro error, ya que el gripper montado tenia un 
dimensionamiento incorrecto lo cual generaba un mal ensamble entre ambas piezas, por lo que fue necesario 
volver a realizar el CAD completo del gripper para que este coincidiera con las bases que tenemos de nuestro
brazo robótico. Para esto desensamblamos el robot físico que se encontraba en el cubículo de trabajo del CIA
y tomamos las medidas del gripper con ayuda de nuestras herramientas de medición disponibles (Vernier y regla).
Una vez realizado el redimensionamiento y creación del nuevo gripper, este se añadio a su lugar correspondiente
en el CAD del brazo completo, posteriormente como último paso corregimos todos los errores de conexión que habia
entre las piezas y que generaban el error para poder realizar el archivo URDF y emplearlo en simulaciones de 
matlab.

A continuacón se muestra una imagen renderizada del CAD del brazo completo, después de realizar la recreación 
del gripper y corregir los errores de ensamble.

![CAD corregido render](https://github.com/mrg-mex/Proyecto_3_semestre_2023-1/blob/main/5R_Pos0.JPG)

A partir de la meta pasada, logramos movernos a la siguiente meta que era realizar el archivo URDF del CAD para
emplearlo en simulaciones en matlab. Para realizar esta actividad solo fue necesario seguir los pasos de un tutorial 
en youtube que adjunto a continuación.

![VIDEO PARA OBTENER URDF](https://www.youtube.com/watch?v=CKlK5H8EguA&t=2423s)

Por ultimo importamos este URDF a matlab para poder realizar simulaciones de movimiento.

# Conclusiones
Se lograron cumplir los objetivos y metas establecidas al inicio del proyecto, se logro con exito el inicio del 
planteamiento del modelo cinematico, tambien se llevo a cabo la correcion de piezas del modelado del brazo completo para 
posteriormente poder realizar el ensamble completodel robot para que este se pueda utilizar correctamente para 
simulaciones en matlab, posteriormente logramos llevar a cabo gracias a lo anterior, la etencion del URDF para 
poder exportarlo a matlab y asi poder simular en este los movimientos del brazo robotico.

El proyecto nos ayudo a poder asentar el conocimiento adquirido a lo largo del semestre, poniendo en marcha 
tanto lo visto en clase, como el calculo para el modelo cinematico, el uso de matlab y como funcionan las simualciones
en el software, como tambien aprendimos a utilizar GitHub y a aprender a realizar un archivo URDF, lo cual nos
brinda mucho conocmiento y experiencia para nuestra futura vida profesional como ingenieros.
# Autores
| Iniciales  | Description |
| ----------:| ----------- |
| **BUPD** | Brandon Ulises Pérez Delgado [GitHub profile](https://github.com/Brandon-PD) |
| **JARC**  | Jonathan Alejandro Rodríguez Corona [GitHub profile](https://github.com/AlejandroCorona083) |
| **EPM** | Erik Peña Medina [GitHub profile](https://github.com/ErikFiUNAM) |
| **DRR** | Diego Ramírez Rebollar |

# Referencias
<a id="1">[1]</a> “Dynamixel: All-in-one smart actuator,” ROBOTIS.US. [Online]. Available: https://www.robotis.us/dynamixel/. 

<a id="2">[2]</a>  W. Caraguay Ambuludi y L. Benavides Castillo, “Interfaz de Simulación de la Cinemática de Robots Manipuladores Seriales”, Investigatio, vol. 7, pp. 35–47, 2016.


