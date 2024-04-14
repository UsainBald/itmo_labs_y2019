#include <iostream>
#include <stack>
#include <bits/stdc++.h> 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::stack<long long> a;
    std::string s;
    long long n, x, y;
    while(std::cin >> s) {
        try {
            n = std::stoll(s);
            a.push(n);
        }
        catch(std::invalid_argument) {
            char c = s[0];
            y = a.top();
            a.pop();
            x = a.top();
            a.pop();
            switch(c) {
                case '+':
                    a.push(x + y);
                    break;
                case '-':
                    a.push(x - y);
                    break;
                case '*':
                    a.push(x * y);
                    break;
                default:
                    break;
            }
        }
    }
    std::cout << a.top();
}