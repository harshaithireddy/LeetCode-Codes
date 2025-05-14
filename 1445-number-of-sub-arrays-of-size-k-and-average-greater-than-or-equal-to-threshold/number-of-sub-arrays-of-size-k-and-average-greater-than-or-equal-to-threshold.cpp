class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size() < k) return 0;

        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if(sum >= threshold * k) cnt++;

        for(int i = k; i < arr.size(); i++) {
            sum -= arr[i-k];
            sum += arr[i];

            if(sum >= threshold * k) cnt++;
        }
        return cnt;
    }
};