#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    if(n1 < n2){
        return true;
    }
    if(n1 > n2){
        return false;
    }

    for (int i=0; i<n1; i++)
    {
       if (s1[i] < s2[i])
          return true;
       if (s1[i] > s2[i])
          return false;
    }
 
    return false;
}

vector<string> numSort(int n , vector<string >& numbers){
    sort(numbers.begin(), numbers.end(), cmp);

    return numbers;
}


int main(){
    int n;
    cin>>n;
    vector<string > numbers(n);
    for(auto &str:numbers){
        cin>> str;
    }
    vector<string> result = numSort(n, numbers);
    for(auto &str: result){
        cout<< str<<" ";
    }
}