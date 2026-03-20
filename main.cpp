#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second 
#define pii pair<int, int>
const int MAXN = 2510;

int n, m, p, q, dist[MAXN];
vector<pii>adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>>pq;

signed main(){
    cin >> n >> m >> p >> q;

    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for(int i = 1; i <= n; i++) dist[i] = LLONG_MAX;

    dist[p] = 0;
    pq.push({dist[p], p});

    while(!pq.empty()){
        int u = pq.top().S, du = pq.top().F;
        // cout << "u : " << u << ", du: " << du << ", dist[u]: " << dist[u] << endl;
        pq.pop();

        if(du > dist[u] || u == q) continue;
        for(auto i : adj[u]){
            int v = i.F, w = i.S;

            if(dist[u] + w  < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // for(int i = 1; i <= n; i++) cout << dist[i] << ' ';
    // cout << endl;

    cout << dist[q];
}