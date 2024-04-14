#include <iostream>

int get_root(int* s, int x) {
    if (s[x] == x) {
        return x;
    }
    else {
        return get_root(s, s[x]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int *s = new int[n + 1];
    int *exp = new int[n + 1];
    int *exp_diff = new int[n + 1];
    int *ranks = new int[n + 1];
    for (int i = 1; i < n + 1; i++) {
        s[i] = i;
        exp[i] = 0;
        exp_diff[i] = 0;
    }
    int x, v, r1, r2, sum;
    std::string str;
    for (int i = 0; i < m; i++) {
        std::cin >> str;
        if (str == "join") {
            std::cin >> x >> v;
            r1 = get_root(s, x);
            r2 = get_root(s, v);
            if (r1 != r2) {
                if (ranks[r1] < ranks[r2]) {
                    std::swap(r1, r2);
                }
                if (ranks[r1] == ranks[r2]) {
                    ranks[r1]++;
                }
                exp_diff[r2] = exp[r1];
                s[r2] = r1;
            }
        }
        else if (str == "add") {
            std::cin >> x >> v;
            r1 = get_root(s, x);
            exp[r1] += v;
        }
        else if (str == "get") {
            std::cin >> x;
            sum = exp[x] - exp_diff[x];
            while(s[x] != x) {
                x = s[x];
                sum += exp[x] - exp_diff[x];
            }
            std::cout << sum << std::endl;
        }
    }
}