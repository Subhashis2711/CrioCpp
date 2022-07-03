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

ListNode* partition(ListNode* head , int x) {
    ListNode *result;
    ListNode* small_h = NULL;
    ListNode* small_t = NULL;
    ListNode* eq_h = NULL;
    ListNode* eq_t = NULL; 
    ListNode* great_h = NULL; 
    ListNode* great_t = NULL;

    ListNode* cur = head;

    while(cur != NULL){
        if(cur->val < x){
            if(small_h == NULL){
                small_h = cur;
                small_t = cur;
            }else{
                small_t->next = cur;
                small_t = small_t->next;
            }
        }else if(cur->val == x){
            if(eq_h == NULL){
                eq_h = cur;
                eq_t = cur;
            }else{
                eq_t->next = cur;
                eq_t = eq_t->next;
            }
        }else{
            if(great_h == NULL){
                great_h = cur;
                great_t = cur;
            }else{
                great_t->next = cur;
                great_t = great_t->next;
            }
        }
        cur = cur->next;
    }
    // cout<<small_h->val<<endl;
    // cout<<eq_h->val<<endl;
    // cout<<great_h->val<<endl;


    if(great_t != NULL) great_t->next = NULL;
    
    if(small_h == NULL){
        if(eq_h == NULL){
            return great_h;
        }
        eq_t->next = great_h;
        return eq_h;
    }

    if(eq_h == NULL){
        small_t->next = great_h;
        return small_h;
    }

    small_t->next = eq_h;
    eq_t->next = great_h;

    return small_t;
}

int main(){
    cin >> 

}