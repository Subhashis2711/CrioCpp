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


ListNode* oddEvenLinkedList(ListNode *head) {
    if (head == NULL)
        return NULL;
 
    
    ListNode* odd = head;
    ListNode* even = head->next;
 
   
    ListNode* evenFirst = even;
 
    while (1)
    {
        
        if (!odd || !even || !(even->next))
        {
            odd->next = evenFirst;
            break;
        }
 
        odd->next = even->next;
        odd = even->next;
 
        
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenFirst;
            break;
        }
 
        even->next = odd->next;
        even = odd->next;
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

    ListNode* result = oddEvenLinkedList(l1.getHead());
    l1.printList();
}