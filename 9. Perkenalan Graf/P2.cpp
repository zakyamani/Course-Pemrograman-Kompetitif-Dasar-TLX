#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll T, N, M, K, S;
vector<vector<ll>> J(10, vector<ll>(2));
vector<ll> I(2);

void solve(ll N, ll M, ll K, ll S, vector<ll> I, vector<vector<ll>> J){
    bool result = false;
    queue<vector<ll>> blok;
    queue<ll> step;

    for(int i=0; i<K; i++){
        vector<vector<bool>> visited(501, vector<bool>(501, false));
        visited[J[i][0]][J[i][1]] = true;
        blok.push(J[i]);
        step.push(0);
        while(!blok.empty()){
            ll y = blok.front()[0];
            ll x = blok.front()[1];

            if(visited[I[0]][I[1]]){
                result = true;
                break;
            }

            if((y + 2 <= N) && (x + 1 <= M) && (!visited[y+2][x+1])){
                
                if(step.front() < S){
                    visited[y+2][x+1] = true;
                    step.push(step.front() + 1);
                    blok.push({y+2,x+1});
                }
            }
            if((y - 2 > 0) && (x + 1 <= M) && (!visited[y-2][x+1])){
                
                if(step.front() < S){
                    visited[y-2][x+1] = true;
                    step.push(step.front() + 1);
                    blok.push({y-2,x+1});
                }

            }
            if((y + 2 <= N) && (x - 1 > 0) && (!visited[y+2][x-1])){
                if(step.front() < S){
                    visited[y+2][x-1] = true;
                    step.push(step.front() + 1);
                    blok.push({y+2,x-1});
                }
            }
            if((y - 2 > 0) && (x - 1 > 0) && (!visited[y-2][x-1])){
                if(step.front() < S){
                    visited[y-2][x-1] = true;
                    step.push(step.front() + 1);
                    blok.push({y-2,x-1});
                }
            }
            if((y + 1 <= N) && (x + 2 <= M) && (!visited[y+1][x+2])){
                
                if(step.front() < S){
                    visited[y+1][x+2] = true;
                    step.push(step.front() + 1);
                    blok.push({y+1,x+2});
                }
            }
            if((y - 1 > 0) && (x + 2 <= M) && (!visited[y-1][x+2])){
            
                if(step.front() < S){
                    visited[y-1][x+2] = true;
                    step.push(step.front() + 1);
                    blok.push({y-1,x+2});
                }
            }
            if((y + 1 <= N) && (x - 2 > 0) && (!visited[y+1][x-2])){
                
                if(step.front() < S){
                    visited[y+1][x-2] = true;
                    step.push(step.front() + 1);
                    blok.push({y+1,x-2});
                }
            }
            if((y - 1 > 0) && (x - 2 > 0) && (!visited[y-1][x-2])){
                
                if(step.front() < S){
                    visited[y-1][x-2] = true;
                    step.push(step.front() + 1);
                    blok.push({y-1,x-2});
                }
            }
            step.pop();
            blok.pop();
        }
    }
    if(result){
        cout << "TRUE" << endl;
    }else{
        cout << "FALSE" << endl;
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M >> K >> S >> I[0] >> I[1];    
        for(int i=0; i<K; i++) cin >> J[i][0] >> J[i][1];
        solve(N, M, K, S, I, J);
    }
}