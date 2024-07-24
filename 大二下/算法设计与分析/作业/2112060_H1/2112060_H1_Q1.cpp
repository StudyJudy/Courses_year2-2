#include<iostream>
using namespace std;
class Man
{
public:
	char name;//��¼��������
	char rank[1000];//��¼Ů��˳��
	bool visited[1000] = { false };//��¼�Ѿ�proposed����rejected��Ů��
	bool propose;//��¼�ǲ�������ƥ��
	char matched;//��¼Ŀǰƥ��Ķ���
};
class Woman 
{
public:
	char name;//��¼Ů������
	char rank[1000];//��¼����˳��
	bool accept;//��¼�ǲ�������ƥ��
	char matched;//��¼Ŀǰƥ��Ķ���
};
int main()
{
	int n;
	char temp1, temp2;
	cout << "n= ";
	cin >> n;
	Man* man = new Man[n];//����
	Woman* woman = new Woman[n];//Ů��
	for (int i1 = 0; i1 < n; i1++)//������Ϣ
	{
		cin >> man[i1].name;//��ǰ����������
		man[i1].propose = false;//��ʼ��δƥ��
		cin >> temp1;//����:
		for (int j = 0; j < n; j++)
		{
			cin >> man[i1].rank[j];//���뵱ǰ�������ǵ�Ů��ƥ��˳��
			if (j != n - 1)//�������һ��
			{
				cin >> temp2;//����>
			}
		}
	}
	for (int i1 = 0; i1 < n; i1++)//Ů����Ϣ
	{
		cin >> woman[i1].name;//��ǰŮ��������
		woman[i1].accept = false;//��ʼ��δƥ��
		cin >> temp1;//����:
		for (int j = 0; j < n; j++)
		{
			cin >> woman[i1].rank[j];//���뵱ǰŮ�����ǵ�����ƥ��˳��
			if (j != n - 1)//�������һ��
			{
				cin >> temp2;//����>
			}
		}
	}
	for (int i = 0; i < n; i++)//����ѡ��Ȩ
	{
		int m, p;
		for ( m = 0; m < n; m++)//�ҵ���ǰ����û�ҹ������ȼ���ߵ�Ů��
		{
			if (man[i].visited[m] == false)
			{
				break;//�ҵ����˳�ѭ������Ů����������man[i].rank[m]
			}
		}
		for ( p = 0; p < n; p++)//�ҵ���Ů��
		{
			if (woman[p].name == man[i].rank[m])
			{
				break;//�ҵ��˸�Ů������Ů����Ϣ����woman[p]λ��
			}
		}
		if (man[i].propose == false && woman[p].accept == false)//������û�гɹ���propose�Ҹ�Ů��ĿǰҲû��accept��ƥ��
		{
			man[i].propose = true;//������ƥ��
			man[i].matched = woman[p].name;//����ƥ��Ķ����������woman[p].name
			woman[p].accept = true;//��ǰŮ����ƥ��
			woman[p].matched = man[i].name;//��ǰŮ��ƥ��Ķ����������man[i].name
		}
		else if (woman[p].accept == true)//Ů���Ѿ���ƥ��Ķ����ˣ�������ͻ��Ů���оܾ�Ȩ
		{
			int m1, m2, m3;//�ֱ��ҵ�����¼���������������ȼ�
			for ( m1 = 0; m1 < n; m1++)//m1��¼��ǰ�¾��������rank��λ��
			{
				if (woman[p].rank[m1] == man[i].name)
				{
					break;//�ҵ��˵�ǰ�¾����ߵ�λ����m1
				}
			}
			for ( m2 = 0; m2 < n; m2++)//m2��¼��ǰ��ƥ������rank��λ��
			{
				if (woman[p].rank[m2] == woman[p].matched)
				{
					break;//�ҵ��˵�ǰ��ƥ������λ����m2
				}
			}
			if (m1 < m2)//Ů��woman[p]����,m1<m2,�¾�����man[i]�����ȼ����ߣ���ܾ�ԭ��ƥ��
			{
				char temp3 = woman[p].matched;//temp3��¼ԭƥ����������
				man[i].propose = true;//man[i]��ƥ��
				man[i].matched = woman[p].name;//man[i]ƥ������������woman[p].name
				woman[p].accept = true;//Ů����ƥ��
				woman[p].matched = man[i].name;//woman[p]ƥ��Ķ�������ָ�����man[i].name
				for (int m3 = 0; m3 < n; m3++)//�ҵ�ԭƥ������ֱ��ܾ��������Ϣ
				{
					if (man[m3].name == temp3)//�ҵ��ˣ���m3��λ��
					{
						man[m3].propose = false;//���δƥ��״̬
						man[m3].matched = false;//û��ƥ�����
						for (int m4 = 0; m4 < n; m4++)//�ҵ�ԭƥ��Ů�������ȼ�λ��
						{
							if (man[m3].rank[m4] == woman[p].name)
							{
								man[m3].visited[m4] = 1;//ԭŮ����λ�ñ���ѷ��ʹ�
								i = m3 - 1;//��һ����Ҫƥ����������man[m3]
							}
						}
					}
				}
			}
			else if (m1 > m2)//Ů��woman[p]����,m1>m2,��ƥ���������ȼ����ߣ���ܾ��¾�����
			{
				man[i].visited[m] = 1;//��ǰŮ����λ���ѷ��ʹ�
				i = i - 1;//��һ����Ҫƥ�����������man[i]
			}
		}
	}
	//���ƥ���Ľ��
	for (int a = 0; a < n; a++)
	{
		cout << "(" << man[a].name << "," << man[a].matched << ")" << endl;
	}
	return 0;
}