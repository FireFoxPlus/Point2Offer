#include "Pro37.h"

int Pro37_2::getLen(snode<int> *head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->getNext();
    }
    return len;
}

snode<int> *Pro37_2::getFirstCommon(snode<int> *head1 , snode<int> *head2)
{
    int len1 = getLen(head1) , len2 = getLen(head2);
    if(len1 > len2)
    {
        int before = len1 - len2;
        while(before > 0)
        {
            head1 = head1->getNext();
            before--;
        }
    }
    else
    {
        int before = len2 - len1;
        while(before > 0)
        {
            head2 = head2->getNext();
            before--;
        }
    }

    while(head1 != head2 && head1 != NULL && head2 != NULL)
    {
        head1 = head1->getNext();
        head2 = head2->getNext();
    }
    return head1;
}
