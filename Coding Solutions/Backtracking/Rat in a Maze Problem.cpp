// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

void ratMaze(int row, int col, int m[][MAX], int n, vector<string> &ans, string probAns)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(probAns);
        return;
    }


    if (row + 1 < n)
    {
        if (m[row + 1][col] == 1)
        {
            probAns += "D";
            m[row][col] = 0;
            ratMaze(row + 1, col, m, n, ans, probAns);
            probAns.pop_back();
            m[row][col] = 1;
        }
    }

    if (col - 1 >= 0)
    {
        if (m[row][col - 1] == 1)
        {
            probAns += "L";
            m[row][col] = 0;
            ratMaze(row, col - 1, m, n, ans, probAns);
            probAns.pop_back();
            m[row][col] = 1;
        }
    }

    if (col + 1 < n)
    {
        if (m[row][col + 1] == 1)
        {
            probAns += "R";
            m[row][col] = 0;
            ratMaze(row, col + 1, m, n, ans, probAns);
            probAns.pop_back();
            m[row][col] = 1;
        }
    }


    if (row - 1 >= 0)
    {
        if (m[row - 1][col] == 1)
        {
            probAns += "U";
            m[row][col] = 0;
            ratMaze(row - 1, col, m, n, ans, probAns);
            probAns.pop_back();
            m[row][col] = 1;
        }
    }
}

vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> ans;
    string probAns = "";
    if (m[0][0] == 1)
        ratMaze(0, 0, m, n, ans, probAns);

    return ans;
}
