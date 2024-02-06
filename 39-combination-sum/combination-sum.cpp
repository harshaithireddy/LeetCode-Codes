class Solution {
private:
    void Combinations(vector<int>& candidates, int index, int target, int size, vector<int>& V, vector<vector<int>>& ans, int sum) {
        if(sum > target || index >= size) {
            return;
        }
        else if(sum == target) {
            ans.push_back(V);
            return;
        }

        V.push_back(candidates[index]);
        Combinations(candidates, index, target, size, V, ans, sum + candidates[index]);
        V.pop_back();
        Combinations(candidates, index + 1, target, size, V, ans, sum);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> V;
        vector<vector<int>> ans;
        Combinations(candidates, 0, target, candidates.size(), V, ans, 0);
        return ans;
    }
};