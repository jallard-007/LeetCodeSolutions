#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        const int n = nums.size() - 1;
        int frontIndex = 0; 
        while (frontIndex < n) {
            int middleIndex = frontIndex + 1;
            int backIndex = n;
            while (middleIndex < backIndex) {
                const int sum = nums[frontIndex] + nums[middleIndex] + nums[backIndex];
                if (sum == 0) {
                    ans.push_back({nums[frontIndex], nums[middleIndex], nums[backIndex]});
                    while (middleIndex < backIndex && nums[backIndex] == nums[--backIndex]);
                } else if (sum < 0) {
                    while (middleIndex < backIndex && nums[middleIndex] == nums[++middleIndex]);
                } else {
                    while (middleIndex < backIndex && nums[backIndex] == nums[--backIndex]);
                }
            }
            while (frontIndex < n && nums[frontIndex] == nums[++frontIndex]);
        }
        return ans;
    }
};
