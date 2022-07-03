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

ListNode* reverseLinkedList(ListNode *head) {
	ListNode* cur = head;
	ListNode* prev = NULL;
	ListNode* next = NULL;


	while(cur){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	head = prev;

	return head;

}

ListNode* sumLists2(ListNode* head1 , ListNode* head2) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    int carry = 0;

    ListNode* rev_head1 = reverseLinkedList(head1);
    ListNode* rev_head2 = reverseLinkedList(head2);

    while(rev_head1 || rev_head2 || carry){
        int sum = 0;

        if(rev_head1){
            sum += rev_head1->val;
            rev_head1 = rev_head1->next;
        }

        if(rev_head2){
            sum += rev_head2->val;
            rev_head2 = rev_head2->next;
        }

        sum += carry;
        int new_val = sum % 10;
        carry = sum / 10;

        ListNode* node = new ListNode(new_val);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;
}

int main(){
    int n1,n2;
    cin >> n1;

    LinkedList l1;
    for( int i = 0; i < n1; i++){
        int data;
        cin >> data;
        l1.insertNode(data);
    }

    cin>>n2;
    LinkedList l2;
    for( int i = 0; i < n2; i++){
        int data;
        cin >> data;
        l2.insertNode(data);
    }

    ListNode* result = sumLists(l1.getHead(), l2.getHead());
    ListNode* temp = result;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}