#include <bits/stdc++.h>
using namespace std;

// TODO: Implement this method
string bigIntegerAddition(string num1 , string num2){
	if(num1.length() > num2.length()){
		swap(num1, num2);
	}

	int n1 = num1.length();
	int n2 = num2.length();
	int diff = n2-n1;

	int carry = 0;
	string res = "";

	for(int i = n1-1; i >= 0; i--){
		int sum = ((num1[i] - '0') + (num2[i+diff] - '0') + carry);
		res.push_back(sum%10 + '0');
		carry = sum/10;
		
	}

	for(int i = diff-1; i >= 0; i--){
		int sum = (num2[i] - '0') + carry;
		res.push_back(sum%10 + '0');
		carry = sum/10;

	}

	if(carry){
		res.push_back(carry + '0');
	}

	reverse(res.begin(), res.end());

	return res;
} 

// NOTE: Please do not modify this function
int main() 
{ 
	string str1,str2;
    cin>>str1>>str2;
	cout << bigIntegerAddition(str1, str2)<<endl; 
	return 0; 
} 
