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




//给定一个长度为N的整型数组arr，可以划分
//成左右两个部分： 左部分arr[0..K]，右部
//分arr[K+1..arr.length-1]，K可以取值的范
//围是[0,arr.length-2] 求这么多划分方案中，
//左部分中的最大值减去右部分最大值的绝对值，
//最大是多少？ 例如： [2,7,3,1,1] 当左部分为[2,7]，右
//部分为[3,1,1]时，左部分中的最大值减去右部分最大值的绝对值为4;
// 当左部分为[2,7,3]，右部分为[1,1]时，
// 左部分中的最大值减去右部分最大值的绝对值为6; 最后返回的结果为6。
// 注意：如果数组的长度为N，请尽量做到时间复杂度O(N)，额外空间复杂度O(1)

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


//给定一个单链表的头部节点head，链表长度为N。
//如果N为偶数，那么前N/2个节点算作左半区，后N/2个节点算作右半区；
//如果N为奇数，那么前N/2个节点算作左半区，后N/2+1个节点算作右半区；
//左半区从左到右依次记为L1->L2->...，右半区从左到右依次记为R1->R2->...。
//请将单链表调整成L1->R1->L2->R2->...的样子。
//例如： 1->2->3->4 调整后：1->3->2->4 1->2->3->4->5 调整后：1->3->2->4->5
//要求：如果链表长度为N，时间复杂度请达到O(N)，
//额外空间复杂度请达到O(1)
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
//给定一个路径数组paths，表示一张图。
//paths[i]==j代表城市i连向城市j，
//如果paths[i]==i表示i城市是首都，
//一张图里只会有一个首都，
//不会有分图且图中除了首都指向自己之外不会有环；
//例如：paths={9,1,4,9,0,4,8,9,0,1} 由这个数组表示的图如下图所示。
//城市1是首都所以距离为0；离首都距离为1的城市只有城市9；
//离首都距离为2的城市有城市0，3，7；
//离首都距离为3的城市有城市4，8；离首都距离为4的城市有城市2，5，6；
//所以，距离为0的城市有1座；距离为1的城市有1座；距离为2的城市有3座；
//距离为3的城市有2座；距离为4的城市有3座；
//那么统计数组为numArr={1,1,3,2,3,0,0,0,0,0}，
//numArr[i]==j代表距离为i的城市有j座；
//要求实现一个void类型的函数，输入一个路径数组paths，
//直接在原数组上调整，使之变为numArr数组。
//paths={9,1,4,9,0,4,8,9,0,1}，函数处理后，
//paths={1,1,3,2,3,0,0,0,0,0}。
//要求：如果paths长度为N，时间复杂度为O(N)，额外空间复杂度为O(1)；

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
