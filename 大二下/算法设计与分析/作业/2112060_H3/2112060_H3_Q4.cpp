#include<iostream>
using namespace std;
int main()
{
	int n;//����ͼ����n���ڵ�
	int m;//����ͼ����m����
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	int matrix[50][50] = { 0 };//����ͼ���ڽӾ���
	int a, b;
	int* ans = new int[n];//�����
	int c = 0;
	int* visited = new int[n];//��¼�ǲ����Ѿ��鵽��
	for (int i = 0; i < n; i++)//��ʼ����û�鵽����Ϊ0
	{
		visited[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;//һ���ߵ�������
        matrix[a][b] = 1;//�ڽӾ����иõ���Ϊ1
	}
	int flag = 1;
	while (flag)//�������е㶼�������������
	{
		for (int i = 0; i < n ; i++)//��0��ʼ����ÿ����û���ҵ����ĵ㣬һ����ֻ�г��ȣ�û����Ȳ������������ͼ���õ�
		{
			int j;
			if (visited[i] == 0)
			{
				for (j = 0; j < n; j++)//��ÿ�������
				{
					if (matrix[j][i] != 0)
					{
						break;
					}
				}
				if (j == n)//һ���ж���0
				{
					ans[c++] = i;//�ҵ�һ���㣬�����������
					visited[i] = 1;
					//cout << i << " ";
					for (int k = 0; k < n; k++)//������������ͼ���õ����ھ�������һ�о����0
					{
						matrix[i][k] = 0;
					}
					if (c == n)
					{
						flag = 0;
					}
					break;
				}
			}

		}
	}
	cout << "������������" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}