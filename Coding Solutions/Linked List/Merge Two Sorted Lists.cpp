/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2, *sortedHead = NULL;
        ListNode *temp3 = sortedHead;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val < temp2->val)
            {
                if (temp3 == NULL)
                {
                    temp3 = temp1;
                    sortedHead = temp3;
                    temp1 = temp1->next;
                    continue;
                }
                temp3->next = temp1;
                temp3 = temp1;
                temp1 = temp1->next;
            }
            else
            {
                if (temp3 == NULL)
                {
                    temp3 = temp2;
                    sortedHead = temp3;
                    temp2 = temp2->next;
                    continue;
                }
                temp3->next = temp2;
                temp3 = temp2;
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL)
        {
            if (temp3 == NULL)
            {
                temp3 = temp1;
                sortedHead = temp3;
                temp1 = temp1->next;
                continue;
            }
            temp3->next = temp1;
            temp3 = temp1;
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            if (temp3 == NULL)
            {
                temp3 = temp2;
                sortedHead = temp3;
                temp2 = temp2->next;
                continue;
            }
            temp3->next = temp2;
            temp3 = temp2;
            temp2 = temp2->next;
        }

        return sortedHead;
    }
};

//Better Solution
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};