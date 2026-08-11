#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, P, Q;
vector<vector<int>> jalan(2501);
map <vector<ll>, ll> jarak;
queue<ll> open;
vector<ll> shortest(2501, LLONG_MAX);
vector<ll> visited(2501, 0);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> P >> Q;
    for(int i=0; i<M; i++){
        ll U, V, W; cin >> U >> V >> W;
        jalan[U].push_back(V);
        jalan[V].push_back(U);
        jarak[{U,V}] = W;
        jarak[{V,U}] = W;
    }
    open.push(P);
    shortest[P] = 0;
    while(!open.empty()){
        ll curr = open.front();
        visited[curr]++;
        for(int i=0; i<jalan[curr].size(); i++){
            ll dist = shortest[curr] + jarak[{curr, jalan[curr][i]}];
            if(dist < shortest[jalan[curr][i]]){
                shortest[jalan[curr][i]] = dist;
            }
            if(visited[jalan[curr][i]] < jalan[jalan[curr][i]].size()){
                open.push(jalan[curr][i]);
            }
        }
        open.pop();

    }
    cout << shortest[Q] << endl;



}