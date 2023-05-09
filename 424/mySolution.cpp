#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string& s, int k) {
        int letters[26] = {0};
        int answer = 1;
        int maxCount = 1;
        for (int i = 0, j = 0; i < s.size(); ++j) {
            maxCount = max(++letters[s[j] - 'A'], maxCount);
            if (j - i + 1 - maxCount > k) {
                --letters[s[i++] - 'A'];
            }
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};
