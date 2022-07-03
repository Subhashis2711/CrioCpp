ListNode* removeDups(ListNode* head)
{
	unordered_set<int> st;

	ListNode* cur = head;
	ListNode* prev = NULL;

	
	while(cur != NULL){
		if((prev != NULL) && (st.find(cur->val) != st.end())){
			prev->next = cur->next;
			cur = prev->next;
		}else{
			st.insert(cur->val);
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}