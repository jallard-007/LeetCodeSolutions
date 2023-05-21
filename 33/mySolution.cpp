#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            if ((nums[middle] > target && 
              (nums[left] <= target || nums[left] > nums[middle])) ||
              ((nums[middle] < target) &&
              (nums[right] < target) && nums[right] > nums[middle])
            ) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return -1;
    }
};