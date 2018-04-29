                                                                                    
 #include <Shifter.h>;
 #include <Wire.h> 
 #include "RTClib.h" 

  DS1307 RTC; 

 int DATO1 = 0;
 int DATO2 = 1;
 int DATO3 = 2;
 int DATO4 = 3;
 int DATO5 = 4;
 int DATO6 = 5;
 int DATO7 = 6;
 int DATO8 = 7;
 int DATO9 = 8;
 int DATO10 = 9;
 int DATO11 = 10;
 int DATO12 = 11;
 int DATO13 = 12;
 int DATO14 = 13;
 int DATO15 = 14;
 int DATO16 = 15;
 int DATO17 = 16;
 int DATO18 = 17;
 int DATO19 = 18;
 int DATO20 = 19;
 int DATO21 = 20;
 int DATO22 = 21;
 int DATO23 = 22;
 int DATO24 = 23;
 int DATO25 = 24;
 int DATO26 = 25;
 int DATO27 = 26;
 int DATO28 = 27;
 int DATO29 = 28;
 int DATO30 = 29;
 int DATO31 = 30;
 int DATO32 = 31;
 
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

 #define SER_pin 11
 #define RCLK_pin 8
 #define SRCLK_pin 12
 #define NUM_REGISTERS 4 


 Shifter shifter(SER_pin,RCLK_pin,SRCLK_pin,NUM_REGISTERS);

void setup() {
    
    Wire.begin(); 
    RTC.begin(); 
    Serial.begin(9600);
   // RTC.adjust(DateTime(__DATE__, __TIME__));
//      if (!RTC.isrunning()) {
//   
//    Serial.println("RTC is NOT running!");// following line sets the RTC to the date & time this sketch was compiled
//   RTC.adjust(DateTime(__DATE__, __TIME__));
//   }
   
}

void loop() {
  
 DateTime now = RTC.now();

 int hora = now.hour();
 int minutos = now.minute();

 Serial.print(hora);
 Serial.print(":");
 Serial.println(minutos);
 
 int decena = now.minute()/10;                // ESTOS LOS USO PARA PRENDER LOS LEDS INDEPENDIENTES DE 
 int unidad = now.minute() - (decena*10);     //               LOS   MINUTOS 1 2 3 Y 4




 
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
  {
    opcion=1;
    }

  if (minutos>=5 and minutos<10)
  {
    opcion=2;
    }
  if (minutos>=10 and minutos<15)
  {
    opcion=3;
    }
 if (minutos>=15 and minutos<20)
  {
    opcion=4;
    }
 if (minutos>=20 and minutos<25)
  {
    opcion=5;
    }
 if (minutos>=25 and minutos<30)
  {
    opcion=6;
    }

 if (minutos>=30 and minutos<35)
  {
    opcion=7;
    }

  if (minutos>=35 and minutos<40)
  {
    opcion=8;
    hora=hora+1;
    }

  if (minutos>=40 and minutos<45)
  {
    opcion=9;
    hora=hora+1;
    }

  if (minutos>=45 and minutos<50)
  {
    opcion=10;
    hora=hora+1;
    }

  if (minutos>=50 and minutos<55)
  {
    opcion=11;
    hora=hora+1;
    }

  if (minutos>=55 and minutos<60)
  {
    opcion=12;
    hora=hora+1;
    }


 switch (hora){

  case (0):
    shifter.setPin(son,HIGH);shifter.setPin(las,HIGH);shifter.setPin(es,LOW);shifter.setPin(la,LOW);
  
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
    shifter.setPin (siete,LOW);shifter.setPin (seis,LOW);shifter.setPin (cinco,LOW);shifter.setPin (cuatro,LOW);shifter.setPin (tres,LOW);shifter.setPin (dos,LOW);shifter.setPin (una,LOW);
    shifter.write();
    break;
  
  case (1):
    shifter.setPin(es,HIGH);shifter.setPin(la,HIGH);shifter.setPin(son,LOW);shifter.setPin(las,LOW);

    
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
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

    
    shifter.setPin (doce,HIGH); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
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
  
    shifter.setPin (doce,LOW); shifter.setPin (once,LOW);shifter.setPin (diez,LOW);shifter.setPin (nueve,LOW);shifter.setPin (ocho,LOW);
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
