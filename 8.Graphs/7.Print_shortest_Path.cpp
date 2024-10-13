// In this problem i have to print the shortest path from node 1 to node n using dijkstras algorithm

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1, 1e9);
        dist[1] = 0;
        pq.push({0,1});
        vector<int>res;
        vector<int>parent(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        
        vector<pair<int,int>>adj[n+1];
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        while(!pq.empty()){
            int edgeWeight = pq.top().first;
            int vertix = pq.top().second;
            pq.pop();
            
            for(auto it : adj[vertix]){
                int weight = it.second;
                int adjNode = it.first;
                
                if(edgeWeight + weight < dist[adjNode]){
                    dist[adjNode] = edgeWeight + weight;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode] = vertix;
                } 
            }
        }
        if(dist[n] == 1e9){
            res.push_back(-1);
            return res;
        }
        int path = n;
        res.push_back(n);
        while(path != 1){
            path = parent[path];
            res.push_back(path);
        }
        res.push_back(1);
        res.push_back(dist[n]);
        reverse(res.begin(),res.end());
        return res;
    }