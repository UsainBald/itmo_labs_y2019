// REAL 100 % NOT CLICKBAIT BEST FASTEST MOST WORKING SOLUTION TO TRAFFIC (adding one more lane)
#include <iostream>
#include <cstdio>

using namespace std;

const int t_size = 262144;
int tree[t_size];

void build_tree(int v, int tl, int tr, int n2) {
    if (tl == tr) {
        if (tl < n2) {
            tree[v] = 1;
        }
        else {
            tree[v] = 0;
        }
    }
    else {
        int tmid = (tl + tr) / 2;
        build_tree(v * 2, tl, tmid, n2);
        build_tree(v * 2 + 1, tmid + 1, tr, n2);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

void car_leaves(int place, int n2) { // NOOOOOOOOO CAR WHY U LEAVE U NEED TO BE PARKED TAKING PRIME REAL ESTATE WHY YOU GO CREATE TRAFFIC 
    int p1, p2;
    p1 = place + t_size / 2;
    p2 = (place + n2 / 2) % n2 + t_size / 2;
    while (p1 > 0) {
        tree[p1]++;
        p1 /= 2;
    }
    while (p2 > 0) {
        tree[p2]++;
        p2 /= 2;
    }
}

int car_parks(int v, int tl, int tr) { // YES YES CAR PLEASE PARK WE NEED YOU HERE AT THE VERY CENTER OF THE CITY DOING HUGE ECONOMIC WORK STANDING STILL
    if (v >= t_size / 2 && tree[v] == 1) {
        return v;
    }
    if (tree[v] == 0) {
        return -1;
    }
    else {
        int tmid = (tl + tr) / 2;
        int x = car_parks(v * 2, tl, tmid);
        if (x == -1) {
            return car_parks(v * 2 + 1, tmid + 1, tr);
        }
        else {
            return x;
        }
    }
    
}

void park(int place, int n2) {
    int p1, p2;
    p1 = place + t_size / 2;
    p2 = (place + n2 / 2) % n2 + t_size / 2;
    while (p1 > 0) {
        tree[p1]--;
        p1 /= 2;
    }
    while (p2 > 0) {
        tree[p2]--;
        p2 /= 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout); 
    int n, m;
    cin >> n >> m;
    build_tree(1, 0, t_size / 2 - 1, 2 * n);
    int x;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s == "enter") {
            cin >> x;
            x--;
            bool found = false;
            int tl, tr, v, parent, val;
            v = x + t_size / 2;
            tl = x;
            tr = x;
            if (tree[v] == 1) {
                found = true;
            }
            val = 1;
            if (!found) {
                while (!found) {
                    parent = v / 2;
                    if (parent * 2 + 1 == v) {
                        v = parent;
                        tl -= val;
                    }
                    else {
                        if (tree[parent] > tree[v]) {
                            found = true;
                        }
                        v = parent;
                        tr += val;
                    }
                    val *= 2;
                }
                v = v * 2 + 1;
                tl = (tl + tr) / 2 + 1;
                
                int p = car_parks(v, tl, tr);
                cout << (p - t_size / 2) % n + 1  << endl;
                park(p - t_size / 2, n * 2);
            }
            else {
                park(v - t_size / 2, n * 2);
                cout << (v - t_size / 2) % n + 1 << endl;
            }
        }
        else if (s == "exit") {
            cin >> x;
            x--;
            car_leaves(x, n * 2);
        }
        // cout << tree[t_size / 16] << endl;
        // cout << tree[t_size / 8] << " " << tree[t_size / 8 + 1] << endl;
        // cout << tree[t_size / 4] << " " << tree[t_size / 4 + 1] << " " << tree[t_size / 4 + 2] << " " << tree[t_size / 4 + 3] << " " << endl;
        // cout << tree[t_size / 2] << " " << tree[t_size / 2 + 1] << " " << tree[t_size / 2 + 2] << " " << tree[t_size / 2 + 3] << " " << tree[t_size / 2 + 4] << " " << tree[t_size / 2 + 5] << " " << tree[t_size / 2 + 6] << " " << tree[t_size / 2 + 7] << " " << endl;
    }
}