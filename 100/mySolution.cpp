#include <stack>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            if (p || q) {
                return false;
            }
            return true;
        }
        stack<TreeNode *> stackP;
        stackP.push(p);
        stack<TreeNode *> stackQ;
        stackQ.push(q);
        while (!stackP.empty() && !stackQ.empty()) {
            p = stackP.top();
            stackP.pop();
            q = stackQ.top();
            stackQ.pop();
            while (p && q) {
                if (p->val != q->val) {
                    return false;
                }
                if (p->right || q->right) {
                    if (!p->right || !q->right) {
                        return false;
                    }
                    stackP.push(p->right);
                    stackQ.push(q->right);
                }
                p = p->left;
                q = q->left;
            }
            if (p || q) {
                return false;
            }
        }
        return stackP.empty() && stackQ.empty() && !p && !q;
    }
};