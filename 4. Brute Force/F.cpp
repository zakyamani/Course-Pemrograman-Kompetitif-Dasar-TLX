#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, N;
    cin >> M >> N;
    char warna[M][N];
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> warna[i][j];
        }
    }

    int baris[M][N][M * N];
    int kolom[M][N][M * N];
    bool include[M][N];
    int total[M][N];

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            include[i][j] = false;
        }
    }

    for(int B=0; B<M; B++){
        for(int K=0; K<N; K++){
            baris[B][K][0] = B;
            kolom[B][K][0] = K;
            total[B][K] = 1;
            if(include[B][K]){
                continue;
            }

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
                                include[baris[B][K][i] + 1][kolom[B][K][i]] = true;
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
                                include[baris[B][K][i]][kolom[B][K][i] + 1];
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
                                include[baris[B][K][i] - 1][kolom[B][K][i]] = true;
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
                                include [baris[B][K][i]][kolom[B][K][i] - 1] = true;
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
    int maxBaris;
    int maxKolom;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(total[i][j] > totalMax){
                totalMax = total[i][j];
                maxBaris = i;
                maxKolom = j;
            }
        }
    }

    for(int i=0; i<totalMax; i++){
        warna[baris[maxBaris][maxKolom][i]][kolom[maxBaris][maxKolom][i]] = '.';
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(warna[i][j] == '.'){
                bool turun = false;
                for(int k=i; k > 0; k--){
                    if(warna[k-1][j] != '.'){
                        warna[k][j] = warna[k-1][j];
                    }
                    turun = true;
                }
                if(turun){
                    for(int k=0; k<i; k++){
                        if(warna[k][j] != '.'){
                            warna[k][j] = '.';
                            break;
                        }
                    }
                }
                
            }
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout << warna[i][j] << " ";
        }
        cout << endl;
    }

    




}