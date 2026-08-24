// Last updated: 24/08/2026, 22:39:51
struct Node{
    char left; 
    char right; 
    int length;
    int prefix; 
    int suffix; 
    int best;
};

class Solution {
    vector<Node> tree;
    Node mergeNodes(const Node& left, const Node& right){
        Node result;

        result.left = left.left;
        result.right = right.right;
        result.length = left.length + right.length;
        
        result.prefix = left.prefix;
        result.suffix = right.suffix;
        result.best = max(left.best, right.best);
        if (left.right == right.left){
            if (left.prefix == left.length) result.prefix = left.length + right.prefix;
            if (right.suffix == right.length) result.suffix = left.suffix + right.length;
            
            result.best = max(result.best, left.suffix + right.prefix);
        }

        return result;
    }
    
    void build(int node, int start, int end, const string& s){
        if (start == end){
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }

        int mid = start + (end - start) / 2;
        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);

        tree[node] = mergeNodes(
            tree[node * 2], tree[node * 2 + 1]
        );
    }
    
    void update(int node, int start, int end, int index, char ch){
        if (start == end){
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = start + (end - start) / 2;
        if (index <= mid) update(node * 2, start, mid, index, ch);
        else update(node * 2 + 1, mid + 1, end, index, ch);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int m = queryIndices.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        vector<int> result(m);
        
        for (int i = 0; i < m; ++i){
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree[1].best;
        }

        return result;
    }
};