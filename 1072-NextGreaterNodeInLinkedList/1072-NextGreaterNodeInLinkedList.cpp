// Last updated: 06/07/2026, 19:06:16
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            values.push_back(cur->val);
        }

        vector<int> result(values.size(), 0);

        stack<int> st;
        for (int i = 0; i < values.size(); ++i) {
            while (!st.empty() && values[i] > values[st.top()]) {
                result[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};