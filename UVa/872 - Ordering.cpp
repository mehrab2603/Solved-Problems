#include<bits/stdc++.h>

using namespace std;

const int MAX = 30;

bool vis[MAX];
int indegree[MAX];
char rev[MAX];
map< char, int > variable;
vector< int > adj[MAX];
vector< vector< int > > ans;

void dfs(int, int, vector< int >);

struct Compare {
    bool operator()(const vector< int >& v1, const vector< int >& v2) const {
        for(int i = 0; i < (int)v1.size(); i++) {
            if(v1[i] != v2[i]) return v1[i] < v2[i];
        }
        return true;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    bool start = false;
    while(t--) {
        getchar();
        if(!start) start = true;
        else printf("\n");
        variable.clear();
        ans.clear();
        char ch;
        int counter = 0;
        vector< char > temp;
        while((ch = getchar()) != '\n')
            if(ch != ' ')
                temp.push_back(ch);
        sort(temp.begin(), temp.end());
        for(int i = 0; i < (int)temp.size(); i++) {
            ch = temp[i];
            variable[ch] = counter;
            rev[counter++] = ch;
        }
        for(int i = 0; i < counter; i++) adj[i].clear(), indegree[i] = 0, vis[i] = false;
        while((ch = getchar()) != '\n') {
            if(ch >= 'A' && ch <= 'Z') {
                getchar();
                char ch2 = getchar();
                adj[variable[ch2]].push_back(variable[ch]);
                indegree[variable[ch]]++;
            }
        }
        for(int i = 0; i < counter; i++) {
            if(indegree[i] == 0) {
                vector< int > temp;
                temp.push_back(i);
                dfs(counter, i, temp);
            }
        }
        if(ans.size() == 0) printf("NO\n");
        else {
            for(int i = 0; i < (int)ans.size(); i++) reverse(ans[i].begin(), ans[i].end());
            sort(ans.begin(), ans.end(), Compare());
            for(int i = 0; i < (int)ans.size(); i++) {
                printf("%c", rev[ans[i][0]]);
                for(int j = 1; j < (int)ans[i].size(); j++) {
                    printf(" %c", rev[ans[i][j]]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

void dfs(int n, int u, vector< int > taken) {
    if((int)taken.size() == n) {
        ans.push_back(taken);
        return;
    }
    vis[u] = true;
    for(int i = 0; i < (int)adj[u].size(); i++) indegree[adj[u][i]]--;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0 && !vis[i]) {
            vector< int > temp = taken;
            temp.push_back(i);
            dfs(n, i, temp);
        }
    }
    vis[u] = false;
    for(int i = 0; i < (int)adj[u].size(); i++) indegree[adj[u][i]]++;
}
