// Last updated: 14/09/2026, 09:32:31
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