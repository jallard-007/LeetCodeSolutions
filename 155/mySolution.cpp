#include <vector>

using namespace std;

class MinStack {
public:
    vector<pair<int, int>> stack;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if (val < min) {
            min = val;
        }
        stack.emplace_back(val, min);
    }
    
    void pop() {
        stack.pop_back();
        if (!stack.empty()) {
            min = stack.back().second;
        } else {
            min = INT_MAX;
        }
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return min;
    }
};
