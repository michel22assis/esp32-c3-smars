# Pinout proposto — Carrinho SMARS + ESP32-C3 Super Mini

Proposta inicial (ajustável). Evita strapping **GPIO2 / GPIO8 / GPIO9** em sinais críticos de boot.

## Alimentação

```
Bateria (ex.: 7,4 V 2S ou 6 V) ──┬── Driver motores (VMOT)
                                 │
                                 └── Regulador 5 V / buck ──┬── VCC HC-SR04 (se 5 V)
                                                            ├── pino 5V da Super Mini (OU USB, nunca os dois)
                                                            └── (opcional) receptor IR

Super Mini 3V3 ── só sensores 3,3 V de baixa corrente / pull-ups
GND comum entre bateria, driver, sensores e ESP32
```

## Mapa de GPIOs (rascunho)

| Função | GPIO | Notas |
|--------|------|-------|
| LED frontal verde | **GPIO0** | PWM opcional |
| LED frontal azul | **GPIO1** | PWM opcional |
| HC-SR04 TRIG | **GPIO3** | Saída 3,3 V OK |
| HC-SR04 ECHO | **GPIO4** | Se módulo 5 V → **divisor** para 3,3 V |
| IR receptor (VS1838 etc.) | **GPIO10** | Entrada digital |
| Motor Esq. IN1 | **GPIO5** | Para DRV8833 / TB6612 |
| Motor Esq. IN2 / PWM | **GPIO6** | Conforme driver |
| Motor Dir. IN1 | **GPIO7** | |
| Motor Dir. IN2 / PWM | **GPIO20** | |
| LED placa (debug) | **GPIO8** | Embarcado; active-low; strapping |
| BOOT | **GPIO9** | Só botão da placa |
| UART / debug | GPIO21 TX / GPIO20 RX | Se liberar 20, use outro pino p/ motor |

> Se precisar de 2 PWM + 2 DIR por motor com DRV8833, reorganize: ex. `PWM_A=GPIO5`, `AIN1=GPIO6`, `AIN2=GPIO7`, `PWM_B=GPIO10`, etc., e mude o IR para GPIO1.

## Drivers sugeridos

| Driver | Por quê |
|--------|---------|
| **DRV8833** | Compacto, 3,3 V logic OK, bom para N20 / mini DC |
| TB6612FNG | Mais corrente, também 3,3 V friendly |
| L298N | Comum, mas grande e ineficiente; OK para protótipo |

## HC-SR04 em 3,3 V

- VCC do módulo costuma ser **5 V**.
- **TRIG** aceita 3,3 V.
- **ECHO** em 5 V: use divisor (ex. 2k2 + 3k3) para o GPIO do ESP32.

## Diagrama lógico (texto)

```
                    ┌─────────────────────┐
   USB-C / 5V ─────►│  ESP32-C3 SuperMini │
   GND ────────────►│                     │── GPIO0/1 ──► LEDs
                    │                     │── GPIO3/4 ──► HC-SR04
                    │                     │── GPIO10 ───► IR RX
                    │                     │── GPIO5..7,20 ► Driver
                    └──────────┬──────────┘
                               │ GND comum
                    ┌──────────┴──────────┐
   Bateria ────────►│  Driver motores     │──► Motor L / Motor R
                    └─────────────────────┘
```
