// take an element and place it in its correct order
for(int i=0; i<=n-1; i++){
    int j = i;
    while(j>0 && arr[j-1] > arr[j]){
        swap(arr[j-1],arr[j]);
        j--;
    }
}

// T.C -> O(n^2);