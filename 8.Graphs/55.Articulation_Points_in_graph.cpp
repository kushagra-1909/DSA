// Nodes on whose removal the graph breaks into two or more components
// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// tin[] -> store the time of insertion when doing dfs
// low[] -> min of all adjacent nodes apart from parent and visited nodes

class Solution {
  private:
    int timer = 1;
    void dfs(int node, int parent, vector<int>&vis, vector<int>adj[], int tin[], 
             int low[], vector<int>&mark){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer ++;
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,vis,adj,tin,low,mark);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>vis(V,0);
        int low[V];
        int tin[V];
        vector<int>mark(V,0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,tin,low,mark);
            }
        }
        
        vector<int>ans;
        for(int i=0; i<V; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};