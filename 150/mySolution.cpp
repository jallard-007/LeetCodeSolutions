#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> calculationStack;
        for (const string& token: tokens) {
            if (token.size() > 1 || token[0] >= '0' && token[0] <= '9') {
                calculationStack.push_back(stoi(token));
            } else {
                int operandIndex = calculationStack.size() - 1;
                int result;
                if (token == "+") {
                    result = calculationStack[operandIndex - 1] + calculationStack[operandIndex];
                } else if (token == "-") {
                    result = calculationStack[operandIndex - 1] - calculationStack[operandIndex];

                } else if (token == "*") {
                    result = calculationStack[operandIndex - 1] * calculationStack[operandIndex];
                } else /* division */ {
                    result = calculationStack[operandIndex - 1] / calculationStack[operandIndex];
                }
                calculationStack.pop_back();
                calculationStack.back() = result;
            }
        }
        return calculationStack.back();
    }
};
