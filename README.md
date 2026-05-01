# get_next_line

A **42 School** project that implements `get_next_line(int fd)`: a function that reads and returns the next line from a file descriptor, handling buffering between calls.

> Returns a dynamically allocated string containing the line (including the trailing `\n` when present), or `NULL` on end-of-file or error.

---

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
  - [Basic version](#basic-version)
  - [Bonus (multiple file descriptors)](#bonus-multiple-file-descriptors)
- [API](#api)
- [How it works (high-level)](#how-it-works-high-level)
- [Notes & Edge Cases](#notes--edge-cases)
- [Build flags](#build-flags)
- [Author](#author)

---

## Features

- Reads from any valid file descriptor (`fd`).
- Uses an internal **static buffer** to keep leftovers between calls.
- Supports configurable `BUFFER_SIZE` at compile time.
- **Bonus version** supports **multiple FDs** simultaneously (up to `FD_MAX`).

---

## Project Structure

- `get_next_line.c` — core implementation (single FD).
- `get_next_line_utils.c` — helper functions (`ft_strjoin`, buffer cleanup, etc.).
- `get_next_line.h` — header + prototypes.

Bonus:

- `get_next_line_bonus.c` — core implementation (multiple FDs).
- `get_next_line_utils_bonus.c` — helper functions for bonus.
- `get_next_line_bonus.h` — bonus header + `FD_MAX`.

---

## Requirements

- C compiler (`cc` recommended by 42)
- POSIX environment (uses `read`, `open`, etc.)

---

## Installation

Clone the repository:

```bash
git clone https://github.com/Danilo-Ferreira37/get_next_line.git
cd get_next_line
```

There is no Makefile in this repository, so compile manually (examples below).

---

## Usage

### Basic version

Create a small test file, e.g. `main.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (perror("open"), 1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

Compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line.c get_next_line_utils.c main.c -o gnl
```

Run:

```bash
./gnl
```

---

### Bonus (multiple file descriptors)

Example `main_bonus.c`:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
        return (perror("open"), 1);

    // alternating reads
    char *l1 = get_next_line(fd1);
    char *l2 = get_next_line(fd2);
    printf("%s", l1); free(l1);
    printf("%s", l2); free(l2);

    close(fd1);
    close(fd2);
    return (0);
}
```

Compile:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -o gnl_bonus
```

---

## API

### Mandatory

```c
char *get_next_line(int fd);
```

Header: `get_next_line.h`

### Bonus

Same API, but the implementation is able to manage multiple file descriptors at once.

Header: `get_next_line_bonus.h`

---

## How it works (high-level)

The function keeps a **static buffer** between calls:

1. If the buffer is empty, it calls `read(fd, buffer, BUFFER_SIZE)`.
2. It appends buffer content into a dynamically allocated string (`ft_strjoin`).
3. When a `\n` is found, it stops and returns the accumulated line.
4. The leftover after the newline stays in the buffer (via `clean_buffer`) for the next call.

Bonus version uses a 2D static buffer `buffer[FD_MAX][BUFFER_SIZE]`, one per file descriptor.

---

## Notes & Edge Cases

- `BUFFER_SIZE` must be **> 0** (function returns `NULL` otherwise).
- Return value is always **heap-allocated** when non-`NULL` → caller must `free()`. 
- On `read()` error (`-1`), the function frees internal allocations and returns `NULL`.
- If the file does not end with `\n`, the last call returns the final chunk without newline.

---

## Build flags

Recommended (42 style):

- `-Wall -Wextra -Werror`
- `-D BUFFER_SIZE=N`

Example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c main.c -o gnl
```

---

## Author

- GitHub: [Danilo-Ferreira37](https://github.com/Danilo-Ferreira37)