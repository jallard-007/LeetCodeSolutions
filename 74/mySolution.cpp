#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix[0].size();
        int first = 0;
        int last = matrix.size() * matrix[0].size() - 1;
        int middle;
        while (first <= last) {
            middle = (first + last) / 2;
            const int val = matrix[middle / n][middle % n];
            if (val == target) {
                return true;
            } else if (val > target) {
                last = middle - 1;
            } else {
                first = middle + 1;
            }
        }
        return false;
    }
};