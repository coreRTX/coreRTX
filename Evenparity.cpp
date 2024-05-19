#include <iostream>
#include <bitset>
bool isEvenParity(const std::bitset<7>& binaryData) {
    int countOnes = binaryData.count();
    return (countOnes % 2 == 0);
}
int main() {
    std::bitset<7> binaryData;
    // Input 7-bit binary data
    std::cout << "Enter 7-bit binary data (e.g., 1101101): ";
    std::cin >> binaryData;

    // Check parity
    if (isEvenParity(binaryData)) {
        std::cout << "Even parity check passed. Data is correct.\n";
    } else {
        std::cout << "Even parity check failed. Data may be corrupted.\n";
    }

    return 0;
}

