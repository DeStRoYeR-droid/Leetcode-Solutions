// Last updated: 06/07/2026, 19:03:45
class ProductOfNumbers {
private:
    vector<int> prefix = {1};
    int size;
public:
    ProductOfNumbers(){
        prefix.reserve(40000);
        size = 1;
    }
    
    void add(int num) {
        if (num == 0){
            prefix = {1};
            size = 1;
        }
        else{
            prefix.push_back(prefix[size++-1] * num);
        }
    }
    
    int getProduct(int k) {
        return (k >= size) ? 0 : prefix[size-1] / prefix[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */