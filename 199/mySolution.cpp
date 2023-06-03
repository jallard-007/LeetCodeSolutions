#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if (!root) {
            return answer;
        }
        vector<pair<TreeNode *, int>> stack;
        stack.emplace_back(root, 0);
        while (!stack.empty()) {
            TreeNode *curr = stack.back().first;
            int level = stack.back().second;
            stack.pop_back();
            while (curr) {
                if (level >= answer.size()) {
                    answer.emplace_back(curr->val);
                }
                ++level;
                if (curr->left) {
                    stack.emplace_back(curr->left, level);
                }
                curr = curr->right;
            }
        }
        return answer;
    }
};
