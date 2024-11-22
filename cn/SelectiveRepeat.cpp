#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Simulates the transmission of a frame (0: lost, 1: acknowledged)
bool sendFrame(int frameNumber) {
    int success = rand() % 2; // Randomly decide success or failure
    return success;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int totalFrames, windowSize;

    cout << "Enter the total number of frames to send: ";
    cin >> totalFrames;
    cout << "Enter the window size: ";
    cin >> windowSize;

    vector<bool> acknowledged(totalFrames, false); // Acknowledgment tracker
    int base = 0; // Window base

    while (base < totalFrames) {
        cout << "\nCurrent window: ";
        for (int i = base; i < base + windowSize && i < totalFrames; ++i) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = base; i < base + windowSize && i < totalFrames; ++i) {
            if (!acknowledged[i]) {
                cout << "Sending frame " << i << "... ";
                if (sendFrame(i)) {
                    cout << "Acknowledged.\n";
                    acknowledged[i] = true;
                } else {
                    cout << "Lost. Retransmitting later.\n";
                }
            }
        }

        // Move the window base to the next unacknowledged frame
        while (base < totalFrames && acknowledged[base]) {
            base++;
        }
    }

    cout << "\nAll frames sent and acknowledged successfully!\n";
    return 0;
}



// Input Example
// Enter the total number of frames to send: 6
// Enter the window size: 3