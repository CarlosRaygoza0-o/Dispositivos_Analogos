const int LED =3;  // indicando que el led se encuentra en el pin3
const int potenciometro =0; // el potenciometro esta conectado al pin A0
int intensidad;  //variable para la intensidad de brillo

void setup() {
Serial.begin(9600);
// No se necesitan declaran los pines analogicos
//ya que se realiza automáticamente
pinMode (LED, OUTPUT);  // declaramos el led como salida

}

void loop() {
//los valores analogicos se usan entre 0 y 255
//asi que el valor del potenciometro lo dividos en 4
intensidad = analogRead (potenciometro) / 4;
//analogWrite recibe los valores analogicos del pin
analogWrite(LED, intensidad);
//Muestra los valores en el monitor serial enviados por el potenciómetro
Serial.println(intensidad);
delay(1000);
}