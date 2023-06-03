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
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return -1;
        }
        vector<TreeNode*> stack;
        stack.reserve(20);
        TreeNode *curr = root;
        while (curr) {
            stack.emplace_back(curr);
            curr = curr->left;
        }
        int count = 0;
        while (!stack.empty()) {
            curr = stack.back();
            stack.pop_back();
            ++count;
            if (count == k) {
                return curr->val;
            }
            curr = curr->right;
            if (curr) {
                stack.emplace_back(curr);
                curr = curr->left;
                while (curr) {
                    stack.emplace_back(curr);
                    curr = curr->left;
                }
            }
        }
        return -1;
    }
};

class Solution1 {
public:
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k)->val;
    }

    TreeNode* helper(TreeNode* root, int k) {
        if (!root) {
            ++count;
            return nullptr;
        }
        if (TreeNode *node = helper(root->left, k)) {
            return node;
        }
        if (count == k) {
            return root;
        }
        return helper(root->right, k);
    }
};