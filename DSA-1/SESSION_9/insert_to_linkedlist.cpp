#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;

    ListNode(int _data = 0) {
        data = _data;
        next = NULL;
    }
};

// Use new ListNode(data) to create new node

class LinkedList {

public:
    ListNode *head;
    ListNode *tail;

    LinkedList() {
        head = tail = NULL;
    }

    void insertAtBeginning(int data) {
        ListNode *new_node = new ListNode(data);

        if(head == NULL){
            head = new_node;
            tail = new_node;
        }else{
            new_node->next = head;
            head = new_node;
        }
    }

    void insertAtEnd(int data) {
        ListNode *new_node = new ListNode(data);

        if(head == NULL){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node;
            tail = tail->next;
        }
        
    }
};