#include "preInclude.h"
#include <vector>
#include <algorithm>

using namespace std;
void oddInOddEvenInEven(vector<int>& arr, int len)
{
    int oddStart = 1 , evenStart = 0;
    while(oddStart < len && evenStart < len)
    {
        while(arr[oddStart] % 2 == 1)
            oddStart += 2;
        while(arr[evenStart] % 2 == 0)
            evenStart += 2;
        if(oddStart < len && evenStart < len)
        {
            arr[oddStart] = arr[oddStart] + arr[evenStart];
            arr[evenStart] = arr[oddStart] - arr[evenStart];
            arr[oddStart] = arr[oddStart] - arr[evenStart];
        }
    }
}

int getFirstUnFormedNum(vector<int> &arr, int len)
{
    int mins = 0 , maxs = arr[0];
    vector<int> rs;
    vector<int>::iterator rs_iter , rs_end;
    for(int i = 0; i < len; i++)
    {
        int rs_size = rs.size();
        for(int j = 0; j < rs_size; j++)
            rs.push_back(arr[i] + rs[j]);
        rs.push_back(arr[i]);
    }
    sort(rs.begin() , rs.end());
    for(rs_iter = rs.begin(); rs_iter != rs.end(); rs_iter++)
    {
        if(rs_iter == rs.begin())
            continue;
        if(*rs_iter - *(rs_iter - 1) > 1)
            break;
    }
    if(rs_iter == rs.end())
        return rs.back() + 1;
    else
        return *(rs_iter - 1) + 1;
}




//����һ������ΪN����������arr�����Ի���
//�������������֣� �󲿷�arr[0..K]���Ҳ�
//��arr[K+1..arr.length-1]��K����ȡֵ�ķ�
//Χ��[0,arr.length-2] ����ô�໮�ַ����У�
//�󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ��
//����Ƕ��٣� ���磺 [2,7,3,1,1] ���󲿷�Ϊ[2,7]����
//����Ϊ[3,1,1]ʱ���󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵΪ4;
// ���󲿷�Ϊ[2,7,3]���Ҳ���Ϊ[1,1]ʱ��
// �󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵΪ6; ��󷵻صĽ��Ϊ6��
// ע�⣺�������ĳ���ΪN���뾡������ʱ�临�Ӷ�O(N)������ռ临�Ӷ�O(1)

int getMaxABSLeftAndRight(vector<int> &vec, int len)
{
    int *pre = new int[len] , *suffix = new int[len];
    int maxs = vec[0];
    for(int i = 0; i < len; i++)
    {
        if(i == 0)
            pre[0] = vec[0];
        if(vec[i] > maxs)
            maxs = vec[i];

        pre[i] = maxs;
    }
    maxs = vec.back();
    for(int i = vec.size() - 1; i >= 0; i--)
    {
        if(i == vec.size() - 1)
            suffix[i] = vec.back();
        if(vec[i] > maxs)
            maxs = vec[i];

        suffix[i] = maxs;
    }
    maxs = 0;
    for(int i = 0; i < vec.size(); i++)
    {
        if(abs(suffix[i] - pre[i]) > maxs)
            maxs = abs(suffix[i] - pre[i]);
    }
    return maxs;
}


//����һ���������ͷ���ڵ�head��������ΪN��
//���NΪż������ôǰN/2���ڵ��������������N/2���ڵ������Ұ�����
//���NΪ��������ôǰN/2���ڵ��������������N/2+1���ڵ������Ұ�����
//��������������μ�ΪL1->L2->...���Ұ������������μ�ΪR1->R2->...��
//�뽫�����������L1->R1->L2->R2->...�����ӡ�
//���磺 1->2->3->4 ������1->3->2->4 1->2->3->4->5 ������1->3->2->4->5
//Ҫ�����������ΪN��ʱ�临�Ӷ���ﵽO(N)��
//����ռ临�Ӷ���ﵽO(1)
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL){}
};

void relocateList(struct ListNode* head)
{
    struct ListNode *runner1 = head , *runner2 = head;
    while(runner1->next != NULL)
    {
        if(runner1->next->next != NULL)
            runner1 = runner1->next->next;
        else
            runner1 = runner1->next;
        runner2 = runner2->next;
    }
    struct ListNode *rightStart = runner2 , *leftStart = head;
    bool leftHead = true;
    while(leftStart != runner2 && rightStart != NULL)
    {
        if(leftHead)
        {
            struct ListNode *tmp = leftStart->next;
            leftStart->next = rightStart;
            leftStart = tmp;
        }
        else
        {
            struct ListNode *tmp = rightStart->next;
            rightStart->next = leftStart;
            rightStart = tmp;
        }
        leftHead = !leftHead;
    }
}
//
//����һ��·������paths����ʾһ��ͼ��
//paths[i]==j�������i�������j��
//���paths[i]==i��ʾi�������׶���
//һ��ͼ��ֻ����һ���׶���
//�����з�ͼ��ͼ�г����׶�ָ���Լ�֮�ⲻ���л���
//���磺paths={9,1,4,9,0,4,8,9,0,1} ����������ʾ��ͼ����ͼ��ʾ��
//����1���׶����Ծ���Ϊ0�����׶�����Ϊ1�ĳ���ֻ�г���9��
//���׶�����Ϊ2�ĳ����г���0��3��7��
//���׶�����Ϊ3�ĳ����г���4��8�����׶�����Ϊ4�ĳ����г���2��5��6��
//���ԣ�����Ϊ0�ĳ�����1��������Ϊ1�ĳ�����1��������Ϊ2�ĳ�����3����
//����Ϊ3�ĳ�����2��������Ϊ4�ĳ�����3����
//��ôͳ������ΪnumArr={1,1,3,2,3,0,0,0,0,0}��
//numArr[i]==j�������Ϊi�ĳ�����j����
//Ҫ��ʵ��һ��void���͵ĺ���������һ��·������paths��
//ֱ����ԭ�����ϵ�����ʹ֮��ΪnumArr���顣
//paths={9,1,4,9,0,4,8,9,0,1}�����������
//paths={1,1,3,2,3,0,0,0,0,0}��
//Ҫ�����paths����ΪN��ʱ�临�Ӷ�ΪO(N)������ռ临�Ӷ�ΪO(1)��

void pathArrToNumArr(vector<int>& paths,int len)
{



}

int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(3);
    a.push_back(1);
    a.push_back(1);
    cout<<getMaxABSLeftAndRight(a , 5);



}
