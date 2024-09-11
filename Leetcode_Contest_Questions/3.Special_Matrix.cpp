// Given N and a square matrix with dimensions NXN. Find the minimum number of moves
// required to make a matrix special. In a single move, you can select an arbitary element and
// increase/decrease it by 1.
// A special matrix is defined as a matrix where at least one row or column that contains
// only special numbers.
// A special number P is a non-negative integer for which the following quadratic equation has
// at least one negative integer root:
// x^2 - 2*P + x = 0;

int minMoves(int N, vector<vector<int>>matrix){
        vector<int>v;
        for(int i=0; i<50; i++){
            int sn = (i*(i+1))/2;
            v.push_back(sn); 
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<N; i++){
            int c = 0;
            for(int j=0; j<N; j++){
                int x = upper_bound(v.begin(),v.end(),matrix[i][j])-v.begin();
                // x will return that first index which is strictly greater than matrix[i][j]
                c += min(v[x] - matrix[i][j] , matrix[i][j]-v[x-1]);
            }
            ans = min(c,ans);
        }
        
        for(int j=0; j<N; j++){
            int c = 0;
            for(int i=0; i<N; i++){
                int x = upper_bound(v.begin(),v.end(),matrix[i][j])-v.begin();
                // x will return that first index which is strictly greater than matrix[i][j]
                c += min(v[x] - matrix[i][j] , matrix[i][j]-v[x-1]);
            }
            ans = min(c,ans);
        }
        return ans;
    }