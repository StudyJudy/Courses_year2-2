#include<iostream>
#include<map>
#include<set>
using namespace std;
int main() 
{
	int n;//�������
	cin >> n;
	int e;
	cin >> e;//�ߵ�����
	int* start = new int[e];//��ʼ��
	int* end = new int[e];//�յ�
	int* length = new int[e];//Ȩֵ
	int matrix[50][50];
	set<int>node;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			matrix[i][j] = 0;//�ڽӾ���ȫ����ʼ��Ϊ0
		}
    }
	for (int i = 0; i < e; i++)
	{
		cin >> start[i] >> end[i] >> length[i];
		matrix[start[i]][end[i]] = length[i];
		matrix[end[i]][start[i]] = length[i];//�ڽӾ���
	}
	for (int i = 0; i < e - 1; i++)
	{
		for (int j = 0; j < e - i - 1; j++)
		{
			if (length[j] > length[j + 1])
			{
				int temp;
				temp = length[j];//����length��С����˳��
				length[j] = length[j + 1];
				length[j + 1] = temp;

				int temp1;
				temp1 = start[j];
				start[j] = start[j + 1];
				start[j + 1] = temp1;

				int temp2;
				temp2 = end[j];
				end[j] = end[j + 1];
				end[j + 1] = temp2;
			}
		}
	}
	int sum = 0;//·����
	//�������̵������ߵ�����һ�����㿪ʼ
	node.insert(start[0]);
	node.insert(end[0]);//����̵������ߵ���������뼯��
	sum += length[0];
	while (node.size() != n)//�㼯û�����������ҵ�
	{
		int min_length = 10000000;//�����óɱȽϴ��length
		int pos;//��¼��̱ߵ�λ��
		for (int i = 0; i < e; i++)
		{
			if (node.count(start[i]) || node.count(end[i]))
			{
				if (node.count(start[i])&& node.count(end[i]) == 0)//�Ҽ��������еĵ�����������ߣ������ҵ��ظ��ıߣ�Ҳ���ܺ��Ѿ����ʹ��ĵ��γɻ�
				{
					if (min_length > length[i])//����
					{
						min_length = length[i];
						pos = end[i];
					} 
				}
				else if (node.count(end[i]) && node.count(start[i]) == 0)//�Ҽ��������еĵ�����������ߣ������ҵ��ظ��ıߣ�Ҳ���ܺ��Ѿ����ʹ��ĵ��γɻ�
				{
					if (min_length > length[i])//����
					{
						min_length = length[i];
						pos = start[i];
					}
				}
			}
		}
		sum += min_length;//������һ����̱�
		node.insert(pos);//���������뼯��
	}
	cout << sum;
	return 0;
}