class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(supplies.begin(), supplies.end());

        vector<string> res;
        bool flag = true;

        while(flag) {
            flag = false;
            for(int i = 0; i < recipes.size(); i++) {
                if (st.count(recipes[i])) continue;

                bool contain = true;
                for(auto it : ingredients[i]) {
                    if(!st.count(it)) {
                        contain = false;
                        break;
                    }
                }

                if(contain) {
                    st.insert(recipes[i]);
                    res.push_back(recipes[i]);
                    flag = true;
                }
            }
        }
        return res;
    }
};
