#include<iostream>
using namespace std;
int main()
{
	int n;//n���˻����
	int n2;//n2�����״̬����˻����
	cin >> n;
	if (n >= 0)//�Ǹ���
	{
		cout << n;
	}
	else//�������ɼ�ȥһλ����
	{
		int n1 = 0 - n;//��ɾ���ֵ��������
		int m1 = n1 / 10;//ɾ�����һ�����ֺ�ľ���ֵ

		int p1 = n1 % 10;//p1ȡ���һλ
		int m2 = m1 / 10 * 10 + p1;//ɾ�������ڶ������ֺ�ľ���ֵ

		if (m1 <= m2)//���m1<=m2����-m1>=-m2
		{
			n2 = 0 - m1;
		}
		else//���m1>m2����-m1<-m2
		{
			n2 = 0 - m2;
		}
		cout << n2;
	}
	return 0;
}