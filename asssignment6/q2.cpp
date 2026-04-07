#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    int n = friends.size();
    unordered_set<int> visited;
    queue<int> q;
    visited.insert(id);
    q.push(id);

    int currLevel = 0;

    while (!q.empty() && currLevel < level) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int person = q.front();
            q.pop();
            for (int f : friends[person]) {
                if (!visited.count(f)) {
                    visited.insert(f);
                    q.push(f);
                }
            }
        }
        currLevel++;
    }

    unordered_map<string, int> freq;
    while (!q.empty()) {
        int person = q.front();
        q.pop();
        for (const string& video : watchedVideos[person]) {
            freq[video]++;
        }
    }

    vector<pair<string, int>> videos(freq.begin(), freq.end());
    sort(videos.begin(), videos.end(), [](const auto& a, const auto& b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    vector<string> result;
    for (auto& [video, count] : videos) {
        result.push_back(video);
    }

    return result;
}

int main() {
    vector<vector<string>> watchedVideos = {
        {"A", "B"},
        {"C"},
        {"B", "C"},
        {"D"}
    };

    vector<vector<int>> friends = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    int id = 0;
    int level = 1;

    vector<string> result = watchedVideosByFriends(watchedVideos, friends, id, level);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
