// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a;
    cin >> n;
    while (!isEmpty()) {
      pop();
    }
    while (!isFull(n)) {
      cin >> a;
      push(a);
    }
    cout << getMin() << endl;
  }
}// } Driver Code Ends


/*Complete the function(s) below*/
int mn = 1000000000;
void push(int a)
{
  //add code here.
  s.push(a);
  mn = min(mn, a);
}

bool isFull(int n)
{
  //add code here.
  return (s.size() == n);
}

bool isEmpty()
{
  //add code here.
  return s.empty();
}

int pop()
{
  //add code here.
  int item = s.top();
  s.pop();
  return item;
}

int getMin()
{
  //add code here.
  int item = mn;
  mn = 10000000;
  return item;
}