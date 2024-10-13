#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q;
    cin >> q;
    map<string, ll> ing;
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            string name;
            cin >> name;
            ll n;
            cin >> n;
            bool flg = true;
            vector<pair<ll, string>> qs;
            for (ll i = 0; i < n; ++i) {
                ll ki;
                string si;
                cin >> ki >> si;
                qs.push_back({ki, si});
                if (ing[si] < ki) {
                    flg = false;
                }
            }
            if (flg) {
                for (ll i = 0; i < n; ++i) {
                    ing[qs[i].second] -= qs[i].first;
                }
                cout << "Milkshake " << name << " is ready\n";
            } else {
                cout << ":(\n";
            }
        } else {
            ll k;
            string s;
            cin >> k >> s;
            ing[s] += k;
            cout << s << ": " << ing[s] << "\n";
        }
    }

    return 0;
}
