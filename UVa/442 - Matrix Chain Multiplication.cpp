#include <bits/stdc++.h>
#define MAX 100

using namespace std;
int n;
int rows[MAX], cols[MAX];

int main()
{
     scanf("%d", &n);
     getchar();
     for(int i = 0; i < n; i++)
     {
          char ch;
          int row, col;
          scanf("%c %d %d", &ch, &row, &col);
          getchar();
          rows[ch - 'A'] = row;
          cols[ch - 'A'] = col;
     }
     string s1;
     while(getline(cin, s1))
     {
          int ans = 0;
          int used = 27;
          stack<char> st;
          for(int i = 0; i < (int)s1.length() && ans >= 0; i++)
          {
               if(s1[i] == ')')
               {
                    int mat2 = st.top();
                    st.pop();
                    int mat1 = st.top();
                    st.pop();
                    st.pop();
                    if(cols[mat1 - 'A'] == rows[mat2 - 'A'])
                    {
                         ans += rows[mat1 - 'A'] * cols[mat1 - 'A'] * cols[mat2 - 'A'];
                         rows[used] = rows[mat1 - 'A'];
                         cols[used] = cols[mat2 - 'A'];
                         st.push('A' + used);
                         used++;
                    }
                    else ans = -INT_MAX;
               }
               else
                    st.push(s1[i]);
          }
          if(ans < 0) printf("error\n");
          else printf("%d\n", ans);
          while(!st.empty()) st.pop();
     }
     return 0;
}
