// SubArray Of A is good if every pair of indices i1,i2 in that subarray lies within the range of [a,b]
#include<bits/stdc++.h>

int getCount(int n, vector<int>&arr, int a, int b){
    multiset<int>st;
    int i=0, j=0;
    int ans = 0;

    while(i<n){
        while(st.empty() || a <= *(st.begin()) + arr[j] && --(st.end()) + arr[j] <= b){
            st.insert(arr[j]);
            j++;
        }
        ans += j-i;
        st.erase(st.find(arr[i]));
        i++;
    }

    
    return ans;
}