// Last updated: 06/07/2026, 18:53:42
struct TrieNode{
    unordered_map<int, TrieNode*> next;
    int count = 0;
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        long long result = 0;
        for (const string& w : words){
            TrieNode* x = root;
            for (int i = 0, n = w.size(); i < n; ++i){
                x = x->next.insert({w[i] * 128 + w[n - 1 - i], new TrieNode()}).first->second;
                result += x->count;
            }
            x->count++;
        }

        return result;
    }
};