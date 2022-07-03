#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int min_q;

void push( int x) {
    if (s.empty())
    {
        s.push(x);
        min_q = x;
    }
    else if (x > min_q) {
        s.push(x);
    }
    else {
        s.push(2*x - min_q);
        min_q = x;
    }

}

void pop() {
    
    if(!s.empty()){
        int top = s.top();
        if (top < min_q) {
            min_q = 2*min_q - top;
        }
        s.pop();
    }

}

int findMin() {
    if(!s.empty()){
        return min_q;
    }else{
        return -1;
    }

}

int main()
{
    int n, m, t;
    cin >> t;
    while (t--) {
        int ch;
        cin >> ch;
        if ( ch  == 1) {
            cin >> n;
            push(n);
        }
        else if ( ch == 2)
            pop();
        else
            cout << findMin() << endl;
    }

}







