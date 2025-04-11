#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010101;
const ll MOD = 1e9 + 9;
ll n, dp[MAX];

ll solve(ll cur){
    if(cur < 0) return 0;
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;
    ret += solve(cur - 1) + solve(cur - 2) + solve(cur - 3);
    return ret %= MOD;
}

void run(){
    cin >> n;
    cout << solve(n) << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio
    
    ll t; cin >> t;
    for(int i = 0;i < MAX;i++) dp[i] = -1;
    dp[0] = 1;
    while(t--) run();

    return 0;
}

