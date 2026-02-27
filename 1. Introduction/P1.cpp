#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ll N, M, X;
    cin >> N >> M >> X;
    
    ll mtr[4][max(N,M)][max(N,M)];
    // mtr 0 N M
    // mtr 1 N M
    // mtr 2 M N
    // mtr 3 M N
    for(ll i=0; i<N; i++){
        for(ll j=0; j<M; j++){
            cin >> mtr[0][i][j];
        }
    }
    ll currentmat = 0;
    ll nextmat = 1;

    for(ll i=1; i<=X; i++){
        string op;
        cin >> op;
        
        if(op == "90"){
            if((currentmat == 0) || (currentmat == 1)){
                nextmat = 2;
                for(ll j=0; j<M; j++){
                    for(ll k=0; k<N; k++){
                        mtr[nextmat][j][k] = mtr[currentmat][N-1-k][j];
                    }
                }
            }else{
                nextmat = 0;
                for(ll j=0; j<N; j++){
                    for(ll k=0; k<M; k++){
                        mtr[nextmat][j][k] = mtr[currentmat][M-1-k][j];
                    }
                }
            }
            currentmat = nextmat;
            
        }else if(op == "180"){
            if((currentmat == 0) || (currentmat == 1)){
                if(currentmat == 0){
                    nextmat = 1;
                }else{
                    nextmat = 0;
                }

                for(ll j=0; j<N; j++){
                    for(ll k=0; k<M; k++){
                        mtr[nextmat][j][k] = mtr[currentmat][N-1-j][M-1-k];
                    }
                }
            }else{
                if(currentmat == 2){
                    nextmat = 3;
                }else{
                    nextmat = 2;
                }

                for(ll j=0; j<M; j++){
                    for(ll k=0; k<N; k++){
                        mtr[nextmat][j][k] = mtr[currentmat][M-1-j][N-1-k];
                    }
                }
            }
            currentmat = nextmat;

        }else if(op == "270"){
            if((currentmat == 0) || (currentmat == 1)){
                nextmat = 2;
                for(ll j=0; j<M; j++){
                    for(ll k=0; k<N; k++){
                        mtr[nextmat][j][k] = mtr[currentmat][k][M-1-j];
                    }
                }
            }else{
                nextmat = 0;
                for(ll j=0; j<N; j++){
                    for(ll k=0; k<M; k++){
                        mtr[nextmat][j][k] = mtr[currentmat][k][N-1-j];
                    }
                }
            }
            currentmat = nextmat;

        }else if(op == "_"){
            if((currentmat == 0) || (currentmat == 1)){
                for(ll j=0; j<N/2; j++){
                    for(ll k=0; k<M; k++){
                        swap(mtr[currentmat][j][k], mtr[currentmat][N-1-j][k]);
                    }
                }
            }else{
                for(ll j=0; j<M/2; j++){
                    for(ll k=0; k<N; k++){
                        swap(mtr[currentmat][j][k], mtr[currentmat][M-1-j][k]);
                    }
                }
            }
        }else{
            if((currentmat == 0) || (currentmat == 1)){
                for(ll j=0; j<N; j++){
                    for(ll k=0; k<M/2; k++){
                        swap(mtr[currentmat][j][k], mtr[currentmat][j][M-1-k]);
                    }
                }
            }else{
                for(ll j=0; j<M; j++){
                    for(ll k=0; k<N/2; k++){
                        swap(mtr[currentmat][j][k], mtr[currentmat][j][N-1-k]);
                    }
                }
            }
        }
        

    }
    if((currentmat == 0) || (currentmat == 1)){
        for(ll i=0; i<N; i++){
            for(ll j=0; j<M; j++){
                cout << mtr[currentmat][i][j] <<" ";
            }
            cout<<endl;
        }
    }else{
        for(ll i=0; i<M; i++){
            for(ll j=0; j<N; j++){
                cout << mtr[currentmat][i][j] <<" ";
            }
            cout<<endl;
        }
    }
    

}