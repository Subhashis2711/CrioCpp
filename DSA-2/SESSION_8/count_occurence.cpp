#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int key, int first = true)
{
    int n = arr.size();
    while(low <= high){
        int mid = low + (high-low) / 2;

        if(first){
            if(arr[mid] == key && (mid == 0 || arr[mid - 1] != key)){
                return mid;
            }

            if(arr[mid] == key || arr[mid] > key){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid] == key && (mid == n-1 || arr[mid + 1] != key)){
                return mid;
            }

            if(arr[mid] == key || arr[mid] < key){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return -1;
}


int countOccurrences(int n, vector<int> &arr, int k){
    int first_occ = binarySearch(arr, 0, n-1, k);

    if(first_occ == -1)
        return 0;
    
    int last_occ = binarySearch(arr, 0, n-1, k, false);
    

    return last_occ - first_occ + 1;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = countOccurrences(n, arr, k);
    cout << result;
}