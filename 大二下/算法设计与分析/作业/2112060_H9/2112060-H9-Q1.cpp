#include<iostream>
using namespace std;
void display(bool* pre,int *num, int n, int time)//��ʾ��ǰ�����Ѿ����ʵĴ���
{
	if (time == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << num[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)//����1��n����δ��ʹ�õ����֣�������ӵ���ǰ�����У����Ϊ��ʹ��
		{
			if (pre[i] == 0)
			{
				pre[i] = 1;
				num[time] = i;
				display(pre, num, n, time + 1);
				pre[i] = 0;//���ݵ���һ�㣬����ǰ���ֱ��Ϊδʹ�ã�����������һ������
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	bool* pre = new bool[n + 1];//�������ڱ�������Ƿ��Ѿ���ʹ��
	int* num = new int[n];//���ڴ洢��ǰ����
	for (int i = 0; i <= n; i++)
	{
		pre[i] = 0;
	}
	display(pre, num, n, 0);
	delete[] pre;
	return 0;
}