#include <bits/stdc++.h>
using namespace std;


long long contigiousSequence( vector<long long > &arr) {
    long long cur_sum = 0;
    long long max_sum = LLONG_MIN;
    cout << max_sum << endl;

    for(long long int i = 0; i < arr.size(); i++){
        cur_sum += arr[i];
        max_sum = max(cur_sum, max_sum);


        if(cur_sum < 0){
            cur_sum = 0;
        }
        

    }

    return max_sum;
}

int main()
{
	int n;
	cin >> n;
	vector<long long> arr(n);
	for ( int i = 0; i < n ; i++)  cin >> arr[i];
	long long mx = contigiousSequence(arr);
	cout << mx << endl;
}
