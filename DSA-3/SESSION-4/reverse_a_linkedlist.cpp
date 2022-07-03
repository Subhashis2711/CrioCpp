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