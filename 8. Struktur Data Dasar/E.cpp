#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int N; cin >> N;
    int Q; cin >> Q;
    map <string, vector<string>> no;
    while(N--){
        string nama; cin >> nama;
        string nomor; cin >> nomor;
        no[nama].push_back(nomor);
    }

    while(Q--){
        string nama; cin >> nama;
        if(no[nama].empty()){
            cout << "NIHIL" << endl;
        }else{
            cout << no[nama].front() << endl;
        }
    }
    
}