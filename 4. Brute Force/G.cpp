#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<char> warna(625);
vector<vector<int>> daerah(625);
int jumlahDaerah = 0;
int totalMax = -1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> warna[i * 25 + j];
        }
    }

    vector<bool> visited(625, false);
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!visited[i * 25 + j]){
                int currentWarna = warna[i * 25 + j];
                queue<int> antrian;
                antrian.push(i * 25 + j);
                visited[antrian.front()] = true;
                while(!antrian.empty()){
                    if((antrian.front() % 25 != (N-1)) && (!visited[antrian.front() + 1]) && (warna[antrian.front()+1] == currentWarna)){
                        antrian.push(antrian.front() + 1);
                        visited[antrian.back()] = true;
                    }
                    if((antrian.front() % 25 != 0) && (!visited[antrian.front() - 1]) && (warna[antrian.front()-1] == currentWarna)){
                        antrian.push(antrian.front() - 1);
                        visited[antrian.back()] = true;
                    }
                    if((antrian.front() + 25 < M * 25) && (!visited[antrian.front() + 25]) && (warna[antrian.front()+25] == currentWarna)){
                        antrian.push(antrian.front() + 25);
                        visited[antrian.back()] = true;
                    }
                    if((antrian.front() - 25 >= 0) && (!visited[antrian.front() - 25]) && (warna[antrian.front()-25] == currentWarna)){
                        antrian.push(antrian.front() - 25);
                        visited[antrian.back()] = true;
                    }
                    daerah[jumlahDaerah].push_back(antrian.front());
                    antrian.pop();
                }
                jumlahDaerah++;
            }
        }
    }
    int total;
    for(int k=0; k<jumlahDaerah; k++){
        if(daerah[k].size() <= 1) continue;
        total = daerah[k].size() * (daerah[k].size()-1);
        vector<char> newWarna(625);
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                newWarna[i * 25 + j] = warna[i * 25 + j];
            }
        }
        for(int i=0; i<daerah[k].size(); i++){
            newWarna[daerah[k][i]] = '.';
        }
        
        for(int j=N-1; j>=0; j--){
            int turun = 0;
            for(int i=M-1; i>=0; i--){
                if(newWarna[i * 25 + j] == '.'){
                    turun++;
                }else{
                    swap(newWarna[i * 25 + j], newWarna[i * 25 + j + 25 * turun]);
                }
            }
        }

        vector<bool> newVisited(625, false);
        vector<vector<int>> newDaerah(625);
        int newJumlahDaerah = 0;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(!newVisited[i * 25 + j] && (newWarna[i * 25 + j] != '.')){
                    int currentWarna = newWarna[i * 25 + j];
                    queue<int> antrian;
                    antrian.push(i * 25 + j);
                    while(!antrian.empty()){
                        newVisited[antrian.front()] = true;
                        if((antrian.front() % 25 != (N-1)) && (!newVisited[antrian.front() + 1]) && (newWarna[antrian.front()+1] == currentWarna)){
                            antrian.push(antrian.front() + 1);
                            newVisited[antrian.back()] = true;
                        }
                        if((antrian.front() % 25 != 0) && (!newVisited[antrian.front() - 1]) && (newWarna[antrian.front()-1] == currentWarna)){
                            antrian.push(antrian.front() - 1);
                            newVisited[antrian.back()] = true;
                        }
                        if((antrian.front() + 25 < M * 25) && (!newVisited[antrian.front() + 25]) && (newWarna[antrian.front()+25] == currentWarna)){
                            antrian.push(antrian.front() + 25);
                            newVisited[antrian.back()] = true;
                        }
                        if((antrian.front() - 25 >= 0) && (!newVisited[antrian.front() - 25]) && (newWarna[antrian.front()-25] == currentWarna)){
                            antrian.push(antrian.front() - 25);
                            newVisited[antrian.back()] = true;
                        }
                        newDaerah[newJumlahDaerah].push_back(antrian.front());
                        antrian.pop();
                    }
                    newJumlahDaerah++;
                }
            }
        }
        int maxDaerah = 0;
        for(int i=0; i<newJumlahDaerah; i++){
            int totalDaerah = newDaerah[i].size();
            maxDaerah = max(maxDaerah, totalDaerah);
        }
        if(maxDaerah > 1){
            total += (maxDaerah * (maxDaerah - 1));
        }
        totalMax = max(total, totalMax);
        // for(int i=0; i<M; i++){
        //     for(int j=0; j<N; j++){
        //         cout << newWarna[i * 25 + j];
        //     }
        //     cout << endl;
        // }
        // cout << total << " " << maxDaerah << endl;


    }

    cout << totalMax << endl;
    


}