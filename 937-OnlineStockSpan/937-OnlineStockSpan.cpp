// Last updated: 06/07/2026, 19:07:18
class StockSpanner {
    vector<int> prices;    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int result = 0;
        int i = prices.size() - 1;
        while (i >= 0){
            if (prices[i] <= price) ++result;
            else break;
            --i;
        }
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */