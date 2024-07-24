#include<iostream>
using namespace std;
const int MAXN = 4;                                                                                        
const int INF = 10000000;
int cost[4][4];
bool vis[4];
int ans = INF;
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
        return b;
}
void dfs(int dep, int res) 
{
    if (dep == MAXN) 
    { // ����Ҷ�ڵ㣬���´�
        ans = min(ans, res);
        return;
    }
    // ���㵱ǰ�ڵ���Ͻ�
    int upper_bound = 0;
    for (int i = dep; i < MAXN; i++) 
    {
        int min_cost = INF;
        for (int j = 0; j < MAXN; j++) 
        {
            if (!vis[j]) 
            {
                min_cost = min(min_cost, cost[j][i]);
            }
        }
        upper_bound += min_cost;
    }
    if (res + upper_bound >= ans) 
    { // ��֦
        return;
    }
    for (int i = 0; i < MAXN; i++) 
    {
        if (!vis[i]) 
        {
            vis[i] = true;
            dfs(dep + 1, res + cost[i][dep]);
            vis[i] = false;
        }
    }
}

int main() 
{
    // ���뱸��ʱ���
    for (int i = 0; i < MAXN; i++) 
    {
        for (int j = 0; j < MAXN; j++) 
        {
            cin >> cost[i][j];
        }
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
