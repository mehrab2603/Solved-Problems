#include<bits/stdc++.h>

using namespace std;

char start[4], finish[4];
bool forbidden[26][26][26];

int bfs();

struct Node {
    char a, b, c;
    int dist;
    Node(char a, char b, char c, int dist) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->dist = dist;
    }
};

int main() {
    int t, caseno = 0;
    scanf("%d", &t);
    getchar();
    while(t--) {
        memset(forbidden, false, sizeof forbidden);
        getchar();
        scanf("%s", start);
        getchar();
        scanf("%s", finish);
        getchar();
        int n;
        scanf("%d", &n);
        char string1[27], string2[27], string3[27];
        while(n--) {
            scanf("%s %s %s", string1, string2, string3);
            getchar();
            int size1 = strlen(string1), size2 = strlen(string2), size3 = strlen(string3);
            for(int i = 0; i < size1; i++)
                for(int j = 0; j < size2; j++)
                    for(int k = 0; k < size3; k++)
                        forbidden[string1[i] - 'a'][string2[j] - 'a'][string3[k] - 'a'] = true;
        }
        printf("Case %d: %d\n", ++caseno, bfs());
    }
    return 0;
}

int bfs() {
    if(forbidden[start[0] - 'a'][start[1] - 'a'][start[2] - 'a']) return -1;
    if(start[0] == finish[0] && start[1] == finish[1] && start[2] == finish[2]) return 0;
    bool vis[26][26][26];
    memset(vis, false, sizeof vis);
    queue< Node > q;
    q.push(Node(start[0], start[1], start[2], 0));
    vis[start[0] - 'a'][start[1] - 'a'][start[2] - 'a'] = true;
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        int a = top.a - 'a', b = top.b - 'a', c = top.c - 'a';
        int an = a + 1, ap = a - 1, bn = b + 1, bp = b - 1, cn = c + 1, cp = c - 1;
        if(ap < 0) ap += 26;
        if(bp < 0) bp += 26;
        if(cp < 0) cp += 26;
        if(an > 25) an -= 26;
        if(bn > 25) bn -= 26;
        if(cn > 25) cn -= 26;
        if(!forbidden[an][b][c] && !vis[an][b][c]) {
            vis[an][b][c] = true;
            if(an + 'a' == finish[0] && b + 'a' == finish[1] && c + 'a' == finish[2]) return top.dist + 1;
            q.push(Node(an + 'a', b + 'a', c + 'a', top.dist + 1));
        }
        if(!forbidden[ap][b][c] && !vis[ap][b][c]) {
            vis[ap][b][c] = true;
            if(ap + 'a' == finish[0] && b + 'a' == finish[1] && c + 'a' == finish[2]) return top.dist + 1;
            q.push(Node(ap + 'a', b + 'a', c + 'a', top.dist + 1));
        }
        if(!forbidden[a][bn][c] && !vis[a][bn][c]) {
            vis[a][bn][c] = true;
            if(a + 'a' == finish[0] && bn + 'a' == finish[1] && c + 'a' == finish[2]) return top.dist + 1;
            q.push(Node(a + 'a', bn + 'a', c + 'a', top.dist + 1));
        }
        if(!forbidden[a][bp][c] && !vis[a][bp][c]) {
            vis[a][bp][c] = true;
            if(a + 'a' == finish[0] && bp + 'a' == finish[1] && c + 'a' == finish[2]) return top.dist + 1;
            q.push(Node(a + 'a', bp + 'a', c + 'a', top.dist + 1));
        }
        if(!forbidden[a][b][cn] && !vis[a][b][cn]) {
            vis[a][b][cn] = true;
            if(a + 'a' == finish[0] && b + 'a' == finish[1] && cn + 'a' == finish[2]) return top.dist + 1;
            q.push(Node(a + 'a', b + 'a', cn + 'a', top.dist + 1));
        }
        if(!forbidden[a][b][cp] && !vis[a][b][cp]) {
            vis[a][b][cp] = true;
            if(a + 'a' == finish[0] && b + 'a' == finish[1] && cp + 'a' == finish[2]) return top.dist + 1;
            q.push(Node(a + 'a', b + 'a', cp + 'a', top.dist + 1));
        }
    }
    return -1;
}
