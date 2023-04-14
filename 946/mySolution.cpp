#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::vector<int> stack;
        const int n = pushed.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
          stack.push_back(pushed[i]);
          while (!stack.empty() && popped[j] == stack.back()) {
            stack.pop_back();
            ++j;
          }
        }
        return j == n;
    }
};
