/*#include <Servo.h>
%Alejandro Rodríguez 19131
Jorge Lanza 19175
Juan Diego Villafuerte 19593
Brayan Castillo 19700
Código arduino uno comunicación con matlab y arduino nano
Servo pulgar;                   //creamos un objeto servo 
Servo indice;  
Servo enmedio; 
Servo anular;  */

/*int valPulgar = 0;              //valor que se escribira a los servos en grados
int valIndice = 0;
int valEnmedio = 0;
int valAnular = 0;*/
char data;

void setup() 
{ 
 /* pulgar.attach(3);             // asignamos el pin al servo.
  indice.attach(4);  
  enmedio.attach(2);  
  anular.attach(6);  */
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
             //iniciamos la comunicación serial
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  Serial.begin(9600);
} 

void loop() {
  if(Serial.available() >0){    //se revisa si existe un dato en el bus del serial
    data = Serial.read();
    //Serial.println(data);
    delay(500);
  }
  
  
  if(data == '1'){              //pinza 2 dedos
    digitalWrite(2,LOW);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(6,HIGH);
    /*valPulgar = 180;
    valIndice = 180;
    valEnmedio = 0;
    valAnular = 0;*/
  }
  else if(data == '2'){         //número 3
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);
    digitalWrite(6,LOW);
    /*valPulgar = 180;
    valIndice = 180;
    valEnmedio = 180;
    valAnular = 0;*/
  }
  else if(data == '3'){         //simbolo de paz
    digitalWrite(2,LOW);
    delay(500);
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);
    digitalWrite(6,LOW);
    /*valPulgar = 180;
    valIndice = 0;
    valEnmedio = 180;
    valAnular = 0;*/
  }
  else if(data == '4'){         //mano cerrada
    digitalWrite(2,LOW);
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
    digitalWrite(4,LOW);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);
    digitalWrite(6,LOW);
    /*valPulgar = 0;
    valIndice = 0;
    valEnmedio = 0;
    valAnular = 0;*/
  }
  else if(data == '5'){         //mano abierta
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(3,HIGH);
    delay(500);
    digitalWrite(4,HIGH);
    delay(500);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(6,HIGH);
    /*valPulgar = 180;
    valIndice = 180;
    valEnmedio = 180;
    valAnular = 180;*/
  }
  
  /*pulgar.write(valPulgar);      //se escribe al servo el valor al que se desea llegar
  delay(15);                    //se da un delay para que el servo pueda llegar a esa posición
  indice.write(valIndice);
  delay(15); 
  enmedio.write(valEnmedio);
  delay(15); 
  anular.write(valAnular);*/
  delay(50);                           
}
