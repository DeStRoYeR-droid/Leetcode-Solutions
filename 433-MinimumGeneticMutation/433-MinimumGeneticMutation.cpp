// Last updated: 13/07/2026, 22:19:48
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        vector<bool> available(bank.size(), true);
        while (!q.empty()){
            auto [gene, dist] = q.front(); q.pop();
            if (gene == endGene) return dist;
            for (int i = 0; i < bank.size(); ++i){
                if (available[i] && countDifference(gene, bank[i]) == 1){
                    q.push({bank[i], dist + 1});
                    available[i] = false;
                }
            }
        }

        return -1;
    }

    int countDifference(const string& s1, const string& s2){
        int result = 0;
        for (int i = 0; i < s1.size(); ++i){
            if (s1[i] != s2[i]) ++result;
        }
        return result;
    }
};