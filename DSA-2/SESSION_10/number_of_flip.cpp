#include<bits/stdc++.h>
using namespace std;
int countSetBits(long long n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= (n-1);
    }
    return count;
}

int countConversionBits(long long a, long long b) {
    return countSetBits(a^b);

}

int main() {
	long long a , b;
	cin >> a >> b;
	int answer = countConversionBits(a, b);
	cout << answer;
	return 0;
}