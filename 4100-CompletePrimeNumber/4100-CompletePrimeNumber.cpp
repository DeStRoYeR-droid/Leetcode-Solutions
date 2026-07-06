// Last updated: 06/07/2026, 18:48:06
class Solution {
public:
    bool completePrime(int num) {
        string str = to_string(num);
        for (int i = 0; i < str.size(); ++i){
            if (!isPrime(stoi(str.substr(0, i + 1)))) return false;
            if (!isPrime(stoi(str.substr(i)))) return false;
        }
        return true;
    }

    bool isPrime(int num){
        if (num == 1) return false;
        for (int i = 2; i * i <= num; ++i){
            if (num % i == 0) return false;
        }
        return true;
    }
};