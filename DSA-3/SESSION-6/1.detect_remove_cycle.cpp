/*
Problem Description
Given a linked list, determine if it has a cycle in it.


A linked list cycle means that for last node of LL, called last, last->next is not NULL, but instead points to some other node of the LL(not last itself)


Internally, to represent a cycle in the given linked list, we use an integer pos which represents the zero-indexed position of the node that the last node of the LL is connected to. If pos = -1, it means that there is no cycle in the LL. Note that pos is not passed as a parameter.


For instance, consider an LL 1->2->3->4 and pos = 1. This means that there is a cycle such that 4 is connected to the node at position 1, that is, the node with value 2.

Input format:
There are 2 lines of input.

First line contains space separated integers, denoting the elements of the linked list.

The next line contains one integer - pos, the position that the tail connects to.

Output format
Print "true" without quotes if it has a cycle in it else “false”.

Function definition
You have to complete the given function. It accepts a single argument, the head of the LL, and returns a boolean value - true if there’s a cycle, false if not. You will NOT have access to the variable pos in the function.

Sample Input 1
3 2 0 -4

1

Sample Output 1
true
*/

#include <bits/stdc++.h>
using namespace std;

/* 
Listnode class to create a node for a linked list 
*/
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

/* 
Linked List class containing various operations of a linked list 
*/
class LinkedList{
    public:
    ListNode* head = NULL;
    ListNode* tail = NULL;

    // Constructor
    LinkedList(){
        head = NULL;
    }

    /* Function to insert a node at the end of a linked list */
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

    /* Function to get the length of the linkedlist */
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

    /* Function to create a cycle at a given index from the end */
    void createCycle(int cycle_index){
        ListNode* last = head;
        int len = length();

        ListNode* temp = head;
        if(cycle_index != -1){
            while(cycle_index > 0){
                temp = temp->next;
                --cycle_index;
            }
        }

        tail->next = temp;
    }

    ListNode* getHead(){
        return head;
    }
};

/* 
Function to detect and remove cycle from a linked list.
Parameters: 
meet(ListNode*) - Node at which fast and slow pointers meet.
head(ListNode*) - Head of the linked list.
*/
void removeCycle(ListNode* meet, ListNode* head){
    // Start a pointer from the head 
    ListNode* start = head;

    /* 
    If cycle starts from the first node, move the meet to the end
    of the list.
    Else move the start and meet pointer with same speed until they
    meet. Stop at the previous node.
    */
    if(start == meet){
        while(meet->next != start){
            meet = meet->next;
        }
    }else{

        while(start->next != meet->next){
            start = start->next;
            meet = meet->next;
        }
    }

    // Break the link of the connecting node that makes a cycle.
    meet->next = NULL;
}

/*
Function to check if a cycle is present in the list and remove the cycle.
*/
bool detectAndRemoveCycle(ListNode* head){
    // Initilise two pointers(fast and slow)
    ListNode* p1 = head;
    ListNode* p2 = head;

    /*
    Move the fast pointer with twice speed than the slow pointer.
    If both of them meet somewhere, we can tell that cycle is present.
    */
    while(p1 != NULL && p2 != NULL && p2->next != NULL){
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1 == p2){
            removeCycle(p1, head);
            return true;
            break;
        }
    } 
    
    return false;
}

int main(){
    int n;
    cin >> n;

    LinkedList l1;
    for( int i = 0; i < n; i++){
        int data;
        cin >> data;
        l1.insertNode(data);
    }

    int cycle_index;
    cin >> cycle_index;
    l1.createCycle(cycle_index);

    ListNode* head = l1.getHead();
    bool isCycle = detectAndRemoveCycle(head);
    cout << isCycle << endl;
    l1.printList();
}


