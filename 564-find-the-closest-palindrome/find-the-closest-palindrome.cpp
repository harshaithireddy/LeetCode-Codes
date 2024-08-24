class Solution {
private:
    long long generatePalindrome(long long leftHalf, bool isEvenLength) {
        long long palindrome = leftHalf;
        if(!isEvenLength) leftHalf /= 10;
        while(leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }

public:
    string nearestPalindromic(string numberStr) {
        long long number = stoll(numberStr);
        
        if(number <= 10) return to_string(number - 1);
        if(number == 11) return "9";
        
        if(numberStr == "999999999999999999") return "1000000000000000001";
        
        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        
        vector<long long> palindromes(5);
        palindromes[0] = generatePalindrome(leftHalf - 1, length % 2 == 0);
        palindromes[1] = generatePalindrome(leftHalf, length % 2 == 0);
        
        if(leftHalf < 999999999) {
            palindromes[2] = generatePalindrome(leftHalf + 1, length % 2 == 0);
        }
        else {
            palindromes[2] = stoll("1" + string(length - 1, '0') + "1");
        }
        
        palindromes[3] = pow(10, length - 1) - 1;
        palindromes[4] = pow(10, length) + 1;
        
        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;
        
        for(long long it : palindromes) {
            if(it == number) continue;
            long long difference = abs(it - number);
            if(difference < minDifference || (difference == minDifference && it < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = it;
            }
        }
        
        return to_string(nearestPalindrome);
    }
};

