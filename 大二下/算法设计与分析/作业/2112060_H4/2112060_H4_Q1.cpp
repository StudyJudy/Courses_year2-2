#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;//n������
	int* start = new int[n];//�湤���Ŀ�ʼʱ��
	int* finish = new int[n];//�湤���Ľ���ʱ��
	int end = 0;//��¼����Ľ���ʱ��
	for (int i = 0; i < n; i++)
	{
		cin >> start[i] >> finish[i];//���뿪ʼʱ��ͽ���ʱ��
		if (finish[i] > end)
		{
			end = finish[i];
		}
	}
	//������ʱ����������
	for (int i = 0; i < n; i++)//ð������
	{
		for (int j = i + 1; j < n; j++)
		{
			if (finish[j-1] > finish[j])//����˳��
			{
				int temp1 = finish[j-1];
				finish[j-1] = finish[j];
				finish[j] = temp1;
				int temp2 = start[j-1];
				start[j-1] = start[j];
				start[j] = temp2;
			}
		}
	}
	//for (int i = 0; i < n; i++)//������������
	//{
	//	cout << start[i] << " " << finish[i] << endl;
	//}
	bool* work = new bool[end];//����һ�����飬���ڼ�¼ÿ��ʱ����ǲ������й���
	int type = 0;//��¼���Ŀɼ��ݹ�����Ŀ
	for (int i = 0; i < end; i++)
	{
		work[i] = false;//	ȫ����ʼ��Ϊû�й���
	}
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = start[i]; j < finish[i]; j++)//�жϵ�i�ݹ����İ��ŵ�ʱ��Σ��ǲ��ǿ��Լ�����ݹ�����[ )
		{
			if (work[j] == true)//�ö�ʱ���в���ʱ���й�������
			{
				flag = 0;//flagΪ0����־���ɼ���
				break;//���ɼ�����ݹ���
			}
		}
		if (flag == 1)//��־�ɼ���
		{
			type++;//�ɼ��ݹ���������+1
			for (int j = start[i]; j < finish[i]; j++)//����ݹ������ŵ�ʱ�����Ϊtrue
			{
				work[j] = true;
			}
		}
	}
	cout << type;
	return 0;
}