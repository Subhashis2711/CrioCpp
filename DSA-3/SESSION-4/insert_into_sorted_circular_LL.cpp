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

ListNode* insertIntoSortedCircularList(ListNode* head, int insertVal)
{	
	ListNode* node = new ListNode(insertVal);

    if(head == NULL){
		node->next = node;
		head = node;
        return head;
	}

    if(head->next == NULL){
        cout<<"hi";
    }
    
    ListNode* prev = head;
    ListNode* cur = head->next;

    while(cur != head ){
        cout<<"hi";
        if(
            (insertVal >= prev->val && insertVal <= cur->val) ||
            (insertVal > prev->val && prev->val > cur->val)||
            (insertVal < cur->val && prev->val > cur->val)
        ){
            break;
        }
        prev = prev->next;
        cur = cur->next;
    }

    prev->next = node;
    node->next = cur;
    

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
    int insertVal;
    cin >> insertVal;

    ListNode* result = insertIntoSortedCircularList(l1.getHead(), insertVal);
    ListNode* temp = result;
    while(temp->next != result){
        cout<<temp->val<<" ";
        temp = temp->next;


    }
    cout<<endl;
}