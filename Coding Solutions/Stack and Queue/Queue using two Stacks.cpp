/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    // Your Code
    int item;
    if (s1.empty())
    {
        item = -1;
    }
    else
    {
        while (!s1.empty())
        {
            int element = s1.top();
            s1.pop();
            s2.push(element);
        }
        item = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            int element = s2.top();
            s2.pop();
            s1.push(element);
        }
    }

    return item;
}