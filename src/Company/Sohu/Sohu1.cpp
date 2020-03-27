#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Use brief, otherwise the index won't have a brief explanation.
 *
 * Detailed explanation.
 * @note
 * @see
 */
class CSohu1
{
public:
    struct ListNode
    {
        int value;
        ListNode* next;
    };
    ListNode* reverseList(ListNode* head);
    ListNode* reverseListRecursive(ListNode* head);

    void insertListHead(ListNode*& head, int data);
    void printList(ListNode* head);
    void runTest()
    {
        ListNode* head = NULL;
        for (int i = 0; i < 9; i++)
            insertListHead(head, i);
        cout << "original list: ";
        printList(head);

        head = reverseList(head);
        cout << "reversed list: ";
        printList(head);

        head = reverseListRecursive(head);
        cout << "reversed list: ";
        printList(head);
    }
};

CSohu1::ListNode* CSohu1::reverseList(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* prev = head;
    ListNode* curr = head->next;
    ListNode* temp = head->next->next;
    //  prev -> curr -> temp
    //   a   ->  b   ->  c   ->  d
    //      <-  curr->next = prev
    while (curr) {
        temp = curr->next;  // temp作为中间节点，记录当前结点的下一个节点的位置
        curr->next = prev;  //当前结点指向前一个节点
        prev = curr;        //指针后移
        curr = temp;        //指针后移，处理下一个节点
    }

    head->next = NULL;  // while结束后，将翻转后的最后一个节点（即翻转前的第一个结点head）的链域置为NULL
    return prev;
}

CSohu1::ListNode* CSohu1::reverseListRecursive(ListNode* head)
{
    if (head == NULL || head->next == NULL)  //递归终止条件:找到链表最后一个结点
        return head;
    else {
        ListNode* newhead = reverseListRecursive(head->next);  //先反转后面的链表，从最后面的两个结点开始反转，依次向前
        head->next->next = head;                               //将后一个链表结点指向前一个结点
        head->next = NULL;                                     //将原链表中前一个结点指向后一个结点的指向关系断开
        return newhead;
    }
}

/*!
 * @brief 插入一个新节点到链表中(放在链表头部)
 * @param head head pointer of the list
 * @param data the data to insert before head
 * @return  NULL
 * @note
 */
void CSohu1::insertListHead(ListNode*& head, int data)
{
    //创建新节点
    ListNode* p = new ListNode;
    p->value = data;
    p->next = NULL;

    if (head == NULL) {
        head = p;
        return;
    }
    p->next = head;
    head = p;
}

void CSohu1::printList(ListNode* head)
{
    ListNode* p = head;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}


int main()
{
    CSohu1 res;
    res.runTest();
    return 0;
}
