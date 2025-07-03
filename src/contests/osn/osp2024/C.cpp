#include <iostream>
#include <vector>

using namespace std;

long long tebas(vector<int> A, int h);
int tebang(vector<int> A, long long M);
int main() {
    int N;
    long M;
    vector<int> A;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << tebang(A, M) << endl;

    return 0;
}
long long tebas(vector<int> A, int h) {
    long long sum = 0;
    for (size_t i = 0; i < A.size(); i++) {
        sum += (A[i] - h > 0) ? (A[i] - h) : 0;
    }

    return sum;
}
int tebang(vector<int> A, long long M) {
    int l = 0;
    int r = A.size();
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
