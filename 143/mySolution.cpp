#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
// not the best solution, but it works
    void reorderList(ListNode* head) {
        ListNode *curr = head;
        vector<ListNode *> nodes;
        while (curr) {
            nodes.emplace_back(curr);
            curr = curr->next;
        }
        curr = head;
        int i = 0;
        int j = nodes.size() - 1;
        while (i < j) {
            nodes[i]->next = nodes[j];
            ++i;
            if (i == j) {
                break;;
            }
            nodes[j]->next = nodes[i];
            --j;
        }
        nodes[i]->next = nullptr;
    }
};
