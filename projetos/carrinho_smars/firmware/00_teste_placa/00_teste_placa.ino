/*
 * Teste básico — ESP32-C3 Super Mini
 * ------------------------------------
 * Verifica: upload USB-C, Serial (CDC) e LED embarcado (GPIO8).
 *
 * Arduino IDE:
 *   Placa .............. ESP32C3 Dev Module
 *   USB CDC On Boot .... Enabled
 *   Porta .............. COMx da Super Mini
 *   Velocidade Serial .. 115200
 *
 * Se o upload falhar: segure BOOT, toque RST, solte BOOT, envie de novo.
 * Depois do upload: pressione RST se o sketch não iniciar.
 */

const int LED_PLACA = 8;   // azul na Super Mini (active-low: LOW = aceso)
const int INTERVALO_MS = 500;

void setup() {
  pinMode(LED_PLACA, OUTPUT);
  digitalWrite(LED_PLACA, HIGH);  // apagado

  Serial.begin(115200);
  delay(800);  // tempo para o monitor serial abrir

  Serial.println();
  Serial.println("========================================");
  Serial.println("  TESTE ESP32-C3 Super Mini — OK");
  Serial.println("========================================");
  Serial.printf("Chip model : %s\n", ESP.getChipModel());
  Serial.printf("Cores      : %d\n", ESP.getChipCores());
  Serial.printf("CPU MHz    : %u\n", ESP.getCpuFreqMHz());
  Serial.printf("Flash      : %u bytes\n", ESP.getFlashChipSize());
  Serial.printf("Heap livre : %u bytes\n", ESP.getFreeHeap());
  Serial.printf("LED GPIO   : %d (active-low)\n", LED_PLACA);
  Serial.println("----------------------------------------");
  Serial.println("Se o LED piscar e estas linhas aparecerem,");
  Serial.println("a placa está pronta para o carrinho SMARS.");
  Serial.println("========================================");
  Serial.println();
}

void loop() {
  digitalWrite(LED_PLACA, LOW);   // acende
  Serial.println("[LED] ON");
  delay(INTERVALO_MS);

  digitalWrite(LED_PLACA, HIGH);  // apaga
  Serial.println("[LED] OFF");
  delay(INTERVALO_MS);
}
