#include <iostream>

int a[] = {'(', '[', '{'};
int b[] = {')', ']', '}'};

char closing(char bracket) {
    for (int i = 0; i < 3; i++) {
        if (bracket == a[i]) {
            return b[i];
        }
    }
    return 'L';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    std::string s;
    std::cin >> s;

    int n = s.size();
    int **d = new int*[n];
    for (int i = 0; i < n; i++) {
        d[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            d[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            if (s[j + i] == closing(s[j])) {
                d[j][j + i] = d[j + 1][j + i - 1] + 2;
            }
            else {
                if (d[j + 1][j + i] > d[j][j + i - 1]) {
                    d[j][j + i] = d[j + 1][j + i];
                }
                else {
                    d[j][j + i] = d[j][j + i - 1];
                }
            }
            if (i >= 3) {
                for (int k = 0; k < i - 2; k++) {
                    if (d[j][j + k + 1] + d[j + k + 2][j + i] > d[j][j + i]) {
                        d[j][j + i] = d[j][j + k + 1] + d[j + k + 2][j + i];
                    }
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         std::cout << d[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << d[0][n - 1];
}