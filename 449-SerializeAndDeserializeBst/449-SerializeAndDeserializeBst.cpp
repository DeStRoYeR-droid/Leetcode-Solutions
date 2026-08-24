// Last updated: 24/08/2026, 22:51:28
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if (root == nullptr) return result;
        result += to_string(root->val) + "(" + serialize(root->left) + ")(" + serialize(root->right) + ")";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return helper(data, i);
    }

    TreeNode* helper(string& str, int& i){
        if (i < str.size() && str[i] == '(') ++i;
        if (i >= str.size() || str[i] == ')') return nullptr;

        int num = 0;
        while (isdigit(str[i])){
            num = num * 10 + str[i] - '0';
            ++i;
        }

        TreeNode* root = new TreeNode(num);
        root->left = helper(str, i);
        ++i;
        root->right = helper(str, i);
        ++i;
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;