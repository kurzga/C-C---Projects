#include <iostream>
#include <iomanip>
#include <conio.h>

class DecimalNumber {
public:
    DecimalNumber(double value, int precision) : decimalValue(value), decimalPlaces(precision) {
        std::string decimalStr = std::to_string(decimalValue);

        size_t dotPos = decimalStr.find('.');
        if (dotPos != std::string::npos) {
            wholePartStr = decimalStr.substr(0, dotPos);
            decimalPartStr = decimalStr.substr(dotPos + 1);
        } else {
            wholePartStr = decimalStr;
            decimalPartStr = "0";
        }

        padDecimalPart();
    }

    void addDecimals(const DecimalNumber &num1, const DecimalNumber &num2);
    void printDecimal() const;

private:
    std::string wholePartStr;
    std::string decimalPartStr;
    double decimalValue;
    int decimalPlaces;

    void padDecimalPart();
};

void DecimalNumber::addDecimals(const DecimalNumber &num1, const DecimalNumber &num2) {
    // Pad the decimal parts to the same length
    DecimalNumber paddedNum1 = num1;
    DecimalNumber paddedNum2 = num2;
    paddedNum1.padDecimalPart();
    paddedNum2.padDecimalPart();

    // Convert decimal parts to integers using std::stoll
    long long intPart1 = std::stoll(paddedNum1.decimalPartStr);
    long long intPart2 = std::stoll(paddedNum2.decimalPartStr);

    // Perform addition
    long long resultIntPart = intPart1 + intPart2;

    // Convert result back to string
    decimalPartStr = std::to_string(resultIntPart);

    // Adjust whole part if necessary
    if (decimalPartStr.length() > paddedNum1.decimalPartStr.length()) {
        wholePartStr = std::to_string(std::stoll(paddedNum1.wholePartStr) + 1);
        decimalPartStr = decimalPartStr.substr(1);
    } else {
        wholePartStr = paddedNum1.wholePartStr;
    }

    // Remove leading zeros in decimal part
    while (!decimalPartStr.empty() && decimalPartStr[0] == '0') {
        decimalPartStr = decimalPartStr.substr(1);
    }

    // Pad decimal part to the specified precision
    padDecimalPart();
}

void DecimalNumber::padDecimalPart() {
    // Pad the decimal part with zeros to the specified precision
    while (decimalPartStr.length() < decimalPlaces) {
        decimalPartStr += "0";
    }
}

void DecimalNumber::printDecimal() const {
    std::cout << wholePartStr << "." << std::setw(decimalPlaces) << std::setfill('0') << decimalPartStr << std::endl;
}

int main() {
    DecimalNumber num1(0.1, 17);
    DecimalNumber num2(0.2, 17);
    DecimalNumber result(0, 17);

    result.addDecimals(num1, num2);

    std::cout << "Result: ";
    result.printDecimal();
    getch();
    return 0;
}
