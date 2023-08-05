#include <iostream>
using namespace std;

//txRx=0 represents transmitter
//txRx=1 represents receiver

// Function prototypes
void application(string &str, int ssize, bool txRx);
void transport(string &str, int ssize, bool txRx);
void network(string &str, int ssize, bool txRx);
void datalink(string &str, int ssize, bool txRx);

void datalink(string &str, int ssize, bool txRx) {
    if (!txRx) {
        str = "AB" + str; // now called frame
        cout << "Bytes in TX at datalink layer is: " << str << '\n';

        // datalink of other system
        txRx = 1;
        ssize=str.size();
        str = str.substr(2, ssize - 2);
        cout << "Bytes in RX at datalink layer is: " << str << '\n';
        network(str, (int)str.size(), txRx);
    }
}
void network(string &str, int ssize, bool txRx) {
    if (!txRx) {
        str = "CD" + str; // now called packet.
        cout << "Bytes in TX at network layer is: " << str << '\n';
        datalink(str, (int)str.size(), txRx);
    } else {
        str = str.substr(2, ssize - 2);
        cout << "Bytes in RX at network layer is: " << str << '\n';
        transport(str, (int)str.size(), txRx);
    }
}
void transport(string &str, int ssize, bool txRx) {
    if (!txRx) {
        str = "EF" + str; // now called segment
        cout << "Bytes in TX at transport layer is: " << str << '\n';
        network(str, (int)str.size(), txRx);
    } else {
        str = str.substr(2, ssize - 2);
        cout << "Bytes in RX at transport layer is: " << str << '\n';
        application(str, (int)str.size(), txRx);
    }
}

void application(string &str, int ssize, bool txRx) {
    if (!txRx) {
        cout << "Bytes in TX at application layer is: " << str << '\n';
        transport(str, (int)str.size(), txRx);
    } else {
        cout << "Final received message: " << str << '\n';
    }
}

int main() {
    string message;
    cout<<"Enter the message at application layer:";
    cin >> message;
    application(message, (int)message.size(), 0);
    return 0;
}
