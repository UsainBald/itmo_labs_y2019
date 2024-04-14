#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, x;
    std::cin >> n >> m;
    int **a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    int **d = new int*[n];
    for (int i = 0; i < n; i++) {
        d[i] = new int[m];
    }
    int **from = new int*[n];
    for (int i = 0; i < n; i++) {
        from[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> x;
            a[i][j] = x;
        }
    }
    d[0][0] = a[0][0];
    for (int i = 1; i < n; i++) {
        d[i][0] = d[i - 1][0] + a[i][0];
    }
    for (int i = 1; i < m; i++) {
        d[0][i] = d[0][i - 1] + a[0][i];
    }
    from[0][0] = -1;
    for (int i = 1; i < n; i++) { // up = 0, left = 1
        from[i][0] = 0;
    }
    for (int i = 1; i < m; i++) {
        from[0][i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (d[i - 1][j] < d[i][j - 1]) {
                d[i][j] = d[i][j - 1] + a[i][j];
                from[i][j] = 1;
            }
            else {
                d[i][j] = d[i - 1][j] + a[i][j];
                from[i][j] = 0;
            }
        }
    }
    std::cout << d[n - 1][m - 1] << std::endl;
    char *f = new char[n + m - 2];
    int i = n - 1, j = m - 1, x1 = 0;
    while (from[i][j] != -1) {
        if (from[i][j] == 0) {
            f[x1] = 'D';
            i--;
        }
        else {
            f[x1] = 'R';
            j--;
        }
        x1++;
    }
    for (i = 0; i < x1; i++) {
        std::cout << f[x1 - i - 1];
    }
}