const int ledPin = 2;

// Parámetros PWM
const int freq = 5000;
const int resolution = 8;
const int channel = 0;  // Canal PWM (0-15 en ESP32)

void setup() {
  // Configura el canal PWM
  ledcSetup(channel, freq, resolution);

  // Asocia el pin al canal
  ledcAttachPin(ledPin, channel);
}

void loop() {
  // 128 = 50% de brillo (0-255)
  ledcWrite(channel, 128);
}