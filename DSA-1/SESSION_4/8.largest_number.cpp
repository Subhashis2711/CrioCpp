#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
float findLargestNumber(float a, float b, float c){
    return (a > b)? ((a > c)? a : c) : ((b > c)? b : c);
}

// NOTE: Please do not modify this function
int main(){
    float a, b, c;
    cin >> a >> b >> c;
    float result = findLargestNumber(a, b, c);
    cout << result;
}