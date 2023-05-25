#include <unordered_map>

using namespace std;

// Definition for a Node.
struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// three pass solution is better, but coming up with that is insane...
// instead, i simply keep a hashmap of nodes, mapping the original to new
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // create head
        Node *copyHead = new Node(head->val);
        unordered_map<Node *, Node *> mappings;
        mappings[head] = copyHead;
        Node *copyCurr = copyHead;
        Node *curr = head;
        while (1) {

            // create/assign random
            if (curr->random) {
                if (mappings[curr->random]) {
                    copyCurr->random = mappings[curr->random];
                } else {
                    copyCurr->random = new Node(curr->random->val);
                    mappings[curr->random] = copyCurr->random;
                }
            }

            // create/assign next
            curr = curr->next;
            if (curr) {
                Node *copyPrev = copyCurr;
                if (mappings[curr]) {
                    copyCurr = mappings[curr];
                } else {
                    copyCurr = new Node(curr->val);
                    mappings[curr] = copyCurr;
                }
                copyPrev->next = copyCurr;
            } else {
                return copyHead;
            }

        }
        return nullptr;
    }
};