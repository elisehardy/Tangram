# Tangram

Quentin Coumes et Hardy Elise


## Compilation

Compilation is done with [CMake](https://cmake.org/) (version 3.7 at least)

```bash
mkdir build
cd build
cmake ..
make
```

This will also build the documentation inside `build/doc/`.

## Utilisation

### Launching the game

The game is launch with the compiled executable `tangram`.

```
./tangram
```

### Controls

To move a piece, `left click` on it and drag it to the position you want. For precise movement
(pixel per pixel), hover the piece with your mouse, and use the keys `W`, `A`, `S` and `D` to move it in the
direction you want.

To rotate a piece, `right click` on it and drag the mouse to the left to rotate the piece
clockwise, and to the left to rotate it counter-clockwise. Once again, to rotate it
step by step, hover the piece with your mouse and use the keys `Q` and `E`.

You can use `ESC` to move back to the main menu in any submenu or game.

Given keys are for the `QWERTY` layout, it should automatically adapt to your layout.

