#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int* BFS(int i, int n, int matrix[50][50])
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
			}
		}
		a++;
	}
	return ans;
}
int* DFS(int i, int n, int matrix[50][50])
{
	stack<int>stk;//ջ
	bool* visited = new bool[n];//��¼�ǲ��Ǳ����ʹ�
	for (int j = 0; j < n; j++)
	{
		visited[j] = false;//��ʼ����Ϊfalse
	}
	int* ans = new int[n];//����������
	int a = 0;
	visited[i] = true;//��һ���ڵ���ʹ���
	stk.push(i);//��һ���ڵ���ջ
	ans[a] = i;//��һ���ڵ�����������
	a++;
	while (!stk.empty())
	{
		int front = stk.top();//ջ���ڵ�
		int j;
		for (j = 0; j < n; j++)
		{
			if (matrix[front][j] == 1 && visited[j] == 0)//��������û�����ʹ�
			{
				visited[j]=true;//j�ڵ���ʹ�
				stk.push(j);//�ýڵ���ջ
				ans[a++] = j;//j�ڵ�����������
				break;//�ҵ�һ����ͣ
			}
		}
		if (j == n)//�������ջ��
		{
			stk.pop();//ջ����ջ
		}
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
	A = BFS(i, n, matrix);
	cout << "BFS��������" << endl;
	for (int j = 0; j < n ; j++)//�������BFS��������
	{
		if (A[j] >= 0)
		{
			cout << A[j] << " ";
		}
	}
	cout << endl;
	int* B = new int[n];
	B = DFS(i, n, matrix);
	cout << "DFS��������" << endl;
	for (int j = 0; j < n ; j++)//�������DFS��������
	{
		if (B[j] >= 0)
		{
			cout << B[j] << " ";
		}
	}
	return 0;
}