#include<iostream>
using namespace std;
int main()
{
	//E02-02: �ϲ�����������б�������һЩ������������
	cout << "E02-02" << endl;
	int n1, n2;//n1Ϊ����A�Ĵ�С��n2Ϊ����B�Ĵ�С
	cout << "����������A�Ĵ�С: ";
	cin >> n1;
	cout << "����������B�Ĵ�С: ";
	cin >> n2;
	int* A = new int[n1];
	int* B = new int[n2];
	for (int i = 0; i < n1; i++)//��������A�����֣������Ǵ�С��������ģ�
	{
		cin >> A[i];
	}
	for (int i = 0; i < n2; i++)//��������B���֣������Ǵ�С��������ģ�
	{
		cin >> B[i];
	}
	int* C = new int[n1 + n2];//����������C�����洢�ϲ��������
	int p = 0, q = 0, r = 0;//p��¼A�����±꣬q��¼B�����±꣬r��¼�����±�
	while (p < n1 && q < n2)//ѭ�������Ƚϣ�С�Ĵ��C��
	{
		if (A[p] <= B[q])
		{
			C[r++] = A[p++];
		}
		else
		{
			C[r++] = B[q++];
		}
	}
	while (p < n1)//Aû����
	{
		C[r++] = A[p++];
	}
	while (q < n2)//Bû����
	{
		C[r++] = B[q++];
	}
	cout << "�ϲ��Ľ���ǣ�" << endl;
	for (int i = 0; i < n1 + n2; i++)//���C
	{
		cout << C[i] << " ";
	}
	cout << endl;
	cout << endl;
	return 0;
}