/*
Problem Description
You are given two strings, a main string S, and a pattern P. You have to find the starting indices of the anagrams of P in S.


Anagrams are permutations of a string. For P="abc”, its anagrams are abc,acb,bca,bac,cba,cab.


Note that indexing starts at 0.

Input format
There is one line of input, containing two space-separated strings S and P.

Output format
First-line should contain the number of such starting indices.

Next line should contain the indices in increasing order separated by a space.

Sample Input 1
aaba ab

Sample Output 1
2

1 2

Explanation 1
The anagrams of pattern "ab" are “ab” and “ba”. These are present at indices 1 and 2 of the input string “aaba”.
*/

/*
Anagrams - Characters of both the strings are same.
If S and P are anagrams, We can use array/map to add frequency of each charcter
from S and reduce frequency if the charcters are present in P.
If the frequeuncy of every  character is 0, then S and P are anagrams.

Using Array[Find frequency - O(1) (both BC AND WC)]
------------
arr[26] = {0}
for(char ch: S){
    arr[ch - 'a'] += 1
}

Using Map [finding frequncy - O(N) (WC)]
------------

*/

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b){
    vector<int> alpha(26, 0);
    bool result = true;

    for(char ch : a){
        alpha[ch - 'a']++;
    }

    for(char ch : b){
        if(alpha[ch - 'a'] > 0){
            alpha[ch - 'a']--;
        }
    }

    for(int i = 0; i < 26; i++){
        if(alpha[i] > 0){
            result = false;
        }
    }

    return result;
}

vector<int> findAnagrams(string s, string p) // O(n *)
{   
    int window = p.size();
    int n = s.size();
    vector<int> result;

    for(int i = 0; i <= n-window; i++){   
        string sub = s.substr(i, window);
        if(isAnagram(sub, p)){
            result.push_back(i);
        }
    }

    return result;
}



int main()
{
	string s, p;
	cin >> s >> p;
	vector<int> answer = findAnagrams(s, p);
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}