#include <bits/stdc++.h>
#define kalcer ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

using namespace std;

vector <int> adj[100001];
bool visited[100001];

void dfs(int sekarang){
    visited[sekarang] = true;
    for(int tetangga : adj[sekarang]){
        if(!visited[tetangga]){
            dfs(tetangga);
        }
    }
}

int main(){
    kalcer
    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        int U, V; cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    int komponen = 0;
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            komponen++;
            dfs(i);
        }
    }
    cout << komponen << endl;

}