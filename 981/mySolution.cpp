#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;
    TimeMap() = default;
    
    void set(const string& key, const string& value, const int timestamp) {
        map[key].emplace_back(value, timestamp);
    }
    
    string get(const string& key, const int timestamp) {
        const auto &keyVector = map[key];
        if (keyVector.empty() || keyVector[0].second > timestamp) {
            return "";
        }
        int first = 0, last = keyVector.size() - 1;
        while (first < last) {
            const int middle = (first + last) / 2;
            if (keyVector[middle].second == timestamp) {
                return keyVector[middle].first;
            }
            if (keyVector[middle].second > timestamp) {
                last = middle - 1;
            } else {
                first = middle + 1;
            }
        }
        if (keyVector[first].second > timestamp) {
            return keyVector[first - 1].first;
        }
        return keyVector[first].first;
    }
};
