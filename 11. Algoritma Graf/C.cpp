#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, Q;
vector<vector<pair<ll,ll>>> vertex(201);

ll total = 0;

ll findShortest(ll start, ll last){
    vector<ll> shortest(N+1, LLONG_MAX);
    shortest[start] = 0;
    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> dist;
    dist.push({0, start});
    while(!dist.empty()){
        ll jarak = dist.top().first;
        ll node = dist.top().second;
        dist.pop();

        if(jarak > shortest[node]) continue;

        for(auto tetangga : vertex[node]){
            ll v = tetangga.first;
            ll d = tetangga.second;

            if(shortest[v] > shortest[node] + d){
                shortest[v] = shortest[node] + d;
                dist.push({shortest[v], v});
            }
        }  
    }
    return shortest[last];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q;
    for(int i=0; i<M; i++){
        ll U, V, W;
        cin >> U >> V >> W;
        vertex[U].push_back({V, W});
        vertex[V].push_back({U, W});
    }
    vector<ll> P(Q);
    for(int i=0; i<Q; i++){
        cin >> P[i];
    }
    
    for(int i=0; i<Q-1; i++){
        total += findShortest(P[i], P[i+1]);
    }

    cout << total << endl;

}