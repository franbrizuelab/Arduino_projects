/*creamos toda una serie de variables que nos van a servir para los valores que usaremos en el sketch.*/
int decena=0;
int unidad=0;
int centena=0;
int unidaddemil=0;
int retardo=5;
int conmutador=1;
int cont=0;
int var=0;

/*Abreviamos el comando ''HIGH'' a ''1'' para facilitar el codigo. Asignamos a cada parte del display su pin correspondiente*/
#define HIGH 1
int a=12;
int f=13;
int b=11;
int g=10;
int e=5;
int d=4;
int c=3;
int dp=2;

/*Establecemos los pines que usaremos como salida. No usamos el loop ''for'' para poder visualizar mas claramente a que pin corresponde cada segmento*/

void setup() {
   pinMode(13,OUTPUT); //f
   pinMode(12,OUTPUT); //a
   pinMode(11,OUTPUT); //b
   pinMode(10,OUTPUT); //g
   pinMode(9,OUTPUT);  //conmutador 4
   pinMode(8,OUTPUT); //CONMUTADOR 2
   pinMode(7,OUTPUT); //CONMUTADOR 1
   pinMode(6,OUTPUT); //CONMUTADOR 3
   pinMode(5,OUTPUT); //e
   pinMode(4,OUTPUT); //d
   pinMode(3,OUTPUT); //c
   pinMode(2,OUTPUT); //dp
}

void loop() {
/*  antes de hacer nada, esperamos 10 milisegundos (el valor de ''retardo'')*/
   delay(retardo);
 /*contador (cont), es una variable que inicializamos en cero, y que va a ir sumando 1 a su valor cada vez que se ejecute ''cont''. Nos servirá para definir que tan rapido queremos que los números avancen.*/
  cont++;

 /*Mientras el contador no haya alcanzado 50, todos los valores se mostrarán como cero, pues así los declaramos al comienzo. cada vez que el contador llegue a 50, se ejecutarán las instrucciones que harán que los númeors vayan ioncrementando su valor*/  
 if(cont==50){
 /*Cuando el contador llega a 50, se reinicia y vuelve a empezar*/
    cont=0;
 /*Se añade 1 a la unidad*/   
   unidad=unidad+1;
 /*Cuando la unidad es igual a 10, se le suma 1 a la decena. Es bastante intuitivo, cada vez que llegamos al 10, la unidad vuelve a cero y se le suma uno a la decena. Seguiremos este procedimiento para los demás valores*/  
   if(unidad>=10){
    decena=decena+1;
    unidad=0;
 /*Lo mismo pero con la decena. Cuando esta alcanza el valor de 10, vuelve a cero y se añade 1 al valor de la centena*/   
    if(decena>=10){
      centena=centena+1;
      decena=0;
 /*El mismom procedimiento, pero con la unidad de mil*/     
      if(centena>=10){
        unidaddemil=unidaddemil+1;
        centena=0;
        }
      }
    } 
  }  

/*Aquí haremos que se conmuten los displays. En ningún momento estarán todos encendidos al mismo tiempo, sin que se encenderán uno a uno, pero a una velocidad imperceptible para el ojo humano, dando la impresión de que todos los displayes están encendidos. Conmutador es una variable que comienza en 1, asi que se ejecutará lo que establecimos para el caso en qe sea 1. Es decir, encendemos sólo el display que indica las unidades.Igualamos ''var'' a ''unidad''. más adelante veremos para que se usa ''var''. Al final de las instrucciones, cambiamos el valor de la variable ''conmutador'', para que, en el siguiente ciclo, se encienda otro display.*/
switch (conmutador){
  case 1:
  digitalWrite(9,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  var=unidad;
  conmutador=2;
                break;
/*El valor de ''conmutador'' ahora es 2, por lo que se ejecutan estas instrucciones, ahora se enciende el display de las decenas, asi que indicamos qie ''var'' se iguale a ''decenas''. Cambiamos el valor de ''conmutador'' para que en el siguiente ciclo se encienda otro siplay*/ 
   case 2:
  digitalWrite(9,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  var=decena;
  conmutador=3;
                break;
 /*Ahora encendemos el display de las centenas y nuevamente cambiamos el valor de ''conmutador''*/
  case 3:
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  var=centena;
  conmutador=4;
                break;
 /*Por ultimo, encendemos el display de la unidad de mil y cambiamos el valor de ''conmutador'' a uno, para que vuelva a encender el display de las unidades en el procimo ciclo*/                
  case 4:
  digitalWrite(9,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  var=unidaddemil;
  conmutador=1;
                break;
                              
               
  }
/*Aquí indicaremos cuales son los segmentos que se dewben iluminar según el número que queramos representar. Cada segmento está conectado a un pin, así que debemos enviar una señal alta (''HIGH'' es reemplazado por ''1'') e indicamos así cuales segmentos deben encenderse para cada número*/
  switch (var){
    case 0:
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
    digitalWrite(dp,LOW);
                   break;
    case 1:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
                   break;
   case 2:
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
                   break;
    case 3:
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,1);
    digitalWrite(dp,LOW);
                   break;
    case 4:
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
                   break;
    case 5:
    digitalWrite(a,1);
    digitalWrite(b,LOW);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,LOW);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(dp,LOW);
                   break;
    case 6:
    digitalWrite(a,1);
    digitalWrite(b,LOW);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(dp,LOW);
                   break;                                  
    case 7:
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
                   break;
    case 8:
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(dp,LOW);
                   break;
    case 9:
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,LOW);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(dp,LOW);
                   break;
    default:
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,LOW);
    digitalWrite(f,1);
    digitalWrite(g,1);
    digitalWrite(dp,LOW);
                   break;               
                                                                   
    }
}
