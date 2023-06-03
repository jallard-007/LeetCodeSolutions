#include <cstdint>

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
    bool isValidBST(TreeNode* root) {
        return inside(root, INT64_MIN, INT64_MAX);
    }

    bool inside(TreeNode *root, int64_t lowest, int64_t highest) {
        if (!root) {
            return true;
        }
        if (root->val >= highest || root->val <= lowest) {
            return false;
        }
        return inside(root->left, lowest, root->val) && inside(root->right, root->val, highest);
    }
};