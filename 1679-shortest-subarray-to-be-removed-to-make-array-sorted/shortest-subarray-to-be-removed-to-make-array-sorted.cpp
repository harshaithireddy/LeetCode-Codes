class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int N = arr.size();
        int res = N;

        int left = 0;
        while(left + 1 < N && arr[left] <= arr[left + 1]) {
            left++;
        }

        if(left == N - 1) return 0;

        int right = N - 1;
        while (right > left && arr[right - 1] <= arr[right]) {
            right--;
        }

        res = min(res, right);
        res = min(res, N - left - 1);

        int i = 0, j = right;
        while(i <= left && j < N) {
            if(arr[i] <= arr[j]) {
                res = min(res, j - i - 1);
                i++;
            }
            else j++;
        }
        return res;
    }
};