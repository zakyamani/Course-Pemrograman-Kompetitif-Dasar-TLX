#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
vector<vector<ll>> vertex(100, vector<ll>(100));
vector<ll> ketua(100);
ll total = 0;

ll findKetua(ll x){
    if(ketua[x] == x){
        return x;
    }
    ketua[x] = findKetua(ketua[x]);
    return ketua[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> node;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ll W; cin >> W;
            node.push({W, i, j});
        }
    }

    for(int i=0; i<N; i++) ketua[i] = i;

    while(!node.empty()){
        ll w = node.top()[0];
        ll u = node.top()[1];
        ll v = node.top()[2];

        ll ketuaU = findKetua(u);
        ll ketuaV = findKetua(v);

        if(ketuaU != ketuaV){
            ketua[ketuaU] = findKetua(ketuaV);
            total += w;
        }
        node.pop();
    }

    cout << total << endl;

    
}