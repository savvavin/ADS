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
    vector<ll> pref;
    pref.push_back(0);
    for (ll i = 0; i < n; ++i) {
        string ss;
        cin >> ss;
        if (ss[0] == '+') {
            ll x = stoll(ss.substr(1));
            s.push(x);
            pref.push_back(pref[pref.size() - 1] + x);
        } else if (ss[0] == '-') {
            cout << s.top() << "\n";
            s.pop();
            pref.pop_back();
        } else {
            ll k = stoll(ss.substr(1));
            ll res = pref[pref.size() - 1] - pref[pref.size() - k - 1];
            cout << res << "\n";
        }
    }

    return 0;
}
