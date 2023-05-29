#include <unordered_map>

using namespace std;

struct MyNode {
    int key;
    MyNode *next;
    MyNode *prev;
    MyNode() : key(0), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    MyNode *end;
    MyNode *start;
    MyNode *list;
    int size;
    unordered_map<int, pair<int, MyNode *>> map;
    LRUCache(int capacity) {
        size = capacity;
        list = new MyNode[capacity];
        end = list + capacity - 1;
        start = list;
        int i = 0;
        if (capacity > 1) {
            list->next = list + 1;
        }
        for (i = 1; i < capacity - 1; ++i) {
            list[i].next = list + i + 1;
            list[i].prev = list + i - 1;
        }
        if (i < capacity) {
            list[i].prev = list + i - 1;
        }
    }

    ~LRUCache() {
        delete[] list;
    }

    void updateCache(int key) {
        MyNode *element = map[key].second;
        if (end == element) {
            return;
        }
        if (element->prev == nullptr) {
            // element is at the start of the list
            start = element->next;
            start->prev = nullptr;
        } else {
            // element has nodes on both sides
            element->prev->next = element->next;
            element->next->prev = element->prev;
        }
        // end pointers
        element->next = nullptr;
        element->prev = end;
        end->next = element;
        end = element;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        updateCache(key);
        return map[key].first;
    }
    
    void put(int key, int value) {
        map[key].first = value;
        if (map[key].second == nullptr) {
            if (map.size() > size) {
                map.erase(start->key);
                map[key].second = start;
            } else {
                map[key].second = start;
            }
            start->key = key;
        }
        updateCache(key);
    }
};
