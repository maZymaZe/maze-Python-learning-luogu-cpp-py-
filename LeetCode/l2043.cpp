class Bank {
   public:
    int n;
    vector<long long> x;
    Bank(vector<long long>& balance) {
        x = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (!(account1 <= n && account2 <= n && account1 > 0 && account2 > 0))
            return false;
        if (x[account1 - 1] < money)
            return false;
        x[account1 - 1] -= money;
        x[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!(account > 0 && account <= n))
            return false;
        x[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!(account > 0 && account <= n))
            return false;
        if (x[account - 1] < money)
            return false;
        x[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */