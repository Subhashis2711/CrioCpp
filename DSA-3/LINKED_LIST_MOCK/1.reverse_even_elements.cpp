/*
Problem Description
Given a singly linked list of integers, reverse every contiguous set of nodes that have only even values.

Input format
N - An integer denoting the number of nodes in the linked list.

N integers follow where ith integer denotes the ith node value in the linked list

Output format
Return the head of the modified list

Constraints
0 <= N <= 10^5

-10^9 <= value <= 10^9

Sample Input 1
8

1 2 3 3 4 6 8 5

Sample Output 1
1 2 3 3 8 6 4 5

Explanation 1
There are two sublists of even elements, which [2] and [4->6->8]. The sublist [4->6->8] has been reversed and the single sublist [2] need not be reversed.
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
	int val;
	ListNode* next;

	ListNode() {}

	ListNode(int x) {
	    val = x;
	    next = NULL;
	}
};

class LinkedList{
    public:
    ListNode* head = NULL;
    ListNode* tail = NULL;

    LinkedList(){
        head = NULL;
    }

    void insertNode(int val){
        ListNode* node = new ListNode(val);
        ListNode* cur = head;

        if(!head){
            head = node;
            tail = node;
            return;
        }else{
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = node;
            tail = node;
            return;
        }
    }

    int length(){
        int len = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            len++;
        } 

        return len;
    }

    void printList(){
        ListNode* cur = head;
        while(cur != NULL){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<"\n";
        return;
    }

    ListNode* getHead(){
        return head;
    }
};

ListNode* reverse(ListNode* head){
    // Inialise current to head and tempand prev to NULL
    ListNode* cur = head;
    ListNode* temp = NULL;
    ListNode* prev= NULL;

    // Iterate till cur is not NULL
    while(cur != NULL){
        /*
        If cur element is even, reverse it using steps-
        1. Store cur in temp.
        2. Move forward cur by one node.
        3. Connect temp to previous.
        4. Make temp as previous.
        Else-
        1. Append cur to the next of node (starting of adjacent evens)
        2.Return prev.
        */
        if(cur->val % 2 == 0){
            temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
            if(cur == NULL){
                return prev;
            }
            
        }else{
            head->next = cur;
            return prev;
        }
    }

    return head;
}

// Function to reverse the contigous even elements found in a linked list.
ListNode* reverseEvenElements(ListNode *head) {
	ListNode *result;
    
    // If head is null, return NULL
    if(!head) return head;

    // Initialise the current to head and even_start to NULL 
    ListNode* cur = head;
    ListNode* even_start = NULL;

    /*
    Iterate through the linked list and check all adjacent nodes 
    till the last node.
    */
    while(cur !=NULL && cur->next != NULL){
        if((cur->val % 2 == 0) && (cur->next->val % 2 == 0)){
            /* 
            If even_start is still NULL, means the adjacent nodes 
            from starting are even. 
            */
            if(even_start == NULL){
                /* 
                Apply reverse operation on the cur node till odd element 
                is found and modify the head accordingly.
                */
                head = reverse(cur);
                
            }else{
                // Else reverse the intermediate nodes and append it to the even_start.
                even_start->next = reverse(cur);
            }
        }

        // Make even_start as current node and move forward the current node.
        even_start = cur;
        cur = cur->next;
    }

    

    return head;

}
    

int main(){
    int n1;
    cin >> n1;

    LinkedList l1;
    for( int i = 0; i < n1; i++){
        int data;
        cin >> data;
        l1.insertNode(data);
    }

    ListNode* result = reverseEvenElements(l1.getHead());
    ListNode* temp = result;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;


    }
    cout<<endl;
}