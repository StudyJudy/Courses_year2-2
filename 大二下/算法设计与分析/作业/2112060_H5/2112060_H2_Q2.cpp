#include<iostream>
using namespace std;
int* dijkstra(int graph[50][50], int n, int x)//�ڽӾ���n���ڵ㣬��x�ڵ㿪ʼ��������ڵ�
{
	int* distance = new int[n];//������¼��ÿ���ڵ����̾���
	for (int i = 1; i <= n; i++)
	{
		distance[i] = 100000000000;//�����ó�һ���������
		if (distance[i] > graph[x][i])
		{
			distance[i] = graph[x][i];//�Ѵ�x����ֱ�ӵ���Ķ���ľ�������Ӧ�ߵ�weight
		}
	}
	distance[x] = 0;//�Լ����Լ��ľ�����0
	bool* visit = new bool[n];//��ʾÿ���ڵ㻹û�����ʹ�
	for (int i = 1; i <= n; i++)
	{
		visit[i] = false;//��ʼ��Ϊ0��ʾ��δ������
	}
	visit[x] = true;//�Լ�һ�����ʹ��Լ�
	for (int i = 1; i <= n; i++)
	{
		int pos = -1;//������¼��������Ԫ�ؾ�����̵Ķ���
		int temp = 100000000000;//������¼��������Ԫ����̾���
		for (int j = 1; j <= n; j++)//�����ҵ���һ�����뼯�ϵĵ�
		{
			if (visit[j] == 0 && distance[j] < temp)//����ڵ�û�з��ʹ�û�ڼ�����
			{
				pos = j;//��¼��ǰ��̾���Ķ���
				temp = distance[j];//��¼��ǰ����̾���
			}
		}
		visit[pos] = true;//���ҵ����������뼯��
		for (int j = 1; j <= n; j++)//���¼��㵱ǰ�ɵ������̾���
		{
			if (visit[j] == 0 && distance[j] > graph[pos][j] + temp)//��û�ڼ�����,���ɴ����̾����б仯���Ը���
			{
				distance[j] = graph[pos][j] + temp;//��¼��ǰû�ڼ����еĵ��x���ʵ���̾���
			}
		}
	}
	return distance;
}
int main()
{
	int n;//n���ڵ�
	cin >> n;
	int m;//m����
	cin >> m;
	int x;
	cin >> x;//��ʾ��x�ڵ㿪ʼ��������ڵ�
	int weight[50][50];//��ά����洢Ȩֵ
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			weight[i][j] = 100000000000;//��ʼ���ɼ���ֵ
		}
	}
	for (int i = 0; i < m; i++)
	{
		int start;
		int end;
		cin >> start >> end;// start->end
		cin >> weight[start][end];//weight
	}
	int* Dis=dijkstra(weight, n, x);
	for (int i = 1; i <= n; i++)
	{
		cout << Dis[i] << " ";
	}
	return 0;
}