class ProductOfNumbers {
public:
    vector<int> prod;
    ProductOfNumbers() {
        prod = {1};
    }
    
    void add(int num) {
        if(num == 0) {
            prod = {1};
        }
        else {
            prod.push_back(num * prod.back());
        }
        
    }
    
    int getProduct(int k) {
        int size = prod.size();
        return (k < size) ? prod.back() / prod[size - k -1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */