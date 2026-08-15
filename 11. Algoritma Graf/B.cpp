#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    while(T--){
        ll N, M; cin >> N >> M;
        vector<vector<pair<ll,ll>>> tetangga(N);
        for(int i=0; i<M; i++){
            ll U, V, W; cin >> U >> V >> W;
            tetangga[U].push_back({V,W});
        }
        vector<ll> shortest(N, LLONG_MAX);
        shortest[0] = 0;
        queue<ll> node;
        node.push(0);
        vector<ll> visited(N, 0);
        while(!node.empty() && (visited[node.front()] <= M)){
            ll currNode = node.front();
            visited[currNode]++;
            if(visited[currNode] >= M) break;
            node.pop();
            for(int i=0; i<tetangga[currNode].size(); i++){
                ll dist = shortest[currNode] + tetangga[currNode][i].second;
                if(dist < shortest[tetangga[currNode][i].first]){
                    shortest[tetangga[currNode][i].first] = dist;
                    node.push(tetangga[currNode][i].first);
                }
            }
        }
        if(!node.empty() && (visited[node.front()] >= M)){
            cout << "Pak Dengklek tidak mau pulang" << endl;
        }else{
            if(shortest[N-1] == LLONG_MAX){
                cout << "Tidak ada jalan" << endl;
            }else{
                cout << shortest[N-1] << endl;
            }
        }
    }

}