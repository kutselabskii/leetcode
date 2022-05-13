#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
	ListNode *root = new ListNode();
	ListNode *head  = root;

	while (list1 != nullptr || list2 != nullptr) {
		if (list1 == nullptr) {
			head->next = list2;
			head = head->next;
			list2 = list2->next;
			continue;
		}

		if (list2 == nullptr) {
			head->next = list1;
			head = head->next;
			list1 = list1->next;
			continue;
		}

		if (list1->val < list2->val) {
			head->next = list1;
			head = head->next;
			list1 = list1->next;
		} else {
			head->next = list2;
			head = head->next;
			list2 = list2->next;
		}
	}

	return root->next;
}