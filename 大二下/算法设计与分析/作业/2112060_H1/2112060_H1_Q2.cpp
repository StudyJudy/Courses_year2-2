#include<iostream>
using namespace std;
int main()
{
	int n, m, a, b;//n��ʾAnn�ܹ�Ҫ�����ε�����m����Ʊ�������Σ�a��ʾ����ƱƱ�ۣ�b��ʾ����ƱƱ��
	cin >> n >> m >> a >> b;
	int sum = 10000000;//��¼��С�ܼ�
	int temp = 0;//��ǰ����۸�
	for (int i = 0; i <= n / m + 1; i++)//i�Ǽ�������Ʊ
	{
		int j = 0;//j�Ǽ��ε���Ʊ
		if (m * i >= n)
		{
			j = 0;
		}
		else
		{
			j = n - m * i;
		}
		temp = b * i + j * a;
		if (temp < sum)
		{
			sum = temp;
		}
	}
	cout << sum;
	return 0;
}
