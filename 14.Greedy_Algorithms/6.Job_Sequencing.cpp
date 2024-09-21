static bool comp(Job val1, Job val2){
        return val1.profit > val2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sabse pehle profit ke according sort karna padega
        // phir uss task ko bilkul deadline ke paas karna h
        vector<int>ans;
        sort(arr,arr + n,comp);
        int maxDeadline = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(arr[i].dead > maxDeadline){
                maxDeadline = arr[i].dead;
            }
        }
        
        vector<int>hash(maxDeadline + 1,-1);
        
        int maxProfit=0, cnt=0;
        
        for(int i=0; i<n; i++){
            for(int j=arr[i].dead ; j>0; j--){
                    if(hash[j] == -1){
                        maxProfit += arr[i].profit;
                        hash[j] = arr[i].id;
                        cnt++;
                        break;
                    }
                }
        }
        ans.push_back(cnt);
        ans.push_back(maxProfit);
        return ans;
        
    } 