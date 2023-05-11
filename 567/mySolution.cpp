#include <array>
#include <string>

using namespace std;
class Solution {
public:
    bool checkInclusion(const string& s1, const string& s2) {
        array<int, 26> m = {0};
        const int n = s1.size();
        for (int i = 0; i < n; ++i) {
            ++m[s1[i] - 'a'];
        }
        int i = 0, j = 0; 
        while (j < s2.size()) {
            if (--m[s2[j] - 'a'] == -1) {
                while (i <= j) {
                  ++m[s2[i++] - 'a'];
                  if (m[s2[j] - 'a'] == 0) {
                      break;
                  }
                }
            } else if (j - i == n - 1) {
                return true;
            }
            ++j;
        }

        return false;
    }
};
