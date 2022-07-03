/*
Problem Description
Given an array in which all numbers except two are repeated once. (i.e. we have 2k+2 numbers and k numbers are occurring twice and remaining two have occurred once).

Find those two numbers in the most efficient way. Return the two numbers in a sorted manner.

Input format
First line of input contains N which denotes the number of elements in the input array.

The next line of input contains N space separated integers.

Output format
Return the two numbers which are present only once in the array in a sorted manner(i.e smaller number first).

Sample Input 1
8

2 3 7 9 11 2 3 11

Sample Output 1
7 9

Explanation
All numbers except 7 and 9 are repeated once.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoNonRepeatingNumbers(int arr[], int n){
    vector<int> result;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        
        if (s.find(arr[i]) != s.end())
            s.erase(arr[i]);
        else
            s.insert(arr[i]);
    }
    for (auto it : s){
        result.push_back(it);
    }

    return result;
        
}
/*
Approach , Using XOR
Function to find two non repeating numbers from an array.
*/
vector<int> twoNonRepeatingNumbers_app1(int arr[], int n){
    vector<int> result;
    int ans = 0;

    /* 
    Iterate through the array and XOR all elements to get XOR of 
    two non-repeating numbers. 
    */
    for(int i = 0; i < n; i++){
        ans ^= arr[i];
    }

    /* 
    Generate a mask by using AND between ans and 2's complement of ans
    By doing this we can get the right most set bit (We have to get a 
    number which has only one set bit of the xor). So that we can divide the 
    numbers into 2 halves and we can get both the numbers separated in
    both the halves.
    */ 
    int mask = ans & -ans;

    // Inititalize num1 and num2 to 0
    int num1 = 0, num2 = 0;

    // Iterate over all the numbers of the array
    for(int i = 0; i < n; i++){
        /* 
        Check if AND between mask and the number gives 0 - first half.
        XOR with num1/num2 to get unique element in both the halves.
        */
        if((mask & arr[i]) == 0){
            num1 ^= arr[i];
        }else{
            num2 ^= arr[i]; 
        }
    }

    // Push the elements to the result vector in ascending order.
    if(num1 < num2){
        result.push_back(num1);
        result.push_back(num2);

    }else{
        result.push_back(num2);
        result.push_back(num1);
    }



    return result;

}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int>ans=twoNonRepeatingNumbers_app1(arr,n);
    cout<<ans[0]<<" "<<ans[1];

}