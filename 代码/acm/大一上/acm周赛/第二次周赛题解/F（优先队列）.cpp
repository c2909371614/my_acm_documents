#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
 
using namespace std;
 
typedef pair<int, int> P;
const int MAXN = 2500;
P cows[MAXN+5];
P lot[MAXN+5];
 
priority_queue<int, vector<int>, greater<int> > que;
 
int main()
{
    int c, l;
    scanf("%d%d", &c, &l);
    
    for (int i = 0; i < c; i++)
        scanf("%d%d", &cows[i].first, &cows[i].second);
    sort(cows, cows + c);
    for (int i = 0; i < l; i++)
        scanf("%d%d", &lot[i].first, &lot[i].second);
    sort(lot, lot + l);
    
    int res = 0;
    int j = 0;
    for (int i = 0; i < l; i++) {
        while (j < c && cows[j].first <= lot[i].first) {
            que.push(cows[j].second);
            j++;
        }
        while (!que.empty() && lot[i].second) {
            int cow = que.top();
            que.pop();
            if (cow >= lot[i].first) {
                lot[i].second--;
                res++;
            }
        }
    }
    printf("%d\n", res);
    
    return 0;
}
