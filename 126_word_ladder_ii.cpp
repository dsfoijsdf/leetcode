#include <bits/stdc++.h>

using namespace std;

// 和迷宫输出路径一个思路，先bfs找到最短路径，再dfs反向输出。
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int> steps;
        for(string& tmp : wordList) steps[tmp] = 505;
        steps[beginWord] = 0;

        bfs(beginWord, endWord, steps);
        vector<string> ans;
        ans.push_back(endWord);
        dfs(beginWord, ans, steps);
        for(int i = 0; i < res.size(); i++) reverse(res[i].begin(), res[i].end());
        return res;
    }
    void bfs(string start, string end, map<string, int>& steps){
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string cur = q.front(); q.pop();
                for(int j = 0; j < cur.size(); j++){
                    string tmp = cur;
                    for(int k = 0; k < 26; k++){
                        tmp[j] = k+'a';
                        if(tmp == cur || steps.count(tmp) == 0 || steps[tmp] != 505) continue;
                        q.push(tmp);
                        steps[tmp] = steps[cur] + 1;
                        if(cur == end) return;
                    }
                }
            }
        }
    }

    void dfs(string target, vector<string>& ans, map<string, int>& steps){
        string cur = ans.back();
        if(target == cur){
            res.push_back(vector<string>(ans));
            return;
        }
        for(int i = 0; i < cur.size(); i++){
            string tmp = cur;
            for(int j = 0; j < 26; j++){
                tmp[i] = j + 'a';
                if(tmp == cur || steps.count(tmp) == 0 || steps[tmp] != steps[cur]-1) continue;
                ans.push_back(tmp);
                dfs(target, ans, steps);
                ans.pop_back();
            }
        }
    }
};