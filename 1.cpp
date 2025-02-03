#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Function to compute power modulo MOD
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Total number of ways to arrange rows and columns
    long long row_config = mod_exp(2LL, n, MOD);  // Ensure all arguments are long long
    long long col_config = mod_exp(2LL, m, MOD);

    // Multiply row and column configurations and take modulo MOD
    long long result = (row_config * col_config) % MOD;

    cout << result << "\n";
    return 0;
}
