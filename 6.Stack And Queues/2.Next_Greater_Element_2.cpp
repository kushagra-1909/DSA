stack<int>st;
int nge[n];

for(int i=2n-1; i>=0; i--){
    while(!st.empty() && st.top() <= arr[i%n]){
        st.pop();
    }
    if(i<n){
        nge[i] = st.empty() ? -1 : st.top();
    }
    st.push(arr[i%n]);
}