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
    void LevelOrder(TreeNode* root, vector<vector<int>>& ans) {
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> v;

            while(size > 0) {
                TreeNode* node = q.front();
                v.push_back(node->val);
                q.pop();

                if(node->left != NULL)
                    q.push(node->left);

                if(node->right != NULL)
                    q.push(node->right);

                size--;
            }

            ans.push_back(v);
        }
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> ans;
        LevelOrder(root, ans);

        for(int i = 0; i < ans.size(); i++) {
            if(i % 2 == 0) {
                vector<int> x = ans[i];
                int prev = -1;
                for(auto it : x) {
                    if(it % 2 != 1 || it <= prev) return false;
                    prev = it;
                }
            }
            else {
                vector<int> x = ans[i];
                int prev = INT_MAX;
                for(auto it : x) {
                    if(it % 2 != 0 || it >= prev) return false;
                    prev = it;
                }
            }
        }
        
        return true;
    }
};