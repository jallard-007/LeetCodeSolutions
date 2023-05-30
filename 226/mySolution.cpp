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
    TreeNode* invertTree(TreeNode* root) {
        vector<TreeNode *> stack;
        stack.push_back(root);
        while (stack.size() > 0) {
            TreeNode* curr = stack.back();
            stack.pop_back();
            while (curr) {
              // swap left and right nodes
              TreeNode *temp = curr->right;
              curr->right = curr->left;
              curr->left = temp;
              if (curr->right) {
                // push right node on stack
                stack.push_back(curr->right);
              }
              // go to left node
              curr = curr->left;
            }
        }
        return root;
    }
};

#include <alloca.h>

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* temp = nullptr;
        TreeNode* curr = nullptr;
        int memSize = 10;
        int memPos = 0;
        TreeNode** mem = (TreeNode **)alloca(memSize * sizeof (TreeNode *));
        mem[memPos++] = root;
        while (memPos > 0) {
            curr = mem[--memPos];
            while (curr) {
                temp = curr->right;
                curr->right = curr->left;
                curr->left = temp;
                if (curr->right) {
                    // push right node on stack
                    if (memPos == memSize) {
                        // this would work properly if alloca did as i expected
                        // expected: successive alloca calls would "grow" the array
                        // but since the stack grows down, and alloca does not allocate the specified amount of memory, this fails.
                        alloca(memSize * sizeof (TreeNode *));
                        memSize += memSize;
                    }
                    mem[memPos++] = curr->right;
                }
                curr = curr->left;
            }
        }
        return root;
    }
};