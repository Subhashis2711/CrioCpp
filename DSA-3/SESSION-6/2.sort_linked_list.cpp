/*
Problem Description
Given a singly linked list containing N integers, sort it in O(NlogN) time.

Input format
N - An integer denoting the number of nodes in the linked list.

N integers follow where ith integer denotes the ith node value in the linked list-

Output format
Return the head of the sorted list.

Function definition
You have to implement the given function. It accepts the head of the LL as an argument. You have to return the new head of the sorted list after sorting it

Constraints
1 <= N <= 10^5

-10^9 <= value <= 10^9

Sample Input 1
4

4 2 1 3

Sample Output 1
1 2 3 4
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

// Class containing functions to sort the linked list using merge sort algorithm
class SortList {
  public:
    /*
    Function to find the mid of the linked list using two pointer approcach.
    */
    ListNode* findMidOfLinkedList(ListNode* head){
        // Initialize the slow and fast pointer as head and head->next 
        ListNode* slow = head;
        ListNode* fast = head->next;

        if(head){
            /*
            Move the fast pointer with twice speed than slow pointer.
            When the fast or fast->next reaches null, the slowpointer will be at 
            the mid.
            */
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
        }

        return slow;
    }

    /*
    Recursive function to merge two lists into a single list with O(1)
    time complexity.
    */
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val <= l2->val){
            l1->next = mergeLists(l1->next, l2);
            return l1; 
        }else{
            l2->next = mergeLists(l1, l2->next);
            return l2;
        }
    }

    // Function to sort a linked list usingmerge sort algorithm.
    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = new ListNode();
        ListNode* head2 = new ListNode();

        // Find the mid node
        mid = findMidOfLinkedList(head);
        
        /* 
        Split the linked list from the mid by assigning mid->next as a new head
        of the second linked-list and making the mid as the lastnode of the 
        first linked list.
        */
        head2 = mid->next;
        mid->next = NULL;

        // Apply mergesort on both the halves.
        ListNode* first = mergeSort(head);
        ListNode* second = mergeSort(head2);

        // Merge the two sorted halves 
        ListNode* result = mergeLists(first, second);

        return result;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* result = NULL;
        result = mergeSort(head);
        return result;
    }

};

int main(){
    int n;
    cin >> n;

    LinkedList l1;
    for( int i = 0; i < n; i++){
        int data;
        cin >> data;
        l1.insertNode(data);
    }

    ListNode* head = l1.getHead();
    SortList l2;
    ListNode* res = l2.sortList(head);

    ListNode* temp = res;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

