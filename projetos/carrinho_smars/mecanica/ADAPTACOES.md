# Adaptações mecânicas — SMARS → ESP32-C3 Super Mini

## Peças originais a baixar

Coloque os STLs oficiais em `mecanica/originais/` (download manual no Thingiverse):

- [thing:1582398](https://www.thingiverse.com/thing:1582398) — SMARS (Kevin Thomas)

Peças típicas: `chassis-SL` / `chassis-S`, `master-wheel`, `slave-wheel`, `mechanical-track`, `holding-board-9v`, mounts de ultrassom/IR.

## O que muda na sua versão (foto)

- Chassis já impresso (verde/rosa, marca **ROBO**) — reaproveitar.
- Rodas grandes com pneu (não necessariamente esteira SMARS clássica).
- Frente com HC-SR04 + 2 LEDs + abertura USB (hoje micro‑USB).

## Peças novas / remix sugeridas

Crie em CAD (Fusion / FreeCAD / OpenSCAD) e salve em `mecanica/adaptadas/`:

| Arquivo sugerido | Função |
|------------------|--------|
| `holder_esp32_c3_supermini.stl` | Encaixe da Super Mini (~24×18×4 mm + USB‑C) |
| `face_usb_c.stl` | Recorte frontal/lateral para USB‑C (substitui micro‑USB) |
| `holder_drv8833.stl` | Fixação do driver de motor |
| `spacer_battery.stl` | Se trocar 9 V por pack 2S/18650 + BMS |

## Medidas úteis (Super Mini)

- Placa: ~**24 × 18 × 4 mm**
- USB‑C: centrado numa das bordas curtas
- Headers: 2×8 pinos (soldar ou usar base expansora)

## Impressão

- PLA/PETG para chassis e holders
- TPU só se for esteira flexível (opcional)
- Sem suporte na maioria das peças SMARS originais

## Ordem prática

1. Fotografar/medir o vão atual do MCU.
2. Modelar holder da Super Mini (tolerância ~0,2–0,3 mm).
3. Abrir passagem USB‑C alinhada ao conector.
4. Só então desmontar o MCU antigo e migrar a fiação.
