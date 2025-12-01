# cub3dCub3D

Cub3D is a 3D graphics project from the 42 curriculum that demonstrates the basics of raycasting to render a 3D environment from a 2D map. The project is built using C and the MiniLibX library, allowing you to explore a Wolfenstein 3D-style first-person view with player movement and simple textures.

Features

Raycasting engine to render a 3D world from a 2D map.

Player movement: forward, backward, strafe left/right.

Player rotation: look left and right.

Simple wall textures for visual enhancement.

Map parsing from .cub files.

Collision detection to prevent walking through walls.

MiniLibX integration for window management and rendering.

Installation

Clone the repository:

git clone <your-repo-url>
cd cub3d


Compile the project using the provided Makefile:

make


Make sure you have MiniLibX installed and linked correctly on your system.

Usage

Run the program with a valid map file (.cub):

./cub3d maps/map.cub


Controls:

Action	Key
Move forward	W
Move backward	S
Strafe left	A
Strafe right	D
Rotate left	Left arrow
Rotate right	Right arrow
Exit	ESC
Project Structure
cub3d/
├── includes/     # Header files
├── srcs/         # Source code
├── maps/         # Sample .cub maps
├── textures/     # Wall textures
├── Makefile
└── README.md

Example


A basic rendering of a 3D map using raycasting.

Technologies Used

C programming language

MiniLibX graphics library

Raycasting technique for 3D rendering

Challenges

Implementing raycasting logic correctly for walls and player vision.

Handling map parsing and errors from .cub files.

Managing player movement and collision detection in a 3D environment.
