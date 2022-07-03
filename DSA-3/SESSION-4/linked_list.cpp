#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode* next;

    // Constructor
    ListNode(int _val = 0){
        val = _val;
        next = NULL;

    }
};

class LinkedList{
    public:
    ListNode* head = NULL;

    LinkedList(){
        head = NULL;
    }

    void insertNode(int val){
        ListNode* node = new ListNode(val);
        ListNode* cur = head;

        if(!head){
            head = node;
            return;
        }else{
            while(cur->next != NULL){
                cur = cur->next;
            }
            cur->next = node;
            return;
        }
    }

    void insertAt(int pos, int val){
        ListNode* node = new ListNode(val);
        if(pos = 0){
            // Insertion at beginning
            node->next = head;
            head = node;


        }else{
            ListNode* cur = head;

            while(cur != NULL && --pos > 0){
                cur = cur->next;
            }

            // Insertion after a node
            if(cur){
                if(cur->next){
                    node->next = cur->next;
                    cur->next = node;
                }
            }
        }
    }

    void deleteAt(int pos){
        if(head == NULL) return;
        if(pos == 0){
            head = head->next;
            return;
        }else{
            ListNode* cur = head;
            while(cur && --pos){
                cur = cur->next;

            }
            if(cur->next){
                cur->next = cur->next->next;
            }
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
};

int main(){
    LinkedList l1;
    l1.insertNode(10);
    l1.insertNode(20);
    l1.printList();
}


