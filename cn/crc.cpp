#include <iostream>
using namespace std;

// Function to perform the division (XOR operation)
void performDivision(int data[], int divisor[], int dataSize, int divisorSize) {
    for (int i = 0; i <= dataSize - divisorSize; i++) {
        if (data[i] == 1) { // Only divide if the leading bit is 1
            for (int j = 0; j < divisorSize; j++) {
                data[i + j] ^= divisor[j]; // XOR operation
            }
        }
    }
}

int main() {
    int dataSize, divisorSize;

    // Input data size and data bits
    cout << "Enter the number of data bits: ";
    cin >> dataSize;
    int data[dataSize + 20] = {0}; // Initialize all elements to 0

    cout << "Enter the data bits (0 or 1): ";
    for (int i = 0; i < dataSize; i++) {
        cin >> data[i];
    }

    // Input divisor size and divisor bits
    cout << "Enter the number of divisor bits: ";
    cin >> divisorSize;

    int divisor[divisorSize];
    cout << "Enter the divisor bits (0 or 1): ";
    for (int i = 0; i < divisorSize; i++) {
        cin >> divisor[i];
    }

    // Append zeros to the data
    for (int i = dataSize; i < dataSize + divisorSize - 1; i++) {
        data[i] = 0;
    }

    // Perform division to calculate CRC
    int tempData[dataSize + divisorSize - 1];
    copy(data, data + dataSize + divisorSize - 1, tempData); // Copy data for division
    performDivision(tempData, divisor, dataSize + divisorSize - 1, divisorSize);

    // Append CRC to the data
    for (int i = dataSize; i < dataSize + divisorSize - 1; i++) {
        data[i] = tempData[i]; // Copy the remainder as CRC
    }


    // Simulate receiver verification
    cout << "Enter the received data bits: ";
    int receivedData[dataSize + divisorSize - 1] = {0};
    for (int i = 0; i < dataSize + divisorSize - 1; i++) {
        cin >> receivedData[i];
    }

    // Perform division on the received data
    performDivision(receivedData, divisor, dataSize + divisorSize - 1, divisorSize);

    // Check remainder to verify
    bool isError = false;
    for (int i = dataSize; i < dataSize + divisorSize - 1; i++) {
        if (receivedData[i] != 0) {
            isError = true;
            break;
        }
    }

    if (isError) {
        cout << "Error detected in received data.\n";
    } else {
        cout << "No error detected in received data.\n";
    }

    return 0;
}