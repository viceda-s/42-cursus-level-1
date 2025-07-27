<h1 align="center">
  get_next_line
</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success">
  <img src="https://img.shields.io/badge/Language-C-informational">
</p>

---

## 🧠 Overview

The goal of this project is to create a function, `get_next_line`, which reads a line from a file descriptor one line at a time, efficiently and correctly. Each call to the function returns the next line from the file, including the newline character (`\n`), if present.

This is a common coding exercise to develop a better understanding of file I/O, memory management, and static variables in C.

---

## 📁 Files

- `get_next_line.c` – Contains the main logic of the function.
- `get_next_line_utils.c` – Helper functions used by `get_next_line`.
- `get_next_line.h` – Header file containing the function prototypes and necessary includes.

---

## 🗞️ Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters:

- `fd` – The file descriptor to read from.

### Return value:

- Returns a line read from a file descriptor, including the terminating newline (`\n`) if there is one.
- Returns `NULL` if there is nothing more to read or an error occurs.

---

## 🛠️ How It Works

- Reads from the given file descriptor using a buffer of size `BUFFER_SIZE`.
- Handles leftover data from previous reads using a static variable.
- Efficiently manages memory to concatenate, extract, and return lines.
- Supports multiple file descriptors simultaneously.

---

## 📦 Compilation

To compile and test the function, use:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can change the `BUFFER_SIZE` to test different buffer sizes.

---

## 📌 Notes

- You must not leak memory.
- `read()` must be called only when necessary.
- Your function must work with any positive `BUFFER_SIZE`, including 1.
- The function must handle multiple file descriptors (bonus).

---

## 💡 Bonus (if enabled)

If you complete the bonus part, your `get_next_line` implementation must be able to handle **multiple file descriptors** simultaneously without losing their respective buffers.

---

## 📚 Example

```c
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 🧪 Testing

You can test with:

```bash
./gnl
```

Or use a testing tool such as:

- [gnlTester](https://github.com/Tripouille/gnlTester)
- [42TESTERS/get\_next\_line](https://github.com/42TESTERS/get_next_line)

---

Happy coding!

