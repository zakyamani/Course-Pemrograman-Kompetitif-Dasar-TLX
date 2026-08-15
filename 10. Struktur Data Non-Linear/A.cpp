#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M;
vector<ll> A(90000);
vector<ll> ketua(90000);
priority_queue<ll> tinggiHujan;
vector<bool> tenggelam(90000, true);
map<ll, vector<ll>> tinggiPulau;
ll total = 0;
ll totalMax = 1;

ll findKetua(ll x){
    if(ketua[x] == x){
        return x;
    }
    ketua[x] = findKetua(ketua[x]);
    return ketua[x];
}

void join(ll x){
    total++;
    ketua[x] = x;
    if((x % 300 != 0) && !tenggelam[x-1]){
        ll rootX = findKetua(x);
        ll rootTetangga = findKetua(x-1);
        if(rootX != rootTetangga){
            total--;
            ketua[rootX] = rootTetangga;
        }
    }
    if((x % 300 != M-1) && !tenggelam[x+1]){
        ll rootX = findKetua(x);
        ll rootTetangga = findKetua(x+1);
        if(rootX != rootTetangga){
            total--;
            ketua[rootX] = rootTetangga;
        }
    }
    if(((x-300) >= 0) && !tenggelam[x-300]){
        ll rootX = findKetua(x);
        ll rootTetangga = findKetua(x-300);
        if(rootX != rootTetangga){
            total--;
            ketua[rootX] = rootTetangga;
        }
    }
    if(((x+300) < N * 300) && !tenggelam[x+300]){
        ll rootX = findKetua(x);
        ll rootTetangga = findKetua(x+300);
        if(rootX != rootTetangga){
            total--;
            ketua[rootX] = rootTetangga;
        }
    }
}

void tinggi(ll h){
    while(!tinggiPulau[h].empty()){
        ll x = tinggiPulau[h].back();
        tenggelam[x] = false;
        join(x);
        tinggiPulau[h].pop_back();
    }
    totalMax = max(totalMax, total);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i * 300 + j];
            tinggiHujan.push(A[i * 300 + j]);
            tinggiPulau[A[i * 300 + j]].push_back(i * 300 + j);
        }
    }

    while(!tinggiHujan.empty()){
        tinggi(tinggiHujan.top());
        tinggiHujan.pop();
    }
    cout << totalMax << endl;
}