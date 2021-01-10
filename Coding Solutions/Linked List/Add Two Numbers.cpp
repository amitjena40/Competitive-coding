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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        int carry = 0;
        while (l1 != NULL and l2 != NULL)
        {
            ListNode* ptr = new ListNode;
            int sum = (l1->val + l2->val) + carry;
            if (sum >= 10)
            {
                ptr->val = sum % 10;
                carry = sum / 10;
            }
            else
            {
                ptr->val = sum;
                carry = 0;
            }

            curr->next = ptr;
            curr = ptr;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            ListNode* ptr = new ListNode;
            int sum = l1->val + carry;
            if (sum >= 10)
            {
                ptr->val = sum % 10;
                carry = sum / 10;
            }
            else
            {
                ptr->val = sum;
                carry = 0;
            }

            curr->next = ptr;
            curr = ptr;

            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            ListNode* ptr = new ListNode;
            int sum = l2->val + carry;
            if (sum >= 10)
            {
                ptr->val = sum % 10;
                carry = sum / 10;
            }
            else
            {
                ptr->val = sum;
                carry = 0;
            }

            curr->next = ptr;
            curr = ptr;

            l2 = l2->next;
        }

        if (carry != 0)
        {
            ListNode* ptr = new ListNode(carry);
            curr->next = ptr;
        }

        return head->next;
    }
};