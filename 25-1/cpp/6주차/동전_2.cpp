#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 10101;
const ll INF = 1e12;
ll dp[MAX], n, m, a[101];

ll solve(ll cur){
    if(cur < 0) return INF;
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret = 0;
    for(int i = 1;i <= n;i++){
        ret = min(ret, solve(cur - a[i]) + 1);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < MAX;i++) dp[i] = -1;
    cout << (solve(m) == INF ? -1 : solve(m));

    return 0;
}

