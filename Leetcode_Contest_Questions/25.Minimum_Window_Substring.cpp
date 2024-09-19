// Smallest Distinct Window
// Given a string 's'. Find the length of the smallest substring in a given string having the
// maximum number of distinct characters.
// Example 1:
// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string
// Example 2:
// Input : "AAAB"
// Output : 2
// Explanation : Sub-string
// "BAC"

class Solution{
    public:
    int findSubString(string str)
    {
        set<char>s;
        for(auto c : str){
            s.insert(c);
        }
        int n = s.size(); // no. of distinct characters in string
        int r=0, l=0, ans = str.size();
        unordered_map<char,int>mpp;
        
        while(r<str.size()){
            mpp[str[r]]++;
            if(mpp.size() == n){
                while(mpp[str[l]] > 1){
                    mpp[str[l]]--;
                    l++;
                }
                ans = min(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};