// Last updated: 06/07/2026, 18:47:18
class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int copy = n, calc = 0;
        while (copy){
            calc += factorial(copy % 10);
            copy /= 10;
        }
        return method(calc, n);
    }

    int factorial(int n){
        int result = 1;
        for (int i = 1; i <= n; ++i) result *= i;
        return result;
    }

    bool method(int ans, int n){
        vector<int> c1(10,0), c2(10,0);

        while(ans != 0){
            c1[ans % 10]++;
            ans /= 10;
        }

        while(n != 0){
            c2[n % 10]++;
            n /= 10;
        }

        return c1 == c2;
    }
};