#include<iostream>
using namespace std;
int main()
{
	int n;//�γ�����
	cout << "n= ";
	cin >> n;
	int* start = new int[n];//��γ̵Ŀ�ʼʱ��
	int* finish = new int[n];//��γ̵Ľ���ʱ��
	int end = 0;//��¼����Ľ���ʱ��
	for (int i = 0; i < n; i++)
	{
		cin >> start[i] >> finish[i];//����γ̿�ʼʱ��ͽ���ʱ��
		if (finish[i] > end)
		{
			end = finish[i];
		}
	}
	int min_room = 0;//��¼����Ҫ�ü������
	for (int i = 0; i < end; i++)//ʱ����
	{
		int need_room = 0;//��¼��ǰʱ��������Ҫ�������ң�һ�����Ҳ���ͬʱ�����ſΣ���Ҳ���ǵ�ǰʱ���м��ſγ�ͬʱ��
		for (int j = 0; j < n; j++)//�γ�
		{
			if (i >= start[j] && i < finish[j])//�ڿγ�ʱ����ڣ��γ�ʱ��Ϊ[ ),i����������ڣ�������Ҫһ������
			{
				need_room++;//��ǰʱ�����Ҫ������������+1
			}
		}
		if (min_room < need_room)//����Ѿ���¼����Ҫ�����ٽ�������С�ڵ�ǰʱ�����Ҫ�����ٽ�������
		{
			min_room = need_room;//��¼����Ҫ�����ٽ���������ɵ�ǰʱ�����Ҫ�����ٽ�������
		}
	}
	cout << min_room;
	return 0;
}