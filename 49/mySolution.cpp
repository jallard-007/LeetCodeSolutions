#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> groups;
    for (auto &str : strs) {
      string s = str;
      std::sort(s.begin(), s.end());
      groups[s].push_back(std::move(str));
    }
    for (auto &group : groups) {
      result.push_back(std::move(group.second));
    }
    return result;
  }
};
