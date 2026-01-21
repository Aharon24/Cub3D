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

```text
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
111111
100101
101001
1100N1
111111


## Resources
- Wolfenstein 3D official page: [http://users.atw.hu/wolf3d/](http://users.atw.hu/wolf3d/)
- miniLibX documentation: [https://harm-smits.github.io/42docs/libs/minilibx/](https://harm-smits.github.io/42docs/libs/minilibx/)
- Raycasting tutorials and articles.
- AI (ChatGPT) was used for planning map parsing, debugging memory leaks, and generating algorithm ideas.

## Notes
- The project is written according to the 42 Norm.
- All memory allocations are freed properly; no leaks or segfaults are allowed.
- For any misconfiguration in the `.cub` file, the program prints `Error` and exits.
- Screenshots and further examples can be added for demonstration.
