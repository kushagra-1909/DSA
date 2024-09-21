// insert interval in a given array such that it is not overlapping 
fun(arr[][], newInterval[]){
    res[][], i=0;
    while(i<n && arr[i][1] < newInterval[0]){
        res.add(arr[i]);
        i=i+1;
    }

    while(i<n && arr[i][0] < newInterval[1]){
        newInterval[0] = min(newInterval[0], arr[i][0]);
        newInterval[1] = max(newInterval[1], arr[i][1]);
        i=i+1;
    }
}

res.add(newInterval);

while(i<N){
    res.add(arr[i]);
    i++;
}

return res;