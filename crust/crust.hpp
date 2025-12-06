/*
* Copyright (c) 2025 Kamerzystanasyt
*
* Creative Commons Attribution-NonCommercial 4.0 International Public License
* (CC BY-NC 4.0)
*
* This work is licensed under the Creative Commons Attribution-NonCommercial 4.0
* International License. To view a copy of this license, visit
* http://creativecommons.org/licenses/by-nc/4.0/ or send a letter to
* Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
*
* You are free to:
*   - Share — copy and redistribute the material in any medium or format
*   - Adapt — remix, transform, and build upon the material
*
* Under the following terms:
*   - Attribution — You must give appropriate credit, provide a link to the
*     license, and indicate if changes were made. You may do so in any reasonable
*     manner, but not in any way that suggests the licensor endorses you or your use.
*   - NonCommercial — You may not use the material for commercial purposes.
*   - No additional restrictions — You may not apply legal terms or technological
*     measures that legally restrict others from doing anything the license permits.
*
* Full license text: https://creativecommons.org/licenses/by-nc/4.0/legalcode
*/



#ifndef CRUST_H
#define CRUST_H


#include            <stdio.h>
#include            <stdlib.h>
#include            <stdbool.h>
#include            <stddef.h>
#include            <stdint.h>
#include            <limits.h>
#include            <string>


/**
* @brief Defines a function.
* @note This macro is an alias for 'int'.
*/
#define fn int

/**
* @brief Empty alias for variable declaration.
* @note Expands to nothing.
*/
#define let

/**
* @brief Empty alias for a mutable variable.
* @note Expands to nothing, as C variables are mutable by default.
*/
#define mut

/**
* @brief Allows early exit from a loop (safe alias for break).
*/
#define brk break

/**
* @brief Skips the current loop iteration (safe alias for continue).
*/
#define next_iter continue



/**
* @brief Marks a constant, immutable value (safe alias for const).
* @note The macro has been removed to avoid conflicts with winnt.h.
*/

/** @typedef Unit type, carries no information (alias for void).*/
typedef void unit;

/** @typedef ASCII character (8-bit).*/
typedef char char8;

/** @typedef Basic boolean type.
* @note Renamed from 'boolean' to avoid conflict with Windows/RPC headers.
*/
typedef bool Boolean;

/** @typedef Signed 8-bit integer.*/
typedef int8_t i8;
/** @typedef Signed 16-bit integer.*/
typedef int16_t i16;
/** @typedef Signed 32-bit integer.*/
typedef int32_t i32;
/** @typedef Signed 64-bit integer.*/
typedef int64_t i64;
/** @typedef Signed pointer size integer (platform-dependent).*/
typedef ptrdiff_t isize;

/** @typedef Unsigned 8-bit integer.*/
typedef uint8_t u8;
/** @typedef Unsigned 16-bit integer.*/
typedef uint16_t u16;
/** @typedef Unsigned 32-bit integer.*/
typedef uint32_t u32;
/** @typedef Unsigned 64-bit integer.*/
typedef uint64_t u64;
/** @typedef Unsigned size type (platform-dependent).*/
typedef size_t usize;

/** @typedef 32-bit floating point number.*/
typedef float f32;
/** @typedef 64-bit floating point number.*/
typedef double f64;

/** @typedef those are redefined to fix E0413*/
#undef strlen
#define strlen(s) ((s).length())
#undef strcmp
#define strcmp(s1, s2) ((s1) == (s2) ? 0 : 1)

/** @typedef String slice (alias for const char*).*/
#undef str
#define str const std::string&
/** @typedef Mutable string variable (alias for char*).*/
#undef String
#define String std::string
/** @typedef Raw pointer to any type.*/
typedef void* RawPtr;
/** @typedef Constant raw pointer to any type.*/
typedef const void* ConstRawPtr;

/**
* @brief Defines an infinite loop (alias for 'for (;;)').
*/
#define loop for (;;)

/**
* @brief Represents a heap-allocated (boxed) value (alias for a pointer).
* @param TYPE The type to be allocated (e.g., i32).
*/
#define Box(TYPE) TYPE*

/**
* @brief Allocates and zero-initializes a heap array/vector (like calloc).
* @param TYPE The element type.
* @param COUNT The number of elements.
*/
#define vector(TYPE, COUNT) (Box(TYPE))calloc(COUNT, sizeof(TYPE))

/**
* @brief Frees memory allocated by Box or vector (alias for free).
* @note W C++: Overide to empty macro, because std::string manages own memory.
*/
#undef drop
#define drop(ptr)

/**
* @brief Allocates memory on the heap without initialization (alias for malloc).
* @param TYPE The type to be allocated.
*/
#define alloc(TYPE) (Box(TYPE))malloc(sizeof(TYPE))


/** @typedef Status type used for Result/Option. 0 = OK/Some, Non-zero = Error/None.*/
typedef i32 ResultStatus;

/** @brief Status: Operation succeeded.*/
#define OK 0
/** @brief Status: Operation failed.*/
#define ERR 1
/** @brief Status: Value is present.*/
#define SOME 0
/** @brief Status: Value is absent.*/
#define NONE 1

/**
* @brief "Unwraps" a status. If the status is not OK (0), the program panics.
* @param STATUS The integer status variable to check.
* @param MSG The error message to display on failure.
*/
#define unwrap(STATUS, MSG) \
    do { \
        if (STATUS != CRUST_OK) { \
            fprintf(stderr, "PANIC: Unwrap failed (%s)\n", MSG); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)


/**
* @brief Prints formatted output to stdout without a newline.
* @param format The format string (e.g., "%d").
* @param ... The arguments to be formatted.
*/
#define print(format, ...) \
    do { \
        printf(format, ##__VA_ARGS__); \
    } while (0)

/**
* @brief Prints formatted output to stdout followed by a newline.
* @param format The format string (e.g., "%s").
* @param ... The arguments to be formatted.
*/
#define println(format, ...) \
    do { \
        printf(format "\n", ##__VA_ARGS__); \
    } while (0)

/**
* @brief Prints formatted output to stderr without a newline.
* @param format The format string.
* @param ... The arguments.
*/
#define eprint(format, ...) \
    do { \
        fprintf(stderr, format, ##__VA_ARGS__); \
    } while (0)

/**
* @brief Halts program execution and prints an error message to stderr.
* @param message The error string to display before exiting.
*/
#define panic(message) \
    do { \
        fprintf(stderr, "PANIC: %s\n", message); \
        exit(EXIT_FAILURE); \
    } while (0)


/** @typedef Alias for const pointer to a type (immutable reference).*/
#define Ref(TYPE) const TYPE*

/** @typedef Alias for a pointer to a type (mutable reference).*/
#define RefMut(TYPE) TYPE*

/**
* @brief Alias for C switch, used for pattern matching.
*/
#define match switch

/**
* @brief Safe alias for the C keyword 'case'.
*/
#define when case

/**
* @brief Alias for C default.
*/
#define _ default

/**
* @brief Alias for C sizeof.
*/
#define size_of(TYPE) sizeof(TYPE)

/**
* @brief Forces a pointer to be stored at a fixed address (safe alias for const).
*/
#define pin const
#endif
