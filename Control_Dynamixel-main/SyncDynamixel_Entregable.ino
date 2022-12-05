

#include <DynamixelWorkbench.h>

#if defined(__OPENCM904__)
  #define DEVICE_NAME "3" //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
#elif defined(__OPENCR__)
  #define DEVICE_NAME ""
#endif   

#define BAUDRATE  1000000
#define DXL_ID_1  1
#define DXL_ID_2  3

//********GLOBALES**********
uint8_t dxl_id[2] = {DXL_ID_1, DXL_ID_2};
//*************************
DynamixelWorkbench dxl_wb;

int32_t goal_position[2] = {10, 1010};

const uint8_t handler_index = 0;

//*********SETUP*************
void setup() {
 Serial.begin(57600);
  bool result = false;
  bool result_Pos = false;
  const char *log;
  uint16_t model_number = 0;
  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if(result==false){
    Serial.println(log);
    Serial.println("No se pudo realizar la conexión");
  }
  else{
    Serial.print("Conexión exitosa : ");
    Serial.println(BAUDRATE);
  }
  
//*******PING DE MOTORES***********
   for (int cnt = 0; cnt < 2; cnt++)
  {
    result = dxl_wb.ping(dxl_id[cnt], &model_number, &log);
    int identificador=(int)dxl_id[cnt];
    if (result == false  )
    {
      Serial.println(log);
      Serial.print("Dynamixel id: " );
      Serial.print(identificador);
      Serial.println(" No encontrado");
    }
    else
    {
      Serial.println("Ping Exitoso");
      Serial.print("id : ");
      Serial.print(dxl_id[cnt]);
      Serial.print(" model_number : ");
      Serial.println(model_number);
    }
  }
//***POSICION INICIAL MOTORES***///
  for (int cn = 0; cn < 2; cn++){
    int32_t get_data = 0;
  result_Pos = dxl_wb.itemRead(dxl_id[cn], "Present_Position", &get_data, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to get present position");
  }
  else
  {
    Serial.print("Dynamixel ID: ");
    Serial.println(dxl_id[cn]);
    Serial.print("Posicion Inicial(value : ");
    Serial.print(get_data);
    Serial.println(")");
  }
  }

}

void loop() {
  
  const char *log;
  bool result = false;
  
  String buffer = "";
  String substring="";
  int i =9;
  int Id=0;  //ID DYNAMIXEL A MOVER
  int Pos=0; // POSICION DE DYNAMIXEL
  String Position="";

  //****LECTURA LINEA TXT*****
  while(Serial.available()>0){
    delay(20);
    buffer +=(char)Serial.read();
    
    //******BUFFER TXT ANALISIS**********
    if(buffer.startsWith("ID:",0)&&buffer.startsWith("Pos:",5)){
      Id=String(buffer[3]).toInt();
      //Serial.println(ID);
      while(i<buffer.length()-1){        
        substring+=buffer[i];
         i++;       
      }
      delay(100);
      Position=substring;
      Pos =Position.toInt();
     
      }
                     
    else{
      //Serial.println(buffer);
    }
    
  }

  //**** ID  Y POS SEGMENTADO**********
   if(substring.length()==((buffer.length()-1)-9)){
         Serial.println(" ");
         Serial.println("INSTRUCCIÓN PARA: ");
         Serial.print("Dynamixel ID: ");
         Serial.print((uint8_t)Id);
         delay(3000);
         
 //*****JOINT MODE CONFIGURACION********
         result = dxl_wb.jointMode((uint8_t)Id, 0, 0, &log);
         if (result == false)
          {
            Serial.println(log);
            Serial.println("Error al cambiar a modo Junta");
          }
        else
        {
            Serial.println("Correctamente cambiado a modo Junta");
            

        }
//*** INSTRUCCION MOVER DYNAMIXEL*****
        dxl_wb.goalPosition((uint8_t)Id, (int32_t)Pos);
         Serial.println("**GIRO COMPLETADO**");
         Serial.print("Dynamixel ID: ");
         Serial.print((uint8_t)Id);
         Serial.print("        ");
         Serial.print("Posicion Actual: ");
         Serial.println((uint32_t)Pos);
         delay(3000);
   }
  
}
