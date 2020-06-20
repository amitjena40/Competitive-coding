// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */

Node* reverse(Node* head) {
    Node *prev, *current, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

bool isPalindrome(Node *head)
{
    //Your code here
    int n = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        n++;
        ptr = ptr->next;
    }

    if (n == 1)
    {
        return true;
    }

    Node *left = head, *right;
    int count = 0;
    ptr = left;
    while (count <= (n / 2))
    {
        count++;
        if (count == (n / 2))
        {
            if (n % 2 == 0)
            {
                right = reverse(ptr->next);
            }
            else
            {
                right = reverse(ptr->next->next);
            }
            ptr->next = NULL;
            break;
        }
        ptr = ptr->next;
    }

    Node *ptr1 = left, *ptr2 = right;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    right = reverse(right);
    ptr1  = left;
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = right;
    return true;
}

