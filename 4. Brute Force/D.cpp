#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    int warna[M][N];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> warna[i][j];
        }
    }
    int B,K;
    cin >> B >> K;
    int baris[M * N];
    int kolom[M * N];
    int total = 1;
    baris[0] = B;
    kolom[0] = K;

    bool lanjut = true;
    while(lanjut){
        lanjut = false;
        int totalSementara = total;
        for(int i=0; i<total;  i++){
            //cout << "debug" << endl;
            if((warna[baris[i]][kolom[i]] == warna[baris[i] + 1][kolom[i]]) && (baris[i] + 1 < M)){
                bool sudahAda = false;
                for(int j=0; j<totalSementara; j++){
                    if((baris[j] == baris[i] + 1) && (kolom[j] == kolom[i])){
                        sudahAda = true;
                        break;
                    }
                }

                if(!sudahAda){
                    baris[totalSementara] = baris[i] + 1;
                    kolom[totalSementara] = kolom[i];
                    totalSementara++;
                    lanjut = true;
                }
                
            }
            if((warna[baris[i]][kolom[i]] == warna[baris[i]][kolom[i] + 1]) && (kolom[i] + 1 < N)){
                bool sudahAda = false;
                for(int j=0; j<totalSementara; j++){
                    if((baris[j] == baris[i]) && (kolom[j] == kolom[i] + 1)){
                        sudahAda = true;
                        break;
                    }
                }
                
                if(!sudahAda){
                    baris[totalSementara] = baris[i];
                    kolom[totalSementara] = kolom[i] + 1;
                    totalSementara++;
                    lanjut = true;
                }
                
            }
            if((warna[baris[i]][kolom[i]] == warna[baris[i] - 1][kolom[i]]) && (baris[i] - 1 >= 0)){
                bool sudahAda = false;
                for(int j=0; j<totalSementara; j++){
                    if((baris[j] == baris[i] - 1) && (kolom[j] == kolom[i])){
                        sudahAda = true;
                        break;
                    }
                }

                if(!sudahAda){
                    baris[totalSementara] = baris[i] - 1;
                    kolom[totalSementara] = kolom[i];
                    totalSementara++;
                    lanjut = true;
                }
                
            }
            if((warna[baris[i]][kolom[i]] == warna[baris[i]][kolom[i] - 1]) && (kolom[i] - 1 >= 0)){
                bool sudahAda = false;
                for(int j=0; j<totalSementara; j++){
                    if((baris[j] == baris[i]) && (kolom[j] == kolom[i] - 1)){
                        sudahAda = true;
                        break;
                    }
                }

                if(!sudahAda){
                    baris[totalSementara] = baris[i];
                    kolom[totalSementara] = kolom[i] - 1;
                    totalSementara++;
                    lanjut = true;
                }
                
            }
        }
        total = totalSementara;
    }
    cout << total * (total - 1) << endl;



}