#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll V, H, N;
vector <ll> v1;
vector <ll> h1;
vector <ll> v2;
vector <ll> h2;
vector <ll> memo(250000, -1);

ll dp(ll batu){
    if(batu == -1){
        return 0;
    }
    if(memo[batu] != -1){
        return memo[batu];
    }
    ll kiri = h1[batu] - 1;
    ll kanan = h2[batu] + 1;
    ll tinggi = v1[batu];
    int batuKanan = -1, batuKiri = -1;
    int tinggiKanan = -1, tinggiKiri = -1;
    for(int i=0; i<N; i++){
        if(((tinggiKanan > v1[i]) || (tinggiKanan == -1)) && (kanan >= h1[i]) && (kanan <= h2[i]) && (tinggi <= v1[i])){
            batuKanan = i;
            tinggiKanan = v1[i];
        }
    }
    for(int i=0; i<N; i++){
        if(((tinggiKiri > v1[i]) || (tinggiKiri == -1)) && (kiri >= h1[i]) && (kiri <= h2[i]) && (tinggi <= v1[i])){
            batuKiri = i;
            tinggiKiri = v1[i];
        }
    }
    memo[batu] = dp(batuKanan) + dp(batuKiri) + 1;
    return memo[batu];
}

int main(){
    cin >> V >> H >> N;
    v1.resize(N);
    h1.resize(N);
    v2.resize(N);
    h2.resize(N);
    
    for(ll i=0; i<N; i++){ 
        cin >> v1[i] >> h1[i] >> v2[i] >> h2[i];
        v1[i]--;
        h1[i]--;
        v2[i]--;
        h2[i]--;
    }
    ll max = -1;
    for(int i=0; i<H; i++){
        ll minTinggi = V;
        ll batu = -1;
        for(int j=0; j<N; j++){
            if((i >= h1[j]) && (i <= h2[j]) && (minTinggi > v1[j])){
                minTinggi = v1[j];
                batu = j;
            }
        }
        if((max == -1) || (max < dp(batu))){
            max = dp(batu);
        }
    }
    cout << max;

}