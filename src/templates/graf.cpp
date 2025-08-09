#include <bits/stdc++.h>

using namespace std;
void bfs(int start, vector<vector<int>> &adjacency_list);
void dfs(int start, vector<vector<int>> &adjacency_list, vector<bool> &visited);

/**
 * @brief Menghitung jarak terpendek dari node awal ke semua node lainnya menggunakan BFS. Dengan Djikstra, kita bisa
 * mendapatkan jarak terpendek pada graf berbobot.
 * @param start Node awal
 * @param adjacency_list Daftar ketetanggaan graf. (Indeks adalah node, dan nilai adalah daftar tetangga, first adalah
 * tetangga, second adalah jarak)
 * @return Vektor jarak terpendek dari node awal ke semua node lainnya
 */
vector<int> shortest_path(int start, vector<vector<pair<int, int>>> &adjacency_list);

int main() {
    cout << 0 << endl;

    return 0;
}
void bfs(int start, vector<vector<int>> &adjacency_list) {
    vector<bool> visited(adjacency_list.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // manipulasi node

        for (int neighbor : adjacency_list[node]) {
            // jika neighbor belum dikunjungi, tandai sebagai dikunjungi dan tambahkan ke antrian
            // manipulasi neighbor
            cout << neighbor << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void dfs(int start, vector<vector<int>> &adjacency_list, vector<bool> &visited) {
    visited[start] = true;
    // manipulasi node

    for (int neighbor : adjacency_list[start]) {
        if (!visited[neighbor]) {
            // manipulasi neighbor
            cout << neighbor << " ";
            dfs(neighbor, adjacency_list, visited);
        }
    }
}

vector<int> shortest_path(int start, vector<vector<pair<int, int>>> &adjacency_list) {
    vector<int> distance(adjacency_list.size(), INT_MAX);
    vector<bool> visited(adjacency_list.size(), false);
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        // manipulasi node
        // tandai sudah dikunjungi.
        visited[node] = true;

        for (auto &neighbor : adjacency_list[node]) {
            int next_node = neighbor.first;
            int edge_weight = neighbor.second;

            if (!visited[next_node] && distance[node] + edge_weight < distance[next_node]) {
                // manipulasi tetangga
                distance[next_node] = distance[node] + edge_weight;
                q.push(next_node);
            }
        }
    }
    return distance;
}
