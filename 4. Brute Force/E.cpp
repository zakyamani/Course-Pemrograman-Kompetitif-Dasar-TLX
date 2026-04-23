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

    int baris[M][N][M * N];
    int kolom[M][N][M * N];
    int total[M][N];

    for(int B=0; B<M; B++){
        for(int K=0; K<N; K++){
            baris[B][K][0] = B;
            kolom[B][K][0] = K;
            total[B][K] = 1;

            bool lanjut = true;

            while(lanjut){
                lanjut = false;
                int totalSementara = total[B][K];
                for(int i=0; i<total[B][K];  i++){
                    if((warna[baris[B][K][i]][kolom[B][K][i]] == warna[baris[B][K][i] + 1][kolom[B][K][i]]) && (baris[B][K][i] + 1 < M)){
                        bool sudahAda = false;
                        for(int j=0; j<totalSementara; j++){
                            if((baris[B][K][j] == baris[B][K][i] + 1) && (kolom[B][K][j] == kolom[B][K][i])){
                                sudahAda = true;
                                break;
                            }
                        }

                        if(!sudahAda){
                            baris[B][K][totalSementara] = baris[B][K][i] + 1;
                            kolom[B][K][totalSementara] = kolom[B][K][i];
                            totalSementara++;
                            lanjut = true;
                        }
                
                    }
                    if((warna[baris[B][K][i]][kolom[B][K][i]] == warna[baris[B][K][i]][kolom[B][K][i] + 1]) && (kolom[B][K][i] + 1 < N)){
                        bool sudahAda = false;
                        for(int j=0; j<totalSementara; j++){
                            if((baris[B][K][j] == baris[B][K][i]) && (kolom[B][K][j] == kolom[B][K][i] + 1)){
                                sudahAda = true;
                                break;
                            }
                        }
                
                        if(!sudahAda){
                            baris[B][K][totalSementara] = baris[B][K][i];
                            kolom[B][K][totalSementara] = kolom[B][K][i] + 1;
                            totalSementara++;
                            lanjut = true;
                        }
                
                    }
                    if((warna[baris[B][K][i]][kolom[B][K][i]] == warna[baris[B][K][i] - 1][kolom[B][K][i]]) && (baris[B][K][i] - 1 >= 0)){
                        bool sudahAda = false;
                        for(int j=0; j<totalSementara; j++){
                            if((baris[B][K][j] == baris[B][K][i] - 1) && (kolom[B][K][j] == kolom[B][K][i])){
                                sudahAda = true;
                                break;
                            }
                        }

                        if(!sudahAda){
                            baris[B][K][totalSementara] = baris[B][K][i] - 1;
                            kolom[B][K][totalSementara] = kolom[B][K][i];
                            totalSementara++;
                            lanjut = true;
                        }
                
                    }
                    if((warna[baris[B][K][i]][kolom[B][K][i]] == warna[baris[B][K][i]][kolom[B][K][i] - 1]) && (kolom[B][K][i] - 1 >= 0)){
                        bool sudahAda = false;
                        for(int j=0; j<totalSementara; j++){
                            if((baris[B][K][j] == baris[B][K][i]) && (kolom[B][K][j] == kolom[B][K][i] - 1)){
                                sudahAda = true;
                                break;
                            }
                        }

                        if(!sudahAda){
                            baris[B][K][totalSementara] = baris[B][K][i];
                            kolom[B][K][totalSementara] = kolom[B][K][i] - 1;
                            totalSementara++;
                            lanjut = true;
                        }
                
                    }
                }
                total[B][K] = totalSementara;
            }

        }
    }

    int totalMax = 0;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(total[i][j] > totalMax){
                totalMax = total[i][j];
            }
        }
    }
    cout << totalMax * (totalMax - 1);




}