#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
int reduceArray(vector<int> arr){
    priority_queue<long int> heap;

    for(long int i = 0; i < arr.size(); i++){
        heap.push(arr[i]);
    }

    while(heap.size() > 1){
        long int x = heap.top();
        heap.pop();

        long int y = heap.top();
        heap.pop();

        if(x != y){
            long int diff = abs(x-y);
            heap.push(diff);
        }


    }

    if(heap.size() == 1){
        return heap.top();
    }else{
        return 0;
    }
}

// NOTE: Please do not modify this function
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0 ; i < n ; ++i) {
        cin >> arr[i];
    }
    int result = reduceArray(arr);
    cout << result << "\n";
}