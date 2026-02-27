#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fact(ll x){
    if(x == 0){
        return 1;
    }else{
        return x * fact(x-1);
    }
}

ll comb3(ll x){
    return fact(x)/(fact(x-3) * fact(3));
}

int main(){
    ll N; cin>>N;

    
    ll X[N], Y[N];
    for(int i=0; i<N; i++){
        cin>>X[i] >> Y[i];
    }

    if(N < 3){
        cout<<0;
        return 0;
    }

    
    ll total = comb3(N);

    ll segarisX[N];
    ll segarisY[N];
    ll total_segaris = 0;

    for(int i=0; i<N; i++){
        segarisX[i] = 0;
        segarisY[i] = 0;
    }

    for(int i=0; i<N; i++){
        ll titikX = 0;
        ll titikY = 0;
        if(segarisX[i] == 0){
            for(int j=0; j<N; j++){
                if(X[i] == X[j]){
                    titikX++;
                }
            }
            if(titikX > 2){
                segarisX[i] = comb3(titikX);
            }
            total_segaris += segarisX[i];
        }
        if(segarisY[i] == 0){
            for(int j=0; j<N; j++){
                if(Y[i] == Y[j]){
                    titikY++;
                }
            }
            if(titikY > 2){
                segarisY[i] = comb3(titikY);
            }
            total_segaris += segarisY[i];
        }
    }

    total -= total_segaris;
    cout<<total;


}
