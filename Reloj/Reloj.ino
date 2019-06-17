 #include <EEPROM.h>                                                                                    
 #include <Shifter.h>;
 #include <Wire.h> 
 #include "RTClib.h" 
 #define UP 2
 #define DOWN 3

  DS1307 RTC; 
 int address1=1;
 int address2=2;

int son=0;
int es=1;
int las=2;
int la=3;

int doce=4;
int dos=5;
int once=6;
int siete=7;
int nueve=8;
int cinco=9;
int diez=10;
int una = 11;
int seis= 12;
int ocho=13;
int cuatro= 14;
int tres= 15;

int menos= 16;
int en = 17;
int y = 18;

int media=19;
int mdiez=20;
int veinte=21;
int cuarto=22;
int punto=23;
int veinti=24;
int mcinco=25;


int i=0;
 
int opcion=0;  // esta me dice la condicion de los minutos, cuarto , diez , punto ,etc...

int m=0;  // variable para entrar a los distintos menus
int corhora=0; //variable que uso para corregir la hora manualmente
int cormin=0; //variable que uso para corregir los minutos manualmente

bool entro=0; //Con esta variable hago la correcion, e impido que entre en un loop
int contador=0; //Contador que se encarga de corregir aun mejor cada 10 dias 9 segundos más
 
 #define SER_pin 11
 #define RCLK_pin 8
 #define SRCLK_pin 12
 #define NUM_REGISTERS 4 


 Shifter shifter(SER_pin,RCLK_pin,SRCLK_pin,NUM_REGISTERS);

void setup() {
    
    Wire.begin(); 
    RTC.begin(); 
    Serial.begin(9600);

    pinMode(4,INPUT_PULLUP);//MENU
    pinMode(2,INPUT_PULLUP);//UP
    pinMode(3,INPUT_PULLUP);//DOWN
    pinMode(5,INPUT_PULLUP);// RESET ALL
    
    

    corhora=EEPROM.read(address1);
    cormin=EEPROM.read(address2);
  // EEPROM.write(address1,0);
  // EEPROM.write(address2,0);
   
    // RTC.adjust(DateTime(__DATE__, __TIME__));
  //if (!RTC.isrunning()) {
  // 
  //  Serial.println("RTC is NOT running!");// following line sets the RTC to the date & time this sketch was compiled
  // RTC.adjust(DateTime(__DATE__, __TIME__));
  // }
   
}

