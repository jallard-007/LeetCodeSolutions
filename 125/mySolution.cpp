#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string &s) {
        const int toLower = 'a' - 'A';
        for (char *beg = s.data(), *rev = s.data() + s.length() - 1; beg < rev; ++beg) {
            if (*beg >= 'A' && *beg <= 'Z') {
                *beg -= toLower;
            } else if (*beg < 'a' || *beg > 'z') {
                ++beg;
                continue;
            }

            if (*rev >= 'A' && *rev <= 'Z') {
                *rev -= toLower;
            } else if (*rev < 'a' || *rev > 'z') {
                --rev;
                continue;
            }

            if (*beg != *rev) {
                return false;
            }
            ++beg;
            --rev;
        }
        return true;
    }
};
