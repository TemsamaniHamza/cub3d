<!-- Save this file as cub3d_readme.md -->

# Cub3D

Cub3D is a 3D graphics project from the 42 curriculum that shows how to render a 3D environment from a 2D map using **raycasting**. It is built in **C** with **MiniLibX**, giving a Wolfenstein 3D-style first-person view.

## Features

* 3D world rendering using raycasting
* Player movement: forward, backward, strafe left/right
* Player rotation: look left and right
* Simple wall textures
* Map parsing from `.cub` files
* Collision detection to prevent walking through walls
* MiniLibX for window and rendering management

## Installation

1. Clone the repo:

   ```bash
   git clone https://github.com/TemsamaniHamza/cub3d.git
   ```

2. Go into the repo:

   ```bash
   cd cub3d
   ```

3. Compile:

> Make sure MiniLibX is installed and linked properly.

```bash
make
```

## Usage

Run the program with a `.cub` map file:

```bash
./cub3d path/to/map.cub
```

**Controls:**

* W: move forward
* S: move backward
* A: strafe left
* D: strafe right
* Left arrow: rotate left
* Right arrow: rotate right
* ESC: exit

## Technologies

* C
* MiniLibX
* Raycasting
