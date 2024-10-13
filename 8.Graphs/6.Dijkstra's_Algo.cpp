// priority queue
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>ds(V,1e9);
        ds[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                if(dist + it[1] < ds[it[0]]){
                    ds[it[0]] = dist + it[1];
                    pq.push({ds[it[0]], it[0]});
                }
            }
        }
        return ds;
    }

    // Time complexity of this algorithm is E logV