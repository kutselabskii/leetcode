#pragma once

// Time: O(N + M)
// Memory: O(1)

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
	if (list1 == nullptr) {
		return list2;
	}

	if (list2 == nullptr) {
		return list1;
	}

	ListNode* root = list1->val < list2->val ? list1 : list2;
	ListNode* first = root;
	ListNode* second = root == list1 ? list2 : list1;

	while (second != nullptr) {
		if (first->next == nullptr) {
			first->next = second;
			break;
		}

		if (first->next->val < second->val) {
			first = first->next;
		} else {
			ListNode* save = first->next;
			first->next = second;
			second = save;
			first = first->next;
		}
	}

	return root;
}