void loop() {

 while (m==0) { 
 DateTime now = RTC.now();

 int hora = now.hour();
 int minutos = now.minute();
 int segundos= now.second();  


 hora= hora+corhora;
 minutos=minutos+cormin;
 
 //Serial.print(corhora);
 //Serial.print(":");
 //Serial.println(cormin);
 //Serial.print(String(hora));Serial.print(":");Serial.print(String(minutos));Serial.print(":");Serial.print(String(segundos-10));Serial.println("");
 //Serial.println(String(hora)+":"+String(minutos)+":"+String(segundos));

 int decena = minutos/10;                // ESTOS LOS USO PARA PRENDER LOS LEDS INDEPENDIENTES DE 
 int unidad = minutos - (decena*10);     //               LOS   MINUTOS 1 2 3 Y 4

 boolean menu = digitalRead(4);          //LEO EL BOTON QUE ES EL UNICO QUE ACTIVA EL MENU.
 boolean resetall= digitalRead(5);       //LEO EL BOTON QUE DA RESET A TODO


    //////////////////////////////////////////////////////////////
    /////////////CORRECCION DERIVA DE HORA////////////////////////
    //////////////////////////////////////////////////////////////
 
 if((now.hour()==0) && (now.minute()==0) && (now.second()==50) && entro==0) //CADA DÍA CORRIGE 9 SEGUNDOS
 {
  RTC.adjust(DateTime(now.year(),now.day(),now.month(),now.hour(),now.minute(),now.second()-9));
  entro=1;
  contador++;
  delay(500);
  }
  if((now.hour()==0) && (now.minute()==0) && (now.second()==21) && entro==1)
  {
    entro=0;
    }
  if (contador==10) //CADA 10 DÍAS CORRIGE 9 SEGUNDOS MENOS
  {
    RTC.adjust(DateTime(now.year(),now.day(),now.month(),now.hour(),now.minute(),now.second()-9));
    contador=0;
    }
  //////////////////////////////////////////////////// 
  
    //////////////////////////////////////////////////////////////////////////////
    /////////////RESETEO DE LA EEPROM, EN CASO DE QUE ALGO FALLE//////////////////
    //////////////////////////////////////////////////////////////////////////////
  if(resetall==0)
  { 
    EEPROM.write(address1,0);
    EEPROM.write(address2,0);
    RTC.adjust(DateTime(2019,25,01,0,0,0));
    delay(200);
    }
  ////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////
  //////////////////RESET DE SEGURIDAD////////////////////////////////
  ////////////////////////////////////////////////////////////////////
  if(cormin>=100)
  {
    EEPROM.write(address1,0);
    EEPROM.write(address2,0);
    delay(200);
    }
  
 if(menu==LOW)
  {
  m=1; // menu 1 entras a el menu para cambiar la hora
  delay(200);
  }
 

 
 if (now.second()==0)
  {
    
    
    for( int aux=0; aux<=32; aux++)
      {
     shifter.setPin(aux,HIGH);
     shifter.write();
     delay(50);
      }
   }

  if (now.second()==30)
  {
    
  
    for( int aux=32; aux>=0; aux--)
      {
     shifter.setPin(aux,HIGH);
     shifter.write();
     delay(50);
     
      }
   }


 if (minutos>=0 and minutos<5)
  {opcion=1;}
  if (minutos>=5 and minutos<10)
  {opcion=2;}
  if (minutos>=10 and minutos<15)
  {opcion=3;}
 if (minutos>=15 and minutos<20)
  {opcion=4;}
 if (minutos>=20 and minutos<25)
  {opcion=5;}
 if (minutos>=25 and minutos<30)
  {opcion=6;}
 if (minutos>=30 and minutos<35)
  {opcion=7;}
 if (minutos>=35 and minutos<40)
  {opcion=8;hora=hora+1;}
 if (minutos>=40 and minutos<45)
  {opcion=9;hora=hora+1;}
 if (minutos>=45 and minutos<50)
  {opcion=10;hora=hora+1;}
 if (minutos>=50 and minutos<55)
  {opcion=11;hora=hora+1;}
 if (minutos>=55 and minutos<60)
  {opcion=12;hora=hora+1;}


 switch (hora){

  case (0):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;
  
  case (1):
    shifter.setPin(es,HIGH);shifter.setPin(la,HIGH);shifter.setPin(son,LOW);shifter.setPin(las,LOW);

    
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,HIGH);
    shifter.write();
    break;

  case (2):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,HIGH);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (3):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,HIGH);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (4):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,HIGH);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (5):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,HIGH);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (6):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,HIGH);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (7):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,HIGH);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (8):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,HIGH);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (9):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,HIGH);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (10):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,HIGH);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (11):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,HIGH);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

   case (12):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

   case (13):
    shifter.setPin(es,HIGH);shifter.setPin(la,HIGH);shifter.setPin(son,LOW);shifter.setPin(las,LOW);

    
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,HIGH);
    shifter.write();
    break;

  case (14):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,HIGH);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (15):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,HIGH);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (16):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,HIGH);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (17):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,HIGH);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (18):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,HIGH);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (19):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,HIGH);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (20):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,HIGH);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (21):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,HIGH);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (22):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,HIGH);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (23):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,HIGH);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

   case (24):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

 }

 

   switch (opcion){

    case 1:
    shifter.setPin(menos,LOW);shifter.setPin(en,HIGH);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,HIGH);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 2:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,HIGH);
    break;

    case 3: 
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,HIGH);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 4:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,HIGH);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 5:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,HIGH);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 6:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,HIGH);shifter.setPin(mcinco,HIGH);
    break;

    case 7:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,HIGH);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 8:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,HIGH);shifter.setPin(mcinco,HIGH);
    break;

    case 9: 
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,HIGH);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 10:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,HIGH);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 11:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,HIGH);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 12:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,HIGH);
    break;
   }

  switch(unidad){
  
  case 0:
      shifter.setPin(26,LOW);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 1:
      shifter.setPin(26,HIGH);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 2:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;  
  case 3:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,LOW);
      break;
  case 4:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,HIGH);
      break;
  case 5:
      shifter.setPin(26,LOW);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 6:
      shifter.setPin(26,HIGH);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 7:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;    
  case 8:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,LOW);
      break; 
  case 9:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,HIGH);
      break;
     
  }

}

  while (m==1){

    DateTime now = RTC.now();

    int hora = now.hour();
    hora= hora+corhora;
    
    if(digitalRead(UP)==LOW)
    {
    corhora=corhora+1;
    delay(200);
    }
    if(digitalRead(DOWN)==LOW)
    {corhora=corhora-1;
    delay(200);
      }

    if(digitalRead(4)==LOW)
    {
      EEPROM.write(address1,corhora);
      m=2;
      delay(200);
      }

    Serial.println("m=1");
    Serial.println(corhora);
    shifter.setAll(LOW);
    
    switch (hora){

  case (0):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;
  
  case (1):
    shifter.setPin(es,HIGH);shifter.setPin(la,HIGH);shifter.setPin(son,LOW);shifter.setPin(las,LOW);

    
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,HIGH);
    shifter.write();
    break;

  case (2):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,HIGH);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (3):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,HIGH);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (4):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,HIGH);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (5):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,HIGH);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (6):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,HIGH);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (7):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,HIGH);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (8):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,HIGH);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (9):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,HIGH);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (10):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,HIGH);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (11):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

   case (12):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

   case (13):
    shifter.setPin(es,HIGH);shifter.setPin(la,HIGH);shifter.setPin(son,LOW);shifter.setPin(las,LOW);

    
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,HIGH);
    shifter.write();
    break;

  case (14):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,HIGH);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (15):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,HIGH);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (16):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,HIGH);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (17):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,HIGH);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (18):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,HIGH);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (19):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,HIGH);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (20):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,HIGH);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (21):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,HIGH);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (22):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,HIGH);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

  case (23):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,LOW); shifter.setPin (once,HIGH);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;

   case (24):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;
    }
  }

  while(m==2){
    if(digitalRead(UP)==LOW)
    {
      cormin=cormin+1;
      delay(200);
    }
    if(digitalRead(DOWN)==LOW)
    {
      cormin=cormin-1;
      delay(200);
    }
    if(digitalRead(4)==LOW)
    {
      EEPROM.write(address2,cormin);
      m=0;
      delay(200);
    }

     DateTime now = RTC.now();
     int minu = now.minute();
     minu= minu+cormin;
     
     int decena = minu/10;                // ESTOS LOS USO PARA PRENDER LOS LEDS INDEPENDIENTES DE 
     int unidad = minu - (decena*10);     //               LOS   MINUTOS 1 2 3 Y 4
   
      shifter.setAll(LOW);
      shifter.write();

     Serial.println("m=2");
     Serial.println(cormin);
     
      if (minu>=0 and minu<5)
        {opcion=1;}
      if (minu>=5 and minu<10)
        {opcion=2;}
      if (minu>=10 and minu<15)
        {opcion=3;}
      if (minu>=15 and minu<20)
        {opcion=4;}
      if (minu>=20 and minu<25)
        {opcion=5;}
      if (minu>=25 and minu<30)
        {opcion=6;}
      if (minu>=30 and minu<35)
        {opcion=7;}
      if (minu>=35 and minu<40)
        {opcion=8;}
      if (minu>=40 and minu<45)
        {opcion=9;}
      if (minu>=45 and minu<50)
        {opcion=10;}
      if (minu>=50 and minu<55)
        {opcion=11;}
      if (minu>=55 and minu<60)
        {opcion=12;}

switch (opcion){

    case 1:
    shifter.setPin(menos,LOW);shifter.setPin(en,HIGH);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,HIGH);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 2:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,HIGH);
    break;

    case 3: 
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,HIGH);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 4: 
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,HIGH);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 5:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,HIGH);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 6:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,HIGH);shifter.setPin(mcinco,HIGH);
    break;

    case 7:
    shifter.setPin(menos,LOW);shifter.setPin(en,LOW);shifter.setPin(y,HIGH);shifter.setPin(media,HIGH);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 8:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,HIGH);shifter.setPin(mcinco,HIGH);
    break;

    case 9:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,HIGH);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 10:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,HIGH);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 11:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,HIGH);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,LOW);
    break;

    case 12:
    shifter.setPin(menos,HIGH);shifter.setPin(en,LOW);shifter.setPin(y,LOW);shifter.setPin(media,LOW);shifter.setPin(mdiez,LOW);shifter.setPin(veinte,LOW);shifter.setPin(cuarto,LOW);
    shifter.setPin(punto,LOW);shifter.setPin(veinti,LOW);shifter.setPin(mcinco,HIGH);
    break;
   }

       switch(unidad){
  
  case 0:
      shifter.setPin(26,LOW);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 1:
      shifter.setPin(26,HIGH);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 2:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;    
  case 3:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,LOW);
      break;
  case 4:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,HIGH);
      break;
  case 5:
      shifter.setPin(26,LOW);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 6:
      shifter.setPin(26,HIGH);shifter.setPin(27,LOW);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;
  case 7:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,LOW);shifter.setPin(29,LOW);
      break;   
  case 8:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,LOW);
      break;
  case 9:
      shifter.setPin(26,HIGH);shifter.setPin(27,HIGH);shifter.setPin(28,HIGH);shifter.setPin(29,HIGH);
      break;   
   }
       
  shifter.write();

  }

}
