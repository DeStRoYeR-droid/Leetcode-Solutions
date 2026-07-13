// Last updated: 13/07/2026, 22:16:24
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
    vector<int> postorder(Node* root) {
        vector<int> result;
        postOrderHelper(root, result);
        return result;
    }
    void postOrderHelper(Node* root, vector<int>& values){
        if (root == nullptr) return;
        
        for (const auto& node : root->children){
            postOrderHelper(node, values);
        }
        values.push_back(root->val);
    }
};