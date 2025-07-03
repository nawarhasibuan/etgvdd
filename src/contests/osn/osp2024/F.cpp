#include <iostream>

using namespace std;

int maju(int m, int n);
int main() {
    int N, M;
    cin >> N >> M;
    cout << maju(M, N) << endl;

    return 0;
}

int maju(int m, int n) {
    if (m < n) return maju(n, m);
    int row = m * (m + 1) / 2;
    int col = (m + n) * (n - 1);
    return row + col;
}
