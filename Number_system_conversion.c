#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   // For character type checking functions
#include <stdbool.h> // For boolean type

// Function to reverse a string in place
void strrev(char *str);

// Function to convert a decimal integer to its binary string representation
char *decimalToBinary(int decimal)
{
    char *binary = (char *)malloc(34); // Increased size for sign and null terminator
    if (binary == NULL)
    {
        fprintf(stderr, "Memory allocation failed in decimalToBinary.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    bool isNegative = false;

    if (decimal < 0)
    {
        isNegative = true;
        decimal = -decimal; // Work with the absolute value
    }

    if (decimal == 0)
    {
        binary[i++] = '0';
    }
    else
    {
        while (decimal > 0)
        {
            binary[i++] = '0' + (decimal & 1);
            decimal >>= 1;
        }
    }

    if (isNegative)
    {
        binary[i++] = '-'; // Prepend '-' for negative numbers
    }
    binary[i] = '\0';
    strrev(binary);
    return binary;
}

// Function to convert a binary string to its decimal integer representation
int binaryToDecimal(char binary[])
{
    int decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            fprintf(stderr, "Invalid binary digit: '%c' in input '%s'.\n", binary[i], binary);
            return -1; // Error code for invalid input
        }
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Function to convert a decimal integer to its octal string representation
char *decimalToOctal(int decimal)
{
    char *octal = (char *)malloc(16); // Increased size for sign and null terminator
    if (octal == NULL)
    {
        fprintf(stderr, "Memory allocation failed in decimalToOctal.\n");
        exit(EXIT_FAILURE);
    }

    bool isNegative = false;
    if (decimal < 0)
    {
        isNegative = true;
        decimal = -decimal;
    }

    sprintf(octal, "%o", decimal);

    if (isNegative)
    {
        // Need to handle negative octal representation, for simplicity prepending '-'
        char *negativeOctal = (char *)malloc(strlen(octal) + 2);
        if (negativeOctal == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        sprintf(negativeOctal, "-%s", octal);
        free(octal);
        octal = negativeOctal;
    }

    return octal;
}

int octalToDecimal(char octal[])
{
    int decimal = 0;
    int length = strlen(octal);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(octal[i]) || (octal[i] - '0') >= 8)
        {
            fprintf(stderr, "Invalid octal digit: '%c' in input '%s'.\n", octal[i], octal);
            return -1; // Error code for invalid input
        }
        decimal = decimal * 8 + (octal[i] - '0');
    }
    return decimal;
}

// Function to convert a decimal integer to its hexadecimal string representation
char *decimalToHexadecimal(int decimal)
{
    char *hexadecimal = (char *)malloc(17); // Increased size for sign and null terminator
    if (hexadecimal == NULL)
    {
        fprintf(stderr, "Memory allocation failed in decimalToHexadecimal.\n");
        exit(EXIT_FAILURE);
    }

    bool isNegative = false;
    if (decimal < 0)
    {
        isNegative = true;
        decimal = -decimal;
    }

    sprintf(hexadecimal, "%X", decimal); // %X for uppercase hex

    if (isNegative)
    {
        char *negativeHex = (char *)malloc(strlen(hexadecimal) + 2);
        if (negativeHex == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        sprintf(negativeHex, "-%s", hexadecimal);
        free(hexadecimal);
        hexadecimal = negativeHex;
    }
    return hexadecimal;
}

int hexadecimalToDecimal(char hex[])
{
    int decimal = 0;
    int length = strlen(hex);

    for (int i = 0; i < length; i++)
    {
        int digitValue;
        if (isdigit(hex[i]))
        {
            digitValue = hex[i] - '0';
        }
        else if (isxdigit(hex[i]))
        {                                    // isxdigit checks for hex digits (0-9, a-f, A-F)
            char lowerHex = tolower(hex[i]); // Convert to lowercase for easier handling
            digitValue = 10 + (lowerHex - 'a');
        }
        else
        {
            fprintf(stderr, "Invalid hexadecimal digit: '%c' in input '%s'.\n", hex[i], hex);
            return -1; // Error code for invalid input
        }
        decimal = decimal * 16 + digitValue;
    }
    return decimal;
}

// Function to convert a hexadecimal string to its binary string representation
char *hexadecimalToBinary(char hex[])
{
    unsigned int hexNum;
    if (sscanf(hex, "%x", &hexNum) != 1)
    {
        fprintf(stderr, "Invalid hexadecimal input: '%s'.\n", hex);
        return NULL;
    }

    char binary[129] = "";
    int i = 0;

    while (hexNum)
    {
        binary[i++] = '0' + (hexNum % 2);
        hexNum /= 2;
    }
    binary[i] = '\0';
    strrev(binary);

    return strdup(binary);
}

// Function to convert a binary string to its hexadecimal string representation
char *binaryToHexadecimal(char binary[])
{
    int length = strlen(binary);
    int padding = (4 - (length % 4)) % 4;
    char paddedBinary[130];
    memset(paddedBinary, '0', padding);
    strcpy(paddedBinary + padding, binary);

    char *binaryHexDigits[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    char hexadecimal[33] = "";

    for (int i = 0; i < length + padding; i += 4)
    {
        char group[5];
        strncpy(group, paddedBinary + i, 4);
        group[4] = '\0';

        for (int j = 0; j < 16; j++)
        {
            if (strcmp(group, binaryHexDigits[j]) == 0)
            {
                char hexDigit[2];
                sprintf(hexDigit, "%X", j);
                strcat(hexadecimal, hexDigit);
                break;
            }
        }
    }
    return strdup(hexadecimal);
}

// Function to convert octal to hexadecimal
char *octalToHexadecimal(char octal[])
{
    int decimalValue = octalToDecimal(octal);
    if (decimalValue == -1)
    {
        return NULL; // Indicate octal to decimal conversion error
    }
    return decimalToHexadecimal(decimalValue);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nNumber Base Converter Menu:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("7. Hexadecimal to Decimal\n"); // Added option 7
        printf("8. Octal to Hexadecimal\n");   // Added option 8
        printf("9. Exit\n");                   // Changed Exit option to 9
        printf("Enter your choice (1-9): ");

        if (scanf("%d", &choice) != 1)
        {
            fprintf(stderr, "Invalid input. Please enter a number between 1 and 9.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        if (choice == 9)
        { // Changed exit choice to 9
            printf("Exiting program. Goodbye!\n");
            break;
        }

        char input[100];
        char *result = NULL;
        int decimalResult;

        switch (choice)
        {
        case 1: // Decimal to Binary
            printf("Enter a decimal number: ");
            if (scanf("%d", &decimalResult) != 1)
            {
                fprintf(stderr, "Invalid decimal input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            result = decimalToBinary(decimalResult);
            if (result)
            {
                printf("Binary representation: %s\n", result);
                free(result);
            }
            break;

        case 2: // Binary to Decimal
            printf("Enter a binary number: ");
            if (scanf("%99s", input) != 1)
            {
                fprintf(stderr, "Invalid binary input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            decimalResult = binaryToDecimal(input);
            if (decimalResult != -1)
            {
                printf("Decimal representation: %d\n", decimalResult);
            }
            break;

        case 3: // Decimal to Octal
            printf("Enter a decimal number: ");
            if (scanf("%d", &decimalResult) != 1)
            {
                fprintf(stderr, "Invalid decimal input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            result = decimalToOctal(decimalResult);
            if (result)
            {
                printf("Octal representation: %s\n", result);
                free(result);
            }
            break;

        case 4: // Octal to Decimal
            printf("Enter an octal number: ");
            if (scanf("%99s", input) != 1)
            {
                fprintf(stderr, "Invalid octal input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            decimalResult = octalToDecimal(input);
            if (decimalResult != -1)
            {
                printf("Decimal representation: %d\n", decimalResult);
            }
            break;

        case 5: // Hexadecimal to Binary
            printf("Enter a hexadecimal number: ");
            if (scanf("%99s", input) != 1)
            {
                fprintf(stderr, "Invalid hexadecimal input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            result = hexadecimalToBinary(input);
            if (result)
            {
                printf("Binary representation: %s\n", result);
                free(result);
            }
            break;

        case 6: // Binary to Hexadecimal
            printf("Enter a binary number: ");
            if (scanf("%99s", input) != 1)
            {
                fprintf(stderr, "Invalid binary input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            result = binaryToHexadecimal(input);
            if (result)
            {
                printf("Hexadecimal representation: %s\n", result);
                free(result);
            }
            break;
        case 7: // Hexadecimal to Decimal
            printf("Enter a hexadecimal number: ");
            if (scanf("%99s", input) != 1)
            {
                fprintf(stderr, "Invalid hexadecimal input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            decimalResult = hexadecimalToDecimal(input);
            if (decimalResult != -1)
            {
                printf("Decimal representation: %d\n", decimalResult);
            }
            break;
        case 8: // Octal to Hexadecimal
            printf("Enter an octal number: ");
            if (scanf("%99s", input) != 1)
            {
                fprintf(stderr, "Invalid octal input.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }
            result = octalToHexadecimal(input);
            if (result)
            {
                printf("Hexadecimal representation: %s\n", result);
                free(result);
            }
            break;

        default:
            printf("Invalid choice. Please select an option from 1 to 9.\n");
        }
    }

    return 0;
}

// Reverses a string in-place.
void strrev(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}