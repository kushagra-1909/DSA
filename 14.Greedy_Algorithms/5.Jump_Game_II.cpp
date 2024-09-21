int fun(int arr[]){
    int jumps = 0, l=0, r=0;
    while(r < N){
        farthest = 0;
        for(int i=l ; i<r; i++){
            farthest = max(i+arr[i] , farthest);
        }
        l = r+1;
        r = farthest;
        jumps++;
    }
    return jumps;
}