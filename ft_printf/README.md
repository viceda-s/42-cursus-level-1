# ft_printf

*This project has been created as part of the 42 curriculum by viceda-s.*

## Description

**ft_printf** is a recreation of the C standard library function `printf`. The goal of this project is to understand and implement variadic functions, format string parsing, and output formatting with various flags and modifiers. This implementation converts a format string with variable arguments into formatted output and writes it to the standard output (stdout).

The project demonstrates proficiency in:
- Variadic function implementation using `stdarg.h` (va_list, va_start, va_arg, va_end)
- Format string parsing and validation
- Conversion specifier handling (%c, %s, %d, %i, %u, %x, %X, %p, %%)
- Flag and modifier processing (-, 0, #, +, space, width, precision)
- Clean code architecture following 42 Norminette standards
- Efficient memory management and error handling

### Key Features
- ✅ Handles all required conversion specifiers (%c, %s, %d, %i, %u, %x, %X, %p, %%)
- ✅ Supports bonus flags (-, 0, #, +, space)
- ✅ Width and precision modifiers
- ✅ Proper memory management
- ✅ 100% Norminette compliant
- ✅ Full error handling

## 🎯 Conversion Specifiers

| Specifier | Type | Example |
|-----------|------|---------|
| `%c` | Character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | `ft_printf("%s", "hello")` → `hello` |
| `%d` | Signed integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | Signed integer | `ft_printf("%i", 42)` → `42` |
| `%u` | Unsigned integer | `ft_printf("%u", 42u)` → `42` |
| `%x` | Hex (lowercase) | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hex (uppercase) | `ft_printf("%X", 255)` → `FF` |
| `%p` | Pointer | `ft_printf("%p", ptr)` → `0x7ffee...` |
| `%%` | Percent literal | `ft_printf("%%")` → `%` |

## 🚩 Flags (Bonus)

| Flag | Effect | Example |
|------|--------|---------|
| `-` | Left-align | `ft_printf("%-10d", 42)` → `42        ` |
| `0` | Zero-padding | `ft_printf("%010d", 42)` → `0000000042` |
| `+` | Force sign | `ft_printf("%+d", 42)` → `+42` |
| ` ` | Space for +ve | `ft_printf("% d", 42)` → ` 42` |
| `#` | Alternate form | `ft_printf("%#x", 255)` → `0xff` |

## 📏 Modifiers

### Width
Specifies minimum field width. Pads with spaces (or zeros if `0` flag is set).

```c
ft_printf("%10d", 42)      // "        42" (right-aligned)
ft_printf("%-10d", 42)     // "42        " (left-aligned)
```

### Precision
For strings: maximum characters to print  
For numbers: minimum digits to print

```c
ft_printf("%.5s", "hello world")  // "hello"
ft_printf("%.5d", 42)             // "00042"
```

## Instructions

### Compilation

The project includes a Makefile with the following targets:

**Build Mandatory Part:**
```bash
make
```

**Build with Bonus:**
```bash
make bonus
```

**Clean Object Files:**
```bash
make clean
```

**Full Clean (remove library and objects):**
```bash
make fclean
```

**Rebuild:**
```bash
make re
make re_bonus
```

### Installation

1. Clone the repository:
```bash
git clone <repository_url>
cd ft_printf
```

2. Compile the library:
```bash
make bonus
```

3. The library `libftprintf.a` will be created in the project directory.

### Usage

Include the header in your C program:
```c
#include "ft_printf.h"
```

Compile your program with the library:
```bash
gcc -Wall -Wextra -Werror my_program.c -L. -lftprintf -o my_program
./my_program
```

### Basic Example
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");           // Hello World!
    ft_printf("Number: %d\n", 42);                // Number: 42
    ft_printf("Hex: %#x\n", 255);                 // Hex: 0xff
    ft_printf("Pointer: %p\n", &main);            // Pointer: 0x... 
    return (0);
}
```

## 🛠️ Project Structure

### Mandatory Part
- `ft_printf.c` - Main entry point
- `ft_printf.h` - Header file with function declarations
- `ft_printf_utils.c` - Utility functions
- `ft_printf_numbers.c` - Number printing functions

### Bonus Part
- `ft_printf_bonus.c` - Main bonus entry point
- `ft_printf_bonus.h` - Bonus header with t_format struct
- `ft_printf_parse_bonus.c` - Format string parser
- `ft_printf_format_bonus.c` - Format handling dispatcher
- `ft_printf_char_str_bonus.c` - Character and string formatting
- `ft_printf_numbers_bonus.c` - Basic number output
- `ft_printf_utils_bonus.c` - Bonus utility functions
- `ft_printf_int_bonus.c` - Signed integer formatting (< 25 lines ✅)
- `ft_printf_uint_bonus.c` - Unsigned integer formatting
- `ft_printf_hex_bonus.c` - Hexadecimal formatting (< 25 lines ✅)

## 📊 File Statistics

| Metric | Value |
|--------|-------|
| Total Files | 13 (10 C files + 1 header + Makefile) |
| Total Lines | ~800 |
| Functions | 35+ |
| Max lines per function | 25 (Norminette compliant) |
| Norminette Status | ✅ 100% PASS |

## 🚀 Compilation

### Build Mandatory Part
```bash
make
```

### Build with Bonus
```bash
make bonus
```

### Clean Object Files
```bash
make clean
```

### Full Clean
```bash
make fclean
```

### Rebuild
```bash
make re
make re_bonus
```

## 💻 Usage

### Basic Example
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");           // Hello World!
    ft_printf("Number: %d\n", 42);                // Number: 42
    ft_printf("Hex: %#x\n", 255);                 // Hex: 0xff
    ft_printf("%.2f\n", 3.14);                    // (no float support)
    return (0);
}
```

### Compilation with Library
```bash
gcc -Wall -Wextra -Werror my_program.c -L. -lftprintf -o my_program
./my_program
```

## 🎓 Implementation Details

### Algorithm and Data Structure

The implementation follows a **parser-dispatcher-formatter architecture** that ensures clean separation of concerns and maintainability.

#### Chosen Algorithm: State-Based Format Parser

The core algorithm processes the format string character by character using a state machine approach:

1. **Input Scanning Phase**: Iterate through the format string
   - Regular characters → Write directly to stdout
   - '%' character → Trigger parsing state

2. **Format Parsing Phase** (`ft_parse_format`):
   - Extract flags in order: -, 0, #, +, space (stored as booleans)
   - Parse width: collect consecutive digits or skip if none
   - Parse precision: check for '.', then collect digits
   - Identify conversion specifier: c, s, d, i, u, x, X, p, %

3. **Dispatch Phase** (`ft_handle_format`):
   - Route to appropriate formatter based on conversion type
   - Character/String → `ft_format_char` / `ft_format_str`
   - Integer → `ft_format_int`
   - Unsigned → `ft_format_uint`
   - Hexadecimal → `ft_format_hex`
   - Pointer → Special case of hex with '0x' prefix

4. **Formatting Phase**:
   - Apply width padding (left or right based on '-' flag)
   - Apply precision (minimum digits for numbers, max chars for strings)
   - Apply sign handling ('+' or ' ' for positive numbers)
   - Apply alternate form ('#' for 0x prefix)
   - Output formatted result

**Justification for this approach:**
- **Modularity**: Each phase is isolated in separate functions (< 25 lines per Norminette)
- **Maintainability**: Adding new format specifiers requires minimal changes
- **Performance**: Single-pass parsing with O(n) complexity
- **Clarity**: State is explicitly tracked in `t_format` structure
- **Memory Efficiency**: No dynamic allocation for formatting operations

#### Key Data Structure: `t_format`

```c
typedef struct s_format
{
    char    conversion;  // The format specifier (%d, %s, etc)
    int     minus;       // - flag (left-align)
    int     zero;        // 0 flag (zero-padding)
    int     dot;         // . present (precision specified)
    int     hash;        // # flag (alternate form)
    int     plus;        // + flag (force sign)
    int     space;       // space flag
    int     width;       // Minimum field width
    int     precision;   // Precision value
}   t_format;
```

**Justification for `t_format` structure:**
- **Encapsulation**: All format information in one place
- **Clear State**: Each flag/modifier has explicit boolean or integer field
- **Pass-by-value**: Small structure (36-40 bytes) passed efficiently
- **Type Safety**: Strongly typed fields prevent errors
- **Extensibility**: Easy to add new flags without breaking existing code

The structure is initialized with default values (all flags = 0, width = 0, precision = -1) and populated during parsing. The precision default of -1 distinguishes between "no precision" and "precision of 0".

### Architecture Flow

```
User calls ft_printf("%+10d", 42)
    ↓
[ft_printf_bonus.c] - Entry point
    ├─ Iterates format string
    ├─ Calls ft_parse_format() when '%' found
    │
[ft_printf_parse_bonus.c] - Parser
    ├─ Extracts flags (-, 0, #, +, space)
    ├─ Parses width
    ├─ Parses precision
    └─ Returns t_format struct
    │
[ft_printf_format_bonus.c] - Dispatcher
    ├─ Routes to appropriate formatter
    │
[ft_printf_int_bonus.c] - Formatter
    ├─ Applies flags and width
    ├─ Calls basic output functions
    │
[ft_printf_numbers_bonus.c] - Output
    └─ Prints raw digits to stdout
```

### Implementation Trade-offs

**Chosen: Static buffer approach for number conversion**
- Uses small stack buffer for digit conversion
- No malloc/free overhead
- Sufficient for all integer types (max 20 digits for 64-bit)

**Alternative considered: Dynamic allocation**
- Would allow arbitrary precision
- Rejected due to: memory overhead, leak risks, unnecessary complexity

**Chosen: Recursive digit printing**
- Clean and readable implementation
- Stack depth limited by number size (max ~20 calls)
- Norminette-friendly (keeps functions short)

**Alternative considered: Iterative with buffer**
- Would avoid recursion
- Rejected due to: more complex code, harder to keep under 25 lines

## ✅ Quality Assurance

### Norminette Compliance
```bash
norminette ft_printf*.c ft_printf*.h
# Result: ALL OK! ✅
```

### Code Quality
- ✅ All functions < 25 lines (Norminette requirement)
- ✅ All functions have single responsibility
- ✅ Proper memory management (no leaks)
- ✅ Comprehensive error handling
- ✅ Clean code architecture

### Testing
Test with your own programs:
```bash
gcc -Wall -Wextra -Werror test.c -L. -lftprintf -o test
./test
```

## 📚 Examples

### Flags and Width
```c
ft_printf("%10d\n", 42);           // "        42"
ft_printf("%-10d\n", 42);          // "42        "
ft_printf("%010d\n", 42);          // "0000000042"
ft_printf("%+d\n", 42);            // "+42"
ft_printf("% d\n", 42);            // " 42"
```

### Precision
```c
ft_printf("%.5s\n", "hello world"); // "hello"
ft_printf("%.5d\n", 42);            // "00042"
ft_printf("%5.2d\n", 1);            // "   01"
```

### Hexadecimal
```c
ft_printf("%x\n", 255);             // "ff"
ft_printf("%X\n", 255);             // "FF"
ft_printf("%#x\n", 255);            // "0xff"
ft_printf("%#X\n", 255);            // "0XFF"
```

### Pointers
```c
int x = 42;
ft_printf("%p\n", &x);              // "0x7ffee... (address depends on system)"
ft_printf("%p\n", NULL);            // "(nil)" (or "0x0" depending on implementation)
```

## 🔧 Requirements Met

### Mandatory Part
- ✅ Implements `ft_printf` function
- ✅ Handles all basic conversion specifiers (%c, %s, %d, %i, %u, %x, %X, %p, %%)
- ✅ Returns number of characters printed
- ✅ Proper error handling

### Bonus Part
- ✅ Flag: `-` (left-alignment)
- ✅ Flag: `0` (zero-padding)
- ✅ Flag: `#` (alternate form)
- ✅ Flag: `+` (force sign)
- ✅ Flag: ` ` (space for positive)
- ✅ Width modifier
- ✅ Precision modifier
- ✅ 100% Norminette compliant (all functions < 25 lines)

## 🚨 Known Limitations

- ❌ Does NOT support floating-point formats (%f, %e, %g)
- ❌ Does NOT support length modifiers (l, h, etc.)
- ❌ Does NOT support variable width (*) or precision (*.*)

## Resources

### Documentation and References

**C Standard Library:**
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Official Linux documentation for printf
- [C99 Standard - 7.19.6 Formatted input/output functions](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) - Official C standard specification
- [cppreference - printf](https://en.cppreference.com/w/c/io/fprintf) - Comprehensive C reference

**Variadic Functions:**
- [stdarg.h documentation](https://www.tutorialspoint.com/c_standard_library/stdarg_h.htm) - Guide to va_list, va_start, va_arg, va_end
- [Variadic Functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/) - GeeksforGeeks tutorial

**42 School Resources:**
- [42 Norminette](https://github.com/42School/norminette) - Code style checker
- [ft_printf subject](https://projects.intra.42.fr/) - Official project requirements (42 intranet)

**Additional Learning:**
- [Binary, Decimal and Hexadecimal Numbers](https://www.mathsisfun.com/binary-decimal-hexadecimal.html) - Number system conversion
- [Understanding Format Specifiers](https://www.cplusplus.com/reference/cstdio/printf/) - Format specifier breakdown

### AI Usage Description

**Tasks where AI was used:**
1. **Documentation Assistance**: AI (GitHub Copilot) was used to help structure and format this README according to 42 standards
2. **Code Review**: AI was consulted for alternative implementation approaches and best practices
3. **Debugging Support**: AI helped identify edge cases and potential issues during development

**Parts of the project created with AI assistance:**
- README.md structure and formatting (this document)
- Code comments and documentation strings
- Test case generation ideas

**Parts implemented WITHOUT AI:**
- All core algorithm logic and implementation (100% manual)
- Format parsing state machine
- All conversion specifier handlers
- Flag and modifier processing
- Memory management and error handling
- Makefile configuration
- Norminette compliance fixes

**Development Approach:**
The project was primarily developed through manual implementation, using official documentation and the 42 curriculum as primary references. AI tools were used as supplementary resources for documentation, code review suggestions, and learning alternative approaches, but all final implementation decisions and code were written manually to ensure deep understanding of the concepts.

### Return Value
The function returns the total number of characters printed to stdout, excluding the null terminator (just like the real `printf`).

### NULL Handling
- `%s` with NULL pointer prints `(null)`
- `%p` with NULL pointer prints `(nil)` or implementation-specific

### Flag Combinations
- `-` flag disables `0` flag padding
- Precision with `d` means zero-padding
- Multiple flags can be combined

## 🎓 Learning Outcomes

This project teaches:
- String parsing and format specification handling
- Variable argument functions (va_list, va_arg, va_end)
- Recursive digit printing
- Flag and modifier processing
- Clean code architecture with modular design
- Norminette compliance standards

## 📞 Author

**viceda-s** <viceda-s@student.42luxembourg.lu>

42 School Luxembourg

## 📄 License

This project is part of the 42 School curriculum.