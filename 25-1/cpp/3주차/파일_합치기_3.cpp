#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010101;
ll n, a[MAX];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    priority_queue <ll, vector<ll>, greater<ll>> pq;
    for(int i = 1;i <= n;i++) pq.push(a[i]);

    ll result = 0;
    while(pq.size() > 1){
        ll fi = pq.top(); pq.pop();
        ll se = pq.top(); pq.pop();

        pq.push(fi + se);
        result += fi + se;
    }

    cout << result << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}

