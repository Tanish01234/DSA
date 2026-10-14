#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> g[10];
bool visit[10];

void dfs(int u) {
  visit[u] = true;
  cout << u << " ";

  for (int v : g[u]) {
    if (!visit[v])
      dfs(v);
  }
}

void bfs(int start) {
  queue<int> q;

  q.push(start);
  visit[start] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    cout << u << " ";

    for (int v : g[u]) {
      if (!visit[v]) {
        visit[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  g[0].push_back(1);
  g[0].push_back(2);
  g[1].push_back(3);
  g[1].push_back(4);
  g[2].push_back(5);
  g[3].push_back(6);

  cout << "dfs: ";
  dfs(0);

  for (int i = 0; i < 10; i++)
    visit[i] = false;

  cout << "\nbfs: ";
  bfs(0);

  return 0;
}