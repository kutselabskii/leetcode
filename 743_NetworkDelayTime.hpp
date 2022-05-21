#pragma once

#include <vector>
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

    dfs(k, 0);

    int answer = -1;
    for (int i = 1; i <= n; ++i) {
        if (best[i] == INT_MAX) {
            return -1;
        }
        answer = max(answer, best[i]);
    }

    return answer;
}