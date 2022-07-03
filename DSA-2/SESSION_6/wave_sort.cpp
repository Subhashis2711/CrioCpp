#include <bits/stdc++.h>
using namespace std;

vector<int> wiggleSort(vector<int> &arr , int n) {
    sort(arr.begin(), arr.end());

    vector<int> res(n);
    int p1 = 0, p2 = (n/2);

    int i = 0;
    while(p1 < n/2 || p2 < n){

        if(i % 2 == 0){
            res[i] = arr[p1];
            p1++;
        }else{
            res[i] = arr[p2];
            p2++;
        }
        i++;
    }

    return res;

}

vector<int> wiggleSort_a2(vector<int> &arr , int n) {
    for(int i = 1; i < n; i += 2){
        if(i > 0 && arr[i-1] > arr[i]){
            swap(arr[i], arr[i-1]);
        }

        if(i < n-1 && arr[i+1] > arr[i]){
            swap(arr[i], arr[i+1]);
        }
    }

    return arr;
}



int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> ans = wiggleSort_a2(arr, n);
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

}