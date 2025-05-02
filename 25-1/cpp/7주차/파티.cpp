#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e12;
ll n, m, x, d[MAX][MAX];
vector <pair<ll, ll>> adj[MAX];

using pll = pair<ll, ll>;
priority_queue <pll, vector<pll>, greater<pll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m >> x;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }

    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < MAX;j++) d[i][j] = INF;
    }

    for(int i = 1;i <= n;i++){
        while(!pq.empty()) pq.pop();
        pq.push({0, i});

        while(!pq.empty()){
            auto[cd, cur] = pq.top(); pq.pop();
            if(d[i][cur] <= cd) continue;
            d[i][cur] = cd;

            for(auto& [nxt, co] : adj[cur]){
                if(d[i][nxt] <= cd + co) continue;
                pq.push({cd + co, nxt});
            }
        }
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        result = max(result, d[i][x] + d[x][i]);
    }
    cout << result;

    return 0;
}

