#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
typedef long long ll;
vector<int>adj[1000001];
bool visited[1000001];
void dfs(int src){
    stack<int>stk;
    stk.push(src);
    while(stk.empty()==false){
        int node=stk.top();
        stk.pop();
        if(visited[node]==false){
            visited[node]=true;
            cout<<node<<" ";
            #pragma omp parallel for 
            for(int i=0;i<adj[node].size();i++){
                int adjNode=adj[node][i];
                if(visited[adjNode]==false){
                    stk.push(adjNode);
                }
            }
        }
    }
}
int main(){
    int n,m,src;
    cin>>n>>m>>src;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    #pragma omp parallel for
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    dfs(src);
    return 0;
}

// Input
// 6 5 1
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
