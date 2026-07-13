// Last updated: 13/07/2026, 22:21:33
class Solution {
    vector<int> freq1, freq2;
public:
    Solution() : freq1(10, 0), freq2(10, 0){}

    string getHint(string secret, string guess) {
        const int n = secret.size();    

        int bulls = 0;
        int cows = 0;

        for (int i = 0; i < n; ++i){
            if (secret[i] == guess[i]){
                bulls++;
                continue;
            }
            freq1[secret[i] - '0']++;
            freq2[guess[i] - '0']++;
        }

        for (int i = 0; i < 10; ++i){
            if (freq1[i] && freq2[i]){
                cows += min(freq1[i], freq2[i]);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};