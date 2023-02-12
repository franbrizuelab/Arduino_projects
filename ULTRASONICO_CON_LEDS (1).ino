 int trigger = 10;           // declaramos la palabra trigger como un tipo entero y al mismo tiempo reemplaza al pin 9
 int echo = 11;           // declaramos la palabra echo como un tipo entero y al mismo tiempo reemplaza al pin 8
 float tiempo_de_espera,distancia; // creamos una variable de fotante; es decir, nos puede dar resultados en decimales.
 int valorverde;
 int valorrojo;
 int valoramarillo;
void setup() {
  Serial.begin (9600);   // establemos la comucicacion serial
  pinMode (trigger, OUTPUT); // declarmos el pin 9 como salida
  pinMode (echo, INPUT);   // declaramos el 8 como entrada
}

void loop() {
digitalWrite (trigger, HIGH);// ahora ponemos en alto pin 8 durante 10 microsegundos;
delayMicroseconds (1);     // pues este el momento en que emite el sonido durante 10 segungos
digitalWrite (trigger, LOW); // ahora ponemos en bajo pin 8 

tiempo_de_espera = pulseIn (echo,HIGH,4000); // pulseIn, recoge la señal del sonido que emite el trigger
/*La función pulseIn espera la aparición de un pulso en una entrada y mide su duración, dando como resultado la duración medida                   
 El primer parámetro (ECHO) es el pin sobre el que se realizará la medición.
Y el segundo parámetro (HIGH) indica si el pulso a esperar será un 1 (HIGH) o un 0 (LOW).
 */
distancia =(tiempo_de_espera/2)/29.15; // formula para hallar la distancia

Serial.print (distancia);    // imprimimos la distancia en cm
Serial.println ("cm");
delay (150);

valorverde = map(distancia, 33, 52, 0, 255);
valorrojo = map(distancia, 0, 20, 0, 255);
valoramarillo = map(distancia, 18, 37, 0, 255);

if (distancia>=0 && distancia <=20){  //
  analogWrite (9,valorrojo);
  }else{ analogWrite(9,0);  
    }
if (distancia>=18 && distancia <=37){
  analogWrite (6,valoramarillo);
  }else{ analogWrite(6,0);  
    }
    
if (distancia>=33 && distancia <=52){
  analogWrite (2,0);
  analogWrite (5,valorverde);
   }else{ analogWrite(5,0);  
    }
    
  }
