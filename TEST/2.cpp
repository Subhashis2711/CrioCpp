#include<iostream>
#include<string>
using namespace std;

int main(){
    int day, mon;
    cout<<"Enter your birth date(day and month) as 2 integers separated by space"<<endl;
    cin>>day>>mon;
    
    int sum = 0;
    while(day > 0){
        int rem = day % 10;
        sum += rem;
        day = day / 10;
    }

    int sum_by_month = sum/mon;
    int sum_per_month = sum%mon;

    float res = sum_by_month + sum_per_month;

    cout<<"Your Lucky Number is: "<<res;

    
}