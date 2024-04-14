#include <iostream>

int main() {
    struct dsu{
        int *s = new int[300001];
        int *ranks = new int[300001];
        int *size = new int[300001];
        int *min = new int[300001];
        int *max = new int[300001];

        dsu() {
            for (int i = 1; i < 300001; i++) {
                s[i] = i;
                ranks[i] = 1;
                size[i] = 1;
                min[i] = i;
                max[i] = i;
            }
        }
        
        int get_root(int x) {
            if (s[x] == x) {
                return x;
            }
            else {
                return s[x] = get_root(s[x]);
            }
        }

        void merge(int x1, int x2) {
            int r1 = get_root(x1), r2 = get_root(x2);
            if (r1 != r2) {
                if (ranks[r1] < ranks[r2]) {
                    std::swap(r1, r2);
                }
                if (ranks[r1] == ranks[r2]) {
                    ranks[r1]++;
                }
                s[r2] = r1;
                size[r1] += size[r2];
                max[r1] = std::max(max[r1], max[r2]);
                min[r1] = std::min(min[r1], min[r2]);
            }
        }

        void print_root(int x) {
            int f = get_root(x);
            std::cout << min[f] << " " << max[f] << " " << size[f] << std::endl;
        }
    };

    dsu d;
    int n, x1, x2;
    std::cin >> n;
    std::string s;
    while (std::cin >> s) {
        if (s == "union") {
            std::cin >> x1 >> x2;
            d.merge(x1, x2);
        }
        else if (s == "get") {
            std::cin >> x1;
            d.print_root(x1);
        }
    }
}