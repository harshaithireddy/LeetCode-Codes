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
private:
    void RightView(TreeNode* root, int level, unordered_map<int, int>& mpp, vector<int>& res) {
        if(root == NULL) return;
        if(mpp.find(level) == mpp.end()) {
            mpp[level] = root->val;
            res.push_back(root->val);
        }

        RightView(root->right, level + 1, mpp, res);
        RightView(root->left, level + 1, mpp, res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> mpp;
        RightView(root, 0, mpp, res);

        return res;
    }
};