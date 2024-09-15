long long countPairs(int n, int arr[], int k) {
        vector<int>temp(k,0);
        for(int i=0; i<n; i++){
            temp[arr[i]%k]++;
        }
        long long cnt = 0;
        for(int i=0; i<k; i++){
            long long a = temp[i];
            cnt += (a*(a-1))/2;
        }
        return cnt;
    }