// You are given a 2D matrix grid consisting of positive integers.

// You have to select one or more cells from the matrix such that the following conditions are satisfied:

// No two selected cells are in the same row of the matrix.
// The values in the set of selected cells are unique.
// Your score will be the sum of the values of the selected cells.

// Return the maximum score you can achieve.

// Dp with bitmasking

class Solution {
public:
    int score(int val, int row_mask, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(val > 100) return 0;

        if(dp[val][row_mask] != -1){
            return dp[val][row_mask];
        }

        dp[val][row_mask] = score(val+1,row_mask,grid,dp);

        for(int r=0; r<grid.size(); r++){
            if(row_mask & (1<<r)) continue;
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] != val)continue;
                dp[val][row_mask] = max(dp[val][row_mask] , val+score(val+1,row_mask|(1<<r),grid,dp));
            }
        }
        return dp[val][row_mask];
    }
    int maxScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>>dp(101,vector<int>(pow(2,rows)+1,-1));
        return score(1,0,grid,dp);
    }
};