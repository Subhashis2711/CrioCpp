/*
Problem Description
Reverse the bits of a given 32 bits unsigned integer.

Input format
First line contains the number of test cases.

Each line contains a 32 bit unsigned integer.

Output format
Output the Reversed unsigned integer.

Sample Input 1
1

43261596

Sample Output 1
964176192

Explanation 1
The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 whose binary representation is 00111001011110000010100101000000.


*/
#include <bits/stdc++.h>
using namespace std;

#define INT_SIZE sizeof(int) * 8

/*
Function to reverse bits of a given integer.
*/
unsigned int reverseBits(unsigned int n) {
    /*
    Inititalise the reverse integer to 0 and initialise the position
    to start from MSB
    */
    int reverse = 0;
    int pos = INT_SIZE - 1;     
    
    
    // Iterate the position(pos) back till 0 and check if n != 0
    while (pos >= 0 && n)
    {   
        /*
        Check if the current bit is 1 or 0.
        if n = 5 => 101, (101 & 001 = 001 => 1)
        */
        if (n & 1) {
            /*
            If the current bit is 1, we have to place 1 at the 
            corresponding position starting from MSB.
            We can get a binary digit with 1 at the pos by 1 << pos.
            Then we can calculate reverse OR (1<<pos) to make the 
            bit at pos of reverse as 1.
            */
            reverse = reverse | (1 << pos);
        }
    
        // Right shift n to get the next bit and decrease the pos.
        n >>= 1;                
        pos--;                  
    }
 
    return reverse;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned int n;
		cin >> n;
		unsigned int ans = reverseBits(n);
		cout << ans << endl;
	}
}

