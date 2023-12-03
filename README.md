# sim

`sim` is a two-dimensional simulation with a randomly generated world.

`sim` aims to be complex programmatically and logically while having a minimal UI in the terminal that features ASCII representations of the different objects and entities that populate the simulated world.

## Features

- Random world generation
- ASCII interface

## Installation

For the installation, you will need the following:
- A C compiler (e.g. `gcc`, `clang`)
- `meson`

1. Clone the repo:
    ```sh
    $ git clone https://github.com/the-bl4ck-l10n/sim 
    ```
2. Setup `meson`:
    ```sh
    $ meson setup builddir
    ```
3. Compile:
    ```sh
    $ meson compile -C builddir
    ```
4. Profit.

## Usage

After compilation, the binary can be found in the builddir directory. If you want to access `sim` from anywhere in your command line, copy or move it to a directory that is in your `PATH`. Alternatively, you can add an alias to your shell startup script:

```zsh
# ~/.zshrc

alias sim='/absolute/path/to/the/binary'
```

For more information about `sim` itself, see `MANUAL.md`.

## Author

the-bl4ck-l10n (creator and maintainer)
