# Firmware — Carrinho SMARS (ESP32-C3 Super Mini)

## Ambiente

- Arduino IDE + pacote `esp32` (Espressif)
- Placa: **ESP32C3 Dev Module**
- **USB CDC On Boot: Enabled**
- Ver setup em `../../README.md`

Alternativa futura: PlatformIO / ESP-IDF.

## Pastas de sketches

| Pasta | Fase |
|-------|------|
| **`00_teste_placa/`** | **Comece aqui** — Serial + LED + info do chip |
| `01_blink/` | Blink simples (GPIO8) |
| `02_sensores/` | LEDs frontais + HC-SR04 *(próximo)* |
| `03_motores/` | Driver + diferencial |
| `04_ir_remoto/` | Decodificar Xinda |
| `05_autonomo/` | Evitar obstáculo |

### Como rodar `00_teste_placa`

1. Conecte a Super Mini com cabo USB‑C **com dados**.
2. Abra `00_teste_placa/00_teste_placa.ino` na Arduino IDE.
3. Placa: **ESP32C3 Dev Module** · **USB CDC On Boot: Enabled**.
4. Selecione a porta COM → Upload.
5. Abra o **Monitor Serial** a **115200**.
6. Sucesso = LED azul piscando + texto `TESTE ESP32-C3 Super Mini — OK`.

## Bibliotecas previstas

- HC-SR04: leitura por `pulseIn` ou lib `Ultrasonic`
- IR: `IRremote` / `IRremoteESP8266` (validar no C3)
- Motores: `ledcWrite` (PWM nativo ESP32)

## Convenção

Constantes de pino centralizadas no topo de cada `.ino`, alinhadas a `../eletrica/PINOUT.md`.
