#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            const int vol = min(height[left], height[right]) * (right - left);
            if (vol > ans) {
                ans = vol;
            }

            if (height[left] < height[right]) {
                const int h = height[left];
                while(left < right && height[++left] <= h); 
            } else {
                const int h = height[right];
                while(left < right && height[--right] <= h); 
            }
        }
        return ans;
    }
};