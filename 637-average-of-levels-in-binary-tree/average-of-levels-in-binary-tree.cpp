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
    void LevelOrder(TreeNode* root, vector<double>& res) {
        if(root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            double sum = 0, cnt = 0;
            while(size > 0) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                cnt++;

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                size--;
            }
            double avg = sum / cnt;
            res.push_back(avg);
        }
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        LevelOrder(root, res);

        return res;
    }
};