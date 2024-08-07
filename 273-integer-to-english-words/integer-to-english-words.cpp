class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> lessThanTwenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tenPlaces = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        auto twoDigit = [&](int number) {
            if (number < 20) return lessThanTwenty[number];
            else {
                int tens = number / 10;
                int ones = number % 10;
                return tenPlaces[tens] + (ones == 0 ? "" : " " + lessThanTwenty[ones]);
            }
        };

        auto threeDigit = [&](int number) {
            if (number == 0) return string("");
            if (number < 100) return twoDigit(number);
            return lessThanTwenty[number / 100] + " Hundred" + (number % 100 == 0 ? "" : " " + twoDigit(number % 100));
        };

        int billions = num / 1000000000;
        int millions = (num / 1000000) % 1000;
        int thousands = (num / 1000) % 1000;
        int hundreds = num % 1000;

        string result;
        if(billions) result += threeDigit(billions) + " Billion";
        if(millions) result += (result.empty() ? "" : " ") + threeDigit(millions) + " Million";
        if(thousands) result += (result.empty() ? "" : " ") + threeDigit(thousands) + " Thousand";
        if(hundreds) result += (result.empty() ? "" : " ") + threeDigit(hundreds);

        return result;
    }
};
