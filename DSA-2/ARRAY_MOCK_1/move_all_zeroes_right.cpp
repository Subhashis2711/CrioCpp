/*
Problem Description
Given an array A, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Input format
First line will contain a single integer N representing the size of array

Next line will contain N space separated integers representing the array A.

Output format
First line should contain N space separated integers.

Sample Input 1
2

0 1

Sample Output 1
1 0

Constraints:
1<=N<=200000

0<=A[i]<=100000
*/

#include<bits/stdc++.h>
using namespace std;



vector<int > moveZeroes(vector<int > arr)
{   
    int count = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != 0){
            arr[count] = arr[i];
            count += 1;
        }
    }

    for(int i = count; i < arr.size(); i++){
        arr[i] = 0;
    }

    return arr;

}
int main()
{
	int n;
	cin>>n;
	vector<int > arr(n);
	for(int i=0;i < n;i++)
		cin>>arr[i];
	vector<int > result = moveZeroes(arr);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	return 0;
}