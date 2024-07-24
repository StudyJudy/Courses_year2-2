#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
class Node//�ڵ���
{
public:
	int data;//�ڵ�ֵ
	int weight;//Ȩֵ
	int parent;//���ڵ�������λ��
	int lchild;//����������λ��
	int rchild;//�Һ���������λ��
	int level = 0;
};
class Huffman//Huffman tree
{
public:
	Node huffmantree[1000];//��Haffman tree
	int n;//�ڵ����
	void Set(int data[], int weight[], int N);//��ʼ��,data�ǽڵ�ֵ��weight��Ȩֵ��n�ǽڵ����
	void create();//��Haffman tree
};
void Huffman::Set(int data[], int weight[], int N)
{
	n = N;//�ڵ����
	for (int i = 0; i < n; i++)
	{
		Node* node = new Node();//�½ڵ�
		node->data = data[i];//�ڵ�ֵ�ǽڵ�ֵ
		node->weight = weight[i];//Ȩ����Ȩ��
		huffmantree[i] = *node;//�ѽ��õĵ����huffmantree��
	}
}
void Huffman::create()
{
	for (int i = 0; i < (2 * n - 1); i++)//Ϊ���нڵ��������ó�ֵ-1
	{
		huffmantree[i].parent = -1;
		huffmantree[i].lchild = -1;
		huffmantree[i].rchild = -1;
	}
	for (int i = n; i < (2 * n - 1); i++)//������������������Ҷ�ӽ��
	{
		int lNode = -1, rNode = -1;//��¼����Ϊ���Ӻ��Һ��ӵĽڵ��������λ��
		int min1 = 100000, min2 = 100000;//��¼������С��Ȩֵ�ĵ�
		for (int j = 0; j < i; j++)//��huffman�������ҵ�data��С��������
		{
			if (huffmantree[j].parent == -1) //û�ҹ���
			{
				if (huffmantree[j].weight < min1) //��ǰ�ĵ��min1��С�Ļ�ҪС
				{
					min2 = min1;//min1ԭ����ֵ��min2��¼��min1���³ɵ�ǰ�ڵ��dataֵ
					rNode = lNode;
					min1 = huffmantree[j].weight;
					lNode = j;
				}
				else if (huffmantree[j].weight < min2 && huffmantree[j].weight>=min1)
				{
					min2 = huffmantree[j].weight;//min2���³ɵ�ǰ�ڵ��dataֵ
					rNode = j;
				}
			}
		}
		huffmantree[lNode].parent = i;//���ڵ��������λ����i
		huffmantree[rNode].parent = i;//���ڵ��������λ����i
		huffmantree[i].weight = huffmantree[lNode].weight + huffmantree[rNode].weight;//huffmantree�����i��λ�õĵ�weight��huffmantree[lNode].weight + huffmantree[rNode].weight
		huffmantree[i].data = huffmantree[lNode].data + huffmantree[rNode].data; //huffmantree�����i��λ�õĵ�data��huffmantree[lNode].data + huffmantree[rNode].data
		huffmantree[i].lchild = lNode;//huffmantree[i]�����������λ����lNode
		huffmantree[i].rchild = rNode;//huffmantree[i]�Һ����������λ����rNode
		huffmantree[lNode].level = max(huffmantree[lNode].level, huffmantree[rNode].level);//huffmantree[i]�����Һ��ӵĸ߶���һ����
		huffmantree[rNode].level = max(huffmantree[lNode].level, huffmantree[rNode].level);
		huffmantree[i].level = huffmantree[lNode].level + 1;//huffmantree[i]�ĸ߶����ӽڵ�߶�+1
	}
}
int main()
{
	int n;
	cin >> n;
	int data[100], weight[100];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		weight[i] = data[i];
		sum += data[i];
	}
	Huffman hf;
	hf.Set(data, weight, n);
	hf.create();
	int max_level=-1;//�ҵ�����level
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (hf.huffmantree[i].level > max_level)
		{
			max_level = hf.huffmantree[i].level;
		}
	}
	/*for (int i = 0; i < 2 * n - 1; i++)
	{
		cout << hf.huffmantree[i].data << " " << hf.huffmantree[i].weight << " " << hf.huffmantree[i].lchild << " " << hf.huffmantree[i].rchild << " " << hf.huffmantree[i].parent << " " << hf.huffmantree[i].level << endl;
	}*/
	double avg_length = 0;
	for (int i = 0; i < n; i++)
	{
		avg_length += (max_level - hf.huffmantree[i].level) * data[i];//���*Ȩֵ
	}
	avg_length /= sum;
	cout << avg_length;
	return 0;
}