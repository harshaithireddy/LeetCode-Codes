class Solution {
public:
    string getHappyString(int n, int k) {
        int total_happy = 3 * (1 << (n - 1));
        if(k > total_happy) return "";

        string res = "";
        int left = 1, right = total_happy;
        string choices = "abc";
        
        for(int i = 0; i < n; i++) {
            int cur = left;
            int partition_size = (right - left + 1) / choices.size();

            for(char c : choices) {
                if(k >= cur && k < cur + partition_size) {
                    res += c;
                    left = cur;
                    right = cur + partition_size - 1;

                    choices = (c == 'a') ? "bc" : (c == 'b' ? "ac" : "ab");
                    break;
                }
                cur += partition_size;
            }
        }
        return res;
    }
};