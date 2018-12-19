/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	int n = lists.size();
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		ListNode *node = lists[i];
		while (node != NULL)
		{
			temp.push_back(node->val);
			node = node->next;
		}
	}
	sort(temp.begin(), temp.end());
	ListNode *res = new ListNode(0);
	ListNode *ret = res;
	for (int j = 0; j < temp.size(); j++)
	{
		res->next = new ListNode(temp[j]);
		res = res->next;
	}
	return ret->next;
}

};