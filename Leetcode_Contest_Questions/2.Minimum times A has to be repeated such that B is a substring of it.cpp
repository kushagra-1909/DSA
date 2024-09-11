// Given two strings A and B. Find minimum number of times A has to be repeated such that B
// is a Substring of it. If B can never be a substring then return -1.
// Example 1:
// Input:
// A = "abcd"
// B — "cdabcdab"
// Output:
// 3
// Explanation:
// Repeating A three times ("abcdabcdabcd"),
// B is a substring of it. B is not a substring
// of A when it is repeated less than 3 times.

bool isSubstring(string B, string S){
        int M = S.size();
        int N = B.size();
        
        for(int i=0; i<=M-N; i++){
            int j;
            for(j=0; j<N; j++){
                if(S[i+j] != B[j]){
                    break;
                }
            }
            
            if(j == N) return true;
        }
        
        return false;
    }
    int minRepeats(string A, string B) {
        int ans = 1;
        string S = A;
        
        while(S.size() < B.size()){
            S += A;
            ans++;
        }
        
        if(isSubstring(B,S)) return ans;
        
        if(isSubstring(B,S+A)) return ans+1;
        
        return -1;
    }