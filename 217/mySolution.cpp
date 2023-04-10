#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(nums[i]) == map.end()) {
        map.emplace(nums[i], false);
      } else {
        return true;
      }
    }
    return false;
  }
};
