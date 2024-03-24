class Solution {
private:
    void Combinations(vector<int>& candidates, int index, int target,
                      vector<int>& V, vector<vector<int>>& ans) {
        ios_base::sync_with_stdio(false);
        if(target == 0) {
            ans.push_back(V);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            V.push_back(candidates[i]);
            Combinations(candidates, i+1, target-candidates[i], V, ans);
            V.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> V;
        vector<vector<int>> ans;
        Combinations(candidates, 0, target, V, ans);

        return ans;
    }
};