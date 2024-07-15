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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_map<int, bool> hasParent;
        for(auto it : descriptions) {
            int p = it[0];
            int c = it[1];
            int left = it[2];

            TreeNode* x = NULL;
            TreeNode* y = NULL;

            if(mpp.find(p) == mpp.end()) x = new TreeNode(p);
            else x = mpp[p];

            if(mpp.find(c) == mpp.end()) y = new TreeNode(c);
            else y = mpp[c];

            if(left == 1) x->left = y;
            else x->right = y;
            
            hasParent[c] = true;
            mpp[c] = y;
            mpp[p] = x;
        }

        TreeNode* root = NULL;
        for(auto it : mpp) {
            if(!hasParent[it.first]) root = it.second;
        }
        return root;
    }
};