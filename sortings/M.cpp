#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool cmp(string &a, string &b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> a;
    string s;
    while (cin >> s) {
        a.push_back(s);
    }
    sort(a.begin(), a.end(), cmp);
    for (auto x : a) {
        cout << x;
    }

    return 0;
}
