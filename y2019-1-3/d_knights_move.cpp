#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int a[10][3];

    a[0][0] = 4;
    a[0][1] = 6;
    a[0][2] = -1;
    
    a[1][0] = 6;
    a[1][1] = 8;
    a[1][2] = -1;
    
    a[2][0] = 7;
    a[2][1] = 9;
    a[2][2] = -1;
    
    a[3][0] = 4;
    a[3][1] = 8;
    a[3][2] = -1;
    
    a[4][0] = 0;
    a[4][1] = 3;
    a[4][2] = 9;
    
    a[5][0] = -1;
    a[5][1] = -1;
    a[5][2] = -1;
    
    a[6][0] = 0;
    a[6][1] = 1;
    a[6][2] = 7;
    
    a[7][0] = 2;
    a[7][1] = 6;
    a[7][2] = -1;
    
    a[8][0] = 1;
    a[8][1] = 3;
    a[8][2] = -1;
    
    a[9][0] = 2;
    a[9][1] = 4;
    a[9][2] = -1;
    
    int d[100][10];
    for (int i = 1; i < 10; i++) {
        d[0][i] = 1;
    }
    d[0][0] = 0;
    d[0][8] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            d[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                if (a[j][k] != -1) {
                    d[i][j] = (d[i][j] + d[i - 1][a[j][k]]) % 1000000000;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = (sum + d[n - 1][i]) % 1000000000;
    }
    std::cout << sum;
}