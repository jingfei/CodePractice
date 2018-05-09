#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

void dfs(deque<int>& ans, vector<vector<int> >& graph, int N, vector<vector<int>>& res) {
  int now = ans.back();
  if(now == N-1) {
    vector<int> tmpans;
    int tmplen = ans.size();
    for(int i=0; i<tmplen; ++i)
      tmpans.push_back(ans[i]);
    res.push_back(tmpans);
    return;
  }
  vector<int> tmp = graph[now];
  int len = tmp.size();
  for(int i=0; i<len; ++i) {
    ans.push_back(tmp[i]);
    dfs(ans, graph, N);
    ans.pop_back();
  }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
  vector<vector<int>> res;
  deque<int> ans;
  int N = graph.size();
  ans.push_back(0);
  dfs(ans, graph, N, res);
  return res;
}

int main() {
  return 0;
}
