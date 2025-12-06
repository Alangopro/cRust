

# 🦀 cRust

**cRust** is a **header-only experimental library** that brings a small, expressive subset of **Rust-style syntax** into standard **C and C++** through the preprocessor.
It is aimed at developers who enjoy Rust’s clarity but need to remain within a C/C++ toolchain.



---


## Current Features

| Category             | Name                  | Type / Expansion       | Description                                 |
| -------------------- | --------------------- | ---------------------- | ------------------------------------------- |
| **Keywords**         | `fn`                  | `int`                  | Defines a function.                         |
|                      | `let`                 | *(empty)*              | alias for an variable declaration.          |
|                      | `mut`                 | *(empty)*              | alias for an mutable variable.              |
|                      | `brk`                 | `break`                | Early loop exit.                            |
|                      | `next_iter`           | `continue`             | Skip loop iteration.                        |
|                      | `loop`                | `for(;;)`              | Infinite loop.                              |
|                      | `match`               | `switch`               | Rust-style pattern matching.                |
|                      | `when`                | `case`                 | Match arm.                                  |
|                      | `_`                   | `default`              | Default match arm.                          |
|                      | `pin`                 | `const`                | Marks a pinned/fixed pointer.               |
| **Printing / Debug** | `print(fmt, ...)`     | `printf`               | Print without newline.                      |
|                      | `println(fmt, ...)`   | `printf(... + "\n")`   | Print with newline.                         |
|                      | `eprint(fmt, ...)`    | `fprintf(stderr, ...)` | Print to stderr.                            |
|                      | `panic(msg)`          | `fprintf + exit`       | Abort program with message.                 |
|                      | `unwrap(status, msg)` | Panic if not OK        | Rust-like unwrap for status.                |
| **Status Codes**     | `OK`                  | `0`                    | Success.                                    |
|                      | `ERR`                 | `1`                    | Failure.                                    |
|                      | `SOME`                | `0`                    | Value exists.                               |
|                      | `NONE`                | `1`                    | No value.                                   |
| **Types**            | `unit`                | `void`                 | Unit type.                                  |
|                      | `char8`               | `char`                 | 8-bit ASCII character.                      |
|                      | `Boolean`             | `bool`                 | Boolean alias.                              |
|                      | `i8/i16/i32/i64`      | `int8_t` /16/32/64       | Signed integers.                          |
|                      | `isize`               | `ptrdiff_t`              | Signed pointer-sized integer.             |
|                      | `u8/u16/u32/u64`      | `uintX_t`                | Unsigned integers.                        |
|                      | `usize`               | `size_t`               | Unsigned pointer-sized integer.             |
|                      | `f32/f64`             | float / double         | Floating-point types.                       |
|                      | `String`              | `std::string`          | Owned string.                               |
|                      | `str`                 | `const std::string&`   | String slice.                               |
|                      | `RawPtr`              | `void*`                | Raw pointer.                                |
|                      | `ConstRawPtr`         | `const void*`          | Const raw pointer.                          |
|                      | `Ref(T)`              | `const T*`             | Immutable reference.                        |
|                      | `RefMut(T)`           | `T*`                   | Mutable reference.                          |
| **Memory**           | `Box(T)`              | `T*`                   | Heap-allocated value.                       |
|                      | `vector(T, n)`        | `calloc`               | Allocates zeroed array.                     |
|                      | `alloc(T)`            | `malloc`               | Allocates uninitialized T.                  |
|                      | `drop(ptr)`           | *(empty)*              | No-op (prevents freeing C++ RAII types).    |
| **Utilities**        | `size_of(T)`          | `sizeof(T)`            | Alias for `sizeof`.                         |
|                      | `strlen(s)`           | `s.length()`           | String length override for std::string.     |
|                      | `strcmp(s1, s2)`      | equality compare       | std::string equality → 0/1.                 |




---

## Example

```cpp
#include "crust/crust.hpp"
#include <iostream>

fn main() {
    let mut i = 0;

    loop {
        if (i >= 5) {
            break;
        }

        println("Counter value: %d", i);
        i = i + 1;
    }

    return OK;
}
```

---

## Project Status

This library is **experimental** and relies on heavy preprocessor expansion.

Expect behavioral differences between compilers and platforms.
Contributions, ideas, and tests are welcome.




---

## License

This project is licensed under **CC BY-NC 4.0**.

You may use, modify, and share the library **for non-commercial purposes only**, and you **must keep attribution** to the original author. 


[![Cpp](https://img.shields.io/badge/C++-20-blue?logo=cplusplus&logoColor=white&style=for-the-badge)](https://visualstudio.microsoft.com/vs/features/cplusplus/)
[![License: GPL v3](https://img.shields.io/badge/License-C--BY--NC%204.0-green.svg?style=for-the-badge)](https://creativecommons.org/licenses/by-nc/4.0/)
[![Code size](https://img.shields.io/github/languages/code-size/Alangopro/cRust?style=for-the-badge)](#)

[![GitHub stars](https://img.shields.io/github/stars/Alangopro/cRust?style=for-the-badge)](https://github.com/Alangopro/cRust/stargazers)
[![GitHub issues](https://img.shields.io/github/issues/Alangopro/cRust?style=for-the-badge)](https://github.com/Alangopro/cRust/issues)
[![Contributions](https://img.shields.io/badge/contributions-open-brightgreen.svg?style=for-the-badge)](https://github.com/Alangopro/cRust/issues)


[![Discord](https://img.shields.io/badge/Discord-%235865F2.svg?style=for-the-badge&logo=discord&logoColor=white)](https://dc.queenmc.pl/)
[![Telegram](https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white)](https://feds.lol/Kamerzystanasyt)

**Copyright (c) 2025 - Kamerzystanasyt**
