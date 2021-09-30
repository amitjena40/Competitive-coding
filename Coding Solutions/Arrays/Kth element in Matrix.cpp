struct cmp {
  bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
    return x.first > y.first;
  }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

  for (int j = 0; j < n; j++)
  {
    pq.push(make_pair(mat[0][j], make_pair(0, j)));
  }

  for (int cnt = 0; cnt < k - 1 && !pq.empty(); cnt++)
  {
    int i = pq.top().second.first, j = pq.top().second.second;
    pq.pop();

    if (i + 1 < n)
      pq.push(make_pair(mat[i + 1][j], make_pair(i + 1, j)));
  }

  return pq.top().first;
}