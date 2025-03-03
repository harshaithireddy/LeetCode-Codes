class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int left = 0, right = n-1;

        vector<int> res(n);

        for(int i = 0, j = n-1; i < n; i++, j--) {
            if(nums[i] < pivot) res[left++] = nums[i];
            if(nums[j] > pivot) res[right--] = nums[j];
        }

        while(left <= right) res[left++] = pivot;

        return res;
    }
};