// longest Substring without repeating characters
// 2pointer approach

int l=0, r=0;
unordered_map<char,int>mpp;
int len =0;

while(r<n){
    if(mpp.find(s[i]) == mpp.end()){
        mpp[s[i]] = r;
    }
    else if(mpp[s[i]] < l && mpp.find(s[i]) != mpp.end()){
        l = mpp[s[i]] + 1;
        mpp[s[i]] = r;
    }
    len = max(len,r-l+1);
}
