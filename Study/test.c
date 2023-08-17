#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary string to an integer
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int length = strlen(binary);
    
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += 1 << (length - i - 1);
        }
    }
    
    return decimal;
}

// Function to convert an integer to a string
char* intToString(int number) {
    int length = snprintf(NULL, 0, "%d", number);
    char *str = (char *)malloc(length + 1);
    
    if (str != NULL) {
        snprintf(str, length + 1, "%d", number);
    }
    
    return str;
}

int main() {
    const char *binaryString = "01100001";
    
    int decimalNumber = binaryToDecimal(binaryString);
    printf("Decimal: %d\n", decimalNumber);
    
    char *decimalString = intToString(decimalNumber);
    printf("Decimal as string: %c\n", decimalString);
    
    free(decimalString);

    return 0;
}
