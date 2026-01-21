*This project has been created as part of the 42 curriculum by ahapetro.*

# cub3D
**My first RayCaster with miniLibX**

## Summary
This project is inspired by the world-famous Wolfenstein 3D game, considered the first FPS ever created. 
It allows you to explore ray-casting principles and create a dynamic first-person view inside a maze.

## Description
cub3D is a mini RayCaster project where the goal is to render a realistic 3D representation of a maze from a first-person perspective. 
Players can move through the maze using keyboard controls, and walls are rendered with textures according to their orientation (North, South, East, West). 
The project is implemented in C using miniLibX for graphics.

### Mandatory Features
- Raycasting-based 3D rendering.
- Player movement using `W`, `A`, `S`, `D` keys.
- Player rotation using left and right arrow keys.
- ESC key or clicking the window close button exits the game cleanly.
- Floor and ceiling color customization.
- Wall textures for all four directions.
- Proper map parsing and validation (map must be closed with walls).

### Bonus Features
- Wall collisions.
- Minimap system.
- Doors that open and close.
- Animated sprites.
- Mouse-based rotation of point of view.

## Instructions
1. Clone the repository.
2. Run `make` to compile the project.
3. Execute the game with `./cub3D <map_file>.cub`.
4. Controls:
   - `W`, `A`, `S`, `D`: move forward, left, backward, right.
   - Left/Right arrow keys: rotate view.
   - ESC: exit game.
5. The map file must follow the `.cub` format:
   - Allowed characters: `0` (empty), `1` (wall), `N/S/E/W` (player start orientation).
   - The map must be surrounded by walls.
   - Floor (F) and ceiling (C) colors must be in `R,G,B` format.
   - Textures: `NO`, `SO`, `WE`, `EA` followed by path.

### Example Minimal Map File
