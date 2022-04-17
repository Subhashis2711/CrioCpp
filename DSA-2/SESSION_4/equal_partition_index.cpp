#include <bits/stdc++.h>
using namespace std;

int equalPartition(int n, vector<int> arr)
{
    int right_sum = 0, left_sum = arr[0];

    right_sum = accumulate(arr.begin(), arr.end(), 0);

    for (int i = 1 ; i < n; i++) {
        right_sum -= arr[i-1];
        left_sum += arr[i];

        if (left_sum == right_sum)
            return i;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &el : arr)
    {
        cin >> el;
    }
    int answer = equalPartition(n, arr);
    cout << answer << "\n";
}