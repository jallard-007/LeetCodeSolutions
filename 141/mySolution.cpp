
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *slow = head->next;
        if (!slow) {
            return false;
        }
        ListNode *fast = head->next->next;
        while (slow && fast) {
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

#include <unordered_map>
using namespace std;

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, bool> marked;
        ListNode *curr = head;
        while (curr) {
            if (marked[curr]) {
                return true;
            }
            marked[curr] = true;
            curr = curr->next;
        }
        return false;
    }
};