// Last updated: 13/07/2026, 22:19:28
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (const char& ch : s) mp[ch]++;
        priority_queue<pair<int, char>> pq;
        
        for (const auto& [ch, f]  : mp){
            pq.push({f, ch});
        }
        string result = "";
        while (!pq.empty()){
            auto [f, ch] = pq.top(); pq.pop();
            for (int i = 0; i < f; ++i) result += ch;
        }
        return result;
    }
};