// Last updated: 13/07/2026, 22:19:51
struct Node {
    Node* links[2] = {NULL};

    Node* get(int a) { return links[a]; }

    void put(int a, Node* node) { links[a] = node; }

    bool contain(int a) { return links[a] != NULL; }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(int a) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int currBit = (a >> i) & 1;
            if (!node->contain(currBit)) {
                node->put(currBit, new Node());
            }
            node = node->get(currBit);
        }
    }

    int search(int a) {
        Node* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int currBit = (a >> i) & 1;
            if (node->contain(1 - currBit)) {
                ans = ans | (1 << i);
                node = node->get(1 - currBit);
            } else
                node = node->get(currBit);
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        Trie t;
        for (const auto& num : nums) t.insert(num);

        for (const auto& num : nums){
            result = max(result, t.search(num));
        }
        return result;
    }
};