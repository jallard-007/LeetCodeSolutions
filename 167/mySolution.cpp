#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, const int target) {
        for (int large = numbers.size() - 1, small = 0; small < large;) {
            if (numbers[small] + numbers[large] == target) {
                return {small + 1, large + 1};
            } else if (numbers[small] + numbers[large] < target) {
                ++small;
            } else {
                --large;
            }
        }
        return {0, 0};
    }
};
