// Last updated: 06/07/2026, 18:59:12
class Bank {
public:
    vector<long long> accounts;

    inline bool valid(int account) {
        return account >= 1 && account <= (int)accounts.size();
    }
    
    Bank(vector<long long>& balance) : accounts(balance) {}
    
    bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2)) return false;
        if (!withdraw(account1, money)) return false;
        deposit(account2, money);
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!valid(account)) return false;
        accounts[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!valid(account)) return false;
        if (accounts[account - 1] < money) return false;
        accounts[account - 1] -= money;
        return true;
    }
};