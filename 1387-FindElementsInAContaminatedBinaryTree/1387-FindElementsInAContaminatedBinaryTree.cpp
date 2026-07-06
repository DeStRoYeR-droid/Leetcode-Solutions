// Last updated: 06/07/2026, 19:04:42
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
class FindElements {
private:
    unordered_map<int, bool> mp;
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        fix(root, 0);
        mp[0] = true;
    }

    void fix(TreeNode* head, int val){
        if (head->left != nullptr){
            head->left->val = 2 * val + 1;
            mp[head->left->val] = true;
            fix(head->left, head->left->val);
        }
        if (head->right != nullptr){
            head->right->val = 2 * val + 2;
            mp[head->right->val] = true;
            fix(head->right, head->right->val);
        }
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */