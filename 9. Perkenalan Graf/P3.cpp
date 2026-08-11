#include <bits/stdc++.h>

using namespace std;

int durasiMax = -1;
int virusMax;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, S, P; cin >> N >> S >> P;
    int durasi[N+1];
    for(int i=1; i<=N; i++) cin >> durasi[i];
    map<int, string> virus;
    int pendahulu[P];
    for(int i=0; i<P; i++){
        string nama;
        int pasien;
        cin >> nama >> pasien;
        pendahulu[i] = pasien;
        virus[pasien] = nama;
    }
    vector<vector<int>> korban(N+1);
    for(int i=0; i<N-P; i++){
        int j,k; cin >> j >> k;
        korban[j].push_back(k);
    }
    vector<bool> visited(N+1, false);
    

    for(int i=0; i<P; i++){
        stack<int> num;
        stack<int> idx;
        int total = durasi[pendahulu[i]];
        num.push(pendahulu[i]);
        visited[num.top()] = true;
        if((korban[num.top()].size() > 0) && (!visited[korban[num.top()][0]])){
            visited[korban[num.top()][0]] = true;
            idx.push(0);
            num.push(korban[num.top()][0]);
            total += durasi[num.top()];
        }
        if(total > durasiMax){
            durasiMax = total;
            virusMax = i;
        }

        while(!idx.empty()){
            if((korban[num.top()].size() > 0) && (!visited[korban[num.top()][0]])){
                visited[korban[num.top()][0]] = true;
                idx.push(0);
                num.push(korban[num.top()][0]);
                total += durasi[num.top()];
            }else{
                int term = idx.top();
                term++;
                total -= durasi[num.top()];
                idx.pop();
                num.pop();
                if(korban[num.top()].size() > term){
                    idx.push(term);
                    num.push(korban[num.top()][idx.top()]);
                    total += durasi[num.top()];
                }   
            }

            if(total > durasiMax){
                durasiMax = total;
                virusMax = i;
            }
        }
    }

    cout << virus[pendahulu[virusMax]] << endl << durasiMax << endl;
}