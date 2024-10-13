int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(rows,vector<int>(columns, 1e9));
        dist[0][0] = 0; // source
        pq.push({0,{0,0}});
        
        vector<int>dr = {-1,0,1,0};
        vector<int>dc = {0,1,0,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r == rows-1 && c == columns-1){
                return diff;
            }
            
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr<rows && nc >=0 && nc <columns){
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort , {nr,nc}});
                    }
                }
            }
        }
        return 0;
    }

    // Time Complexity -> E log V
    // n* m* 4 * log(n*m)