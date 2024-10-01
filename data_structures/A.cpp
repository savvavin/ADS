#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    stack<ll> s;
    queue<ll> q;
    ll cnt = 1;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (!s.empty() && x > s.top()) {
            cout << 0;
            return 0;
        }
        s.push(x);
        q.push(1);
        while (!s.empty() && s.top() == cnt) {
            q.push(2);
            s.pop();
            ++cnt;
        }
    }
    ll x = q.front();
    q.pop();
    ll c = 1;
    vector<pair<ll, ll>> res;
    while (!q.empty()) {
        if (q.front() == x) {
            ++c;
        } else {
            res.push_back({x, c});
            x = q.front();
            c = 1;
        }
        q.pop();
    }
    res.push_back({x, c});
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
