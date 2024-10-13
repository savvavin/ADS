#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

deque<ll> q1;
deque<ll> q2;

void corr() {
    ll sum = q1.size() + q2.size();
    if (q1.size() < ((sum + 1) / 2)) {
        q1.push_back(q2.front());
        q2.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        char t;
        cin >> t;
        if (t == '+') {
            ll x;
            cin >> x;
            q2.push_back(x);
            corr();
        } else if (t == '*') {
            ll x;
            cin >> x;
            ll sum = q1.size() + q2.size();
            if (sum % 2 == 0) {
                q1.push_back(x);
            } else {
                q2.push_front(x);
            }
            corr();
        } else {
            cout << q1.front() << "\n";
            q1.pop_front();
            corr();
        }
    }

    return 0;
}
