#include <iostream>
#include <bitset>

bool isEvenParity(const std::bitset<7>& binaryData) {
    int countOnes = binaryData.count();
    return (countOnes % 2 == 0);
}
std::bitset<8> addParityBit(const std::bitset<7>& binaryData) {
    std::bitset<8> dataWithParity(binaryData.to_string());
    // Calculate parity bit and append it to the data
    bool parityBit = isEvenParity(binaryData);
    dataWithParity.set(7, !parityBit);
    return dataWithParity;
}
bool checkParity(const std::bitset<8>& binaryData) {
    // Only consider the first 7 bits for parity check
    std::bitset<7> dataWithoutParity(binaryData.to_string().substr(0, 7));
    return !isEvenParity(dataWithoutParity);
}

int main() {
    std::bitset<7> sendData;
    std::bitset<8> receivedData;

    // Sender
    std::cout << "Sender:\n";
    std::cout << "Enter 7-bit binary data to be sent (e.g., 1101101): ";
    std::cin >> sendData;

    // Add parity bit
    std::bitset<8> sendDataWithParity = addParityBit(sendData);
    std::cout << "Data with parity bit: " << sendDataWithParity << "\n\n";

    // Receiver
    std::cout << "Receiver:\n";
    std::cout << "Enter received 8-bit binary data (including parity bit): ";
    std::cin >> receivedData;

    // Check parity
    if (checkParity(receivedData)) {
        std::cout << "Parity check passed. Data is correct.\n";
        std::cout << "Received data without parity bit: " << receivedData << "\n";
    } else {
        std::cout << "Parity check failed. Data may be corrupted.\n";
    }
    return 0;
}
