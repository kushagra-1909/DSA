int smallestSubstring(string S) {
        int l=0, r=0, cnt=INT_MAX;
        map<char,int>mpp;
        
        while(r<S.size()){
            mpp[S[r]]++;
            while(mpp.size() == 3){
                cnt = min(cnt,r-l+1);
                mpp[S[l]]--;
                if(mpp[S[l]] == 0){
                    mpp.erase(S[l]);
                }
                l++;
            }
            r++;
        }
        
        if(cnt != INT_MAX){
            return cnt;
        }
        else{
            return -1;
        }
    }