// Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be
// selected to light up all the edges of the tree.
// An edge lights up when at least one node at the end of the edge is selected.
// Example 1:
// Input:
// edges[]
// = {(1,2), (1,3), (2,4), (3,5), (3,6)}
// 2
// Output:
// Explanation: Selecting nodes 2 and 3 lights
// up all the edges.

class Solution{
  public:
    bool dfs(int src, vector<int>adj[], vector<int>vis, int &cnt){
        vis[src] = 1;
        bool select = false;
        for(auto it: adj[src]){
            if(!vis[it] && !dfs(it,adj,vis,cnt)){
                select = true;
            }
        }
        if(select == true){
            cnt ++;
        }
        return select;
    }
    int countVertex(int N, vector<vector<int>>edges){
        vector<int>adj[N+1];
        int cnt = 0;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(N+1,0);
        dfs(1,adj,vis,cnt);
        return cnt;
    }
};