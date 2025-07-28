# 🖨️ ft_printf

![Score Badge](https://img.shields.io/badge/Score-100%2F100-brightgreen)

## Overview

**ft_printf** is a custom implementation of the standard C library function `printf`, created as part of the 42 Common Core curriculum. This project challenges students to reproduce the formatted output capabilities of `printf` from scratch, supporting a subset of the original conversion specifiers, flags, and behaviors. The goal is to deepen understanding of variadic functions, string formatting, and meticulous memory management in C.

Through this project, you'll gain hands-on experience with:

- Working with variadic arguments using `stdarg.h`
- Parsing format strings and handling various conversion specifiers
- Managing output buffers and ensuring correct formatting
- Strict adherence to 42 coding standards


## Skills Gained

- Advanced C programming: variadic functions, string parsing
- Memory and buffer management
- Robust handling of edge cases
- Developing modular, testable code
- Creating a Makefile for easy compilation and usage


## Supported Conversions

| Specifier | Description |
| :-- | :-- |
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a number in hexadecimal (lowercase) |
| `%X` | Prints a number in hexadecimal (uppercase) |
| `%%` | Prints a literal percent sign |

## Usage

1. **Clone the repository** and navigate to the `ft_printf` directory.
2. **Build the library**:

```
make
```

3. **Include `ft_printf.h`** in your C source files.
4. **Link the compiled object file when compiling your projects**:

```
gcc -Wall -Wextra -Werror yourfile.c ft_printf.c
```


## Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Int: %d, Hex: %x\\n", "world", 42, 42);
    return 0;
}
```

**Sample Output:**

```
Hello world! Int: 42, Hex: 2a
```


## Project Structure

| File | Description |
| :-- | :-- |
| `ft_printf.c` | Main implementation of `ft_printf` |
| `ft_printf.h` | Header file with prototypes and macros |
| `utils.c` | Helper functions for conversions and output |
| `Makefile` | Builds the project |

*Add or modify files according to your repo structure.*

## Testing

Test cases should include all supported conversions, edge cases (NULL, 0, very large values), and combinations of different format specifiers.

## 42 Project Requirements

- No use of standard `printf` or other output functions except `write`
- Code must follow 42 style and compile with `-Wall -Wextra -Werror`
- Only the allowed functions: `write`, `malloc`, `free`, and `va_*` functions
