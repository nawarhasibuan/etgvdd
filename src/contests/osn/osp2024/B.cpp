#include <iostream>

using namespace std;

long long candil(long long B, long long C, long long D);
int main() {
    long long B, C, D;
    cin >> B >> C >> D;
    cout << candil(B, C, D) << endl;

    return 0;
}
long long candil(long long B, long long C, long long D) {
    long long count = 0;
    long long less = 0;
    long long more = 0;
    long long n = C - D;
    if (n == 0) return B > D ? B - D : 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            if (i <= D) less++;
            if (i > B) more++;
            if (n / i != i) {
                count++;
                if (n / i <= D) less++;
                if (n / i > B) more++;
            }
        }
    }

    return count - less - more;
}
