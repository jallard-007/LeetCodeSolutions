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
    // uses O(1) extra space
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        for (int i = 0; i < n; ++i) {
            curr = curr->next;
        }
        if (!curr) {
            return head->next;
        }
        ListNode *nNodesBack = head;
        while (curr->next) {
            curr = curr->next;
            nNodesBack = nNodesBack->next;
        }
        nNodesBack->next = nNodesBack->next->next;
        return head;
    }
}

#include <vector>

class Solution2 {
public:
    // uses O(n) extra space
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head;
        vector<ListNode *> nodes{};
        nodes.reserve(30);
        while (curr) {
            nodes.emplace_back(curr);
            curr = curr->next;
        };
        if (nodes.size() - n == 0) {
            return head->next;
        }
        curr = nodes[nodes.size() - n - 1];
        curr->next = curr->next->next;
        return head;
    }
};