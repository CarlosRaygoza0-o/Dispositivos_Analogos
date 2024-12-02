// Definición de pines
const int pinFotorresistencia = A0; // Pin donde está conectada la fotorresistencia
const int pinLED = 3;              // Pin PWM donde está conectado el LED

void setup() {
  pinMode(pinLED, OUTPUT);         // Configura el pin del LED como salida
  Serial.begin(9600);              // Inicializa la comunicación serial para depuración
}

void loop() {
  // Leer el valor de la fotorresistencia
  int valorLuz = analogRead(pinFotorresistencia);

  // Convertir el valor de luz (0-1023) a rango PWM (0-255)
  int intensidadLED = map(valorLuz, 0, 1023, 0, 255);

  // Enviar el valor al LED
  analogWrite(pinLED, intensidadLED);

  // Mostrar los valores en el monitor serial
  Serial.print("Luz detectada: ");
  Serial.print(valorLuz);
  Serial.print(" -> Intensidad LED: ");
  Serial.println(intensidadLED);

  delay(100); // Pequeña pausa para estabilidad
}
