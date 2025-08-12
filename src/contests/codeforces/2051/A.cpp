#include <bits/stdc++.h>

using namespace std;

void solution();

int main() {
    // input
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    // solution();

    return 0;
}

void solution() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    bool is_sorted = true;
    for (int i = 1; i < n; i++) {
        if (p[i] == i) continue;
        if (p[i] == i + 1 && p[i + 1] == i) {
            swap(p[i], p[i + 1]);
        } else {
            is_sorted = false;
            break;
        }
    }
    if (is_sorted) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
