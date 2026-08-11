#include <bits/stdc++.h>

using namespace std;

int N, M, A, B;
vector<vector<int>> maze(100, vector<int>(100));
map <vector<int>, bool> visited;
queue<vector<int>> node;
queue<int> step;

void solve(){
    int result = -1;
    node.push({A,B});
    step.push(0);
    int y, x;
    visited[node.front()] = true;
    while(!node.empty()){
        y = node.front()[0];
        x = node.front()[1];
        if((y == 0) || (y == N-1) || (x == 0) || (x == M-1)){
            result = step.front() + 1;
            break;
        }
        if((y+1 < N) && (maze[y+1][x] == 0) && (!visited[{y+1, x}])){
            node.push({y+1, x});
            step.push(step.front() + 1);
            visited[{y+1, x}] = true;
        }
        if((y-1 >= 0) && (maze[y-1][x] == 0) && (!visited[{y-1, x}])){
            node.push({y-1, x});
            step.push(step.front() + 1);
            visited[{y-1, x}] = true;
        }
        if((x+1 < M) && (maze[y][x+1] == 0) && (!visited[{y, x+1}])){
            node.push({y, x+1});
            step.push(step.front() + 1);
            visited[{y, x+1}] = true;
        }
        if((x-1 >= 0) && (maze[y][x-1] == 0) && (!visited[{y, x-1}])){
            node.push({y, x-1});
            step.push(step.front() + 1);
            visited[{y, x-1}] = true;
        }
        step.pop();
        node.pop();
    }
    cout << result << endl;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin >> maze[i][j];
    }
    cin >> A >> B;
    A--;
    B--;
    solve();

}