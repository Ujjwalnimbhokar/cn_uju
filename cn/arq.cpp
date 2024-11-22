#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void stopAndWait();
void goBackN();
void selectiveRepeat();

int main() {
    int choice;
    do {
        cout << "\nSliding Window ARQ Menu\n";
        cout << "1. Stop-and-Wait ARQ\n";
        cout << "2. Go-Back-N ARQ\n";
        cout << "3. Selective Repeat ARQ\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                stopAndWait();
                break;
            case 2:
                goBackN();
                break;
            case 3:
                selectiveRepeat();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}

// Stop-and-Wait ARQ
void stopAndWait() {
    int frames;
    cout << "Enter the number of frames to send: ";
    cin >> frames;

    for (int i = 1; i <= frames; ++i) {
        cout << "Sending frame " << i << "...\n";
        cout << "Acknowledgment received for frame " << i << ".\n";
    }
    cout << "All frames sent successfully.\n";
}

// Go-Back-N ARQ
void goBackN() {
    int frames, window_size;
    cout << "Enter the number of frames to send: ";
    cin >> frames;
    cout << "Enter the window size: ";
    cin >> window_size;

    int sent = 0;
    while (sent < frames) {
        for (int i = 0; i < window_size && sent + i < frames; ++i) {
            cout << "Sending frame " << sent + i + 1 << "...\n";
        }
        cout << "Acknowledgment received for all frames in the window.\n";
        sent += window_size;
    }
    cout << "All frames sent successfully.\n";
}

// Selective Repeat ARQ
void selectiveRepeat() {
    int frames, window_size;
    cout << "Enter the number of frames to send: ";
    cin >> frames;
    cout << "Enter the window size: ";
    cin >> window_size;

    vector<bool> received(frames, false);
    for (int i = 0; i < frames; ++i) {
        cout << "Sending frame " << i + 1 << "...\n";
        char response;
        cout << "Did frame " << i + 1 << " get acknowledged? (y/n): ";
        cin >> response;
        if (response == 'y') {
            received[i] = true;
            cout << "Acknowledgment received for frame " << i + 1 << ".\n";
        } else {
            cout << "Resending frame " << i + 1 << "...\n";
            i--; // Retransmit the same frame
        }
    }
    cout << "All frames sent successfully.\n";
}




// 1. Stop-and-Wait ARQ
// Input:
// plaintext
// Copy code
// Enter the number of frames to send: 3


// 2. Go-Back-N ARQ
// Input:
// plaintext
// Copy code
// Enter the number of frames to send: 5
// Enter the window size: 3

// 3. Selective Repeat ARQ
// Input:
// plaintext
// Copy code
// Enter the number of frames to send: 4
// Enter the window size: 2