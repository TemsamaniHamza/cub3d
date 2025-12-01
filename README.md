about formatting issues:

# Cub3D

Cub3D is a 3D graphics project from the 42 curriculum that shows how to render a 3D environment from a 2D map using **raycasting**.  
It is built in **C** with **MiniLibX**, giving a Wolfenstein 3D-style first-person view.

## Features
- 3D world rendering using raycasting
- Player movement: forward, backward, strafe left/right
- Player rotation: look left and right
- Simple wall textures
- Map parsing from `.cub` files
- Collision detection to prevent walking through walls
- MiniLibX for window and rendering management

## Installation
1. Clone the repo:


git clone <your-repo-url>
cd cub3d

2. Compile:


make

> MiniLibX must be installed and linked properly.

## Usage
Run with a `.cub` map file:


./cub3d maps/map.cub


Controls:
- W: move forward
- S: move backward
- A: strafe left
- D: strafe right
- Left arrow: rotate left
- Right arrow: rotate right
- ESC: exit

## Technologies
- C
- MiniLibX
- Raycasting
