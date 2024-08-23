class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string fractionAddition(string expression) {
        int n = expression.size();
        vector<string> fractions;
        int i = 0;

        while(i < n) {
            int start = i;
            if(expression[i] == '+' || expression[i] == '-') i++;
            while(i < n && expression[i] != '+' && expression[i] != '-') i++;
            fractions.push_back(expression.substr(start, i - start));
        }

        int totalNum = 0, totalDen = 1;
        
        for(auto frac : fractions) {
            int slashPos = frac.find('/');
            int num = stoi(frac.substr(0, slashPos));
            int den = stoi(frac.substr(slashPos + 1));
            
            totalNum = totalNum * den + num * totalDen;
            totalDen = totalDen * den;
            
            int divisor = gcd(abs(totalNum), totalDen);
            totalNum /= divisor;
            totalDen /= divisor;
        }
        
        return to_string(totalNum) + "/" + to_string(totalDen);
    }
};
