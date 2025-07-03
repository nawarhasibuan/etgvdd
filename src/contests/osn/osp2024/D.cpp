#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int B;
    string Y;
    cin >> B;
    cin >> Y;
    unsigned n = Y.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int digit = (Y[i] - '0');
        unsigned j = i + 1;
        while (digit < B && j < n && Y[i] != '0') {
            dp[i] = (dp[i] + dp[j]) % MOD;
            digit = digit * 10 + (Y[j] - '0');
            j++;
        }
        if (j == n && digit < B) {
            dp[i] = (dp[i] + dp[j]) % MOD;
        } else if (digit == 0) {
            dp[i] = dp[i + 1];
        }
    }
    cout << dp[0] << endl;

    return 0;
}
