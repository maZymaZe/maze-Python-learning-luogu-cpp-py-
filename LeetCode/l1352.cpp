class ProductOfNumbers {
   public:
    vector<long long> s;
    int p0 = -1;
    ProductOfNumbers() { s.push_back(1); }

    void add(int num) {
        if (num != 0)
            s.push_back(s.back() * num);
        else
            s.push_back(1), p0 = s.size();
    }

    int getProduct(int k) {
        if (s.size() - p0 >= k)
            return (int)(s.back() / s[s.size() - 1 - k]);

        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */