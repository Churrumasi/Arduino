const int ledPin = 2;

// Parámetros PWM
const int freq = 5000;
const int resolution = 8;
const int channel = 0;  // Canal PWM

void setup() {

  Serial.begin(115200);

  // Configurar canal PWM
  ledcSetup(channel, freq, resolution);

  // Asociar pin al canal
  ledcAttachPin(ledPin, channel);

  Serial.println("Ingresa un valor de brillo entre 0 y 255:");
}

void loop() {

  if (Serial.available()) {

    String input = Serial.readStringUntil('\n');
    input.trim();

    int brillo = input.toInt();

    if (brillo >= 0 && brillo <= 255) {

      // Usar el CHANNEL, no el pin
      ledcWrite(channel, brillo);

      Serial.print("Brillo ajustado a: ");
      Serial.println(brillo);
    } 
    else {
      Serial.println("Valor invalido. Usa un numero entre 0 y 255.");
    }
  }
}