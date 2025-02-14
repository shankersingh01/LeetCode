class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int product = 1;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            product = 1;
        } else {
            product *= num;
            prefixProduct.push_back(product);
        }
    }

    int getProduct(int k) {
        if (k > prefixProduct.size())
            return 0;
        if (k == prefixProduct.size())
            return prefixProduct.back();
        return prefixProduct.back() /
               prefixProduct[prefixProduct.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */