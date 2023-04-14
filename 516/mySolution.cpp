#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            int diag = 0; // the previous value of dp[i+1][j-1]
            dp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                int tmp = dp[j];
                dp[j] = (s[i] == s[j]) ? diag + 2 : max(dp[j-1], dp[j]);
                diag = tmp;
            }
        }
        return dp[n-1];
    }
};
