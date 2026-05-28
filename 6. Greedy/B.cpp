#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N;
    cin >> N;

    ll x[N];
    ll y[N];
    for(int i=0; i<N; i++){
        cin >> x[i];
    }
    for(int i=0; i<N; i++){
        cin >> y[i];
    }
    sort(x, x+N);
    sort(y, y+N);

    ll hasil = 0;
    for(ll i=0; i<N; i++){
        hasil += (x[i] * y[N-1-i]);
    }
    cout << hasil;

}