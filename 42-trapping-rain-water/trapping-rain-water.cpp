class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        int leftMax = 0, rightMax = 0, res = 0;

        while(i <= j) {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);

            if(leftMax < rightMax) {
                res += (leftMax - height[i]);
                i++;
            }
            else {
                res += (rightMax - height[j]);
                j--;
            }
        }
        return res;
    }
};