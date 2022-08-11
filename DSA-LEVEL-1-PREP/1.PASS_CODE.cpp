#include <bits/stdc++.h>
using namespace std;

string passCode(string A,string B){
    string pass_code = "";
    int n1 = A.size();
    int n2 = B.size();


    int i = 0, j = 0;
    while(i < n1 && j < n2){
        pass_code.push_back(A[i]);
        pass_code.push_back(B[i]);
        i++;
        j++;
    }

    if(i == n1 && j == n2){
        return pass_code;
    }else{
        if(i == n1 && j != n2){
            for(int k = i; k < n2; k++){
                pass_code.push_back(B[k]);
            }
        }else if(j == n2 && i != n1){
            for(int k = j; k < n1; k++){
                pass_code.push_back(A[k]);
            }
        }
    }

    return pass_code;

    
}


int main(){
    string A,B;
    cin>>A>>B;
    cout<<passCode(A,B);
}