/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    // Your code here
    Node *copy = NULL;
    Node *ptr1 = head;
    while (ptr1 != NULL)
    {
        Node *newNode = new Node(ptr1->data);
        newNode->next = ptr1->next;
        if (copy == NULL)
        {
            copy = newNode;
        }
        ptr1->next = newNode;
        ptr1 = ptr1->next->next;
    }

    ptr1 = head;
    while (ptr1 != NULL)
    {
        if (ptr1->arb != NULL)
        {
            ptr1->next->arb = ptr1->arb->next;
        }
        ptr1 = ptr1->next->next;
    }

    ptr1 = head;
    Node *ptr2 = copy;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->next != NULL)
        {
            ptr1->next = ptr1->next->next;
        }

        if (ptr2->next != NULL)
        {
            ptr2->next = ptr2->next->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return copy;
}