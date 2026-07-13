// Last updated: 13/07/2026, 22:16:26
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        preOrderTrav(root, result);
        return result;
    }
    void preOrderTrav(Node* root, vector<int>& order){
        if (root == nullptr) return;
        order.push_back(root->val);

        for (Node* node : root->children){
            preOrderTrav(node, order);
        }
    }
};