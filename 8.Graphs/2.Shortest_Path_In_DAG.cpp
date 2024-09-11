// User function Template for C++
class Solution {
  public:
    void dfs(int s, vector<pair<int,int>>adj[], vector<int>&vis, stack<int>&st){
        vis[s] = 1;
         
        for(auto it : adj[s]){
            if(!vis[it.first]){
                dfs(it.first,adj,vis,st);
            }
        }
        
        st.push(s);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        vector<int>vis(N,0);
        stack<int>st;
        vector<int>dist(N,1e9);
        vector<pair<int,int>>adj[N];
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(it : adj[node]){
                if(it.second + dist[node] <= dist[it.first]){
                    dist[it.first] = it.second + dist[node];
                }
            }   
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
        
    }
};