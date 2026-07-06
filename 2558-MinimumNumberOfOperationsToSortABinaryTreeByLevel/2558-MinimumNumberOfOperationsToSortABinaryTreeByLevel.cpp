// Last updated: 06/07/2026, 18:56:18
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
private:
    int minSwaps(vector<int>& arr, int& length){
        map<int, int> mp;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        for (int i = 0; i < length; i++){
            mp[temp[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < length; ){
            int ind = mp[arr[i]];
            if (ind == i)
                i++;
            else{
                int temp = arr[i];
                arr[i] = arr[ind];
                arr[ind] = temp;
                ans++;
            }
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int answer = 0;

        while (!q.empty()){
            int size = q.size();
            vector<int> values(size);
            int copy = size;
            int index = 0;
            while (size--){
                TreeNode* cur = q.front();
                q.pop();
                values[index++] = cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            answer += minSwaps(values, copy);
        }
        return answer;
    }
};