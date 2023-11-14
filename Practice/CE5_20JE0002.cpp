#include <iostream>
#include <string>

using namespace std;

const int TOTAL_ELEMENTS = 11;
string key[TOTAL_ELEMENTS];
string dob[TOTAL_ELEMENTS];

void initialize() {
    for (int i = 0; i < TOTAL_ELEMENTS; ++i) {
        key[i] = "0";
        dob[i] = "0";
    }
}

int myhash(string keystring) {
    int sum = 0;
    for (char ch : keystring) {
        sum += static_cast<int>(ch);
    }
    return sum % TOTAL_ELEMENTS;
}

void insert(int i, string keystring, string d) {
    while (key[i] != "0") {
        // Resolve collisions using open addressing
        i = (i + 1) % TOTAL_ELEMENTS;
    }
    key[i] = keystring;
    dob[i] = d;
}

void print() {
    cout << "Index\tKey\tDOB" << endl;
    for (int i = 0; i < TOTAL_ELEMENTS; ++i) {
        cout << i << "\t" << key[i] << "\t" << dob[i] << endl;
    }
}

int main() {
    initialize();

    for(int i=0;i<11;i++){
        string userKey, userDob;
        cout << "Enter key: ";
        cin >> userKey;
        cout << "Enter DOB: ";
        cin >> userDob;
        insert(myhash(userKey), userKey, userDob);
    }

    print();

    return 0;
}