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
    void Path(TreeNode* root, string s, vector<string>& res) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(s.size() == 0) s += to_string(root->val);
            else {
                s = s + "->" + to_string(root->val);
            }
            res.push_back(s);
            return;
        }
        if(s.size() == 0) s += to_string(root->val);
        else {
            s = s + "->" + to_string(root->val);
        }
        Path(root->left, s, res);
        Path(root->right, s, res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        Path(root, "", res);

        return res;
    }
};