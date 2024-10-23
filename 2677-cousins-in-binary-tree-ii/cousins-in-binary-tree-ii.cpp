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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        dfs({root});
        return root;
    }

private:
    void dfs(vector<TreeNode*> nodes) {
        if(nodes.empty()) return;

        int totalSum = 0;
        for(auto node : nodes) {
            if(!node) continue;
            if(node->left) totalSum += node->left->val;
            if(node->right) totalSum += node->right->val;
        }

        vector<TreeNode*> children;
        for(auto node : nodes) {
            int childSum = 0;
            if(node->left) childSum += node->left->val;
            if(node->right) childSum += node->right->val;

            if(node->left) {
                node->left->val = totalSum - childSum;
                children.push_back(node->left);
            }
            if(node->right) {
                node->right->val = totalSum - childSum;
                children.push_back(node->right);
            }
        }
        dfs(children);
    }
};