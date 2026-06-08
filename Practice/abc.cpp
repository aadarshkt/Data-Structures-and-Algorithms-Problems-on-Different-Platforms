#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int findPossibleSmallestNumberMatchingPattern(std::string pattern) {
    if (pattern.empty()) {
        return -1;
    }
    if (pattern.length() > 8) {
        return -1;
    }

    for (char c : pattern) {
        if (c != 'M' && c != 'N') {
            return -1;
        }
    }
    std::string result_str = "";
    std::stack<int> s;
    int n = pattern.length();
    for (int i = 0; i <= n; ++i) {
        s.push(i + 1);
        if (i == n || pattern[i] == 'N') {
            while (!s.empty()) {
                result_str += std::to_string(s.top());
                s.pop();
            }
        }
    }
    try {
        if (result_str.empty()) { 
            return -1; // Should not happen with valid non-empty patterns
        }
        return std::stoi(result_str);
    } catch (const std::out_of_range& oor) {
        return -1; 
    } catch (const std::invalid_argument& ia) {
        return -1;
    }
}