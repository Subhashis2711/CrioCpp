#include <bits/stdc++.h>
using namespace std;

long long trailingZeros(long long n)
{   
    if (n < 0){
        return -1;
    }
    int count = 0;
    int power = 5;


    while(n/power >= 1){
        count += n/power;
        power = power * 5;

    }

    return count;
}
int main()
{
	long long  n;
	cin >> n;
	cout << trailingZeros(n) << endl;
	return 0;
}