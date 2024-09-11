void partition(vector<int>&arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        // jab tak esa element nhi milta jo pivot se bada h 
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }

        // jab tak esa element nhi milta jo pivot se chhota h 
        while(arr[j] > pivot && j>=low+1){
            j--;
        }

        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}


void quickSort(vector<int>&arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr,low,high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

// T.C -> O(nlogn)