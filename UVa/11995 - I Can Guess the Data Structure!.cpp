#include <bits/stdc++.h>

using namespace std;

vector<int> output, stackOutput, queueOutput, pqOutput;
bool isStack();
bool isQueue();
bool isPriorityQueue();


int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        bool flag = false;
        int counter = 0;
        for(int i = 0; i < n; i++) {
            int operation, data;
            scanf("%d %d", &operation, &data);
            if(operation == 1 && !flag) {
                st.push(data);
                q.push(data);
                pq.push(data);
                counter++;
            }
            else if(operation == 2 && !flag){
                output.push_back(data);
                counter--;
                if(counter < 0) {
                    flag = true;
                    continue;
                }
                stackOutput.push_back(st.top());
                st.pop();
                queueOutput.push_back(q.front());
                q.pop();
                pqOutput.push_back(pq.top());
                pq.pop();
            }
        }
        if(flag) {
            printf("impossible\n");
            output.clear();
            queueOutput.clear();
            stackOutput.clear();
            pqOutput.clear();
            continue;
        }
        bool stCheck = isStack(), qCheck = isQueue(), pqCheck = isPriorityQueue();
        if((stCheck && qCheck && pqCheck) || (stCheck && qCheck) || (stCheck && pqCheck) || (qCheck && pqCheck))
            printf("not sure\n");
        else if(stCheck)
            printf("stack\n");
        else if(qCheck)
            printf("queue\n");
        else if(pqCheck)
            printf("priority queue\n");
        else
            printf("impossible\n");
        output.clear();
        queueOutput.clear();
        stackOutput.clear();
        pqOutput.clear();
    }
    return 0;
}

bool isStack() {
    if(output == stackOutput)
        return true;
    return false;
}

bool isQueue() {
    if(output == queueOutput)
        return true;
    return false;
}

bool isPriorityQueue() {
    if(output == pqOutput)
        return true;
    return false;
}


