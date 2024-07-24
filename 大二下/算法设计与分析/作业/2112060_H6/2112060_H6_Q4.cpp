#include<iostream>
using namespace std;

long long Merge(int* arr, int* temp, int left, int mid, int right) {
    // �鲢�����еĺϲ�������������������������ϲ���һ���������飬����������Ե�����
    long long count = 0;
    int i = left, j = mid, k = left;
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += mid - i; // ����Ҳ������е�Ԫ��arr[j]С����������е�Ԫ��arr[i]����ô�Ҳ�������arr[j]֮���Ԫ��Ҳ�ض�����arr[i]����Ϊ���������Ҳ������ڲ��Ѿ��������Կ���ֱ�Ӽ������������
        }
    }
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return count;
}

long long MergeSort(int* arr, int* temp, int left, int right) {
    // �鲢��������ʹ�õݹ�ʵ��
    long long count = 0;
    if (right > left) {
        int mid = (right + left) / 2;
        count += MergeSort(arr, temp, left, mid); // �ݹ鴦����벿��
        count += MergeSort(arr, temp, mid + 1, right); // �ݹ鴦���Ұ벿��
        count += Merge(arr, temp, left, mid + 1, right); // ������������������ϲ�������������Ե�����
    }
    return count;
}

long long CountInversions(int* arr, int n) {
    int* temp = new int[n];
    return MergeSort(arr, temp, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << CountInversions(arr, n) << endl;
    delete[] arr;
    return 0;
}
