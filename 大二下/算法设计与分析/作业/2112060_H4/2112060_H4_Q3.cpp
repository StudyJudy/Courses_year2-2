#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;//n������
	int* process = new int[n];//�����������Ҫ���ѵ�ʱ��
	int* deadline = new int[n];//�������deadline
	int sum_time = 0;//��¼�������������Ҫ���ѵ����ʱ��(�ۼ�)
	for (int i = 0; i < n; i++)
	{
		cin >> process[i] >> deadline[i];//���봦��ʱ���ddlʱ��
		sum_time += process[i];
	}
	//��ddlʱ����������
	for (int i = 0; i < n; i++)//ð������
	{
		for (int j = i + 1; j < n; j++)
		{
			if (deadline[j-1] > deadline[j])//����˳��
			{
				int temp1 = deadline[j-1];
				deadline[j-1] = deadline[j];
				deadline[j] = temp1;
				int temp2 = process[j-1];
				process[j-1] = process[j];
				process[j] = temp2;
			}
		}
	}
	//for (int i = 0; i < n; i++)//������������
	//{
	//	cout << process[i] << " " << deadline[i] << endl;
	//}
	bool* time = new bool[sum_time];//����һ��ʱ��������
	for (int i = 0; i < sum_time; i++)
	{
		time[i] = false;//��ʼ��Ϊfalse
	}
	int arranged = 0;//��¼��һ������ôӴ�ʱ�俪ʼ����
	int lateness = 0;//��¼���ӳ�ʱ��
	for (int i = 0; i < n; i++)//��i������
	{
		for (int j = arranged; j < arranged + process[i]; j++)
		{
			time[j] = true;
		}
		arranged = arranged + process[i];
		if (deadline[i] < arranged)//���ӳ���
		{
			lateness += arranged - deadline[i];
		}
	}
	cout << lateness;
	return 0;
}