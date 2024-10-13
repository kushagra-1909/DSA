// There are n cities and m edges connected by some number of flights.
// You are given an array flights where flights[ll
// = [fromi, t0i, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest
// price from src to dst with at most k stops. If there is no such route,
// return -1.
// Example 1:
// Input:
// n = 4
// flights — [[0,1,100], [1,2,100], [2,0,100], [1,3,600], [2,3,200]]
// src = 0
// dst = 3
// k = 1
// Output:
// 700
// Explaination:
// The optimal path with at most 1 stop from city 0 to 3 is
// marked in red and has cost 100 + 600 = 700.
// Note that the path through cities is cheaper but is
// mauo oecause It uses 2 stops.

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>>adj[n]; // array of vector aur vector ka data type pair h
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            
            q.pop();
            if(stops > K) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                
                if(cost + edW < dist[adjNode] && stops <= K){
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        
        if(dist[dst] == 1e9){
            return -1;
        }
        
        return dist[dst];
    }

    // Time Complexity -> E => flights.size();