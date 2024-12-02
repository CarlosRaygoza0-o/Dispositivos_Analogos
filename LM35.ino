// Declaración de pines
const int pinLM35 = A0;  // Pin analógico A0 para el LM35
const int pinLED = 3;   // Pin digital 13 para el LED
int potenciaLED;

float temperatura;       // Variable para almacenar la temperatura
const float umbral = 30; // Umbral de temperatura en °C

void setup() {
  pinMode(pinLED, OUTPUT); // Configurar el pin del LED como salida
  Serial.begin(9600);      // Inicializar la comunicación serie
}

void loop() {
  int lectura = analogRead(pinLM35); // Leer el valor analógico del LM35
  potenciaLED = analogRead(pinLM35) / 4;
  // Convertir la lectura a temperatura en grados Celsius
  temperatura = (lectura * 5.0 / 1023.0) * 100; 
  
  // Mostrar la temperatura en el monitor serie
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  // 
  analogWrite(pinLED, potenciaLED);
  
  delay(1000); // Esperar 1 segundo antes de leer nuevamente
}
