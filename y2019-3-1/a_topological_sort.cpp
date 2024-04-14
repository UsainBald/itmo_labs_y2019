#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 100002;
std::vector<int> g[MAX];
char color[MAX];
std::vector<int> ans;
bool cycle = false;

void dfs(int v) {
    color[v] = 'v'; // visiting
    for (int i = 0; i < g[v].size(); i++) {
        char to_color = color[g[v][i]];
        if (to_color == 'v') {
            cycle = true;
            break;
        }
        if (to_color != 'e') { // ended
            dfs(g[v][i]);
        }
    }
    color[v] = 'e';
    ans.push_back(v);
}

int main() {
    int n, m, x, y;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 0; i < MAX; i++) {
        color[i] = 'n'; // not visited
    }
    for (int i = 1; i < MAX; i++) {
        if (color[i] != 'e' && !g[i].empty()) {
            dfs(i);
        }
    }
    if (cycle || m == 0) {
        std::cout << -1;
    }
    else {
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[ans.size() - i - 1] << " ";
        }
    }
}