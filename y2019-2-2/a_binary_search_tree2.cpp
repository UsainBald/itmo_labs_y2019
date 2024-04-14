#include <iostream>

using namespace std;

struct Node {
    int x;
    Node* left;
    Node* right;

    Node(int val) {
        x = val;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node*& t, Node* v) {
    if (t == nullptr) {
        t = v;
        return;
    }
    if (v->x == t->x) {
        return;
    }
    else {
        if (v->x < t->x) {
            insert(t->left, v);
        }
        else {
            insert(t->right, v);
        }
    }
}

bool exists(Node*& t, int val) {
    if (t == nullptr) {
        return false;
    }
    if (t->x == val) {
        return true;
    }
    if (val < t->x) {
        return exists(t->left, val);
    }
    else {
        return exists(t->right, val);
    }
}

Node* next(Node*& t, int val) {
    Node* cur = t;
    Node* succ = nullptr;

    while (cur != nullptr) {
        if (val < cur->x) {
            succ = cur;
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    return succ;
}

Node* prev(Node*& t, int val) {
    Node* cur = t;
    Node* prev = nullptr;

    while (cur != nullptr) {
        if (val <= cur->x) {
            cur = cur->left;
        }
        else {
            prev = cur;
            cur = cur->right;
        }
    }
    return prev;
}

void delete_node(Node*& t, int val) {
    if (t == nullptr) {
        return;
    }
    if (val == t->x) {
        if (t->left == nullptr && t->right == nullptr) {
            t = nullptr;
        }
        else if (t->left == nullptr) {
            t = t->right;
        }
        else if (t->right == nullptr) {
            t = t->left;
        }
        else {
            Node* succ = next(t, t->x);
            Node* temp = new Node(succ->x);
            temp->left = t->left;
            if (t->right->x != succ->x) {
                temp->right = t->right;
            }
            delete_node(t, temp->x);
            t = temp;
        }
        return;
    }
    if (val < t->x) {
        delete_node(t->left, val);
    }
    else {
        delete_node(t->right, val);
    }
}

signed main() {
    Node* tree = nullptr;
    Node *v;
    string s;
    int x;
    while (cin >> s) {
        if (s == "insert") {
            cin >> x;
            v = new Node(x);
            insert(tree, v);
        }
        else if (s == "exists") {
            cin >> x;
            if (exists(tree, x) == true) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        else if (s == "next") {
            cin >> x;
            Node* ans = next(tree, x);
            if (ans == nullptr) {
                cout << "none" << endl;
            }
            else {
                cout << ans->x << endl;
            }
        }
        else if (s == "prev") {
            cin >> x;
            Node* ans = prev(tree, x);
            if (ans == nullptr) {
                cout << "none" << endl;
            }
            else {
                cout << ans->x << endl;
            }
        }
        else if (s == "delete") {
            cin >> x;
            delete_node(tree, x);
        }
    }
}