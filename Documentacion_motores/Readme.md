# Documentación de los motores Dynamixel AX-18A
---
## Instalación de Tarjeta OpenCM9.04

### 1. Descargar e instalar el IDE de [Arduino](https://www.arduino.cc/en/software)
### 2. Dentro del IDE de Arduino dar clic en "Archivo" (esquina superior izquierda) y después en "Preferencias"
![ArchivoPreferencias IDE](https://i.imgur.com/JbRtXgO.png)
### 3. En el apartado "Gestor de URLs Adicionales de Tarjetas" de la ventana de "Preferencias" pegar el link: **https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCM9.04/master/arduino/opencm_release/package_opencm9.04_index.json** obtenido de [ROBOTIS e-Manual](https://emanual.robotis.com/docs/en/parts/controller/opencm904/) y presionar "Ok"
![Preferencias](https://i.imgur.com/i3gvujG.png)
### 4. Dar clic en la sección de "Herramientas", después en "Placa:" y por último en "Gestor de tarjetas..."
![Gestor de tarjetas](https://i.imgur.com/WDc0RVx.png)
### 5. En el buscador de la ventana "Gestor de tarjetas" escribir "opencm", instalar la única opción que aparece y cerrar la ventana
![Instalacion OpenCM](https://i.imgur.com/Y8BVRsl.png)
---
## Instalación de bibliotecas Dynamixel

### 6. Dar clic en el apartado "Programa" en la parte superior izquierda, después dar clic en "Incluir Librería" y por último en "Administrar bibliotecas..."
![Administrar bibliotecas](https://i.imgur.com/RBUWOHV.png)
### 7. Escribir "Dynamixel2Arduino" en el buscador de la pestaña "Gestor de librerías" e instalar la única opción que aparece
![Gestor de librerías](https://i.imgur.com/4rjSYaY.png)
---
## Ejemplo read_write_ax

### 8. Para abrir el ejemplo read_write_ax hay que dar clic en la sección "Archivo", después en "Ejemplo", después en "OpenCM9.04", después en "07_DyamixelSDK", después en "protocol1.0" y por último en read_write_ax
![Ejemplo ReadWrite AX](https://i.imgur.com/EnPWOM6.png)
### 9. Escribir a continuación de la variable "#define DXL_ID" el ID del servomotor que se quiere mover
![ID](https://i.imgur.com/UQ2G51S.png)
### 10. Escribir un valor mínimo y un valor máximo de posición entre los cuales se moverá el motor (el rango permitido es desde 0 hasta 1023 que son de 0 a 300 grados aproximadamente)
![Posicion](https://i.imgur.com/YBRohBI.png)
---
## Pruebas de movimiento de servomotores Dynamixel

### En este caso se realizaron tres pruebas con distintos parámetros debido a la posición en la que se encontraban los motores y en cada prueba se grabó un vídeo para ver su funcionamiento

### [Prueba 1](https://www.youtube.com/shorts/XA939PQ_-Zk)
### ID de servomotor 1 rango de movimiento de 400 a 500 (de 116 a 145 grados aproximadamente)
![Prueba1](https://i.imgur.com/lcGE2qG.png)
### [Prueba 2](https://www.youtube.com/watch?v=NhqNLQuu300)
### ID de servomotor 4 rango de movimiento de 512 a 612 (de 148.48 a 177.48 grados aproximadamente)
![Prueba2](https://i.imgur.com/3pgluG1.png)
### [Prueba 3](https://www.youtube.com/shorts/ls9LpuPgASs)
### ID de servomotor 5 rango de movimiento de 100 a 512 (de 29 a 148.48 grados aproximadamente)
![Prueba3](https://i.imgur.com/fz8dNzL.png)
---

## Configuración del Dynamixel SDK en Matlab

### 1. Descargar de la página [ROBOTIS e-Manual](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/download/#repository) el archivo con nombre "DYNAMIXEL SDK 3.7.31.zip (For ROS1, Python, C, C++, C#, MATLAB, LabView, Java)" y descomprimirlo
![DescargaSDK](https://i.imgur.com/b7BewZD.png)
### 2. Ahora dentro de Matlab nos tenemos que dirigir a la pestaña "HOME", después al apartado de "ENVIRONMENT" y dar clic en "Set Path"
![SetPath](https://i.imgur.com/ZGIBFD5.png)
### 3. En la ventana de "Set Path" tenemos que dar clic en la opción "Add with Subfolders..." y buscar la ubicación de la carpeta descomprimida "DynamixelSDK-3.7.31" y dar doble clic sobre ella
![DynamixelSDK](https://i.imgur.com/R3QMUeh.png)
### 4. A continuación daremos doble clic en la carpeta "C" después doble clic en la carpeta "include" y por último daremos clic en "Seleccionar esta carpeta"
![IncludeC](https://i.imgur.com/MdHLSlW.png)
### 5. Después, en la ventana "Set Path" tenemos que dar clic en la opción "Add Folder...", buscar la carpeta "DynamixelSDK-3.7.31" y dar doble clic sobre ella, dar doble clic en "C", dar doble clic en "build", dar doble clic en "win64", seleccionar la carpeta "output" dándo un clic sobre ella y por último dar clic en "Seleccionar esta carpeta"
![BuildWin64](https://i.imgur.com/sn3HuFs.png)
### 6. Por último en la ventana "Set Path" tenemos que dar clic en la opción "Add with Subfolder...", buscar la carpeta "DynamixelSDK-3.7.31" y dar doble clic sobre ella, después seleccionaremos la carpeta "matlab" dándo un clic sobre ella y daremos clic en "Seleccionar esta carpeta"
![MatlabFolder](https://i.imgur.com/MdGA0NW.png)
### 7. Para finalizar con la configuración, en la ventana "Set Path" daremos clic en la opción "save" y después en la opción "close"
![SaveClose](https://i.imgur.com/bXtvRW0.png)
