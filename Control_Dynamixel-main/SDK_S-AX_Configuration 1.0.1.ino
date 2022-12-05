/*
*AUTOR: EDGAR TOBÓN SOSA
*CORREO: etobon96@gmail.com
*LICENCIA: Universidad Nacional Autonoma de Mexico
*
*Control de Dynamixel AX-Series a través del BUS de OPENCM 485 (EXP-BOARD)
*Documentacion: http://emanual.robotis.com/docs/en/parts/controller/opencm485exp/#layout
*/

#include <DynamixelSDK.h>  //"Incluimos la libreria de Dynamixel"

/*
*Tabla Control AX-Series
*Tabla de Direcciones: h.,ttps://emanual.robotis.com/docs/en/dxl/ax/ax-12a/#control-table-of-eeprom-area
*/
//DIRECCIONES


//Protocolo para AX-Series
#define PROTOCOL_VERSION 1.0

//Configuraciones por Defecto *Si no se conocen realizar un Scan
#define DXL_ID 1   //ID para cada Dinamixel
#define BAUDRATE 1000000
#define DEVICENAME "3"  //OpenCM 485 EXP's envia y recice el BUS del paquete a traves del USART3

//Indica los valores de configuracion que deseas que necesitas
#define DXL_NEW_ID  1     //Valor si se desea cambiar el ID
#define TORQUE_ENABLE 1   //Valor para habilitar el torque
#define TORQUE_DISABLE 0  //Valor para deshabilitar el torque
#define TORQUE_VALUE 1023 //1023 ->Torque Maximo
#define GOAL_POSITION 400 //Valor posicion
#define SPEED_VALUE   1023   //Valor velociadad


#define DXL_MINIMUM_POSITION_VALUE 100
#define DXL_MAXIMUM_POSITION_VALUE 1000
#define DXL_MOVING_STATUS_THRESHOLD 20  //Umbral de movimiento

#define ESC_ASCII_VALUE 0x1b  //Hexadecimal

int16_t dxl_present_position = 0; //Variable almacena posicion actual
int16_t dxl_present_torque = 0;   //Variable almancena torque actual
int16_t dxl_present_speed = 0;  //Variable almancena la velocidad actual
int16_t DXL_ID_V;
void setup() {

  Serial.begin(115200);
  while (!Serial);

  Serial.println("Comunicación Serial Exitosa");

  //Instanciamos el objeto portHandler de la clase PortHandlerWindows ->OpenCM 485 EXP's
  dynamixel::PortHandler *portHandler = dynamixel::PortHandler::getPortHandler(DEVICENAME);
  //Instanciamos el objeto packetHandler de la clase PortHandlerWindows ->Version 1.0
  dynamixel::PacketHandler *packetHandler = dynamixel::PacketHandler::getPacketHandler(PROTOCOL_VERSION);

  int dxl_comm_result = COMM_TX_FAIL;  //  Fallo transimision de instruccion ->Valor:-1001

  uint8_t dxl_error = 0;

  //Abrir Puerto
  if (portHandler->openPort()) 
  {
    Serial.print("Puerto Abierto con Exito!\n");
  } else {
    Serial.print("Error al abrir el puerto!\n");
  }
  //Configuracion el Baudrate
  if (portHandler->setBaudRate(BAUDRATE)) 
  {
    Serial.print("Configuracion de baudrate exitosa\n");
  }

  else 
  {
    Serial.print("Error al configurara el baudrate");
  }




 //*** TORQUE***

/*
//DESCOMENTA PARA HABILITACIÓN DE TORQUE
  Serial.print("Habilitacion de Torque\n");
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_AX_TORQUE_ENABLE, TORQUE_ENABLE, &dxl_error);
  if(dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);
      
  }
  else if(dxl_error!=0)
  {
    packetHandler->getRxPacketError(dxl_error);
    Serial.print("b");
  }
  else
  {
    Serial.print("Dynamixel Torque Habilitado con Exito\n");
  }
                 
 
*/
 //********************************************************

/*
//DESCOMENTA PARA DESHABILITACIÓN DE TORQUE
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_AX_TORQUE_ENABLE, TORQUE_DISABLE, &dxl_error);
  if (dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);
    Serial.print("aT");
  }
  else if (dxl_error != 0)
  {
    packetHandler->getRxPacketError(dxl_error);
  }
  else
  {
    Serial.print("Dynamixel Torque Deshabilitado con Exito\n");
  }



//**********************************************
*/

/*
* WHEEL MODE CONFIGURACION
dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_CW_ANGLE_LIMIT, 0, &dxl_error);
dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_CCW_ANGLE_LIMIT, 0, &dxl_error);
Serial.print("WHEEL MODE ACTIVADO");



*/

//**************************************************************


//CONFIGURACION DE MAXIMO TORQUE
dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_DXL_MAXIUM_TORQUE, TORQUE_VALUE, &dxl_error);

//GET TORQUE MAXIMO
dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, DXL_ID, 14, (uint16_t*)&dxl_present_torque, &dxl_error);

//**************************************************************

//CONFIGURACION DE VELOCIDAD
dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_MOVING_SPEED, SPEED_VALUE, &dxl_error);

//GET VELOCIDAD
dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, DXL_ID, 14, (uint16_t*)&dxl_present_speed, &dxl_error);
//*************************************************************

 //CONFIGURACION DE POSICION      

  dxl_comm_result = packetHandler->write2ByteTxRx(portHandler, DXL_ID, ADDR_AX_GOAL_POSITION, GOAL_POSITION, &dxl_error);
  if (dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);      
  }
  else if (dxl_error != 0)
  {
    packetHandler->getRxPacketError(dxl_error);
  }
        
 //GET Posicion 
 
  dxl_comm_result = packetHandler->read2ByteTxRx(portHandler, DXL_ID, ADDR_AX_PRESENT_POSITION, (uint16_t*)&dxl_present_position, &dxl_error);
  if (dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);
  }
  else if (dxl_error != 0)
  {
    packetHandler->getRxPacketError(dxl_error);
  }

//*************************************************************

//CHANGE ID
/*
  dxl_comm_result = packetHandler->write1ByteTxRx(portHandler, DXL_ID, ADDR_AX_ID, DXL_NEW_ID, &dxl_error);
  
  if(dxl_comm_result != COMM_SUCCESS)
  {
    packetHandler->getTxRxResult(dxl_comm_result);
    Serial.print("ID no ha cambiado con Exito\n");
      
  }
  else if(dxl_error!=0)
  {
    packetHandler->getRxPacketError(dxl_error);
    Serial.print("ID no ha cambiado con Exito\n");
    
  }
  else
  {
    DXL_ID_V=DXL_NEW_ID;
    Serial.print("ID cambiado con Exito\n");
  }
  

*/

//**************************************************************




  Serial.print("[ID:");      Serial.print(DXL_ID);
  Serial.print(" Torque Actual:");  Serial.print(dxl_present_torque);
  Serial.print(" Velocidad Actual:");  Serial.print(dxl_present_speed);
  Serial.print(" Posicion Actual:");  Serial.print(dxl_present_position);
  Serial.println(" ");         
        
        
    
        
  
}



void loop() {
  // put your main code here, to run repeatedly:
}