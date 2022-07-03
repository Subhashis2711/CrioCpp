#include <bits/stdc++.h>
using namespace std;

int nextGreaterElementWithSameSetOfDigits(int n){
    string str_n = to_string(n);
    int i;
    int size = str_n.size();
    for(i = size-1; i > 0; i--){
        if(str_n[i-1] < str_n[i]){
            break;
        }
    }

    if(i != 0){
        int min = i;
        for(int j = i; j < size; j++){
            if(str_n[j] > str_n[i-1]){
                min = j;
            }
        }

        

        swap(str_n[i-1], str_n[min]);
        reverse(str_n.begin()+i, str_n.end());
    }else{
        return -1;
    }


    return stoi(str_n);
}


int main(){
    int n;
    cin>>n;
    cout<<nextGreaterElementWithSameSetOfDigits(n);
    return 0;
}