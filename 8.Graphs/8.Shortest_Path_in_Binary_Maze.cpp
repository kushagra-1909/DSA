int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int sr = source.first;
        int sc = source.second;
        int dr = destination.first;
        int dc = destination.second;
        
        if(grid[sr][sc] == 0 || grid[dr][dc] == 0){
            return -1;
        }
        
        if(sr == dr && sc == dc){
            return 0;
        }
        
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{sr,sc}});
        vector<vector<int>>dist(r,vector<int>(c,1e9));
        dist[sr][sc] = 0;
        
        while(!q.empty()){
            int dis = q.front().first;
            int cr = q.front().second.first;
            int cc = q.front().second.second;
            q.pop();
            
            for(int der = -1; der<=1; der++){
                for(int dec = -1; dec<=1; dec++){
                    if(abs(der) != abs(dec)){
                        int nr = cr + der;
                        int nc = cc + dec;
                        if(nr>=0 && nr<r && nc >= 0 && nc < c && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]) {
                            dist[nr][nc] = dis+1;
                            if(nr == dr && nc == dc){
                                return dist[dr][dc];
                            }
                            q.push({1+dis,{nr,nc}});
                        }
                    }
                }
            }
        }
        
        return -1;
    }