#include <bits/stdc++.h>

using namespace std;

map <string, vector<string>> keturunan;
vector<string> garis;
vector<int> idx(10000, 0); 

int main(){
    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        string A, B;
        cin >> A >> B;
        keturunan[A].push_back(B);
    }
    cout << keturunan["mew"][1];
}