#include <bits/stdc++.h>

using namespace std;

map <vector<int>, bool> visited;
queue<vector<int>> node;
queue<int> step;

bool isSorted(int N, vector<int> num){
    bool result = true;
    for(int i=0; i<N; i++){
        if(num[i] != i+1){
            result = false;
            break;
        }
    }
    return result;
}

void solve(int N, vector<int> num, int K){
    int result = -1;
    node.push(num);
    visited[num] = true;
    if(isSorted(N, num)){
        cout << 0 << endl;
        return;
    }

    step.push(0);
    
    while(!node.empty()){
        vector<int> curNode(N);
        for(int i=0; i<N; i++) curNode[i] = node.front()[i];
        if(isSorted(N, curNode)){
            result = step.front();
            break;
        }
        node.pop();
        for(int i=0; i<N-K+1; i++){
            vector<int> newNode(N);
            for(int j=0; j<N; j++) newNode[j] = curNode[j];
            for(int j=0; j<K/2; j++){
                swap(newNode[i+j], newNode[i+K-j-1]);
            }
            if(!visited[newNode]){
                node.push(newNode);
                step.push(step.front() + 1);
                visited[newNode] = true;
            }
        }
        step.pop();
    }
    
    cout << result << endl;
}

int main(){
    int N; cin >> N;
    vector<int> num(N);
    for(int i=0; i<N; i++) cin >> num[i];
    int K; cin >> K;
    solve(N, num, K);
}