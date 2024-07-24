#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int k;//�����Сk
    cin >> k;
    int n;//�����еĳ�ʼ����n
    cin >> n;
    int s;//�������еĿ���s
    cin >> s;
    vector<int> cache(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> cache[i];//�����
    }
    vector<int> requests(s);
    for (int i = 0; i < s; i++) 
    {
        cin >> requests[i];//��������
    }
    map<int, int> last_used;//������¼ÿ�����ϴ�ʹ�õ�ʱ��,cache[i]->last_used_time
    for (int i = 0; i < n; i++) //��ʼ������Ԫ�ص��ϴ�ʹ��ʱ��
    {
        last_used[cache[i]] = i;//�����еĳ�ʼ����ϴ�ʹ��ʱ����������ڻ����е�˳��
    }
    vector<int> eviction_schedule;//��¼����Ŀ��ֵ
    for (int i = 0; i < s; i++) 
    {
        int block = requests[i];//ȡ��Ԫ��request[i]
        if (last_used.count(block)) //���request[i]�ǲ����Ѿ���cache�У�����Ѿ�����
        {
           // cout << "exist" << endl;
            continue;//�����¸�ѭ�����ж���һ����
        }
        if (cache.size() < k) //����ÿ鲻��cache�У���黺������ǲ��ǻ���λ�ã������λ��
        {
           // cout << "insert" << endl;
            cache.push_back(block);//request[i]�Ž�cacheȥ
            last_used[block] = i;//�����ϴ�request[i]��Ӧ���ϴ�ʹ��ʱ��
            continue;//�����¸�ѭ�����ж���һ����
        }
        // cache�����Ҳ����ڣ���Ҫ�滻���ҵ�Ҫ����Ŀ�
        map<int, int> next_used;//������¼cache��ÿ�����´����ʹ�õ�ʱ��,cache[i]->last_used_time
        for (int j = i + 1; j < s; j++)//��request�����еĵ�i����֮��Ŀ�ȥ��cache��Ԫ���´ε�����ĳ���ʱ��
        {
            int m;
            for (m = 0; m < k; m++)//����cache��ÿ��Ԫ��
            {
                if (cache[m] == requests[j] && !next_used.count(cache[m]))//request[j]==cache[m]����nest_used�л�û��cache[m]
                {
                    next_used[cache[m]] = j;//cache[m]->next_used_time=j
                }
            }
        }
        int flag = 1;
        for (int m = 0; m < k; m++)
        {
            if (last_used[cache[m]] && !next_used.count(cache[m]))//���������иÿ鲻�ٳ���
            {
                next_used[cache[m]] = s + 1;//�´��������ʱ��ͳһд��s+1
                flag = 0;
            }
        }
        if (flag == 0)//���������д��ڲ���ʹ�õĿ�
        {
            int evict_block = -1;//��ʼ��
            int evict_time = s;//��ʼ��
            for (auto it = last_used.begin(); it != last_used.end(); it++)
            {
                if (it->second < evict_time && next_used[it->first] == s + 1)//it���ϴη���ʱ��ȵ�ǰ��¼����Զ�ķ���ʱ�仹Ҫ��Զ����it��Ӧ�ں���requesr�����в��ٳ���
                {
                    evict_block = it->first;//����
                    evict_time = it->second;//����
                }
            }
            //������滻��
            last_used.erase(evict_block);//�ڼ�¼�ϴη���ʱ�������������¼
            for (int j = 0; j < cache.size(); j++) //�ڻ������ҵ�Ҫ������������
            {
                if (cache[j] == evict_block)//���µ�ȥ�滻 
                {
                    cache[j] = block;
                }
            }
            //cout << "replace" << endl;
            last_used[block] = i;//��¼�¼�����������ϴη���ʱ��
            eviction_schedule.push_back(evict_block);//�ѱ�����Ŀ������������е�vector��
        }
        else if (flag == 1)//cache�еĿ���request�����к������з��ʵ�
        {
            int evict_block = -1;//��ʼ����¼��Զ���ʵĿ�
            int evict_time = -1;//��ʼ����¼��Զ���ʵĿ�ķ���ʱ��
            for (int j = 0; j < n; j++)
            {
                for (auto it = next_used.begin(); it != next_used.end(); it++)
                {
                    if (it->second > evict_time)//��Զ
                    {
                        evict_block = it->first;//������Զ���ʵĿ�
                        evict_time = it->second;//������Զ���ʵ�ʱ��
                    }
                }
            }
            last_used.erase(evict_block);//�ڼ�¼�ϴη���ʱ�������������¼
            for (int j = 0; j < cache.size(); j++) //�ڻ������ҵ�Ҫ������������
            {
                if (cache[j] == evict_block)//���µ�ȥ�滻 
                {
                    cache[j] = block;
                }
            }
           // cout << "replace" << endl;
            last_used[block] = i;//��¼�¼�����������ϴη���ʱ��
            eviction_schedule.push_back(evict_block);//�ѱ�����Ŀ������������е�vector��
        }
    }
    // ��ӡ������������
    for (int i = 0; i < eviction_schedule.size(); i++) 
    {
        cout << eviction_schedule[i] << " ";
    }
    cout << endl;
    return 0;
}
