#include <algorithm>

using namespace std;

//Definition for a binary tree node.
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
    bool balanced = true;
    bool isBalanced(TreeNode* root) {
        helper(root);
        return balanced;
    }

    int helper(TreeNode* root) {
        if (!root || balanced == false) {
            return 0;
        }
        int l = helper(root->left) + 1;
        int r = helper(root->right) + 1;
        if (l - r > 1 || r - l > 1) {
            balanced = false;
        }
        return max(l, r);
    }
};
