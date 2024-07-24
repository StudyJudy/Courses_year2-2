#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
// ��Ʒ�Ľṹ�壬���������ͼ�ֵ
struct Item 
{
    int weight;
    int value;
};

// ��̬�滮������
int knapsack(vector<Item>& items, int n, int capacity)
{
    // ������ά�������洢����������Ž�
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    // �������
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++) 
        {
            // ��ѡ��ǰ��Ʒ�����Ž�
            int bestWithoutCurrent = dp[i - 1][j];

            // ѡ��ǰ��Ʒ�����Ž�
            int bestWithCurrent = 0;
            if (j >= items[i - 1].weight) 
            {
                bestWithCurrent = dp[i - 1][j - items[i - 1].weight] + items[i - 1].value;
            }

            // ȡ����������Ľϴ�ֵ
            dp[i][j] = max(bestWithoutCurrent, bestWithCurrent);
        }
    }
    // ����������������Ž�
    return dp[n][capacity];
}

int main() 
{

    int capacity, n;
    cin >> capacity >> n;
    //vector<Item> items = { {2,12}, {1,10}, {3,20}, {2,15} };
    //int capacity = 5;
    vector<Item> items;
    int* w = new int[n];
    int* v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; i++)//������������
    {
        for (int j = i + 1; j < n; j++)
        {
            if (w[j] < w[j - 1])
            {
                int temp = w[j];
                w[j] = w[j - 1];
                w[j - 1] = temp;

                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        Item it;
        it.weight = w[i];
        it.value = v[i];
        items.push_back(it);
    }
    //for (int i = 0; i < n; i++)
    //{
    //    cout << items[i].weight <<items[i].value<< endl;
    //}
    // ��¼��ʼʱ��
    auto start = chrono::high_resolution_clock::now();

    // ���ö�̬�滮������
    int maxvalue = knapsack(items, n, capacity);

    // ��¼����ʱ��
    auto end = chrono::high_resolution_clock::now();

    // �������ͳ�������ʱ��
    cout << "The maximum value is " << maxvalue << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    return 0;
}
