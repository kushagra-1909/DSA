class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        queue<int>q;
        vector<int>adj[N];
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>dist(N,1e9);
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
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
