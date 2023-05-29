using namespace std;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k - 1; ++i) {
            if (!curr) {
                return head;
            }
            curr = curr->next;
        }
        ListNode* next = curr->next;
        curr->next = nullptr;
        ListNode* const newHead = reverseList(head);
        head->next = next;
        curr = next;
        while (curr) {
            for (int i = 0; i < k - 1; ++i) {
                if (!curr) {
                    return newHead;
                }
                curr = curr->next;
            }
            if (!curr) {
                return newHead;
            }
            next = curr->next;
            curr->next = nullptr;
            ListNode* temp = head;
            head = head->next;
            temp->next = reverseList(head);
            head->next = next;
            curr = next;
        }

        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};