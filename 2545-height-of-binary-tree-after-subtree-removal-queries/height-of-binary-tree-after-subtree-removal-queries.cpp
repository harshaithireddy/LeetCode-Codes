auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    map<int, pair<int, int>> nodeInfo;
    map<int, priority_queue<pair<int, int>, vector<pair<int, int>>>> levelMap;

    int computeHeight(TreeNode *root, int currentLevel) {
        if(!root) return 0;
        int leftHeight = 0, rightHeight = 0;
        if(root->left) {
            leftHeight = computeHeight(root->left, currentLevel + 1);
        }
        if(root->right) {
            rightHeight = computeHeight(root->right, currentLevel + 1);
        }
        nodeInfo[root->val] = {max(leftHeight, rightHeight) + 1, currentLevel};
        levelMap[currentLevel].push({max(leftHeight, rightHeight) + 1, root->val});
        return max(leftHeight, rightHeight) + 1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        computeHeight(root, 0);
        vector<int> res;
        for(int q : queries) {
            int level = nodeInfo[q].second;
            int height = nodeInfo[q].first;
            int maxHeight = 0;

            if(levelMap[level].top().second != q) {
                res.push_back(level + levelMap[level].top().first - 1);
            }
            else if(levelMap[level].size() == 1) res.push_back(level - 1);
            else {
                pair<int, int> topNode = levelMap[level].top();
                levelMap[level].pop();
                res.push_back(level + levelMap[level].top().first - 1);
                levelMap[level].push(topNode);
            }
        }
        return res;
    }
};
