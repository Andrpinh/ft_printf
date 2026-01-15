*This project has been created as part of the 42 curriculum by andrpinh.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the standard C `printf` function.
The goal of the project is to handle a subset of the original `printf` conversions:

* `%c` → character
* `%s` → string
* `%p` → pointer
* `%d` / `%i` → integer decimal
* `%u` → unsigned decimal
* `%x` / `%X` → hexadecimal (lowercase/uppercase)
* `%%` → literal percent sign

The function is designed to behave identically to the standard `printf` for these conversions, returning the exact number of characters printed.

The project does **not implement buffer management**, as required by the 42 subject.

---

## Instructions

### Compilation of the library

To compile the `libftprintf.a` library, simply run:

```bash
make
```

This will produce the static library `libftprintf.a` in the root of your repository.

### Cleaning

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Recompile everything from scratch:

```bash
make re
```

### Using `ft_printf` in your programs

1. Include the header:

```c
#include "ft_printf.h"
```

2. Compile your program and link with the library:

```bash
cc main.c -L. -lftprintf -o my_program
```

3. Run your program:

```bash
./my_program
```

### Example program

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;
    char *str = "Hello 42!";
    void *ptr = str;

    ft_printf("Char: %c\n", 'A');
    ft_printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Integer: %d\n", n);
    ft_printf("Unsigned: %u\n", 3000);
    ft_printf("Hex lowercase: %x\n", 255);
    ft_printf("Hex uppercase: %X\n", 255);
    ft_printf("Percent: %%\n");
    
    return 0;
}
```

Expected output (may vary for pointer address):

```
Char: A
String: Hello 42!
Pointer: 0x7ffee0bff618
Integer: 42
Unsigned: 3000
Hex lowercase: ff
Hex uppercase: FF
Percent: %
```

---

## Algorithm and Data Structures

`ft_printf` relies on:

1. **Parsing the format string:** Iterate through each character. When a `%` is found, the next character determines the conversion.

2. **Variadic arguments:** Use `stdarg.h` (`va_list`, `va_start`, `va_arg`, `va_end`) to fetch the corresponding argument.

3. **Dedicated printing functions:**

   * `ft_putchar` → prints a single character
   * `ft_putstr` → prints a string, prints `(null)` if NULL
   * `ft_putnbr` → prints signed integers using `long` to handle INT_MIN
   * `ft_putunbr` → prints unsigned integers
   * `ft_puthex` → prints hexadecimal numbers, uppercase or lowercase
   * `ft_putptr` → prints pointer addresses prefixed with `0x`, prints `0x0` if NULL

Each function returns the number of characters printed, summed by `ft_printf`.

Recursion is used for numbers and hexadecimals.

No extra data structures are required.

---

## Resources

* [C Standard Library Documentation](https://en.cppreference.com/w/c/io/fprintf)
* [Variadic Functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/)
* [42 ft_printf subject PDF](https://projects.intra.42.fr)

### AI usage

AI assisted in:

* Explaining project requirements
* Reviewing algorithms and code structure

All code and logic was manually implemented by me.

---

## Additional Notes

* Library created with `ar` as required
* Testable against standard `printf` for correctness
