
# Number Base Converter (C)

## Description

This C program is a command-line tool for converting numbers between different bases: decimal, binary, octal, and hexadecimal. It provides a simple menu-driven interface to perform the following conversions:

*   Decimal to Binary
*   Binary to Decimal
*   Decimal to Octal
*   Octal to Decimal
*   Hexadecimal to Binary
*   Binary to Hexadecimal
*   Hexadecimal to Decimal
*   Octal to Hexadecimal

The program is written in C and is designed to be easy to use and understand. It includes error handling for invalid input and memory management to prevent leaks.  It now also supports negative decimal number conversions to binary and octal (represented with a leading '-').

## Features

*   **Menu-Driven Interface:** Easy to navigate and select conversion options.
*   **Error Handling:**  Robustly handles invalid input formats (non-numeric menu choices, invalid digits in binary/octal/hexadecimal input).
*   **Memory Management:**  Dynamically allocates memory for string results and frees it after use.
*   **Clear Output:**  Displays the converted number in the chosen base with descriptive messages.
*   **Decimal to Binary Conversion:** Converts decimal integers (including negative) to their binary string representation (negative numbers have a leading '-').
*   **Binary to Decimal Conversion:** Converts binary strings to decimal integers, validating binary input.
*   **Decimal to Octal Conversion:** Converts decimal integers (including negative) to their octal string representation (negative numbers have a leading '-').
*   **Octal to Decimal Conversion:** Converts octal strings to decimal integers, validating octal input.
*   **Hexadecimal to Binary Conversion:** Converts hexadecimal strings to their binary string representation, validating hexadecimal input.
*   **Binary to Hexadecimal Conversion:** Converts binary strings to their hexadecimal string representation.
*   **Hexadecimal to Decimal Conversion:** Converts hexadecimal strings to decimal integers, validating hexadecimal input.
*   **Octal to Hexadecimal Conversion:** Converts octal strings to hexadecimal strings, validating octal input.

## Requirements

*   A C compiler (like GCC)
*   Standard C libraries (should be available on any system with a C compiler)