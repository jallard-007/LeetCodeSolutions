#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> answer(nums.size(), 1);


    int r = 1;
    for (int i = 0; i < nums.size(); ++i) {
      answer[i] = r;
      r *= nums[i];
    }

    int k = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      answer[i] *= k;
      k *= nums[i];
    }

    return answer;
  }
};
