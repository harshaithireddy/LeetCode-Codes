class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        vector<bool> isPrime(1001, true);
        isPrime[0] = isPrime[1] = false;
        
        for(int i = 2; i <= 1000; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
                for(int j = i * i; j <= 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int prev = 0;
        for(int i = 0; i < nums.size(); i++) {
            bool flag = false;
            
            for(int j = primes.size() - 1; j >= 0; j--) {
                int prime = primes[j];
                if(prime < nums[i] && nums[i] - prime > prev) {
                    nums[i] -= prime;
                    prev = nums[i];
                    flag = true;
                    break;
                }
            }
            
            if(!flag && nums[i] <= prev) {
                return false;
            }
            prev = nums[i];
        }
        return true;
    }
};
