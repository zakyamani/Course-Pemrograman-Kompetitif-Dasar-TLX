#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll R, C;
vector<vector<ll>> beban(1001, vector<ll>(1001));
ll a,b,c,d;
vector<vector<ll>> bebanMax(1001, vector<ll> (1001, LLONG_MAX));

void solve(){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> node;
    bebanMax[a][b] = 0;
    node.push({0, a, b});

    while(!node.empty()){
        ll u = node.top()[1];
        ll v = node.top()[2];
        ll w = node.top()[0];
        node.pop();
        if((u - 1 >= 1) && (bebanMax[u][v] < bebanMax[u - 1][v]) && (beban[u - 1][v]) != -1){
            bebanMax[u - 1][v] = max(beban[u - 1][v], bebanMax[u][v]);
            node.push({bebanMax[u-1][v], u-1, v});
        }
        if((u + 1 <= R) && (bebanMax[u][v] < bebanMax[u + 1][v]) && (beban[u + 1][v]) != -1){
            bebanMax[u + 1][v] = max(beban[u + 1][v], bebanMax[u][v]);
            node.push({bebanMax[u+1][v], u+1, v});
        }
        if((v - 1 >= 1) && (bebanMax[u][v] < bebanMax[u][v-1]) && (beban[u][v-1]) != -1){
            bebanMax[u][v - 1] = max(beban[u][v-1], bebanMax[u][v]);
            node.push({bebanMax[u][v-1], u, v-1});
        }
        if((v + 1 <= C) && (bebanMax[u][v] < bebanMax[u][v+1]) && (beban[u][v+1]) != -1){
            bebanMax[u][v+1] = max(beban[u][v+1], bebanMax[u][v]);
            node.push({bebanMax[u][v+1], u, v+1});
        }

    }

    cout << bebanMax[c][d];


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> beban[i][j];
        }
    }
    cin >> a >> b >> c >> d;
    solve();
}