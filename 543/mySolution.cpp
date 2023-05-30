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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxDiameter;
    }

    int helper(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int l = helper(root->left) + 1;
        int r = helper(root->right) + 1;
        if (r + l > maxDiameter){
            maxDiameter = r + l;
        }
        return max(r, l);
    }
};