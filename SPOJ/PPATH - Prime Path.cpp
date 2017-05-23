//#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;
bool marked[10000];
vector<int> prime;
void initSieve();
bool isPrime(int);
void segSieve();
int bfs();
int stoint(string);
string s1, s2;

int main()
{
    initSieve();
    for(int i = 2; i * i < 10000; i++)
        if(isPrime(i)) prime.push_back(i);
    segSieve();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin >> s1 >> s2;
        cout << bfs() << endl;
    }

    return 0;
}


void initSieve()
{
    memset(marked, false, sizeof marked);
    for(int i = 3; i * i < 10000; i = i + 2)
    {
        if(!marked[i])
        {
            for(int j = i * i; j < 10000; j += i)
                marked[j] = true;
        }
    }
}

bool isPrime(int n)
{
    if(n == 2) return true;
    else if(n % 2 == 0) return false;
    else return !marked[n];
}

void segSieve()
{
    for(int i = 0; i < (int)prime.size(); i++)
    {
        int start = (1000 / prime[i]) * prime[i];
        for(int j = start; j < 10000; j += prime[i])
            marked[j] = true;
    }
}

int bfs()
{
    if(s1 == s2) return 0;
    int dist[10000];
    bool vis[10000];
    memset(vis, false, sizeof vis);
    queue<string> q;
    int src = stoint(s1);
    dist[src] = 0;
    vis[src] = true;
    q.push(s1);
    while(!q.empty())
    {
        string top = q.front();
        q.pop();
        int u = stoint(top), udist = dist[u];
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(j == 0 && i == 0) continue;
                string temp = top;
                temp[j] = '0' + i;
                if(temp == s2) return udist + 1;
                int v = stoint(temp);
                if(!vis[v] && !marked[v])
                {
                    vis[v] = true;
                    dist[v] = udist + 1;
                    q.push(temp);
                }
            }
        }
    }
    return -1;
}

int stoint(string str)
{
    istringstream is(str);
    int temp;
    is >> temp;
    return temp;
}

