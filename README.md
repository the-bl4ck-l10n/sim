# sim

`sim` is a two-dimensional simulation with a randomly generated world.

`sim` aims to be complex programmatically and logically while having a minimal UI in the terminal that features ASCII representations of the different objects and entities that populate the simulated world.

## Features

- Random world generation
- ASCII interface

## Installation

For the installation, you will need the following:
- A C compiler (e.g. `gcc`, `clang`)
- `make`

1. Clone the repo and move into it:
    ```sh
    $ git clone https://github.com/the-bl4ck-l10n/sim 
    $ cd sim
    ```
2. Compile:
    ```sh
    $ make
    ```
3. Profit.

If you are using `clang` or something else as your preferred compiler, change the `CC` variable in the Makefile to refer to it before running `make`.
You may also have to configure the `LIBS` and `INCLUDES` variables to use the shell command to get the correct flags for your compiler on your system.

## Usage

After compilation, the binary can be found in the `bin` directory. If you want to access `sim` from anywhere in your command line, copy or move it to a directory that is in your `PATH`. Alternatively, you can add an alias to your shell startup script:

```zsh
# ~/.zshrc

alias sim='/absolute/path/to/the/binary'
```

You can then run `sim` from your command line like a normal command.

For more information about `sim` itself, see `MANUAL.md`.

## Author

the-bl4ck-l10n (creator and maintainer)
