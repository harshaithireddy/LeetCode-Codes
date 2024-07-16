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
    string rootToStart, rootToDest;
    void dfs(TreeNode* node, string& path, int startValue, int destValue) {
        if(node == NULL) return;

        if(node->val == startValue) rootToStart = path;
        if(node->val == destValue) rootToDest = path;

        path.push_back('L');
        dfs(node->left, path, startValue, destValue);
        path.pop_back();

        path.push_back('R');
        dfs(node->right, path, startValue, destValue);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        dfs(root, path, startValue, destValue);

        int i = 0, j = 0;
        int common = 0;
        while(i < rootToStart.size() && j < rootToDest.size()) {
            if(rootToStart[i] == rootToDest[j]) {
                common++;
                i++;
                j++;
            }
            else break;
        }
        rootToStart = rootToStart.substr(common);
        rootToDest = rootToDest.substr(common);

        for(auto &it : rootToStart) it = 'U';

        return rootToStart + rootToDest;
    }
};