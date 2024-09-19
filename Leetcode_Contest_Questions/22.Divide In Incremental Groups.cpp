// Given two integers N and K, the task is to count the number of ways to divide N into K
// groups of positive integers such that their sum is N and the number of elements in groups
// follows a non-decreasing order (i.e. group[i] <= group[i+l]).
// Example 1:
// Input:
// Output:
// 5
// Explanation:
// There are 5 groups such that their sum is 8
// and the number of positive integers in each
// group is 4. The 5 groups are [1, 1, 1, 5],
// [1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3] and

// tabulation Code

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        vector<vector<int>>dp(N+1,vector<int>(K+1,0));
        for(int i=1; i<=N; i++){
            dp[i][1] = 1;
        }
        for(int i=1; i<=N; i++){
            for(int j=2; j<=K; j++){
                if(j>i)continue;
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            }
        }
        return dp[N][K];
    }
};
