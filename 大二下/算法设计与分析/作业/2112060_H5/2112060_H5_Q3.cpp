#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n;
	cin >> n;//n���ڵ�
	int m;
	cin >> m;//m����
	int weight[50][50];
	int* edge = new int[m];
	int* start = new int[m];
	int* end = new int[m];
	int k = 0;
	for (int i = 0; i < m; i++)//����ͼ
	{
		cin >> start[i] >> end[i];//start->end
		cin >> edge[i];//start->end��Ȩֵ
	}
	//��edge��С�����������,��Ӧ�ģ�start��endҲҪ����˳��
	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (edge[j] < edge[j - 1])
			{
				int temp = edge[j - 1];
				edge[j - 1] = edge[j];
				edge[j] = temp;

				int temp1 = start[j - 1];
				start[j - 1] = start[j];
				start[j] = temp1;

				int temp2 = end[j - 1];
				end[j - 1] = end[j];
				end[j] = temp2;
			}
		}
	}
	set<int>node;//�㼯�ϣ������ж���û�л�����
	//krusal�㷨���
	int edgenum = 0;//��ǰ�������бߵ�����
	int sum = 0;//��С��������·����
	for (int i = 0; i < m; i++)//m����
	{
		if (node.count(start[i]) && node.count(end[i]))//count��������ĳ��ֵ��Ԫ�ظ���������������صĶ���1����ô���������ߺ�һ������ֻ������Բ��ܼ���������
		{
			continue;//����һ����
		}
		node.insert(start[i]);//
		node.insert(end[i]);//�������ߵ�������ӽ�����
		edgenum++;//�������еıߵ�����+1
		sum += edge[i];//Ȩֵ�ͼ���������
	}
	cout << sum;
	return 0;
}