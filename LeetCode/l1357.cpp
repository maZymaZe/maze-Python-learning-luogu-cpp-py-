class Cashier {
public:
    int mn,md;
    unordered_map<int,int> mp;
    int cnt=0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        mn=n,md=discount;
        int l=products.size();
        for (int i=0;i<l;i++) {
            mp.insert({products[i],prices[i]});
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        int l=product.size();
        double tot=0;
        for(int i=0;i<l;i++) {
            tot+=(double)(mp[product[i]])*amount[i];
        }
        if(cnt==mn)tot=tot-(tot*md)/100,cnt=0;
        return tot;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */