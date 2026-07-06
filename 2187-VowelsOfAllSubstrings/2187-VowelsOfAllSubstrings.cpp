// Last updated: 06/07/2026, 18:59:03
class Solution {
public:
    long long countVowels(string word) {
        static const string VOWELS = "aeiou";
        long long result = 0;
        const long long n = word.size();
        for (int i = 0; i < n; ++i){
            if (VOWELS.find(word[i]) != string::npos)
                result += (i + 1) * (n - i);
        }
        return result;
    }
};