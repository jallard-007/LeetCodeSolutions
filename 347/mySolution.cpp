#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto i : nums) {
      m[i]++;
    }
    vector<vector<int>> sort(nums.size() + 1);
    for (auto entry : m) {
      sort[entry.second].push_back(entry.first);
    }
    vector<int> answer;
    for (int i = nums.size(); i >= 0; --i) {
      if (!sort[i].empty()) {
        answer.insert(answer.end(), sort[i].begin(), sort[i].end());
      }
    }
    answer.resize(k);
    return answer;
  }
};
