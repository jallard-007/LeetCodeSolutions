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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;
        vector<pair<TreeNode *, int>> stack;
        stack.emplace_back(root, 0);
        while (!stack.empty()) {
            TreeNode *curr = stack.back().first;
            int level = stack.back().second;
            stack.pop_back();
            while (curr) {
                if (level >= levelOrderTraversal.size()) {
                    levelOrderTraversal.emplace_back();
                }
                levelOrderTraversal[level].emplace_back(curr->val);
                ++level;
                if (curr->right) {
                    stack.emplace_back(curr->right, level);
                }
                curr = curr->left;
            }
        }
        return levelOrderTraversal;
    }
};
