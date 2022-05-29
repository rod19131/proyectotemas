#include <VarSpeedServo.h> 

VarSpeedServo pulgar;  //creamos un objeto servo 
VarSpeedServo indice;  //creamos un objeto servo 
VarSpeedServo enmedio;  //creamos un objeto servo 
VarSpeedServo anular;  //creamos un objeto servo 
VarSpeedServo menique; //creamos un objeto servo  

#define buttonPin1 A3    // the number of the pushbutton pin
#define buttonPin2 A2    // the number of the pushbutton pin
#define buttonPin3 A1    // the number of the pushbutton pin
#define buttonPin4 A0    // the number of the pushbutton pin
#define buttonPin5 A5    // the number of the pushbutton pin

int old_button1 = 0;
int old_button2 = 0;
int old_button3 = 0;
int old_button4 = 0;
int old_button5 = 0;

int valPulgar = 90;
int valIndice = 90;
int valMedio = 90;
int valAnular = 90;
int valMenique = 90;


void setup() 
{ 
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);

  pulgar.attach(10);  // asignamos el pin al servo.
  indice.attach(9);
  enmedio.attach(6);
  anular.attach(5);
  menique.attach(11);

} 

void loop() {
  if (digitalRead(buttonPin1) == LOW){
    old_button1 = 1;

    
  }

  if (digitalRead(buttonPin2) == LOW){
    old_button2 = 1;

    
  }

  if (digitalRead(buttonPin3) == LOW){
    old_button3 = 1;

    
  }

  if (digitalRead(buttonPin4) == LOW){
    old_button4 = 1;

    
  }
  
  if (digitalRead(buttonPin5) == LOW){
    old_button5 = 1;

    
  }

    
  if(digitalRead(buttonPin1) == HIGH && old_button1 == 1){
    valPulgar = 90;
    indice.write(valIndice,30);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,60);
    anular.write(valAnular,30);
    menique.write(valMenique,30);
    //delay(15); 
    
    
  }

  if(digitalRead(buttonPin2) == HIGH && old_button2 == 1){
    valIndice = 90;
    indice.write(valIndice,60);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,30);
    menique.write(valMenique,30);

    //delay(15);
    
    
  }

  if(digitalRead(buttonPin3) == HIGH && old_button3 == 1){
    valMedio = 90;
    indice.write(valIndice,30);
    enmedio.write(valMedio,60);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,30);
    menique.write(valMenique,30);
    //delay(15);
    
  }

  if(digitalRead(buttonPin4) == HIGH && old_button4 == 1){
    valAnular = 90;
    indice.write(valIndice,30);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,60);
    menique.write(valMenique,30);
    
  }


  if(digitalRead(buttonPin5) == HIGH && old_button5 == 1){
    valMenique = 90;
    indice.write(valIndice,30);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,30);
    menique.write(valMenique,6033);
    
  }
  
  if(digitalRead(buttonPin1) == LOW && old_button1 == 1){
    valPulgar = 180;  
    indice.write(valIndice,30);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,90);
    anular.write(valAnular,30);
    menique.write(valMenique,30);
      
  }

  if(digitalRead(buttonPin2) == LOW && old_button2 == 1){
    valIndice = 180; 
    indice.write(valIndice,90);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,30);
    menique.write(valMenique,30);
      
  }

  if(digitalRead(buttonPin3) == LOW && old_button3 == 1){
    valMedio = 0;  
    indice.write(valIndice,30);
    enmedio.write(valMedio,120);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,30);
    menique.write(valMenique,30);
      
  }

  if(digitalRead(buttonPin4) == LOW && old_button4 == 1){
    valAnular = 0;  
    indice.write(valIndice,30);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,90);
    menique.write(valMenique,30);
      
  } 

  if(digitalRead(buttonPin5) == LOW && old_button5 == 1){
    valMenique = 180;  
    indice.write(valIndice,30);
    enmedio.write(valMedio,30);
    pulgar.write(valPulgar,30);
    anular.write(valAnular,30);
    menique.write(valMenique,50);
      
  }  
   
  
}
