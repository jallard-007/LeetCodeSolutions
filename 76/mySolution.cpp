#include <string>

using namespace std;

class Solution {
public:
    int indexOfChar(char c) {
        if (c <= 'Z') {
            return c - 'A';
        }
        return c - 'a' + 26;
    }

    string minWindow(const string& s, const string& t) {
        int charCounts[52] = {0};
        for (char c : t) {
            ++charCounts[indexOfChar(c)];
        }

        int matched = 0;
        for (int count : charCounts) {
            if (count == 0) {
                ++matched;
            }
        }

        int minimumWindowIndex = 0;
        unsigned int minimumWindowSize = 0xFFFFFFFF;

        int i = 0, j = 0;
        while (j < s.size()) {
            const int value = --charCounts[indexOfChar(s[j++])];
            if (value == 0) {
                if (++matched == 52) {
                    while (i < j) {
                        if ((j - i) < minimumWindowSize) {
                            minimumWindowIndex = i;
                            minimumWindowSize = j - i;
                        }
                        if (++charCounts[indexOfChar(s[i++])] == 1) {
                            --matched;
                            break;
                        }
                    }
                }
            }
        }
        if (minimumWindowSize == 0xFFFFFFFF) {
            return "";
        }
        return s.substr(minimumWindowIndex, minimumWindowSize);
    }
};
