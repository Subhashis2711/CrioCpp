#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cout<<"Enter a three digit integer: "<<endl;
    cin>>n;
    int num = n;

    int sum = 0;
    while(n > 0){
        int rem = n % 10;
        sum += rem;
        n = n/10;
    }

    int req_sum = ((sum / 10) + 1)*10;
    int digit = req_sum - sum;
    string dig_str = to_string(digit);

    
    string num_str = to_string(num);
    num_str.insert(1, dig_str);

    int res_num = stoi(num_str);

    cout<<"The PIN number is: "<< res_num;
}