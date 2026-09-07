// Last updated: 07/09/2026, 22:31:38
class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long result = 0;
        int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        auto ptrend = pizzas.end();
        
        bool turn = 1;
        int oddDays = ((n / 4) % 2) ? n / 8 + 1 : n / 8;
        int evenDays = n / 8;
        
        
        for (int i = 0; i < oddDays; ++i){
            result += *(ptrend - 1);
            ptrend--;
        }
        for (int i = 0; i < evenDays; ++i){
            result += *(ptrend - 2);
            ptrend -= 2;
        }
        return result;
    }
};