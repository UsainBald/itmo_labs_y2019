#include <iostream>

void combinations(int, int, int, int, int*, int*);
int* combinations(int, int, int*);

void combinations(int set, int at, int set_len, int n, int* s_size, int* subsets) {
    if (set_len == 0) {
        subsets[*s_size] = set;
        *s_size += 1;
    }
    else {
        for (int i = at; i < n; i++) {
            set = set | (1 << i);
            combinations(set, i + 1, set_len - 1, n, s_size, subsets);
            set = set & (~(1 << i));
        }
    }
}

int* combinations(int set_len, int n, int* sub_size) {
    int *subsets = new int[1 << n];
    int subsets_size = 0;
    combinations(0, 0, set_len, n, &subsets_size, subsets);
    *sub_size = subsets_size;
    return subsets;
}

bool in(int s, int subset) {
    return ((1 << s) & subset) != 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int **a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    int **d = new int*[n];
    for (int i = 0; i < n; i++) {
        d[i] = new int[1 << n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            d[i][j] = 1000000000; // dp matrix
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int *tour = new int[n];
    int min_cost = 1000000000;
    int last_cost = 1000000000;
    for (int k = 0; k < n; k++) {
        int s = k; // start node
        for (int i = 0; i < n; i++) {
            if (i != s) {
                d[i][(1 << s) | (1 << i)] = a[s][i];
            }
        }

        for (int i = 2; i < n; i++) {
            int comb_size = 0;
            int *combs = combinations(i + 1, n, &comb_size);
            for (int j = 0; j < comb_size; j++) {
                int subset = combs[j]; // TODO
                if (in(s, subset)) { // if starting node is in a combination
                    for (int next = 0; next < n; next++) {
                        if ((next != s) && in(next, subset)) {
                            int state = subset ^ (1 << next);
                            int min_dist = 1000000000;
                            for (int end_node = 0; end_node < n; end_node++) {
                                if (end_node != s && end_node != next && in(end_node, subset)) {
                                    int new_dist = d[end_node][state] + a[end_node][next];
                                    if (new_dist < min_dist) {
                                        min_dist = new_dist;
                                    }
                                }
                            }
                            d[next][subset] = min_dist;
                        }
                    }
                }
            }
        }

        int end_state = (1 << n) - 1;
        for (int end = 0; end < n; end++) {
            if (end != s) {
                int new_cost = d[end][end_state];
                if (new_cost < min_cost) {
                    min_cost = new_cost;
                }
            }
        }
        if (min_cost < last_cost) {
            last_cost = min_cost;
            int state = (1 << n) - 1;
            int last_index = s;
            for (int i = n - 1; i > 0; i--) {
                int index = -1;
                for (int j = 0; j < n; j++) {
                    if (j != s && in(j, state)) {
                        if (index == -1) {
                            index = j;
                        }
                        int prev_dist = d[index][state] + a[index][last_index];
                        int new_dist = d[j][state] + a[j][last_index];
                        if (new_dist < prev_dist) {
                            index = j;
                        }
                    }
                }
                tour[i - 1] = index;
                state = state ^ (1 << index);
                last_index = index;
            }
            tour[n - 1] = s;
        }
    }
    if (n > 1) {
        std::cout << min_cost << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << tour[i] + 1 << " ";
        }
    }
    else {
        std::cout << 0 << std::endl;
        std::cout << 1;
    }
}