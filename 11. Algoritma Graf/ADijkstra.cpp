#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, P, Q;
vector<vector<pair<ll,ll>>> adj(2501);
vector<ll> shortest(2501, LLONG_MAX);

void solve(){
    priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> dist;

    dist.push({0, P});
    while(!dist.empty()){
        ll jarak = dist.top().first;
        ll node = dist.top().second;
        dist.pop();

        if(jarak > shortest[node]) continue;

        for(auto tetangga : adj[node]){
            ll v = tetangga.first;
            ll d = tetangga.second;

            if(shortest[node] + d < shortest[v]){
                shortest[v] = shortest[node] + d;
                dist.push({shortest[v], v});
            }
        }
    }
    cout << shortest[Q] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> P >> Q;
    for(int i=0; i<M; i++){
        ll U, V, W;
        cin >> U >> V >> W;
        adj[U].push_back({V, W});
        adj[V].push_back({U, W});
    }
    shortest[P] = 0;
    solve();
    

}