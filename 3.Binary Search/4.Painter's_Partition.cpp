// low -> maximum of array , high -> sum of all pages of array
// low = max(arr), high = sum of all elements of arr

int countStudents(vector<int>&arr, int pages){
    int students = 1;
    long long pagesStudent = 0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }
        else{
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>&arr, int n, int m){
    // n -> number of books , m -> number of students
    if(m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low <= high){
        int mid = (low + high)/2;
        int students = countStudents(arr,mid);
        if(student > m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}