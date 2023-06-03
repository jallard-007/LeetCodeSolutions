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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int answer = 0;
        vector<pair<TreeNode *, int>> stack;
        stack.reserve(20);
        stack.emplace_back(root, -__INT32_MAX__);
        while (!stack.empty()) {
            TreeNode *curr = stack.back().first;
            int greatest = stack.back().second;
            stack.pop_back();
            while (curr) {
                if (curr->val >= greatest) {
                    ++answer;
                    greatest = curr->val;
                }
                if (curr->right) {
                    stack.emplace_back(curr->right, greatest);
                }
                curr = curr->left;
            }
        }
        return answer;
    }
};
