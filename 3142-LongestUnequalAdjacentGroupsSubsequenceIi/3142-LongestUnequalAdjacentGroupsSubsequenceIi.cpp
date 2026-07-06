// Last updated: 06/07/2026, 18:54:29
class Solution {
private:
    int hammingDistance(const string& word1, const string& word2){
        if (word1.size() != word2.size()) return false;
        int distance = 0;
        for (int i = 0; i < word1.size(); ++i){
            distance += word1[i] != word2[i];
        }
        return distance;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = groups.size();
        vector<int> dp(n, 1), parent(n, -1);
        int maxi = 1;

        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (groups[i] != groups[j] && 
                    hammingDistance(words[i], words[j]) == 1 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        vector<string> result;
        result.reserve(maxi);
        for (int i = 0; i < n; ++i){
            if (maxi == dp[i]){
                while (i != -1){
                    result.push_back(words[i]);
                    i = parent[i];
                }
                break;
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};