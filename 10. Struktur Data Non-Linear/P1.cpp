#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M;
vector<ll>tinggi(90000);
vector<ll>pulau(90000); // 300 * r + c
vector<bool> tenggelam(90000, true);
ll currentPulau = 0;
queue<ll> baruMuncul;

ll findRepresentative(ll x){
    if(pulau[x] == x){
        return x;
    }else{
        pulau[x] = findRepresentative(pulau[x]);
        return pulau[x];
    }
}

void join(ll x){
    pulau[x] = x;
    if(((x - 300) >= 0) && (!tenggelam[x - 300])){
        pulau[x] = findRepresentative(x-300);
        currentPulau--;
    }
    if(((x-1) >= (x - (x % 300))) && (!tenggelam[x - 1]) && (pulau[x] != pulau[x-1])){
        pulau[x] = findRepresentative(x-1);
        currentPulau--;
    }
    if((x <= (N * M - 301)) && (!tenggelam[x + 300]) && (pulau[x] != pulau[x+300])){
        pulau[x] = findRepresentative(x + 300);
        currentPulau--;
    }
    if(((x+1) <= (x + M - 1 - (x % 300))) && (!tenggelam[x + 1]) && (pulau[x] != pulau[x+1])){
        pulau[x] = findRepresentative(x + 1);
        currentPulau--;
    }
}

void munculkan(ll x){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tinggi[i * 300 + j] == x){
                tenggelam[i * 300 + j] = false;
                currentPulau++;
                baruMuncul.push(i * 300 + j);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    ll hujan[N * M];
    ll idx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tinggi[i * 300 + j];
            hujan[idx] = tinggi[i * 300 + j];
            idx++;
        }
    }
    ll maxPulau = 1;
    sort(hujan, hujan + (N*M));
    for(int i=N*M-1; i>=0; i--){
        if((i > 0) && (hujan[i] == hujan[i-1])){
            continue;
        }
        munculkan(hujan[i]);
        while(!baruMuncul.empty()){
            join(baruMuncul.front());
            baruMuncul.pop();
        }
        maxPulau = max(maxPulau, currentPulau);
    }

    cout << maxPulau << endl;



}