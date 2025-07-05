#include <iostream>
#include <vector>

using namespace std;

long long tebas(vector<int> A, int h);
int tebang(vector<int> A, long long M, int max_val);
int main() {
    int N;
    long long M;
    int max_val;
    vector<int> A;
    cin >> N >> M;
    int x;
    cin >> x;
    A.push_back(x);
    max_val = x;
    for (int i = 1; i < N; i++) {
        max_val = (x > max_val) ? x : max_val;
        cin >> x;
        A.push_back(x);
    }
    cout << tebang(A, M, max_val) << endl;

    return 0;
}
long long tebas(vector<int> A, int h) {
    long long sum = 0;
    for (size_t i = 0; i < A.size(); i++) {
        sum += (A[i] - h > 0) ? (A[i] - h) : 0;
    }

    return sum;
}
int tebang(vector<int> A, long long M, int max_val) {
    int l = 0;
    int r = max_val;
    while (l < r) {
        int pohon = (l + r) / 2;
        if (tebas(A, pohon) > M) {
            l = pohon + 1;
        } else {
            r = pohon;
        }
    }

    return tebas(A, l) < M ? l - 1 : l;
}
