<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=gradient&customColorList=1,2,30&height=150&section=header&text=Cub3D&fontSize=80&fontColor=ffffff&animation=fadeIn&fontAlignY=45&desc=A%20RayCasting%20Engine%20Inspired%20by%20Wolfenstein%203D&descAlignY=75&descAlign=50&descSize=20&stroke=ffffff&strokeWidth=2"/>
  
  <br />
  
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Math-Raycasting-blueviolet?style=for-the-badge" />
  <img src="https://img.shields.io/badge/School-1337-000000?style=for-the-badge&logo=42&logoColor=white" />
</div>

---

## 🕹️ About The Project

**Cub3D** is a 3D game engine built from scratch in **C**, using the **Raycasting** rendering technique. This project mimics the graphical engine of the legendary *Wolfenstein 3D* (1992), translating a 2D map layout into a navigable 3D world.

Unlike modern engines (Unity/Unreal), this project requires manual pixel manipulation. Every frame is calculated using trigonometry to detect wall collisions and render vertical strips of pixels, creating the illusion of depth.

---

## ✨ Key Features

- **Raycasting Engine:** Real-time projection of a 2D grid into a 3D perspective.
- **Texture Mapping:** Renders different textures for North, South, East, and West walls.
- **Color Parsing:** Supports custom floor and ceiling colors (RGB).
- **Collision Detection:** Smooth movement system that prevents walking through walls.
- **Map Parsing:** Reads `.cub` files to dynamically generate worlds.
- **Memory Management:** Zero memory leaks (Validated with Valgrind).

---

## 📐 The Math Behind It

The engine uses **DDA (Digital Differential Analysis)** to cast rays from the player's position.

1.  **Ray Casting:** For every vertical column on the screen, a ray is fired.
2.  **Wall Hit:** The algorithm calculates the distance to the nearest wall.
3.  **Fisheye Correction:** Corrects the distortion caused by viewing angles.
4.  **Drawing:** Calculates the height of the wall strip based on distance and draws it.

```math
PerpendicularDistance = (SideDist - DeltaDist);
LineHeight = (ScreenHeight / PerpendicularDistance);
```

🛠️ Installation & Usage
Prerequisites
GCC Compiler

Make

X11 / MiniLibX libraries (Linux/macOS)

Building the Engine
```bash
git clone https://github.com/70rn4d0/42-common-core.git
cd Cub3d_game
make
```
Running the Game
Provide a map file (with .cub extension) as an argument:
```bash
./CUB3D map.cub
```
Controls
```lua
Key,Action
W A S D,Move Player
← →,Rotate Camera
ESC,Quit Game
```
🗺️ Map Configuration (.cub)
The engine parses configuration files with specific rules:
```Plaintext
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
101001
111111
```
