// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // uses the existing lists to store sum, only potentially one memory allocation on final carry
    // for some reason this is showing up as slower on LeetCode, beast ~20% on time, ~99% on memory
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *root = l1;
        int overflow = 0;
        ListNode *prev = nullptr;
        while (l1 && l2) {
            l1->val += l2->val + overflow;
            if (l1->val > 9) {
                overflow = 1;
                l1->val -= 10;
            } else {
                overflow = 0;
            }
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *extra = nullptr;
        if (l2) {
            extra = l2;
            prev->next = l2;
        } else if (l1) {
            extra = l1;
        }
        while (extra) {
            extra->val += overflow;
            if (extra->val > 9) {
                extra->val -= 10;
                prev = extra;
                extra = extra->next;
            } else {
                overflow = 0;
                break;
            }
        }
        if (overflow) {
            prev->next = new ListNode(1);
        }
        return root;
    }
};
