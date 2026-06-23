# fract-ol

A real-time fractal explorer written in C, rendered with the [MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library. Zoom into the infinite detail of the Mandelbrot and Julia sets, recolor them on the fly, and explore bonus fractals like the Burning Ship and the Dragon Curve.

This is a [42 School](https://42.fr) project built around complex-plane iteration, pixel buffers, and event-driven rendering.

> [!NOTE]
> `fract-ol` targets Linux and depends on X11. You will need the `libmlx`, `Xext`, and `X11` development libraries installed.

## Features

- **Mandelbrot set** — the classic escape-time fractal.
- **Julia sets** — fully parameterized; pass your own complex constant on the command line.
- **Mouse-wheel zoom** — zoom toward the cursor with smooth scaling, up to 35 levels deep.
- **Live recoloring** — switch the base color to red, green, or blue, or cycle through random palettes.
- **Adjustable precision** — raise or lower the iteration count to trade detail for speed.
- **Pannable view** — move around the complex plane with the arrow keys.
- **Bonus fractals** — Burning Ship and an L-system Dragon Curve.

## Requirements

- A Linux system with X11
- `cc` (or `gcc`) and `make`
- MiniLibX dependencies: `libmlx`, `libXext`, `libX11`, `libm`, `libz`

## Getting started

Clone the repository and build the mandatory program:

```sh
git clone <repository-url> fract-ol
cd fract-ol
make
```

To build the bonus program with the extra fractals:

```sh
make bonus
```

Other Makefile targets:

| Target     | Description                                  |
|------------|----------------------------------------------|
| `make`     | Build `fract-ol` (mandatory part)            |
| `make bonus` | Build `fract-ol-bonus`                     |
| `make clean` | Remove object files                        |
| `make fclean`| Remove object files and binaries           |
| `make re`    | Rebuild everything from scratch            |

## Usage

The fractal to render is selected by the first command-line argument.

```sh
# Mandelbrot set
./fract-ol Mandelbrot

# Julia set — pass the real and imaginary parts of the constant
./fract-ol Julia -0.8 0.156
```

Bonus fractals are available through the `fract-ol-bonus` binary:

```sh
# Burning Ship
./fract-ol-bonus BS

# Dragon Curve
./fract-ol-bonus Dragon
```

> [!TIP]
> Running the program with no arguments (or invalid ones) prints the full list of commands and controls.

## Controls

| Input              | Action                              |
|--------------------|-------------------------------------|
| Mouse wheel up     | Zoom in toward the cursor           |
| Mouse wheel down   | Zoom out                            |
| Arrow keys         | Pan the view                        |
| `s`                | Increase iteration precision        |
| `a`                | Decrease iteration precision        |
| `r`                | Set base color to red               |
| `g`                | Set base color to green             |
| `b`                | Set base color to blue              |
| `c`                | Cycle to a random color             |
| `Esc`              | Quit                                |

> [!NOTE]
> The Dragon Curve is a static render, so zoom, pan, and color controls do not apply to it.

## How it works

Each pixel on screen maps to a point on the complex plane. For that point, the program iterates the fractal's recurrence (for example, `z = z² + c` for the Mandelbrot set) until the value escapes a bounded region or the iteration limit is reached. The number of iterations before escape determines the pixel's color.

The rendering pipeline lives in a handful of focused source files:

| File                  | Responsibility                                          |
|-----------------------|---------------------------------------------------------|
| `main.c`              | Entry point, argument parsing, MLX setup                |
| `fractol.c`           | Fractal iteration formulas (Mandelbrot, Julia, …)       |
| `pixels.c`            | Plane-to-pixel mapping and pixel buffer writes          |
| `colors_bitshift.c`   | TRGB color packing, shading, and channel manipulation   |
| `hooks.c`             | Keyboard and mouse event handlers                       |
| `display_action.c`    | Applies actions (zoom, pan, recolor) to the view        |
| `dragoncrv.c`         | L-system generation of the Dragon Curve (bonus)         |
| `utils.c`             | Input validation, info display, cleanup                 |

Resolution defaults to 1920×1080 and can be overridden at compile time with the `WIDTH` and `HEIGHT` macros.

The project bundles a custom `libft` (a reimplementation of standard C library functions) used throughout the codebase.
