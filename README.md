<h1 align="center">cub3D</h1>

<p align="center">
  A C raycasting project with MiniLibX, `.cub` parsing, textured walls, and player movement.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 badge" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language badge" />
  <img src="https://img.shields.io/badge/Status-completed-brightgreen?style=for-the-badge" alt="Status badge" />
</p>

<p align="center">
  <strong>Raycasting • MiniLibX • Parsing • Textures • 42</strong>
</p>

---

## 📌 Overview

`cub3D` is a project developed as part of the 42 curriculum.

This repository contains a small 3D engine written in C. It parses a `.cub` configuration file, validates texture paths, floor and ceiling colors, map layout, and player spawn, then opens a MiniLibX window and renders a textured maze with a raycasting pipeline.

This project focuses on:
- parsing and validating `.cub` files
- handling player movement and camera rotation
- rendering textured walls with DDA raycasting
- freeing allocated resources correctly on exit

> Note: this README is based only on information that can be verified directly from this repository. The official subject PDF is not present here, so anything not visible in the codebase is intentionally left unclaimed.

---

## ✨ Features

- ✅ Parses `.cub` files with `NO`, `SO`, `WE`, `EA`, `F`, and `C` entries
- ✅ Validates texture extensions, file accessibility, and required configuration fields
- ✅ Validates map characters, closed walls, and single player spawn
- ✅ Renders textured walls with colored floor and ceiling
- ✅ Supports keyboard movement, rotation, `ESC`, and window-close exit handling
- ⚠️ The current project code uses keyboard controls only; no mouse-look is implemented

---

## 🧠 Concepts Covered

Through this project, I worked on the following concepts:

- event handling with MiniLibX
- structured parsing of configuration files
- RGB parsing and conversion
- DDA raycasting
- texture sampling per rendered column
- collision checks and cleanup of allocated resources

---

## 🛠️ Build

Clone the repository and compile the project:

```bash
git clone git@github.com:Middle-555/Cub3D.git
cd Cub3D/cub3d
make
```

Available Makefile rules:

```bash
make
make exe
make clean
make fclean
make re
```

Build notes:
- The project Makefile links the Linux MiniLibX with X11: `-lXext -lX11 -lm -lz`.
- A build was attempted in this environment on March 28, 2026, and stopped on `fatal error: 'X11/Xlib.h' file not found`.
- In practice, this means the project should be compiled on a Linux setup with the required X11 development headers installed.

---

## 🚀 Usage

Run the program with:

```bash
./cub3D <path/to/map.cub>
```

Examples:

```bash
./cub3D maps/map/basique.cub
./cub3D maps/map/evolved.cub
./cub3D maps/map/manquecouleur.cub
```

Usage notes:
- The code handles `W`, `A`, `S`, `D` for movement.
- `UP` and `DOWN` move forward and backward, while `LEFT` and `RIGHT` rotate the camera.
- `ESC` and the window close button both trigger cleanup and exit.

---

## 📂 Project Structure

```text
.
├── README.md
└── cub3d/
    ├── Makefile
    ├── include/
    │   ├── cub.h
    │   └── minilibx-linux/
    ├── main.c
    ├── maps/
    │   ├── map/
    │   └── textures/
    └── srcs/
        ├── gameplay/
        ├── minilibx/
        ├── parsing/
        ├── raycasting/
        └── utils/
```

Structure details:
- `cub3d/include/`: main project header and bundled MiniLibX headers
- `cub3d/srcs/`: main project source code
- `cub3d/srcs/gameplay/`: movement, rotation, exit hooks, and cleanup
- `cub3d/srcs/parsing/`: `.cub` parsing, validation, and game structure initialization
- `cub3d/srcs/raycasting/`: ray setup, DDA traversal, distance calculation, and textured column rendering
- `cub3d/srcs/utils/libft/`: local `libft` used by the project
- `cub3d/maps/`: sample valid and invalid maps plus XPM textures

---

## ⚙️ Project Constraints

This project follows the constraints that are visible in the repository itself:
- written in C
- structured as a 42 `cub3D` project
- uses MiniLibX and a local `libft`
- includes explicit cleanup paths for textures, images, map data, window, and display resources
- stays within the scope of parsing a map file and rendering a simple textured 3D scene

Additional note:
- I cannot confirm the exact official allowlist of authorized functions from the subject because that document is not present in this repository.

---

## 🧪 Testing

The repository currently supports the following testing approach:
- build the project with the provided `Makefile`
- run the executable with valid sample maps such as `basique.cub` and `evolved.cub`
- run the executable with invalid sample maps to verify parser rejection paths
- review parsing branches for missing textures, invalid colors, invalid map characters, and missing player spawn
- run memory checks with Valgrind on a Linux environment

Suggested manual test commands:

```bash
make
./cub3D maps/map/basique.cub
./cub3D maps/map/manquecouleur.cub
```

Memory checks:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/map/basique.cub
```

Testing notes:
- The repository includes several invalid maps in `cub3d/maps/map/`, such as missing colors, missing paths, invalid map structure, and missing player spawn cases.
- I could not confirm runtime behavior in this environment because compilation stopped on the missing `X11/Xlib.h` dependency.

---

## 📖 What I Learned

This project helped me improve in the following areas:
- structuring a medium-sized C project around clear modules
- building a parser that rejects invalid input early
- understanding camera vectors, FOV, and per-column raycasting
- thinking more carefully about cleanup and resource ownership

---

## 🚧 Possible Improvements

Although the current repository already covers the core scope, several improvements could be considered:
- add mouse-based camera rotation
- make the build more portable across Linux and macOS environments
- extend the engine with bonus features such as a minimap or HUD
- strengthen automated validation with a dedicated parser test script

---

## 👤 Author

Middle  
42 student

<p>
  <a href="https://github.com/Middle-555">GitHub</a>
</p>
