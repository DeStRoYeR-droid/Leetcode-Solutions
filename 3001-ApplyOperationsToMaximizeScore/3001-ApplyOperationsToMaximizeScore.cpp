// Last updated: 06/07/2026, 18:54:39
const int MOD = 1e9 + 7;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());

        vector<int> primeScore(maxNum + 1, 0);        
        vector<bool> isPrime(maxNum + 1, true);        
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i <= maxNum; ++i){
            if (isPrime[i]){
                for (int j = i; j <= maxNum; j += i){
                    primeScore[j]++;
                    isPrime[j] = false;
                }
            }
        }

        vector<int> nextGreater(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i){
            while (!st.empty() && primeScore[nums[i]] >= primeScore[nums[st.top()]])
                st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        st = stack<int>();
        vector<int> prevGreaterOrEqual(n, -1);
        for (int i = 0; i < n; ++i){
            while (!st.empty() && primeScore[nums[i]] > primeScore[nums[st.top()]])
                st.pop();
            
            prevGreaterOrEqual[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        vector<pair<int, int>> sortedElements;
        for (int i = 0; i < n; ++i){
            sortedElements.emplace_back(nums[i], i);
        }
        sort(sortedElements.rbegin(), sortedElements.rend());

        long long res = 1;
        for (auto& [num, idx] : sortedElements){
            long long left = prevGreaterOrEqual[idx];
            long long right = nextGreater[idx];

            long long count = (idx - left) * (right - idx);
            long long operations = min(count, (long long) k);
            res = (res * powMod(num, operations, MOD)) % MOD;
            k -= operations;
            if (k == 0) break;
        }
        return res;
    }

    long long powMod(long long x, long long n, int mod){
        long long res = 1;
        x %= mod;
        while (n > 0){
            if (n % 2 == 1) res = (res * x) % mod;
            x = (x * x) % mod;
            n /= 2;
        }
        return res;
    }
};