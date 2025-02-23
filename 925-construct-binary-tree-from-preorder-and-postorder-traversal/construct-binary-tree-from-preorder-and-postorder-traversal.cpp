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
    TreeNode* solver(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& mpp, int i1, int i2, int j1, int j2) {
        if(i1 > i2) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[i1]);
        if(i1 == i2) return root;
        
        int left_val = preorder[i1 + 1];
        int mid = mpp[left_val];
        int leftSize = mid - j1 + 1;
        
        root->left = solver(preorder, postorder, mpp, i1 + 1, i1 + leftSize, j1, mid);
        root->right = solver(preorder, postorder, mpp, i1 + leftSize + 1, i2, mid + 1, j2 - 1);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int N = postorder.size();
        
        for(int i = 0; i < N; ++i) {
            mpp[postorder[i]] = i;
        }
        return solver(preorder, postorder, mpp, 0, N - 1, 0, N - 1);
    }    
};