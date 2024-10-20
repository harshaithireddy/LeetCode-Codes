class Solution {
private:
        char fun(vector<char>& V, char op) {
        if(op == '&') {
            for(char c : V) {
                if(c == 'f') return 'f';
            }
            return 't';
        }
        else if(op == '|') {
            for(char c : V) {
                if(c == 't') return 't';
            }
            return 'f';
        }
        else if(op == '!') {
            return (V[0] == 'f') ? 't' : 'f';
        }
        return 'f';
    }
public:
    bool parseBoolExpr(string expression) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> open;
        int n = expression.size();

        for(int i = 1; i < n; i++) {
            if(expression[i] == '(') open.push_back(i);
        }

        for(int i = open.size() - 1; i >= 0; i--) {
            vector<char> V;
            int j = open[i];
            char result;

            while(j < n && expression[j] != ')') {
                if(expression[j] == 'f' || expression[j] == 't') {
                    V.push_back(expression[j]);
                }
                j++;
            }
            if(V.size() == 1) {
                result = (expression[open[i] - 1] == '!') ? (V[0] == 'f' ? 't' : 'f') : V[0];
            }
            else {
                result = fun(V, expression[open[i] - 1]);
            }

            expression.erase(expression.begin() + open[i] - 1, expression.begin() + j + 1);
            expression.insert(expression.begin() + open[i] - 1, result);
        }
        return expression[0] == 't';
    }
};