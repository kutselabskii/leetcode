#include <iostream>

#include "21_MergeTwoSortedLists.hpp";

int main()
{
	int a[] = {2};
	int b[] = {1};

	ListNode *l1 = nullptr, *l2 = nullptr, *h1 = nullptr, *h2 = nullptr;

	for (auto s : a) {
		if (l1 == nullptr) {
			l1 = new ListNode(s);
			h1 = l1;
		} else {
			h1->next = new ListNode(s);
			h1 = h1->next;
		}
	}

	for (auto s : b) {
		if (l2 == nullptr) {
			l2 = new ListNode(s);
			h2 = l2;
		} else {
			h2->next = new ListNode(s);
			h2 = h2->next;
		}
	}

	auto res = mergeTwoLists(l1, l2);

	std::cin.get();
	return 0;
}

