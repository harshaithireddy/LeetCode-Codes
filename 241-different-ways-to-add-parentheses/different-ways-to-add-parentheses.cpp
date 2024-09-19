class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for(int i = 0; i < expression.size(); i++) {
            char symbol = expression[i];
            if(symbol == '+' || symbol == '-' || symbol == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));

                for(int x = 0; x < s1.size(); x++) {
                    for(int y = 0; y < s2.size(); y++) {
                        if(symbol == '+') res.push_back(s1[x] + s2[y]);
                        else if(symbol == '-') res.push_back(s1[x] - s2[y]);
                        else if(symbol == '*') res.push_back(s1[x] * s2[y]);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        return res;
    }
};