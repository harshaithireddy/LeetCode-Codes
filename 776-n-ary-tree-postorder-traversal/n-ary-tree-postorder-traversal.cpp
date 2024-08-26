/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solver(Node* root, vector<int>& res) {
        for(int i = 0; i < root->children.size(); i++) {
            solver(root->children[i], res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(root == NULL) return {};

        vector<int> res;
        solver(root, res);

        return res;
    }
};