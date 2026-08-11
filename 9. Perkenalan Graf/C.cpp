#include <bits/stdc++.h>

using namespace std;

map <string, vector<string>> keturunan;
vector<string> garis;
vector<int> idx(10001, 0); 

int main(){
    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        string A, B;
        cin >> A >> B;
        keturunan[A].push_back(B);
    }
    string awal, akhir; cin >> awal >> akhir;
    garis.push_back(awal);
    bool ketemu = false;
    while(!ketemu){
        if((!keturunan[garis.back()].empty()) && (idx[garis.size()] < keturunan[garis.back()].size())){
            garis.push_back(keturunan[garis.back()][idx[garis.size()]]);
        }
        if(garis.back() == akhir){
            ketemu = true;
        }else if((keturunan[garis.back()].empty()) || (idx[garis.size()] >= keturunan[garis.back()].size())){
            garis.pop_back();
            idx[garis.size()]++;
            for(int i=garis.size()+1; i<10001; i++){
                idx[i] = 0;
            }
        }
        if(garis.size() == 0){
            ketemu = true;
        }
    }
    if(garis.size() != 0){
        for(int i=0; i<garis.size(); i++){
            cout << garis[i] << endl;
        }
        return 0;
    }
    for(int i=0; i<10001; i++){
        idx[i] = 0;
    }
    swap(awal, akhir);
    garis.push_back(awal);
    ketemu = false;
    while(!ketemu){
        if((!keturunan[garis.back()].empty()) && (idx[garis.size()] < keturunan[garis.back()].size())){
            garis.push_back(keturunan[garis.back()][idx[garis.size()]]);
        }
        if(garis.back() == akhir){
            ketemu = true;
        }else if((keturunan[garis.back()].empty()) || (idx[garis.size()] >= keturunan[garis.back()].size())){
            garis.pop_back();
            idx[garis.size()]++;
            for(int i=garis.size()+1; i<10001; i++){
                idx[i] = 0;
            }
        }
        if(garis.size() == 0){
            ketemu = true;
        }
    }
    if(garis.size() != 0){
        for(int i=0; i<garis.size(); i++){
            cout << garis[i] << endl;
        }
    }else{
        cout << "TIDAK MUNGKIN" << endl;
    }
}