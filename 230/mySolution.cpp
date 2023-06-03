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