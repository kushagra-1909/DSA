int r=0, l=0;
int n = arr.size();
unordered_map<int,int>mpp; // int->freq


while(r<n){
    mpp[arr[r]]++;
    if(mpp.size() > k){
        mpp[arr[l]]--;
        if(mpp[arr[l]] == 0){
            mpp.erase(mpp[arr[l]]);
        }
    }
    if(mpp.size() <= k){
        maxlen = max(maxlen,r-l+1);
    }
    r++;
}

return maxlen;