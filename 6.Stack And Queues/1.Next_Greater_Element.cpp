stack<int>st;
int nge[n];

for(int i=n-1; i>=0; i--){
    while(!st.empty() && st.top() <= arr[i]){
        st.pop();
    }

    if(st.empty()){
        nge[i] = -1;
    }
    else{
        nge[i] = st.top();
    }

    st.push(arr[i]);
}

//T.C -> O(2N)