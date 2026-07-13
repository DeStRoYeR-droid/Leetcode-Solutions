// Last updated: 13/07/2026, 22:16:27
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
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int maxHeight = 1;
        for (const auto& node : root->children) maxHeight = max(maxHeight, maxDepth(node) + 1);
        return maxHeight;
    }
};