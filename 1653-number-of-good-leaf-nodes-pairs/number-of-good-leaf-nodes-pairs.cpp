/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    vector<int> dfs(TreeNode* root, int& distance) {
        if(root == NULL) return {0};
        if(root->left == NULL && root->right == NULL) return {1};

        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);

        for(auto x : left) {
            for(auto y : right) {
                if(x > 0 && y > 0 && x + y <= distance) res++;
            }
        }

        vector<int> V;
        for(auto it : left) {
            if(it > 0 && it < distance) V.push_back(it + 1);
        }
        for(auto it : right) {
            if(it > 0 && it < distance) V.push_back(it + 1);
        }
        return V;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);

        return res;
    }
};