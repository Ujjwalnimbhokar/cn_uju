#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void goBackN(int totalFrames, int windowSize) {
    int frameSent = 0;

    while (frameSent < totalFrames) {
        cout << "\nSending frames in window starting from " << frameSent << "...\n";

        // Simulate sending a window of frames
        vector<bool> ackReceived(windowSize, false);
        for (int i = 0; i < windowSize && frameSent + i < totalFrames; ++i) {
            int success = rand() % 2; // Randomly simulate acknowledgment (1 -> success, 0 -> failure)
            if (success) {
                ackReceived[i] = true;
                cout << "Frame " << (frameSent + i) << " sent successfully and acknowledged.\n";
            } else {
                cout << "Frame " << (frameSent + i) << " lost or corrupted. No acknowledgment received.\n";
                break;
            }
        }

        // Check if all frames in the window were acknowledged
        int lastAckedFrame = frameSent; // Track the last successfully acknowledged frame
        for (int i = 0; i < windowSize && frameSent + i < totalFrames; ++i) {
            if (ackReceived[i]) {
                lastAckedFrame++;
            } else {
                break;
            }
        }

        // Slide the window
        if (lastAckedFrame > frameSent) {
            frameSent = lastAckedFrame;
        } else {
            cout << "Retransmitting window starting from frame " << frameSent << "...\n";
        }
    }

    cout << "\nAll frames sent successfully!\n";
}

int main() {
    srand(time(0)); // Seed for random number generation

    int totalFrames, windowSize;

    cout << "Enter the total number of frames: ";
    cin >> totalFrames;

    cout << "Enter the window size: ";
    cin >> windowSize;

    goBackN(totalFrames, windowSize);

    return 0;
}


// Input Example
// Enter the total number of frames: 10
// Enter the window size: 4