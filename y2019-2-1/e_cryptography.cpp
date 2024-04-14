#include <tuple>
#include <fstream>

void build_tree(std::tuple<int, int, int, int>*, int, int, int, int);
std::tuple<int, int, int, int> mx_prod(std::tuple<int, int, int, int>, std::tuple<int, int, int, int>, int);

const int t_size = 262144 * 2;
std::tuple<int, int, int, int> tree[t_size];

void build_tree(std::tuple<int, int, int, int>* a, int v, int tl, int tr, int mod) {
    // std::cout << tl << " " << tr << std::endl;
    if (tl == tr) {
        tree[v] = a[tl];
    }
    else {
        int tmid = (tl + tr) / 2;
        build_tree(a, v * 2, tl, tmid, mod);
        build_tree(a, v * 2 + 1, tmid + 1, tr, mod);
        tree[v] = mx_prod(tree[v * 2], tree[v * 2 + 1], mod);
    }
}

std::tuple<int, int, int, int> range_mx_prod(std::tuple<int, int, int, int>* a, int v, int tl, int tr, int l, int r, int mod) {
    std::tuple<int, int, int, int> neutral;
    std::get<0>(neutral) = 1;
    std::get<1>(neutral) = 0;
    std::get<2>(neutral) = 0;
    std::get<3>(neutral) = 1;
    if (l > r) {
        return neutral;
    }
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tmid = (tl + tr) / 2;
    return mx_prod(range_mx_prod(a, v * 2, tl, tmid, l, std::min(tmid, r), mod),
     range_mx_prod(a, v * 2 + 1, tmid + 1, tr, std::max(tmid + 1, l), r, mod), mod);
    
}

std::tuple<int, int, int, int> mx_prod(std::tuple<int, int, int, int> x, std::tuple<int, int, int, int> y, int mod) {
    std::tuple<int, int, int, int> res;
    std::get<0>(res) = ((std::get<0>(x) * std::get<0>(y)) % mod + (std::get<1>(x) * std::get<2>(y)) % mod) % mod;
    std::get<1>(res) = ((std::get<0>(x) * std::get<1>(y)) % mod + (std::get<1>(x) * std::get<3>(y)) % mod) % mod;
    std::get<2>(res) = ((std::get<2>(x) * std::get<0>(y)) % mod + (std::get<3>(x) * std::get<2>(y)) % mod) % mod;
    std::get<3>(res) = ((std::get<2>(x) * std::get<1>(y)) % mod + (std::get<3>(x) * std::get<3>(y)) % mod) % mod;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    std::ifstream in;

    in.open("crypto.in");
    int r, n, m;
    in >> r >> n >> m;
    std::tuple<int, int, int, int> *a = new std::tuple<int, int, int, int>[t_size];

    std::tuple<int, int, int, int> add;
    for (int i = 0; i < n; i++) {
        in >> std::get<0>(add) >> std::get<1>(add) >> std::get<2>(add) >> std::get<3>(add);
        a[i] = add;
    }
    std::get<0>(add) = 1;
    std::get<1>(add) = 0;
    std::get<2>(add) = 0;
    std::get<3>(add) = 1;
    for (int i = n; i < t_size; i++) {
        a[i] = add;
    }

    build_tree(a, 1, 0, t_size / 2 - 1, r);
    
    std::ofstream out;
    out.open("crypto.out");
    int left, right;
    std::tuple<int, int, int, int> ans;
    for (int i = 0; i < m; i++) {
        in >> left >> right;
        ans =  range_mx_prod(a, 1, 0, t_size / 2 - 1, left - 1, right - 1, r);
        out << std::get<0>(ans) << " " << std::get<1>(ans) << std::endl;
        out << std::get<2>(ans) << " " << std::get<3>(ans) << std::endl << std::endl;
    }
}
