class Solution {
public:
    string countOfAtoms(string formula) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = formula.size();
        int i, j, k;
        
        vector<int> mulFactor(n, 1);
        int mul = 1;
        stack<int> st;

        for(i = n-1; i >= 0; i--) {
            char c = formula[i];
            if(c == ')') {
                string num = "";
                for(j = i+1; j < n; j++) {
                    c = formula[j];
                    if(!isdigit(c)) break;
                    num += c;
                }

                int digit = (num == "") ? 1 : stoi(num);
                mul = mul * digit;
                st.push(digit);
            }
            else if(c == '(') {
                int digit = st.top();
                st.pop();
                mul = mul / digit;
            }
            mulFactor[i] = mul;
        }

        map<string, int> mpp;
        for(int i = 0; i < n; i++) {
            char c = formula[i];
            if(isupper(c)) {
                string ele = "";
                ele += c;

                for(j = i+1; j < n; j++) {
                    c = formula[j];
                    if(!islower(c)) break;
                    ele += c;
                }

                string num = "";
                for(k = j; k < n; k++) {
                    c = formula[k];
                    if(!isdigit(c)) break;
                    num += c;
                }
                int dig = (num == "") ? 1 : stoi(num);

                mpp[ele] += mulFactor[i] * dig;
                i = k - 1;
            }
        }

        string res = "";
        for(auto it : mpp) {
            res += it.first;
            if(it.second > 1) res += to_string(it.second);
        }
        return res;
    }
};
