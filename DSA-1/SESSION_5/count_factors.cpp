#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
pair<int, int> numberOfDivisorsAndSum(int n)
{
    int sum = 0;
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            sum += i;
            count += 1;
        }
    }

    return {count, sum};
}

// NOTE: Please do not modify this function
int main()
{
    int n;
    cin >> n;
    pair<int, int> ans = numberOfDivisorsAndSum(n);
    cout << ans.first << " " << ans.second << endl;
}