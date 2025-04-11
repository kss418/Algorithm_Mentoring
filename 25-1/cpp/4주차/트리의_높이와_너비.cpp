#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 10101;
const ll INF = 1e9;
ll n, m, l[MAX], r[MAX], idx[MAX];
bool root[MAX];
ll cnt, dep[MAX], mn[MAX], mx[MAX];

void dfs(ll cur, ll dep = 1){
    if(l[cur] != -1) dfs(l[cur], dep + 1);
    ll num = ++cnt;
    mn[dep] = min(mn[dep], num);
    mx[dep] = max(mx[dep], num);

    if(r[cur] != -1) dfs(r[cur], dep + 1);
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) root[i] = 1, mn[i] = INF;
    for(int i = 1;i <= n;i++){
        cin >> idx[i] >> l[idx[i]] >> r[idx[i]];
        if(l[idx[i]] != -1) root[l[idx[i]]] = 0;
        if(r[idx[i]] != -1) root[r[idx[i]]] = 0;
    }

    for(int i = 1;i <= n;i++){
        if(!root[i]) continue;
        dfs(i);
    }

    ll diff = 0, result = 0;
    for(int i = 1;i <= n;i++){
        if(mx[i] - mn[i] + 1 > diff){
            result = i;
            diff = mx[i] - mn[i] + 1;
        }
    }

    cout << result << " " << diff;

    return 0;
}