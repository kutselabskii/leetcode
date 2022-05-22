#pragma once

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> ways;
vector<int> best;

void dfs(int node, int time)
{
    if (time > best[node]) {
        return;
    }

    best[node] = time;
    for (auto& way : ways[node]) {
        dfs(way.first, time + way.second);
    }
}

void bfs(int k)
{
    queue<int> q;
    q.push(k);
    best[k] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto& way : ways[node]) {
            int time = best[node] + way.second;
            if (best[way.first] > time) {
                best[way.first] = time;
                q.push(way.first);
            }
        }
    }
}

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    ways.resize(n + 1);
    best.assign(n + 1, INT_MAX);

    for (int i = 0; i < times.size(); ++i) {
        ways[times[i][0]].push_back({times[i][1], times[i][2]});
    }

    for (int i = 1; i <= n; i++) {
        sort(ways[i].begin(), ways[i].end());
    }

    bfs(k);

    int answer = -1;
    for (int i = 1; i <= n; ++i) {
        if (best[i] == INT_MAX) {
            return -1;
        }
        answer = max(answer, best[i]);
    }

    return answer;
}