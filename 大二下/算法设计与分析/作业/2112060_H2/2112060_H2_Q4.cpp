#include <iostream>
using namespace std;
int main()
{
	//E02-04: ʵ����̾����㷨����������������
	cout << "E02-04" << endl;
	int n3;//n3���������
	cout << "�����Ķ���" << endl;
	cin >> n3;
	int* X = new int[n3];//x����
	int* Y = new int[n3];//y����
	char temp;
	int minlength = 10000000000;//������̾����ƽ��
	cout << "������" << endl;
	for (int i = 0; i < n3; i++)
	{
		cin >> temp >> X[i] >> temp >> Y[i] >> temp;
	}
	//��������ҵ���̾���
	for (int i = 0; i < n3; i++)//�㣨X[i],Y[i]��
	{
		for (int j = i + 1; j < n3; j++)//�㣨X[j],Y[j]��,
		{
			if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) < minlength)//�ȵ�ǰ��̾���С
			{
				minlength = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
			}
		}
	}
	cout << "��̾����ƽ��Ϊ��" << minlength << endl;
	//�����ҵ���С�����������
	for (int i = 0; i < n3; i++)//�㣨X[i],Y[i]��
	{
		for (int j = i + 1; j < n3; j++)//�㣨X[j],Y[j]��,j���ܵ���i
		{
			if ((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]) == minlength)//�ȵ�ǰ��̾���С
			{
				cout << "(" << X[i] << "," << Y[i] << ")" << "," << "(" << X[j] << "," << Y[j] << ")" << endl;
			}
		}
	}
	cout << endl;

	return 0;
}