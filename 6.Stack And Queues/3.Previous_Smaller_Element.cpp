class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // Reverse the array 
        stack<int>st;
        vector<int>nse(n);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() >= a[i]){
                st.pop();
            }
        
            if(st.empty()){
                nse[i] = -1;
            }
            else{
                nse[i] = st.top();
            }
            st.push(a[i]);
        }
        return nse;
    }
};