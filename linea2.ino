//Declaracion del control de los motores
const int controlM1 = 5;
const int controlM2 = 6;

//Declaracion de los sensores 
const int sensor0 = A0 ; 
const int sensor1 = A1 ; 
const int sensor2 = A2 ;
 

void setup(){
//Activa comunicación serial  
  Serial.begin(9600);   

}


void loop(){
  
//Se hace lectura de cada uno de los sensores y se imprimen en el monitor serial para calibrar los sensores
//Se descomentan los retardos para poder observar los valores que toman cada uno de los sensores en negro y blanco

//  Serial.print("Sensor 0 derecho : ");
  Serial.println(analogRead(sensor0));
  //delay(1000);
  //Serial.print("Sensor 1 central : ");
  Serial.println(analogRead(sensor1));
   //delay(1000);
  //Serial.print("Sensor 2 izquierdo : ");
  Serial.println(analogRead(sensor2));
   //delay(1000);

//Activa los dos motores si encuentra blanco en el sensor central 
if ((analogRead(sensor1) < 200)){ 
  
  analogWrite(controlM1,255);
  analogWrite (controlM2,255);
  
//Baja la velocidad de un motor para dar vuelta a la izquierda 
//si detecta blanco en el sensor derecho y negro en los otros dos sensores

} else if((analogRead (sensor0) < 500) && (analogRead(sensor1) > 500) && ((analogRead(sensor2)>500))){ 
  analogWrite(controlM1,255);
  analogWrite (controlM2,70);

//Baja la velocidad de un motor para dar vuelta a la derecha 
//si detecta blanco en el sensor izquierdo y negro en los otros dos sensores

}else if ((analogRead(sensor2) < 200) && (analogRead(sensor0)>200) && ((analogRead(sensor0) > 200))) {//Se detiene el motor para dar vuelta a la derecha

  analogWrite(controlM1,70);
  analogWrite (controlM2,255);
  
  }
}
