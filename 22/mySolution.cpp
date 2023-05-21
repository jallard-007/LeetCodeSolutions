#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stack;
        vector<int> answer;
        answer.resize(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                answer[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return answer;
    }
};
