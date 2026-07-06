// Last updated: 06/07/2026, 18:51:53
constexpr int mod = 1e9 + 7;
typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix& a, const Matrix& b){
    Matrix result(26, vector<long long> (26, 0));
    for (int i = 0; i < 26; ++i){
        for (int k = 0; k < 26; ++k){
            if (a[i][k] == 0) continue;
            for (int j = 0; j < 26; ++j){
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return result;
}

Matrix matrix_power(Matrix mat, int power){
    Matrix result(26, vector<long long> (26, 0));
    for (int i = 0; i < 26; ++i){
        result[i][i] = 1;
    }

    while (power > 0){
        if (power % 2 == 1) result = multiply(result, mat);
        mat = multiply(mat, mat);
        power /= 2;
    }
    return result;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix transition(26, vector<long long>(26, 0));
        for (int c = 0; c < 26; ++c){
            int num = nums[c];
            for (int j = 1; j <= num; ++j){
                int nextChar = (c + j) % 26;
                transition[c][nextChar]++;
            }
        }

        Matrix matPow = matrix_power(transition, t);
        vector<long long> cnt(26, 0);
        for (const char& ch : s) cnt[ch - 'a']++;

        vector<long long> newCnt(26, 0);
        for (int i = 0; i < 26; ++i){
            for (int j = 0; j < 26; ++j){
                newCnt[j] = (newCnt[j] + cnt[i] * matPow[i][j]) % mod;
            }
        }

        long long total = 0;
        for (long long x : newCnt){
            total = (total + x) % mod;
        }
        return total;
    }
};