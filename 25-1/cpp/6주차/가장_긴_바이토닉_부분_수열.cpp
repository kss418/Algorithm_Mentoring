#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll dp[MAX][2], a[MAX], n;

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 1;

    if(cnt) for(int i = 1;i < cur;i++){
        if(a[i] <= a[cur]) continue;
        ret = max(ret, solve(i, 0) + 1);
        ret = max(ret, solve(i, 1) + 1);
    }
    else for(int i = 1;i < cur;i++){
        if(a[i] >= a[cur]) continue;
        ret = max(ret, solve(i, 0) + 1);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j <= 1;j++) dp[i][j] = -1;
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result = max(result, max(solve(i, 0), solve(i, 1)));
    }
    cout << result;
    return 0;
}

