#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &depth, const vector<int> &input, int x) {
    if (depth[x] > 0)
        return depth[x];
    if (input[x] == -1) {
        depth[x] = 1;
    } else {
        depth[x] = dfs(depth, input, input[x]) + 1;
    }
    return depth[x];
}
int main() {
    int n;
    cin >> n;
    vector<int> input(n + 1, 0);
    vector<int> depth(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> input[i];

    // algo
    int cmax = 1;
    for (int i = 1; i <= n; i++) {
        cmax = max(cmax, dfs(depth, input, input[i]));
    }
    cout << cmax << endl;

    return 0;
}