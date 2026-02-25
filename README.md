# Gwendal-s-hackpad
My personnal Hackpad

<img src=assets/cad_without_rotary_encoders.png alt="cad" width="500"/>

## PCB
here is the schematic of my pcb :

<img src=assets/schematic.png alt="Schematic" width="300"/>

and here is the resulting layout, it needs to be pretty compact to fit in the 100mm*100mm requirements

<img src=assets/pcb.png alt="pcb" width="300"/>

The silkscreen was made on figma and imported as an SVG. (sources are [here](pcb/assets))

## BONUS
Since I had extra space and the kit comes with them, I figured I could include the rotary encoders inside a bonus version of my hackpad, while the main version keeps only 16 inputs to fit within the limit

<img src=assets/cad_with_rotary_encoders.png alt="cad bonus" width="300"/>

## BOM:
Here should be everything you need to make this hackpad

in the kit :
- 16x Cherry MX Switches
- 16x DSA Keycaps
- 2x M3x5x4 Heatset inserts
- 2X M3x12mm SHCS Bolts
- 16x 1N4148 DO-35 Diodes
- 1x 0.91" 128x32 OLED Display
- 1x XIAO RP2040
- 1x Case (3 printed parts)

to source yourself :
- 1x MCP23017 (I²C IO expander)
- 1x 100nF Capacitor (decoupling the MCP power)
- 8x 4.7k ohm resistors (pull up/pull down resistors for the matrix and the I²C circuit)

Optional :
- 2x EC11 Rotary Encoder
- 2x 1N4148 DO-35 Diodes
- 1x 8cm² cork sheet (for the bottom of the case)

## EXTRA STUFF :
I designed this project in 4 days of vacation, learnt to use kicad and pcb design in general
If firmware doesn't support 2 different I²C circuits, I added 0 ohm resistors (R9 and R10), that can be soldered shut to make a single I²C circuit, currently it uses 2 by default for speed and stability.
I designed the case to be 3d printable without supports (exept the cutout bit on the top cover, purely for aesthetic purposes, feel free to fill it in to avoid supports entirely)
I made some firmware that should support the matrix, but does not support the encoders nor the OLED screen yet, I am waiting until I have actually made the board to test it.