// Last updated: 13/07/2026, 22:21:00
#pragma GCC target("abm")
#pragma GCC target("bmi")
#pragma GCC target("avx2")
#pragma GCC target("bmi2")
#pragma GCC target("lzcnt")
#pragma GCC target("popcnt")
#pragma GCC target("native")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-march=native")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
static const bool __boost = []() {
   cin.tie(nullptr);
   cout.tie(nullptr);
   return std::ios_base::sync_with_stdio(false);
}();

class TrieNode {
    public:
        int index;
        bool end;
        TrieNode* links[26];
        vector<int> palinSuffix;

        TrieNode(){
            index = -1;
            end = false;
            for (int i = 0; i < 26; ++i) links[i] = nullptr;
        }
};

class Trie {
    TrieNode* root;

    bool isPalindrome(string& s, int l, int r){
        while (l < r){
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string& word, int idx){
            TrieNode* node = root;
            for (int i = word.size() - 1; i >= 0; --i){
                if (isPalindrome(word, 0, i)){
                    node->palinSuffix.push_back(idx);
                }

                if (node->links[word[i] - 'a'] == nullptr){
                    node->links[word[i] - 'a'] = new TrieNode();
                }

                node = node->links[word[i] - 'a'];
            }

            node->end = true;
            node->index = idx;

            node->palinSuffix.push_back(idx);
        }

        void search(string& word, int idx, vector<vector<int>>& result){
            TrieNode* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (node->end && node->index != idx && isPalindrome(word, i, word.size() - 1)) {
                    result.push_back({idx, node->index});
                }
                if (!node->links[word[i] - 'a']) return;
                node = node->links[word[i] - 'a'];
            }

            for (int j : node->palinSuffix) {
                if (idx != j) result.push_back({idx, j});
            }
        }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie t;
        for (int i = 0; i < words.size(); i++) {
            t.insert(words[i], i);
        }

        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i){
            t.search(words[i], i, result);
        }
        return result;
    }
};