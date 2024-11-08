#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

typedef struct {
    long long wholePart;
    long long decimalPart;
    int decimalPlaces;
} DecimalNumber;

void initializeDecimal(DecimalNumber *num, double value, int precision) {
    num->wholePart = (long long)value;
    num->decimalPart = (long long)((value - num->wholePart) * 1e17);  // Scaling factor for precision
    num->decimalPlaces = precision;
}

void addDecimals(DecimalNumber *result, const DecimalNumber *num1, const DecimalNumber *num2) {
    result->wholePart = num1->wholePart + num2->wholePart;
    result->decimalPart = num1->decimalPart + num2->decimalPart;

    while (result->decimalPart >= 1e17) {
        result->decimalPart /= 10;
        result->decimalPlaces--;
    }
}

void printDecimal(const DecimalNumber *num) {
    printf("%lld.%020lld\n", num->wholePart, num->decimalPart);
}

int main() {
    DecimalNumber num1, num2, result;
    initializeDecimal(&num1, 0.1, 17);
    initializeDecimal(&num2, 0.2, 17);
    result.decimalPlaces = 17;

    addDecimals(&result, &num1, &num2);

    printf("Result: ");
    printDecimal(&result);

    return 0;
}
