#include <vector>
#include <array>
#include <iostream>

using namespace std;



class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        vector<array<int, 2>> stack;
        for (int x = 0; x < rooms.size(); ++x) {
            for (int y = 0; y < rooms[x].size(); ++y) {
                if (rooms[x][y] == 0) {
                    // found a gate, mark distance from this gate if its smaller
                    stack.push_back({x, y});
                    while (!stack.empty()) {
                        int i = stack.back()[0];
                        int j = stack.back()[1];
                        stack.pop_back();
                        int distance = rooms[i][j] + 1;
                        ++i;
                        if (i < rooms.size() && rooms[i][j] > distance) {
                            rooms[i][j] = distance;
                            stack.push_back({i, j});
                        }
                        i -= 2;
                        if (i >= 0 && rooms[i][j] > distance) {
                            rooms[i][j] = distance;
                            stack.push_back({i, j});
                        }
                        ++i;
                        ++j;
                        if (j < rooms[i].size() && rooms[i][j] > distance) {
                            rooms[i][j] = distance;
                            stack.push_back({i, j});
                        }
                        j -=2;
                        if (j >= 0 && rooms[i][j] > distance) {
                            rooms[i][j] = distance;
                            stack.push_back({i, j});
                        }
                    }
                }
            }
        }
    }

};

int main() {
    vector<vector<int>> rooms = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    // expected : 
    /*
        3  -1   0   1
        2   2   1  -1
        1  -1   2  -1
        0  -1   3   4
    */
    Solution s;
    s.wallsAndGates(rooms);
    for (int x = 0; x < rooms.size(); ++x) {
        for (int y = 0; y < rooms[x].size(); ++y) {
            cout << rooms[x][y] << ", ";
        }
        cout << '\n';
    }
}
