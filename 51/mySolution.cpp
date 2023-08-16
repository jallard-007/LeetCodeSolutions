#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr;
        vector<vector<int>> pos;
        pos.resize(n);
        for (int i = 0; i < n; ++i) {
            pos[i].resize(n);
            curr.emplace_back(n, '.');
        }
        h(0, n, ans, curr, pos);
        return ans;
    }

    void h(int i, int n, vector<vector<string>>& ans, vector<string>& curr, vector<vector<int>>& pos) {
    if (i == n) {
        ans.emplace_back(curr);
        return;
    }

    for (int j = 0; j < n; ++j)
        if (pos[i][j] == 0) {
            // mark positions that this queen is attacking
            for (int x = 0; x < n; ++x) {
                ++pos[x][j]; // vertical
                // dont need to mark along same line
            }
            // diagonals down, dont need to go up
            for (int x = i + 1, y = j + 1; x < n && y < n; ++x, ++y) {
                ++pos[x][y];
            }
            for (int x = i + 1, y = j - 1; x < n && y >= 0; ++x, --y) {
                ++pos[x][y];
            }

            curr[i][j] = 'Q';
            h(i + 1, n, ans, curr, pos);
            curr[i][j] = '.';

            // unmark positions
            for (int x = 0; x < n; ++x) {
                --pos[x][j];
            }
            for (int x = i + 1, y = j + 1; x < n && y < n; ++x, ++y) {
                --pos[x][y];
            }
            for (int x = i + 1, y = j - 1; x < n && y >= 0; ++x, --y) {
                --pos[x][y];
            }

        }
    }
};