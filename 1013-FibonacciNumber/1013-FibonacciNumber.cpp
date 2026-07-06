// Last updated: 06/07/2026, 19:06:38
using ll = long long;

using Matrix = array<array<ll, 2>, 2>;

Matrix mul(Matrix a, Matrix b) {
	Matrix res = {{{0, 0}, {0, 0}}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return res;
}
class Solution {
public:
    int fib(int n) {
        Matrix base = {{{1, 0}, {0, 1}}};
        Matrix m = {{{1, 1}, {1, 0}}};

        for (; n > 0; n /= 2, m = mul(m, m)) {
            if (n & 1) base = mul(base, m);
        }

        return base[0][1];
    }
};

