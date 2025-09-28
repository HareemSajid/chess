# Chess Game (C++ & SFML)

A basic chess game built in **C++** using **SFML** (Simple and Fast Multimedia Library).

* Provides an 8×8 chessboard with alternating light and dark squares.
* Full initial setup of pieces for both players.
* Mouse-driven piece selection and movement.
* Turn-based play: White and Black alternate turns.
* Basic move validation for: Pawn, Rook, Knight, Bishop, Queen, King.
* King capture detection ends the game and announces the winner.
* Start (cover) screen and end screen.
* Demonstrates OOP: inheritance, polymorphism, aggregation, and association.

## Features

* *8x8 board with alternating light/dark squares*
* *Initial piece setup for both sides*
* *Mouse-based piece selection and move*
* *Turn-based gameplay*
* *Basic move validation per piece*
* *King-capture detection for game end*
* *Start screen and winner announcement*
* *Polymorphism via virtual `isValidMove` in `Piece` class*
* *Aggregation of textures (optionally) in `Chess` class*

## Prerequisites

* *C++17 or later compiler* (g++, clang, MSVC)
* *SFML 2.5+* installed and configured (Graphics, Window, System)

## Build & Run (Linux / macOS example)

---

-> How to Build and Run

1. Ensure SFML is installed and linked correctly.  

---
Author
Hareem Sajid
1. Install SFML (platform-specific).
2. From project root:
```bash
mkdir build
cd build
cmake ..
make
./ChessSFML
