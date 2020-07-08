/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    // Your Code
    q2.push(x);
    while (!q1.empty())
    {
        int item = q1.front();
        q1.pop();
        q2.push(item);
    }

    swap(q1, q2);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    // Your Code
    int item;
    if (q1.empty())
    {
        item = -1;
    }
    else
    {
        item = q1.front();
        q1.pop();
    }

    return item;
}