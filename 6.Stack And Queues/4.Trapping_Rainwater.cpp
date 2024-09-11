while(l<r){
    if(arr[l] <= arr[r]){
        if(lmax > arr[l]){
            total += lmax-arr[l];
        }
        else{
            lmax = arr[l];
        }
        l++;
    }
    else{
        if(rmax > arr[r]){
            total += rmax-arr[r];
        }
        else{
            rmax = arr[r];
        }
        r--;
    }
}