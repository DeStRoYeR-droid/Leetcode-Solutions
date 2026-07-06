// Last updated: 06/07/2026, 19:01:58
class Fancy {
private:
    static const long long MOD = 1e9 + 7;
    vector<long long> arr;
    long long mul, add;

    long long binExpMod(long long a, long long b){
        long long result = 1;
        a %= MOD;
        while (b > 0){
            if (b & 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    long long modInverse(long long a){
        return binExpMod(a, MOD - 2);
    }

public:
    Fancy() {
        mul = 1;
        add = 0;
    }

    void append(int val) {
        long long stored = ((val - add + MOD) % MOD * modInverse(mul)) % MOD;
        arr.push_back(stored);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};