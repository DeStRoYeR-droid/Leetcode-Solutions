// Last updated: 13/07/2026, 22:16:34
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<Node*> bfs;
        bfs.push(root);

        while (!bfs.empty()){
            int s = bfs.size();
            vector<int> row;
            row.reserve(s);
            
            while (s--){
                Node* cur = bfs.front(); bfs.pop();
                row.push_back(cur->val);
                for (const auto& node : cur->children) bfs.push(node);
            }

            result.push_back(row);
        }
        return result;
    }
};