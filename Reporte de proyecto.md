
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
para movimientos roboticos poderosos y flexibles.

Los Dynamixel tienen un elevado desempeño como actuador ya que contienen un Motor de corriente directa completamente 
integrado con un reductor, un controlador interno y un driver para su conexión. 



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

--> *Agregar imagen*

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

--> *Agregar imagen*

A partir de la meta pasada, logramos movernos a la siguiente meta que era realizar el archivo URDF del CAD para
emplearlo en simulaciones en matlab. Para realizar esta actividad solo fue necesario seguir los pasos de un tutorial 
en youtube que adjunto a continuación.

--> *Agregar video*

Por ultimo importamos este URDF a matlab para poder realizar simulaciones de movimiento.

# Conclusiones
# Autores
| Iniciales  | Description |
| ----------:| ----------- |
| **BUPD** | Brandon Ulises Pérez Delgado [GitHub profile](https://github.com/Brandon-PD) |
| **JARC**  | Jonathan Alejandro Rodríguez Corona [GitHub profile](https://github.com/AlejandroCorona083) |
| **EPM** | Erik Peña Medina [GitHub profile](https://github.com/ErikFiUNAM) |
| **DRR** | Diego Ramírez Rebollar |

# Referencias
<a id="1">[1]</a> “Dynamixel: All-in-one smart actuator,” ROBOTIS.US. [Online]. Available: https://www.robotis.us/dynamixel/. 

