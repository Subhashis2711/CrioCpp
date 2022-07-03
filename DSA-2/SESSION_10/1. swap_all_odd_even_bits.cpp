/*
Problem Description
Given an unsigned integer N, swap all odd bits with even bits. Every even position bit is swapped with the adjacent bit on the right side and every odd position bit is swapped with adjacent on the left side. Assume a 32 bit integer.

Input format
N which represents an unsigned integer.

Output format
Single output integer after the algorithm has successfully swapped bits of the input.

Constraints
0 <= N <= 2147483647

Sample Input 1
22

Sample Output 1
41

Explanation 1
The given number is 22 (00010110), it should be converted to 41 (00101001).
*/
#include<bits/stdc++.h>
using namespace std;

void printBinary(unsigned int n){
    for(int i = 32; i >= 0; i--){
        cout << ((n >> i) & 1);
    }
    cout<<endl;
}

/*
Approach-1:
Function to swap all even and odd bits using loop.
*/
unsigned int swapAllOddAndEvenBits_app1(unsigned int n) {
    // Start a loop from 0th bit till 32nd bit.
    for(int i = 0; i < 32; i += 2){
        /*
        Get the ith bit and i+1th bit.
        Apply AND(&) between n and 1<<i. if the result > 0. The ith 
        bit is 1, else 0;
        e.g
        22 -> 00010110
        let i = 2
        1 << 2 = 00000100
        00010110
        00000100
        ---------
        00000100   > 1 => So 2nd bit is 1
        */
        int i_bit = ((n & (1 << i)) > 0) ? 1 : 0;
        int i_1_bit = ((n & (1 << (i+1))) > 0) ? 1 : 0;

        // Check if the adjacent bits (odd and even) are not equal
        if(i_bit != i_1_bit){
            // Toggle the bits to swap using XOR(^).
            n = n ^ (1 << i);
            n = n ^ (1 << i+1);
        } 
    }

    return n;
}

unsigned int swapAllOddAndEvenBits_app2(unsigned int n) {
    unsigned int even_bits = n & 0xAAAAAAAA;
 
    unsigned int odd_bits = n & 0x55555555;
 
    even_bits >>= 1; 
    odd_bits <<= 1; 
 
    return (even_bits | odd_bits); 
}


int main()
{
	unsigned int n;
	cin >> n;
	unsigned int answer = swapAllOddAndEvenBits_app1(n);
	cout << answer;
	return 0;
}