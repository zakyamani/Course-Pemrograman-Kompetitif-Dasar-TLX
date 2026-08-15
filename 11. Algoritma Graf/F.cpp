#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, T, A, B;
vector<vector<ll>> jalan(501);
ll durasiMinimum = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T >> A >> B;
    for(int i=0; i<M; i++){
        ll U, V;
        cin >> U >> V;
        jalan[U].push_back(V);
        jalan[V].push_back(U);
    }
    for(int i=0; i<T; i++){
        ll X, Y; cin >> X >> Y;
        jalan[X].push_back(Y);
        jalan[Y].push_back(X);
        queue<pair<ll,ll>> step;
        step.push({A, 0});
        vector<bool> visited(N + 1, false);
        visited[A] = true;
        ll currNode;
        ll currStep;
        bool nemuJakarta = false;
        while(!step.empty()){
            currNode = step.front().first;
            currStep = step.front().second;
            step.pop();
            if(currNode == B){
                nemuJakarta = true;
                break;
            }
            for(int i=0; i<jalan[currNode].size(); i++){
                ll nextNode = jalan[currNode][i];
                if(!visited[nextNode]){
                    visited[nextNode] = true;
                    step.push({nextNode, currStep + 1});
                }
            }
        }
        if(nemuJakarta) durasiMinimum = min(durasiMinimum, currStep);
        jalan[X].pop_back();
        jalan[Y].pop_back();
    }
    cout << durasiMinimum << endl;

}