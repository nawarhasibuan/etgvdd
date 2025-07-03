#include <iostream>

using namespace std;

long long sum_digits(int A, int base);
long long gcd(long long A, long long B);

int main() {
    int A;
    cin >> A;
    long long s = 0;
    for (int i = 2; i < A; i++) {
        s += sum_digits(A, i);
    }
    auto f = gcd(s, A - 2);
    cout << s / f << "/" << (A - 2) / f << endl;

    return 0;
}

long long sum_digits(int A, int base) {
    long long s = 0;
    while (A > 0) {
        s += A % base;
        A /= base;
    }
    return s;
}
long long gcd(long long A, long long B) {
    while (B != 0) {
        long long temp = A;
        A = B;
        B = temp % B;
    }

    return A;
}
