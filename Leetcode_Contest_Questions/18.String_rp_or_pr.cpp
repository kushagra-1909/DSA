// Given a string S. In one operation, you can remove the substring "pr" from the string S and
// get amount X or you can remove the substring "rp" and get the amount Y.
// Find the maximum amount you can get if you perform zero or more such operations
// optimally.
// Note :
// •
// •
// Substring of a string S is defined as a continuous sequence of characters in S.
// After removing "pr" or "rp", the order of remaining letters should remain the same.
// Example:
// Input:
// S "abppprrr"
// Output: 15
// Explanation:
// https://practice.geeksforgeeks.org/contest/interview-series-google-2/problems


class Solution{   
public:
    long long solve(int X,int Y,string S){
        int n = S.size();
        int ans = 0;
        int i = 0;
        if(X>Y){
            while(i<n){
                if(S[i] == 'p' && S[i+1] == 'r'){
                    S.erase(S.begin()+i, S.begin()+i+2);
                    i = 0;
                    ans += X;
                }
                i++;
            }
            i = 0;
            while(i<n){
                if(S[i] == 'r' && S[i+1] == 'p'){
                    S.erase(S.begin()+i, S.begin()+i+2);
                    i = 0;
                    ans += Y;
                }
                i++;
            }
        }else{
            while(i<n){
                if(S[i] == 'r' && S[i+1] == 'p'){
                    S.erase(S.begin()+i, S.begin()+i+2);
                    i = 0;
                    ans += Y;
                }
                i++;
            }
            i = 0;
            while(i<n){
                if(S[i] == 'p' && S[i+1] == 'r'){
                    S.erase(S.begin()+i, S.begin()+i+2);
                    i = 0;
                    ans += X;
                }
                i++;
            }
        }
        return ans;
    }
};


// correct code
class Solution{   
public:
    
    long long help(int first, int second, string s, string rem){
        stack<char>st;
        long long total = 0;
        for(int i=0; i<s.size(); i++){
            if(st.size() && s[i] == rem[1] && st.top() == rem[0]){
                total += first;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        s = "";
        while(st.size()){
            s += st.top();
            st.pop();
        }
        for(int i=0; i<s.size(); i++){
            if(st.size() && s[i] == rem[1] && st.top() == rem[0]){
                total += second;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return total;
    }
    long long solve(int X,int Y,string S){
      if(X>Y){
        return help(X,Y,S,"pr");  
      }
      else{
        return help(Y,X,S,"rp");
      }
    }
};