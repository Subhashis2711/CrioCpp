#include <bits/stdc++.h>
using namespace std;

#define MAX 500


int multiply(int x, vector<int> &res, int res_size)
{
    int carry = 0;  
 
    for (int i=0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; 
        carry  = prod/10;   
    }
 
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

// TODO: Implement this method
vector<int> largeFactorial(int n) 
{ 
    vector<int> res(MAX);
    vector<int> result;

    res[0] = 1;

    int res_size = 1;

    for (int i=2; i<=n; i++){
        res_size = multiply(i, res, res_size);
    }
    reverse(res.begin(), res.begin()+res_size);
 
    for(int i = 0; i < res_size; i++){
        result.push_back(res[i]);
    }

    return result;
} 

// NOTE: Please do not modify this function
int main(){
    int n;
    cin>>n;
    vector<int> ans = largeFactorial(n);
    for( int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
}