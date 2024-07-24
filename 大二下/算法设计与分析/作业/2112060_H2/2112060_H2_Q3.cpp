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
	//E02-03-1:O(n^2)ʵ����������Ŀ����㷨
	cout << "E02-03, O(n^2)" << endl;
	int N, T;//nΪ�����С,TΪĿ���
	cout << "�����������Сn= ";//���������С
	cin >> N;
	cout << "������Ŀ��ͣ�";
	cin >> T;
	int* array2 = new int[N];//��������
	for (int i = 0; i < N; i++)//�����������֣�����������ģ�
	{
		cin >> array2[i];
	}
	for (int i = 0; i < N; i++)//0��ʼ����
	{
		for (int j = i + 1; j < N; j++)//i+1��ʼ����
		{
			if (array2[i] + array2[j] == T)//��Ӻ�ΪT
			{
				cout << "(" << array2[i] << "," << array2[j] << ")" << ":" << array2[i] << "+" << array2[j] << "=" << T << endl;//�����������
			}
		}
	}
	cout << endl;

	//E02-03-2:O(nlogn)ʵ����������Ŀ����㷨
	cout << "E02-03, O(nlogn)" << endl;
	for (int i = 0; i < N; i++)
	{
		if (Binary_search(array2, i + 1, N - 1, T - array2[i]) != -1)//T-array[i]����
		{
			cout << "(" << array2[i] << "," << array2[Binary_search(array2, i + 1, N - 1, T - array2[i])] << ")" << ":" << array2[i] << "+" << array2[Binary_search(array2, i + 1, N - 1, T - array2[i])] << "=" << T << endl;//�����������
		}
	}
	cout << endl;

	//E02-03-3:O(n)ʵ����������Ŀ����㷨
	cout << "E02-03, O(n)" << endl;
	int start = 0, end = N - 1;//start��ǰ��������end�Ӻ���ǰ����
	while (start < end)//start<end��ʱ�򣬽��б�������start>=end��ʱ�򣬲�Ӧ���в���
	{
		if (array2[start] + array2[end] < T)//�������ֵС��T,��С�������һ��
		{
			start++;
		}
		else if (array2[start] + array2[end] > T)//�������ֵ����T,�ô������Сһ��
		{
			end--;
		}
		else if (array2[start] + array2[end] == T)//�ҵ�һ��
		{
			cout << "(" << array2[start] << "," << array2[end] << ")" << ":" << array2[start] << "+" << array2[end] << "=" << T << endl;//�����������
			start++;//����Ѱ�ҿ��ܵ���һ��
		}
	}
	cout << endl;
	return 0;
}