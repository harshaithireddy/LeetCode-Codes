class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int fives = 0;
        int tens = 0;
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                fives++;
                continue;
            }
            else if(bills[i] == 10) {
                if(fives < 1) return false;
                fives--;
                tens++;
            }
            else {
                if(tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                }
                else if(fives >= 3) fives -= 3; 
                else return false;
            }
        }
        return true;
    }
};