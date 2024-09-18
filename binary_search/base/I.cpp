#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l=1, r=1e9;
    while(l!=r){
        ll mid=(l+r)/2;
        cout<<"? "<<mid<<endl;
        cout.flush();
        string s;
        cin>>s;
        if(s=="YES"){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<"! "<<r<<endl;
    cout.flush();

    return 0;
}
