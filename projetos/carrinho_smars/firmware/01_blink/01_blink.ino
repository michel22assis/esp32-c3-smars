/*
 * Carrinho SMARS — Fase 1
 * ESP32-C3 Super Mini: LED embarcado (GPIO8, active-low) + Serial USB
 *
 * Placa: ESP32C3 Dev Module
 * Ferramentas > USB CDC On Boot > Enabled
 */

const int LED_PLACA = 8;  // active-low na Super Mini

void setup() {
  Serial.begin(115200);
  pinMode(LED_PLACA, OUTPUT);
  digitalWrite(LED_PLACA, HIGH);  // apagado
  delay(500);
  Serial.println("SMARS + ESP32-C3 Super Mini — fase 1 OK");
}

void loop() {
  digitalWrite(LED_PLACA, LOW);   // acende
  Serial.println("LED ON");
  delay(400);
  digitalWrite(LED_PLACA, HIGH);  // apaga
  Serial.println("LED OFF");
  delay(400);
}
