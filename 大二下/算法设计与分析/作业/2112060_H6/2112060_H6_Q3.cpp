#include <iostream>
#include <vector>
using namespace std;
// �������������кϲ�Ϊһ����������
void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1); // ��ʱ�������ڴ�źϲ������������
    int i = left, j = mid + 1, k = 0; // i��jΪ���������������е���ʼ�±꣬kΪ��ʱ������±�
    while (i <= mid && j <= right) { // �������������������е�Ԫ������Ƚϣ�����С��Ԫ�ط�����ʱ������
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        }
        else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) { // ��ʣ���������������е�Ԫ��ȫ��������ʱ������
        temp[k++] = nums[i++];
    }
    while (j <= right) { // ��ʣ����Ҳ����������е�Ԫ��ȫ��������ʱ������
        temp[k++] = nums[j++];
    }
    for (int p = 0; p < k; p++) { // ���ϲ�����������и��ƻ�ԭ������
        nums[left + p] = temp[p];
    }
}

// �鲢����������
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) return; // �ݹ���ֹ������������ֻʣһ��Ԫ��
    int mid = (left + right) / 2; // �����з�Ϊ��������������
    mergeSort(nums, left, mid); // ���������н��й鲢����
    mergeSort(nums, mid + 1, right); // ���������н��й鲢����
    merge(nums, left, mid, right); // �������������������кϲ�Ϊһ����������
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    mergeSort(nums, 0, n - 1); // ���������н��й鲢����
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
