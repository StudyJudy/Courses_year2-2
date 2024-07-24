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

// �ݹ麯�����������Ž�
int knapsackHelper(vector<Item>& items, int capacity, int currentWeight, int currentValue, int currentIndex) {
    // ��������������ƣ�ֱ�ӷ��ؼ�ֵΪ0
    if (currentWeight > capacity) 
    {
        return 0;
    }

    // ����Ѿ������������е���Ʒ�����ص�ǰ��ֵ
    if (currentIndex == items.size()) 
    {
        return currentValue;
    }

    // ��ѡ��ǰ��Ʒ�����Ž�
    int bestWithoutCurrent = knapsackHelper(items, capacity, currentWeight, currentValue, currentIndex + 1);

    // ѡ��ǰ��Ʒ�����Ž�
    int bestWithCurrent = knapsackHelper(items, capacity, currentWeight + items[currentIndex].weight,
        currentValue + items[currentIndex].value, currentIndex + 1);

    // ���������������еĽϴ�ֵ
    return max(bestWithoutCurrent, bestWithCurrent);
}

// ��ٷ�����
int knapsack(vector<Item>& items, int capacity)
{
    // ���õݹ麯�����ӵ�һ����Ʒ��ʼ����
    return knapsackHelper(items, capacity, 0, 0, 0);
}

int main() {
    int capacity, n;
    cin >> capacity >> n;
    //vector<Item> items = { {2,12}, {1,10}, {3,20}, {2,15} };
    //int capacity = 5;
    vector<Item> items;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        Item it;
        it.weight = w;
        it.value = v;
        items.push_back(it);
    }
    // ��¼��ʼʱ��
    auto start = chrono::high_resolution_clock::now();

    // ������ٷ�����
    int maxvalue = knapsack(items, capacity);

    // ��¼����ʱ��
    auto end = chrono::high_resolution_clock::now();

    // �������ͳ�������ʱ��
    cout << "The maximum value is " << maxvalue << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    return 0;
}
