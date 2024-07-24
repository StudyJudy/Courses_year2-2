#include<iostream>
using namespace std;
int Binary_search(int a[], int left, int right, int target) //�۰����
{
	if (left > right)
	{//�����������ʧ��
		return -1;
	}
	while (left <= right)
	{
		//�м�Ԫ���±�
		int mid = (left + right) / 2;
		if (target > a[mid])//target��mid�Ҳ�
		{
			left = mid + 1;//�Ұ��Ѱ��
		}
		else if (target < a[mid])//target��mid���
		{
			right = mid - 1;//����Ѱ��
		}
		else
		{
			return mid;//a[mid]==target���ҵ�target��λ�ã�����target��λ��Ϊmid
		}
	}
	//û���ҵ�
	return -1;
}
int main()
{
	cout << "E02-01" << endl;
	//E02-01: ʵ���˶��ֲ��ң���������ʵ����������֤��
	int n;//nΪ�����С
	cout << "�����������Сn= ";//���������С
	cin >> n;
	int* array = new int[n];//��������
	for (int i = 0; i < n; i++)//�����������֣�����������ģ�
	{
		cin >> array[i];
	}
	int x;//x�Ǵ����ҵ�����
	cout << "����������ҵ�����x= ";
	cin >> x;
	if (Binary_search(array, 0, n - 1, x) == -1)//û�ҵ�x�����������
	{
		cout << "δ�ҵ������֣��������룡" << endl;
	}
	else
	{
		cout << x << "�������е��±�Ϊ: " << Binary_search(array, 0, n - 1, x) << endl;
	}
	cout << endl;
	return 0;
}