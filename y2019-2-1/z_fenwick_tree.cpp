#include <iostream>

#define int long long

using namespace std;

int n;
int a[500000];  //массив
int f[500000];  //дерево Фенвика

int sum(int x) {
    int result = 0;

    for (; x >= 0; x = (x & (x + 1)) - 1) {
        result += f[x];
    }

    return result;
}
//сумма элементов от l до r
int sum(int l, int r) {
    if (l) {
        return sum(r) - sum(l - 1);
    }
    else {
        return sum(r);
    }
}

//увеличение a[idx] на delta
void increase(int idx, int delta) {
    for (; idx < n; idx |= idx + 1) {
        f[idx] += delta;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        increase(i, a[i]);
    }
    std::string s;
    int x1, y;
    while (std::cin >> s) {
        if (s == "set") {
            std::cin >> x1 >> y;
            increase(x1 - 1, y - a[x1 - 1]);
            a[x1 - 1] = y;
        }
        else if (s == "sum") {
            std::cin >> x1 >> y;
            cout << sum(x1 - 1, y - 1) << std::endl;
        }
    }
}