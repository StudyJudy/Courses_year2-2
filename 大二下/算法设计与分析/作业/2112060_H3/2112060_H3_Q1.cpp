#include<iostream>
#include <queue>
using namespace std;
int* BFS(int i,int n,int matrix[50][50],int* layer)
{
	queue<int>q;//����
	bool* visited = new bool[n];//��¼�ǲ��Ǳ����ʹ�
	int* ans = new int[n];//����������

	int a = 0;
	for (int j = 0; j < n; j++)
	{
		visited[j] = false;//��ʼ����Ϊfalse
	}
	q.push(i);//�ѵ�һ���ڵ�Ž�ȥ
	visited[i] = true;
	layer[i] = 0;//��һ���ڵ��ǵ�0��
	while (!q.empty())
	{
		ans[a] = q.front();//��ͷ���
		q.pop();//��ͷ���
		for (int b = 0; b < n; b++)//�����ҵ�
		{
			if (matrix[ans[a]][b] == 1 && visited[b] == false)//����ߴ�����֮ǰû�з��ʹ�
			{
				visited[b] = true;//���ʹ�
				q.push(b);//�������
				layer[b] = layer[ans[a]] + 1;//l�¼����b�ڵ������ans[a]�ڵ����+1
			}
		}
		a++;
	}
	return ans;
}
int main()
{
	int n;//����ͼ����n���ڵ�
	int m;//����ͼ����m����
	int i;//��i��ʼBFS
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	cout << "i= ";
	cin >> i;
	int matrix[50][50] = { 0 };//����ͼ���ڽӾ���
	int* layer = new int[n];//��¼ÿ���ڵ�ڼ���
	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	int* A = new int[n];
	A = BFS(i, n, matrix,layer);
	//cout << "BFS��������" << endl;
	//for (int j = 0; j < n; j++)//�������BFS��������
	//{
	//	cout << A[j] << " ";
	//}
	//cout << endl;
	cout << "BFS tree�нڵ����ڵĲ���" << endl;
	for (int j = 0; j < n; j++)
	{
		cout << layer[j] << " ";
	}
	return 0;
}