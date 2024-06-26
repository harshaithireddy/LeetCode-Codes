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
    void inOrder(TreeNode* root, vector<int>& V) {
        if(root == NULL) return;
        inOrder(root->left, V);
        V.push_back(root->val);
        inOrder(root->right, V);
    }

    TreeNode* helper(vector<int>& in, int low, int high) {
        if(low > high) return NULL;

        int mid = (low + high) / 2;
        TreeNode* curr = new TreeNode(in[mid]);
        curr->left = helper(in, low, mid - 1);
        curr->right = helper(in, mid + 1, high);

        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) return NULL;
        vector<int> V;
        inOrder(root, V);

        return helper(V, 0, V.size() - 1);
    }
};