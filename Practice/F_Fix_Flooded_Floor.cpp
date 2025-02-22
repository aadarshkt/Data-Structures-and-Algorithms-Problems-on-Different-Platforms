#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        string s0, s1;
        cin >> s0 >> s1;
        
        int count = 0;
        for (char c : s0) if (c == '.') count++;
        for (char c : s1) if (c == '.') count++;
        if (count % 2 != 0) {
            cout << "None\n";
            continue;
        }
        
        bool possible = true;
        bool multiple = false;
        int i = 0;
        while (i < n) {
            if (s0[i] == '.' && s1[i] == '.') {
                // Check if next column is also all dots for 2x2 block
                if (i+1 < n && s0[i+1] == '.' && s1[i+1] == '.') {
                    multiple = true;
                    i += 2;
                } else {
                    i += 1;
                }
            } else {
                if (s0[i] == '.' || s1[i] == '.') {
                    if (s0[i] == '.' && s1[i] == '#') {
                        if (i+1 >= n || s0[i+1] != '.' || s1[i+1] != '#') {
                            possible = false;
                            break;
                        }
                        i += 2;
                    } else if (s1[i] == '.' && s0[i] == '#') {
                        if (i+1 >= n || s1[i+1] != '.' || s0[i+1] != '#') {
                            possible = false;
                            break;
                        }
                        i += 2;
                    } else {
                        possible = false;
                        break;
                    }
                } else {
                    i += 1;
                }
            }
        }
        
        if (!possible) {
            cout << "None\n";
        } else if (multiple) {
            cout << "Multiple\n";
        } else {
            cout << "Unique\n";
        }
    }
    
    return 0;
}