#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <string>
#include <map>

using namespace std;

typedef int DataType;
//-----------------------------1.˳���̡�---------------------------------------------

/*˳���Ĳ���*/
//1.����
//2.ɾ��
//3.����
//4.����

/*˳���Ӧ��*/
//1.�����㷨
//2.���ֲ���:�ڳ���Ϊn������arr�в���valֵ���±�,δ�ҵ�����-1
//3.ģ��˫��ջ(��ʡ�ռ�)��ѭ������
//4.��ת˳����ǰxλ�ͺ�n-xλ,��ת����˳���
//5.ɾ���ظ�Ԫ��


//1.�����㷨
//2.���ֲ���:�ڳ���Ϊn������arr�в���valֵ���±�,δ�ҵ�����-1
//C���԰�:
DataType binarySearch_C(DataType*arr,DataType n,DataType val){
    DataType lchild=0,rchild=n-1;   //�����ұ߽�
    while(lchild<=rchild){     //�ж����ұ߽��Ƿ����
        DataType mid=(lchild+rchild)/2; //�����м�ֵ
        if(arr[mid]==val){  //�ҵ�val
            return mid;
        }else if(arr[mid]>val){ //�м�ֵ����val,����߲���
            rchild=mid-1;
        }else{              //�м�ֵС��val,���ұ߲���
            lchild=mid+1;
        }
    }
    return -1;              //û�ҵ�,����-1
}
//C++��:
DataType binarySearch_CPP(vector<DataType>arr,DataType val){
    DataType lchild=0,rchild=arr.size()-1;  //�����ұ߽�
    while(lchild<=rchild){             //�ж����ұ߽��Ƿ����
        DataType mid=(lchild+rchild)/2;     //�����м�ֵ
        if(arr[mid]==val){          //�ҵ�val
            return mid;
        }else if(arr[mid]>val){     //�м�ֵ����val,����߲���
            rchild=mid-1;
        }else{                      //�м�ֵС��val,���ұ߲���
            lchild=mid+1;
        }
    }
    return -1;                      //û�ҵ�,����-1
}
//3.ģ��˫��ջ(��ʡ�ռ�)��ѭ������
//ģ��˫��ջ,������������ɾ��ĵĴ���
typedef struct{     //˫��ջ,ջ������:Ltop+1==Rtop
    DataType Ltop,Rtop;  //����ջ��ջ��,Ltop��ʼ��Ϊ0,Rtop��ʼ��Ϊcapacity-1��LtopΪ���ջ,RtopΪ�Ҳ�ջ
    DataType *data;      //ջ����
    DataType capacity;   //ջ����
}DoubleStack;
int PushDoubleStack(DoubleStack *stack,DataType data,DataType LoR){  //LoRָʾ�������-0���Ҳ�-1,
    if(stack->Ltop+1 == stack->Rtop){   //ջ��
        printf("ջ��,����ʧ��...\n");
        return -1;
    }
    if(!LoR){       //�������ջ
        stack->data[stack->Ltop++]=data;    //��dataѹ��ջ��
        return true;
    }else{          //�����Ҳ�ջ
        stack->data[stack->Rtop--]=data;    //��dataѹ��ջ��
        return true;
    }
}
// bool PopDoubleStack(DoubleStack *stack,DataType*e,DataType LoR){
//     //LoRѡ����ջ����ջ,��ջ��Ԫ�س�ջ��e
//     if(!LoR){
//         if(stack->Ltop==0){
//             printf("ջ��,ɾ��ʧ��...\n");
//             return false;
//         }
//         *e=stack->data[stack->Ltop-1];
//         stack->Ltop--;
//         return true;
//     }else{
//         if(stack->Rtop==stack->capacity-1){
//             printf("ջ��,ɾ��ʧ��...\n");
//             return false;
//         }
//         *e=stack->data[stack->Rtop+1];
//         stack->Rtop++;
//         return true;
//     }
// }

//4.��ת˳����ǰxλ�ͺ�n-xλ,��ת����˳���
//5.ɾ���ظ�Ԫ��

//-----------------------------2.����̡�---------------------------------------------
typedef struct linknode{    //������
    int data;               //������
    struct linknode*next;   //ָ����
}LinkList,LinkListHead,CycleLinkList,CycleLinkListHead,LinkNode,CycleLinkNode;
typedef struct doublelinknode{      //˫����
    int data;               //������
    struct doublelinknode*next,*pre;//ָ����
}DoubleLinkList,DoubleLinkListHead,DoubleLinkNode;
/*��������Ĳ����Ϊͷ���β��*/
/*��\���� ͷ���� ��\˫\ѭ�� ����Ĳ���*/
//1.����
//2.ɾ��
//3.����
//4.����

/*�����Ӧ��*/
//1.��ת��������ת˫������תѭ����������תѭ��˫����
//2.ɾ��ֵΪval��Ԫ��
//3.��ӡ�������������еĹ�ͬ���֣�
//4.�жϵ������Ƿ��ǻ��ĵ�����
//5.�жϵ������Ƿ��л�,���л����ҳ��������
//6.������������Ĺ�����׺
//7.��������ĳֵ���ֳ����С,�м����,�ұߴ����ʽ��
//8.���������ѭ������
//9.��������м���

//1.1��ת����ͷ���ĵ�����
LinkList* reverseLinkList(LinkList*head){   //ʹ��ͷ�巨
    if(!head)return NULL;    //��������NULL
    LinkNode*cur = head,*next = cur->next;  //curָ���һ�����,nextָ����һ������ֹ����
    head = NULL;
    while(cur){             //��ǰδ�ߵ����һ�����
        cur->next = head;   //ͷ��,cur��Ϊ�µ�ͷ���,��head�����ߵĽ�㽨������
        head = cur;         //����headΪcur
        cur = next;         //cur����������
        if(next)next = next->next;  //next��Ȼ����NULLʱ,�ͼ��������߷�ֹ����
    }
    return head;            //�����µ�head���(��ΪҪ��ͷ,���Ա��뷵��head)
}
//1.2��ת��ͷ���ĵ�����:
bool reverseLinkListHead(LinkListHead*head){
    if(!head->next)return true; //��������true,Ҳ���Է���false��
    LinkNode*cur = head->next,*next = cur->next;  //curָ���һ�����,nextָ����һ������ֹ����
    head->next = NULL;  //����head��nextָ��,��������Ϊ��,����ͷ��
    while(cur){         //��cur�������һ�����ʱ
        cur->next = head->next; //ͷ�����ͷ���head���ӵĵ�һ�����
        head->next = cur;       //����head��nextָ��,ָ����ͷ��Ľ��cur
        cur = next;             //cur����������,����ͷ�巨
        if(next)next = next->next;  //��nextδ���������ָ���߽��,��ֹ����
    }
    return true;        //��ת���,����true
}
//1.3��ת����ͷ����ѭ��������:
CycleLinkList*reverseCyclyLinkList(CycleLinkList*head){ //ʹ��ͷ�巨
    if(!head)return NULL;   //��������NULL
    CycleLinkNode*cur_head = head;  //��¼��ǰͷ���,����β���
    CycleLinkNode*cur = head,*next = cur->next;  //curָ���һ�����,nextָ����һ������ֹ����
    head = NULL;
    while(1){  
        cur->next = head;   //ͷ��,cur��Ϊ�µ�ͷ���,��head�����ߵĽ�㽨������
        head = cur;         //����headΪcur
        if(next == cur_head) break; //��nextָ��ͷ���������ѭ��,��ʱcurָ��ԭ�����β���
        cur = next;         //cur����������
        next = next->next;  //next���������߷�ֹ����
    }
    cur_head->next = cur;   //curָ��ԭ�����β���,��ʱcur_headָ��ԭ�����ͷ���,next��ת
    return head;            //�����µ�head���(��ΪҪ��ͷ,���Ա��뷵��head)
}
//1.4��ת��ͷ����ѭ��������:
bool reverseCyclyLinkListHead(CycleLinkListHead*head){
    if(!head->next)return true; //��������true,Ҳ���Է���false
    CycleLinkNode*cur = head->next->next,*next = cur->next;  //curָ��ڶ������,nextָ����һ������ֹ����
    head->next->next = head;  //����head->next��nextָ��,��������Ϊ��,����ͷ��
    
    return true;        //��ת���,����true
}
//1.5��ת����ͷ����˫����:
DoubleLinkList*reverseDoubleLinkList(DoubleLinkList*head){
    if(!head)return NULL;    //��������NULL
    DoubleLinkNode*cur = head->next,*next = cur->next;  //curָ��ڶ������,nextָ����һ������ֹ����
    head->next= NULL;       //����head��nextָ���preָ��
    head->pre = NULL;
    while(cur){             //��ǰδ�ߵ����һ�����
        cur->next = head;   //ͷ��,cur��Ϊ�µ�ͷ���,��head�����ߵĽ�㽨������
        cur->pre = NULL;    //����cur��preָ��
        head->pre = cur;    //����head��preָ��,ָ����ͷ��Ľ��cur
        head = cur;         //����headΪcur
        cur = next;         //cur����������
        if(next)next = next->next;  //next��Ȼ����NULLʱ,�ͼ��������߷�ֹ����
    }
    return head;            //�����µ�head���(��ΪҪ��ͷ,���Ա��뷵��head)
}
//1.6��ת��ͷ����˫����:
bool reverseDoubleLinkListHead(DoubleLinkListHead*head){
    if(!head->next)return true; //��������true,Ҳ���Է���false
    DoubleLinkNode*cur = head->next,*next = cur->next;  //curָ���һ�����,nextָ����һ������ֹ����
    head->next = NULL;  //����head��nextָ��,��������Ϊ��,����ͷ��
    while(cur){         //��ʼͷ��
        cur->next = head->next; //�޸�curָ���next
        cur->pre = head;        //�޸�curָ���pre,������ָ��head
        if(head->next)          //��head->next��Ϊ��
            head->next->pre = cur;  //����head->next��preָ���µ�ͷ����cur
        head->next = cur;       //��ͷ�������head->next
        cur = next;             //cur����������
        if(next)next = next->next;      //next���������߷�ֹ����
    }
    return true;        //��ת���,����true
}

//2.1�ݹ�ɾ������ͷ���ĵ�������ֵΪval��Ԫ��:
LinkList* deleteDuplication(LinkList*head,int val){
    if(!head)return NULL;   //��������
    LinkList*next = head->next; //next����ָ����һ�����,��ֹ����
    if(next->data == val) free(head);   //�����һ������ֵ����val,���ͷŸý��
    return deleteDuplication(next,next->data);  //���غ������ĵݹ�����
}
//2.2�ǵݹ�ɾ������ͷ���ĵ�������ֵΪval��Ԫ��:
LinkList* deleteDuplication2(LinkList*head,int val){
    if(!head)return NULL;   //������ֱ�ӽ���
    while(head && head->data==val){ //�ȹ̶�ͷ���,��ֵ��Ϊval�Ľ����Ϊ�µ�ͷ���
        LinkList*tmp = head->next;  //tmpָ��head->next��ֹ����
        free(head);                 //�ͷ�head
        head = tmp;
    }
    LinkList*pre = head;            //pre��head��ʼ
    LinkList*cur = head?head->next:NULL; //curָ���Ѿ��̶���ͷ���ĵڶ������
    LinkList*next = cur?cur->next:NULL;  //next����ָ����һ�����,��ֹ����
    while(cur){
        if(cur->data == val){       //cur���ֵ����val
            pre->next = next;       //��pre->nextָ��next
            free(cur);              //�ͷ�cur
            cur = next;             //cur����������
            if(next)next = next->next;
        }else{                      //cur���ֵ������val
            pre = cur;              //pre����������
            cur = cur->next;        //cur����������
            next = next?next->next:NULL;
        }
    }
    return head;                    //�����µ�head
}

//3.��ӡ��������ͷ�������������еĹ�ͬ���֣�
void getCommonList(LinkList*head1,LinkList*head2){
    if(!head1 || !head2)return ;    //������ֱ�ӷ���
    LinkList *L = head1,*R = head2; //L��R�ֱ�ָ����������
    while(L && R){                  //��ʼѭ���ж�
        if(L->data == R->data)      //����������ֵ���
            printf("%d ",L->data);
        if(L->data < R->data)       //��L����ֵС��R����ֵ
            L = L->next;
            printf("%d ",L->data);
        if(L->data<R->data)L = L->next;
        if(L->data>R->data)R = R->next;
    }
    printf("\n");   //�Ӹ����з�,Ҳ���Բ���,����ĿҪ��
}

//4.�жϲ���ͷ���ĵ������Ƿ��ǻ��ĵ�����
bool isPalindrome(LinkList*head){   //ʹ�ÿ���ָ�����е�,�����Ƚ�
    if(!head || !head->next)return false;  //��������false
    //1.����ָ���Һ���������е�
    LinkNode*fast = head,*slow = head;
    do{         //��ָ��������,��ָ����һ��
        if(fast->next && fast->next->next)fast = fast->next->next;
        else break;
        slow = slow->next;
    }while(1);  //�˳�ѭ����slow->nextָ��ľ��Ǻ�벿������ĵ�һ�����
    //2.��תslow->next��ʼ�����н�� - Ϊʡ�ռ�,�ɽ��ù���д�ɺ������е���
    LinkNode*cur = slow->next,*next = cur->next;
    slow->next = NULL;
    while(cur){ //��ʼ��ת,ʹ��ͷ�巨
        cur->next = slow->next;
        slow->next = cur;
        cur = next;
        if(next)next = next->next;
    }
    //3.��ʼ�Ƚ�,cur��next����ָ��ǰ��벿�ֵĽ��
    cur = head;         //ָ��ǰ�벿��
    next = slow->next;  //ָ���벿��
    while(cur && next){ //����һ���ߵ�NULLʱֹͣ
        if(cur->data != next->data)return false;
        cur = cur->next;
        next = next->next;
    }
    //4.�Ƚ����,����벿���������·�ת����
    cur = slow->next;
    next = cur->next;
    slow->next = NULL;
    while(cur){ //��ʼ��ת,ʹ��ͷ�巨
        cur->next = slow->next;
        slow->next = cur;
        cur = next;
        if(next)next = next->next;
    }
    return true;//�ȽϽ���,����true
}

//5.�жϲ���ͷ���ĵ������Ƿ��л�,���л����ҳ��������
LinkNode* isLoopList(LinkList*head){    //ʹ�ÿ���ָ��
    if(!head)return NULL;  //������,�޻�,����NULL
    LinkNode*slow = head,*fast = head;  //slowָ���һ�����,fastָ���һ�����
    do{
        slow = slow->next;  //��ָ����һ��
        if(fast->next && fast->next->next)fast = fast->next->next;//��ָ��������
        else return NULL;   //�޻�ֱ�ӷ���NULL,ֻ���жϿ�ָ��,��Ϊ��ָ��ʼ������ָ��ǰ��
    }while(slow!=fast);     //����ָ������,�л�
    //��ָ��ص����,��ָ�벻��,ͬʱ��ʼһ��һ������,�����Ľ�㼴���
    fast = head;
    while(fast != slow){    //fast��slowָ�뿪ʼͬ����
        fast = fast->next;
        slow = slow->next;
    }
    return fast;    //����slowҲ����,��ʱfast == slow
}

//6.����������ͷ���ĵ�����Ĺ�����׺,������ʼ�ڵ�
int getLinkListLength(LinkList*head){   //��������
    int count = 0;
    LinkList*cur = head;
    while(cur){     //����һ�����
        count++;
        cur = cur->next;
    }
    return count;
}
LinkNode*getLinkListRearNode(LinkList*head){    //�ҵ������β���
    LinkList*p = head;
    while(p->next) p = p->next;
    return p;
}
LinkNode*getCommonFinalNode(LinkList*head1,LinkList*head2){ 
    //1.����������ĳ���
    int len1 = getLinkListLength(head1);
    int len2 = getLinkListLength(head2);
    //2.�����������β���
    LinkNode*tail1 = getLinkListRearNode(head1);
    LinkNode*tail2 = getLinkListRearNode(head2);
    //3.�󹫹�����
    if(tail1!=tail2)return NULL;    //β��㲻һ��,˵��û�й�����׺
    LinkNode*LongList = len1>len2?head1:head2;  //LongListָ�����������
    LinkNode*ShortList = LongList==head1?head2:head1;//ShortListָ����̵�����
    int delta = len1>len2?len1-len2:len2-len1;  //�󳤶Ȳ�ֵ
    while(delta--)  //���������߲�ֵ��
        LongList = LongList->next;
    while(LongList!=ShortList){ //��������ͬʱ��,ֱ���ߵ�������ʼ�ڵ�
        LongList = LongList->next;
        ShortList= ShortList->next;
    }
    return LongList;//����ShortListҲ����,��ʱ���Ƕ�ָ�򹫹���׺�ĵ�һ�����
}
//7.������ͷ���ĵ�����ĳֵ���ֳ����С,�м����,�ұߴ����ʽ��
LinkNode* partition(LinkList*head,int val){
    //��������,��¼���������ͷ����β���,����ʼ��ΪNULL
    LinkNode*BigHead,*BigEnd,*EquHead,*EquEnd,*SmlHead,*SmlEnd;
    BigHead=BigEnd=EquHead=EquEnd=SmlHead=SmlEnd = NULL;
    LinkNode*cur = head;    //��head��ʼ�ж�
    while(cur){             //�����н��ŵ���Ӧ����
        if(cur->data<val){  //�ŵ�С����
            if(!SmlHead)    //С������δ���κν��
                SmlHead = SmlEnd = cur;
            else{           //����ŵ����
                SmlEnd->next = cur;
                SmlEnd = SmlEnd->next;
            }
        }else if(cur->data == val){ //�ŵ�������
            if(!EquHead)    //��������δ���κν��
                EquHead = EquEnd = cur;
            else{           //����ŵ����
                EquEnd->next = cur;
                EquEnd = EquEnd->next;
            }
        }else{              //�ŵ�������
            if(!BigHead)    //��������δ���κν��
                BigHead = BigEnd = cur;
            else{           //����ŵ����
                BigEnd->next = cur;
                BigEnd = BigEnd->next;
            }
        }
        cur = cur->next;    //cur����������
    }
    head = SmlHead;         //headָ���������ͷ���
    SmlEnd->next = EquHead; //SmlEndָ���������ͷ���
    EquEnd->next = BigHead; //EquEndָ���������ͷ���
    return head;            //��Ϊ�漰��"��ͷ"����,����Ҫ���ش�������ͷ�����Ϊ�µ�ͷ���
}

//8.�������漰ѭ������ - ˼·:ʹ��ѭ������������,Ϊ�򵥲���ɾ������,ֻʹ��βָ��
//��������ݽ�㼰�ṹ��
typedef struct queueNode{   //���ݽ��
    DataType data;          //������
    struct queueNode*next;  //ָ����
}myQueueNode;
//8.1��Ӳ��� - ����β��ͷ��
bool EnQueue(myQueueNode**q,DataType data){ //��ʱ��queue��β���
    //�����漰"��β"����,���queue�Ĵ�����Ҫ�ö���ָ��
    if(!(*q)){  //�ն�,ֱ�ӽ�Ԫ�ز��뼴��
        *q = (myQueueNode*)malloc(sizeof(myQueueNode));
        (*q)->data = data;
        (*q)->next= (*q);   //�����ڵ�ʱָ���Լ�
        return true;
    }
    //�ӷǿ�,�����q->next����
    myQueueNode*tmp = (myQueueNode*)malloc(sizeof(myQueueNode));
    tmp->data = data;
    tmp->next = (*q)->next; //tmp����q��ͷ���
    (*q)->next = tmp;       //β���qָ��tmp
    (*q) = tmp;             //����tmp��Ϊ�µ�β���
    return true;
}
//8.2���Ӳ���,ֵ�ŵ�e�� - ����ͷ��β��
bool DeQueue(myQueueNode**q,DataType*e){ //��ʱ��queue��β���
    if(!(*q)) return false; //�ն�,����ʧ��
    *e = (*q)->next->data;  //��ͷԪ�س���
    if((*q)->next == (*q)){  //ֻ��һ��Ԫ��ʱ
        free(*q);
        *q = NULL;
        return true;
    }
    //��������Ԫ��,�򽫶�ͷ����
    myQueueNode*tmp = (*q)->next;   //������Ԫ���ó���
    *e = tmp->data;         //ȡֵ����e
    (*q)->next = tmp->next; //��������ԭ����
    free(tmp);              //�ͷ��ڴ�ռ�
    return true;
}
//8.3ȡ��ͷԪ�� - ����ͷ��β��
bool GetHead(myQueueNode*q,DataType*e){
    if(!q) return false;
    *e = q->next->data;
    return true;
}
//8.4ȡ��βԪ�� - ����β��ͷ��
bool GetTail(myQueueNode*q,DataType*e){
    if(!q) return false;
    *e = q->data;
    return true;
}
//8.5�ж϶����Ƿ�Ϊ��
bool isEmpty(myQueueNode*q){
    return !q;
}
//8.6��ն���
void ClearQueue(myQueueNode**q){    //qָ��β���
    if(!(*q)) return;
    myQueueNode*tmp = (*q)->next;   //��ͷ��㿪ʼɾ��
    while(tmp != (*q)){             //��δɾ��β���ʱ
        (*q)->next = tmp->next;
        free(tmp);
        tmp = (*q)->next;
    }
    free(*q);       //����ɾ��β��㼴��
    *q = NULL;
}

//9.��������м��� - ����ָ��
LinkNode* FindMid(LinkNode*head){
    if(!head)return NULL;
    LinkNode*fast = head,*slow = head;
    do{         //��ָ��������,��ָ����һ��
        if(fast->next && fast->next->next)fast = fast->next->next;
        else break;
        slow = slow->next;
    }while(1);  //slowָ���м���(�������ʱ)���м����ǰһ�����(ż�����ʱ)
    return fast->next?slow->next:slow;  //����������桢ż��ʱ�Ĳ�ͬ������
}

//----------------------------------3.ջ�̡�----------------------------------------
/*˳��ջ����ջ�Ĳ���*/
//1.�п�����
//2.Push&Pop
//3.ȡջ��Top

/*ջ��Ӧ��*/
//ע:���ķǵݹ��������Ҫ�õ�ջ,����ᵽ����֪ʶ����ȥ
//1.����ƥ�䡤
//2.���ʽ��ֵ
//3.��׺ת��׺

//1.����ƥ��,˼·��������������ջ,���������ų�ջ���ж��Ƿ�ƥ��
bool isMatch(char* str,int len){    //���ĳ���Ϊlen,�������ַ�����β��'\0'
    char*arr = (char*)malloc(sizeof(char)*len); //ģ��ջ
    for(int i = 0;i < len; i++)arr[i] = '\0';   //��ʼ��ջԪ��
    int top = 0;    //��ʾջ��
    for(int i = 0;i<len;i++){   //������
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') //��������ջ
            arr[top++] = str[i];
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){   //�����������ƥ��
            switch(str[i]){     //ƥ����������������
                case ')':       //��Բ����
                    if(arr[top-1] == '(')top--; //ƥ��ɹ�,����ƥ��
                    else return false;          //ƥ��ʧ��,ֱ�ӽ���
                    break;
                case ']':       //������
                    if(arr[top-1] == '[')top--; //ƥ��ɹ�,����ƥ��
                    else return false;          //ƥ��ʧ��,ֱ�ӽ���
                    break;
                case '}':       //������
                    if(arr[top-1] == '{')top--; //ƥ��ɹ�,����ƥ��
                    else return false;          //ƥ��ʧ��,ֱ�ӽ���
                    break;
                default:        //�������,ֱ�ӷ���false
                    return false;
            }
        }
    }
    free(arr);                  //�ͷ��ڴ�ռ�
    return top == 0?true:false; //��������,��ջ��,��ƥ��
}

//2.���ʽ��ֵ
int ExpressionEvaluate(char* str, int len) {
    char* sym = (char*)malloc(sizeof(char) * len); //����ջ
    int* num = (int*)malloc(sizeof(int) * len); //������ջ
    for (int i = 0; i < len; i++) {//��ʼ��ջԪ��
        sym[i] = '\0';
        num[i] = 0;
    }
    int top_sym = 0, top_num = 0;    //����ջ�Ͳ�����ջ��ջ��
    for (int i = 0; i < len; i++) {     //������,�����з��źͲ�������ջ
        if (str[i] >= '0' && str[i] <= '9')        //���ֽ�numջ
            num[top_num++] = str[i] - '0';
        else if (str[i] == '(')      //������ֱ�ӽ�symջ
            sym[top_sym++] = str[i];
        else if (str[i] == '+' || str[i] == '-') {//�Ӽ���Ҫ�Ƚ�symջԪ�����ȼ�
            if (top_sym == 0 || sym[top_sym - 1] == '(' || sym[top_sym - 1] == '\0')
                sym[top_sym++] = str[i];//���ȼ���,ֱ����ջ����
            else {   //���ȼ���Ȼ����,��һֱ��ջ���ߵ�'('��
                while (sym[top_sym - 1] != '('&& top_sym>0) {
                    int b = num[--top_num], a = num[--top_num];
                    switch (sym[--top_sym]) { //��a��b���м���
                    case '*':num[top_num++] = a * b; break;
                    case '/':num[top_num++] = a / b; break;
                    case '+':num[top_num++] = a + b; break;
                    case '-':num[top_num++] = a - b; break;
                    }
                }
                sym[top_sym++] = str[i]; //��ǰ������ջ
            }
        }
        else if (str[i] == ')') {    //������ֱ�ӳ�ջ��������Ϊֹ
            while (sym[top_sym - 1] != '(') {
                int b = num[--top_num], a = num[--top_num];
                switch (sym[--top_sym]) { //��a��b���м���
                case '*':num[top_num++] = a * b; break;
                case '/':num[top_num++] = a / b; break;
                case '+':num[top_num++] = a + b; break;
                case '-':num[top_num++] = a - b; break;
                }
            }
            top_sym--; //�����ų�ջ
        }
        else if (str[i] == '*' || str[i] == '/')   //ֱ����ջ����
            sym[top_sym++] = str[i];
    }
    while (top_sym > 0) {   //���������symջ���г�ջ
        int b = num[--top_num], a = num[--top_num];
        switch (sym[--top_sym]) { //��a��b���м���
        case '*':num[top_num++] = a * b; break;
        case '/':num[top_num++] = a / b; break;
        case '+':num[top_num++] = a + b; break;
        case '-':num[top_num++] = a - b; break;
        }
    }
    free(sym);  //�ͷ�ջ
    top_num = num[0];
    free(num);  //�ͷ�ջ
    return top_num;
}

//3.��׺ת��׺ - ֻ��һ��ջ,�������־����,�������ſ�������
void InToPost(char* str,int len){
    char*sym = (char*)malloc(sizeof(char)*len); //����ջ
    for(int i=0;i<len;i++)sym[i]='\0';  //��ʼ��ջ
    int top = 0;    //��ʾջ��
    for(int i = 0; i < len; i++){   //��ʼ�����ַ���
        if(str[i]>='0' && str[i] <='9') printf("%c",str[i]);    //����ֱ�����
        else if(str[i] =='+'||str[i] == '-'){   //�Ӽ������ջ���������,ֱ���ջ�'('
            while(top>0 && sym[top-1]!='(')
                printf("%c",sym[--top]);
            sym[top++] = str[i];    //��ǰ������ջ
        }else if(str[i] == '*' || str[i] == '/' || str[i] == '('){//�˳�����ֱ����ջ
            sym[top++] = str[i];
        }else if(str[i] == ')'){        //��ջֱ��������
            while(sym[top-1]!='(')
                printf("%c",sym[--top]);
            top--;  //�����ų�ջ
        }
    }
    while(top>0)    //ʣ��Ԫ�س�ջ
        printf("%c",sym[--top]);
}


//----------------------------------4.���С̡�----------------------------------------
/*��ͨ���С�˫�˶��С�ѭ�����еĲ���*/
//1.��ӳ���
//2.�п�����
//3.ȡ��ͷ��βԪ��

/*���е�Ӧ��*/
//�����϶����ڶ���������������㷨��Ӧ�á�


//---------------------------------5.������-----------------------------------------
typedef struct binarytreenode{  //�������ṹ��
    int data;           //������    
    struct binarytreenode* lchild,*rchild;    //����
    struct binarytreenode* left,*right;   //�Һ���
    //������һЩ��������õ��ϵĶ���,Ϊ�˷������,��һ���嵽�������
    struct binarytreenode* parent;   //�����
    int ltag;      //���־
    int rtag;      //�ұ�־
    int level;     //��
    int height;    //�߶�
    int count;     //�����
    bool balance;  //�Ƿ�ƽ��
}BTree,BTNode;
#define MaxSize 1000
/*�������Ĳ���*/
//1.�ݹ����:ǰ�����򡢺���
//2.�ǵݹ����:ǰ�����򡢺��򡢲���
//3.ʵ�ֶ���������
//4.ʵ��ƽ�������
//5.ʵ������������(�ǵݹ��Morris����)
//6.����B��
//7.����B+��
//8.�����������

/*��������Ӧ��*/
//1.����ֵΪval�Ľ�㣻
//2.�����������T����ȣ�
//3.�����������T�Ŀ��(���������һ��)��
//4.�Ҹ������Node��˫�׽�㣻
//5.��ת������(������������������)��
//6.�ж϶������Ƿ�Ϊ��ȫ��������
//7.�ж������Ķ�����T�Ƿ���ƽ���������
//8.�ж������Ķ�����T�Ƿ��Ƕ�����������
//9.�ж������Ķ�����T�Ƿ�������������
//10.��ֵΪval�ĵ�һ�����
//11.ͳ�ƶ�����������

//дһ������������Ĳ����㷨-���ڲ��Ժ�ߵ������㷨
BTree* CreateBTree(int*arr,int n){  //û�н���λ��ֵΪ-1
    if(!arr || !n)return NULL;    //�����鷵��NULL
    BTNode*root = (BTNode*)malloc(sizeof(BTNode));
    root->data = arr[0];
    root->lchild = root->rchild = root->lchild = root->rchild = NULL;
    //������в�����ӽ��
    BTNode**tmp = (BTNode**)malloc(sizeof(BTNode*)*MaxSize);
    int rear = 0,head = 0,top = 1;   //����ͷβ����
    tmp[rear++] = root;
    while(top < n){ //�������źú����
        BTNode*cur = tmp[head++];   //��ͷ������
        if(arr[top++] !=-1){//����
            cur->lchild = (BTNode*)malloc(sizeof(BTNode));
            cur->lchild->data = arr[top-1];
            cur->lchild->lchild = cur->lchild->rchild = NULL;
            tmp[rear++] = cur->lchild;  //�������
        }
        if(arr[top++] != -1){//�ҽڵ�
            cur->rchild = (BTNode*)malloc(sizeof(BTNode));
            cur->rchild->data = arr[top-1];
            cur->rchild->lchild = cur->rchild->rchild = NULL;
            tmp[rear++] = cur->rchild;  //�Һ������
        }
    }
    free(tmp);      //�ͷ��ڴ�
    return root;    //���ع���õ�ͷ���
}

//1.�ݹ����
void PreOrder_Iterator(BTree*root){  //����
    if(!root)return;
    printf("%d ",root->data);       //��ӡ���ڵ�
    PreOrder_Iterator(root->lchild);  //��ӡ������
    PreOrder_Iterator(root->rchild); //��ӡ������
}
void InOrder_Iterator(BTree*root){  //����
    if(!root)return;
    InOrder_Iterator(root->lchild);   //��ӡ������
    printf("%d ",root->data);       //��ӡ���ڵ�
    InOrder_Iterator(root->rchild);  //��ӡ������
}
void PostOrder_Iterator(BTree*root){//����
    if(!root)return;
    PostOrder_Iterator(root->lchild); //��ӡ������
    PostOrder_Iterator(root->rchild);//��ӡ������
    printf("%d ",root->data);       //��ӡ���ڵ�
}
//�������������ʵ��˼·:
//a.ʹ�õ�����ģ��������:
typedef struct LevelNode{   //�洢���������Ľṹ
    BTree*node;             //�洢�������ڵ�
    struct LevelNode*next;  //�洢��һ�����������
}LevelNodeList;
void LevelOrder_IteratorList(BTree*root){//����
    if(!root)return ;   //����
    LevelNodeList*head = (LevelNodeList*)malloc(sizeof(LevelNodeList));//ͷ���
    head->node = root;
    head->next = NULL;
    LevelNodeList*cur = head,*rear = head;  //ͷβ�ڵ�,ģ�¶���
    while(cur){ //���в���
        printf("%d\n",cur->node->data);     //������н��
        if(cur->node->lchild){//�����еĻ������
            LevelNode*n = (LevelNode*)malloc(sizeof(LevelNode));
            n->next = NULL;
            n->node = cur->node->lchild;
            rear->next = n;
            rear = rear->next;
        }
        if(cur->node->rchild){//�Һ����еĻ������
            LevelNode*n = (LevelNode*)malloc(sizeof(LevelNode));
            n->next = NULL;
            n->node = cur->node->rchild;
            rear->next = n;
            rear = rear->next;
        }
        cur = cur->next;    //��������һ�����ȥ
    }
    //�ǵ�Ҫ���ٶ�̬����Ķ����ڴ�
    cur = head;
    rear = cur->next;
    while(cur){ //����LevelNodeList�ͷ��ڴ�
        free(cur);
        cur = rear;
        if(rear)rear = rear->next;
    }
}
//b.ʹ��ָ������ʵ�ֶ���:
int countTree(BTree*root);  //����ԭ��,�����Ƕ������±�Ӧ�������,����Ҫʹ��,��Ҫ��ǰ����
//���Ե�ʱ��ǵ�Ҫ��ͳ�ƽ������Ĵ���д����
void LevelOrder_IteratorArray(BTree*root){//����
    if(!root)return ;   //����
    //1.��������Ľ�����
    int num = countTree(root);
    BTree**arr = (BTree**)malloc(sizeof(BTree*)*num);  //�����ά����
    int rear = 0,top = 0;
    arr[rear++] = root; //ͷ������
    while(top<rear){
        BTNode*cur = arr[top++];
        printf("%d ",cur->data);     //������н��
        if(cur->lchild) arr[rear++] = cur->lchild;  //�������
        if(cur->rchild)arr[rear++] = cur->rchild; //�Һ������
    }
    free(arr);  //�ǵ��ͷ��ڴ�
}

//2.�ǵݹ����
/*  Morris�㷨-��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)�������±���������
    Morris���и��з�->����������
    ����:cur��root��㿪ʼ,��cur�ǿ�ʱ��
    �����ֵ(���з���);
    (1)cur��������ʱ,cur = cur->rchild;
    (2)cur��������ʱ���������������ҽ��R:
        (a)R->rchild==NULL,��ʾ��һ�η���cur���,ִ�����²���:
            R->rchild = cur;
            cur = cur->lchild;
        (b)R->rchild==root,��ʾ�ڶ��η���cur���,ִ�����²���:
            cur = cur->rchild;
    (3)cur==NULLʱֹͣ

    ��ͨѭ������-ʹ��ջ�����еȷ�ʽ����������
*/
//2.1.Morris�㷨����
void Morris(BTree*root){
    if(!root)return;    //��������
    BTNode*cur = root;  //cur��root��ʼ
    while(cur){         //cur����ֹͣ
        printf("%d\n",cur->data);   //���cur��ֵ-����
        if(!cur->lchild)cur=cur->rchild;   //ֻ�ܵ�һ�εĽ��
        else{           //�ϱߵ����(2)
            BTNode*R = cur->lchild;   //�����������ҽ��
            while(R->rchild && R->rchild!=cur)R=R->rchild;
            if(!R->rchild){  //���(a)����һ�η���
                R->rchild = cur;
                cur = cur->lchild;
            }else{          //���(b)���ڶ��η���
                R->rchild = NULL;
                cur = cur -> rchild;
            }
        }
    }
}

//2.2.Morrisʵ���������:�����һ�ε����ֻ�ܵ���һ�εĽ��ֵ
//��2.1��ȣ���֮ͬ����*���
void Morris_PreOrder(BTree*root){
    if(!root)return;    //��������
    BTNode*cur = root;  //cur��root��ʼ
    while(cur){         //cur����ֹͣ
        if(!cur->lchild){ //ֻ�ܵ�һ�εĽ��
            printf("%d\n",cur->data);   //*���cur��ֵ-����
            cur = cur->rchild;
        }else{          //�ϱߵ����(2)
            BTNode*R = cur->lchild;   //�����������ҽ��
            while(R->rchild && R->rchild != cur)R = R->rchild;
            if(!R->rchild){  //���(a)����һ�η���   
                R->rchild = cur;
                printf("%d\n",cur->data);   //*���cur��ֵ-����
                cur = cur->lchild;
            }else{          //���(b)���ڶ��η���
                R->rchild = NULL;
                cur = cur->rchild;
            }
        }
    }
}

//2.3.Morrisʵ���������:����ڶ��ε����ֻ�ܵ���һ�εĽ��ֵ
//��2.1��ȣ���֮ͬ����*���
void Morris_MidOrder(BTree*root){
    if(!root)return;    //��������
    BTNode*cur = root;  //cur��root��ʼ
    while(cur){         //cur����ֹͣ
        if(!cur->lchild){ //ֻ�ܵ�һ�εĽ��
            printf("%d\n",cur->data);   //*���cur��ֵ-����
            cur = cur->rchild;
        }else{
            BTNode*R = cur->lchild;   //�����������ҽ��
            while(R->rchild && R->rchild != cur)R = R->rchild;
            if(!R->rchild){  //���(a)����һ�η���   
                R->rchild = cur;
                cur = cur->lchild;
            }else{          //���(b)���ڶ��η���
                R->rchild = NULL;
                printf("%d\n",cur->data);   //*���cur��ֵ-����
                cur = cur->rchild;
            }
        }
    }
}

//2.4.Morrisʵ�ֺ�������:ֻ�ڵڶ��ε���Ľ�㴦��������������������ҽ�㣬�����������������ҽڵ�
//Ϊ��֤�ռ临�Ӷ�ΪO(1)���������ʱ���÷�ת������ķ�ʽ����
//2.4.1.��ת���cur�������������ҽڵ�
void reverseRoot(BTNode*cur){
    if(!cur)return;
    BTNode*lchild = cur->lchild;//lchild��Ϊͷ���
    BTNode*R = lchild->rchild; //Rָ���ҽڵ㣬��ֹ����
    cur->lchild = NULL;       //cur->lchild���ÿ�
    while(lchild){            //lchild���վͼ���ִ��
        lchild->rchild = cur->lchild;
        cur->lchild = lchild;
        lchild = R;
        if(R && R->rchild && R->rchild !=cur) R = R->rchild;
        else R = NULL;      //��R->rchildָ��curʱ��֤R�ÿ�
    }
}
//2.4.2.Morris���������㷨
void Morris_PostOrder(BTree*root){
    if(!root)return;    //��������
    BTNode*cur = root;  //cur��root��ʼ
    while(cur){
        if(!cur->lchild)cur = cur->rchild; //ֻ����һ�εĽ��
        else{
            BTNode*R = cur->lchild;       //�����������ҽ��
            while(R->rchild && R->rchild!=cur) R=R->rchild;
            if(!R->rchild){  //��һ�η��ʵ�cur���
                R->rchild = cur;
                cur = cur->lchild;
            }else{          //�ڶ��η��ʵ�cur��㣬Ҫ�����������
                R->rchild = NULL;    //R->rchild���ÿգ����㷴ת
                reverseRoot(cur);   //��תcur��������
                R = cur->lchild;  //R��Ϊ��ʱָ�����ڷ��������ҽ��
                while(R){
                    printf("%d\n",R->data);
                    R = R->rchild;
                }
                reverseRoot(cur);   //�ٽ�cur����������ת����
                cur = cur->rchild;
            }
        }
    }
    //����������������ҽڵ�
    BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
    tmp->lchild = root;
    reverseRoot(tmp);   //�ȷ�ת
    cur = tmp->lchild;
    while (cur) {
        printf("%d\n", cur->data);
        cur = cur->rchild;
    }
    reverseRoot(tmp);
    free(tmp);
}

//2.5.1.����ǵݹ�������������� - �� �� ��
void PreOrderTree(BTree*root){
    if(!root)return ;
    BTNode**q = (BTNode**)malloc(sizeof(BTNode*)*MaxSize);    //���ջ
    int top = 0;    //ջ��
    q[top++] = root;
    while(top){     //ջ�������
        BTNode*cur = q[--top];  //ջ��Ԫ�س�ջ
        printf("%d\n",cur->data);   //���ջ��Ԫ��
        if(cur->rchild)q[top++] = cur->rchild;    //�ҽ����ջ
        if(cur->lchild)q[top++] = cur->lchild;      //������ջ
    }
    free(q);    //�ͷ��ڴ�
}

//2.5.2.����ǵݹ�������������� - �� �� ��
/*
    ˼·��
    1.cur��root��ʼ
    2.cur�ǿջ�ջ�ǿ�ʱ��ִ�����²���
        (1)cur�ǿ�ʱ��ջcur��cur=cur->left;
        (2)curΪ��ʱ��ջ�������ʽ�㣬����cur=cur->right
*/
void InOrderTree(BTree*root){
    if(!root)return ;
    BTNode**q = (BTNode**)malloc(sizeof(BTNode*)*MaxSize);    //���ջ
    int top = 0;    //ջ��
    BTNode*cur = root;  //1.cur��root��ʼ
    while(top || cur){  //cur�ǿջ�ջ�ǿ�
        while(cur){     //(1).cur�ǿ�ʱ��ջcur����������������
            q[top++] = cur;
            cur = cur->lchild;
        }
        cur = q[--top];  //(2).curΪ��ʱ��ջ�������ʽ��
        printf("%d\n",cur->data);
        cur = cur->rchild;        
    }
    free(q);    //�ͷ��ڴ�
}

//2.5.3.����ǵݹ������������� - �� �� ��
/*
    ˼·:
    1.cur��root��ʼ��
    2.cur�ǿջ�ջ�ǿ�ʱ��ִ�����²���
        (1)cur�ǿ�ʱ��ջcur��cur=cur->left;
        (2)curΪ��ʱ��ջ���������������ж�:
            a.�����ҽڵ���ҽڵ��ѷ��ʹ��������cur��㣬����cur = NULL;
            b.����cur����ѹջ����������������
*/
void PostOrderTree(BTree*root){
    if(!root)return ;
    BTNode**q = (BTNode**)malloc(sizeof(BTNode*)*MaxSize);  //���ջ
    int*arr = (int*)malloc(sizeof(int)*MaxSize);    //��¼���ֵ�Ƿ���ʹ���������ֵ<MaxSize
    memset(arr,0,MaxSize);  //��arr��ʼ��Ϊ0
    int top = 0;    //ջ��
    BTNode*cur = root;  //1.cur��root��ʼ
    while(top || cur){  //cur�ǿջ�ջ�ǿ�
        while(cur){     //(1).cur�ǿ�ʱ��ջcur����������������
            q[top++] = cur;
            cur = cur->lchild;
        }
        cur = q[--top];  //(2).curΪ��ʱ��ջ�������±ߵ��ж�
        if(!cur->rchild || arr[cur->rchild->data]){  //a.�����ҽڵ���ҽڵ��ѷ��ʹ��������cur��㣬����cur = NULL
            printf("%d\n",cur->data);
            arr[cur->data] = 1;
            cur = NULL;
        }else{
            q[top++] = cur;  //b.����cur����ѹջ��������������
            cur = cur->rchild;
        }
    }
}

//3.ʵ�ֶ���������
BTree* CreateBST(int*arr,int n){
    if(!arr || !n)return NULL;  //�����鷵��NULL
    int cur = 0;    //��ǰ���ڹ���Ľ��
    BTree*root = (BTNode*)malloc(sizeof(BTNode));   //���ڵ�
    root->data = arr[cur++];
    root->lchild = root->rchild = NULL;
    BTNode*p = root;  //p��root��ʼ�Һ��ʵ�λ�ò�����
    while(cur < n){
        p = root;   //ÿ��ѭ������root��ʼ��
        BTNode*tmp = (BTNode*)malloc(sizeof(BTNode));   //�����½��
        tmp->data = arr[cur++];
        tmp->lchild = tmp->rchild = NULL;
        while(p){
            if(tmp->data < p->data){    //�½��ֵ��С��������
                if(p->lchild)p = p->lchild;
                else{
                    p->lchild = tmp;
                    break;
                }
            }
            if(p->rchild)p = p->rchild; //�½��ֵ����������
            else{
                p->rchild = tmp;
                break;
            }
        }
    }
    return root;
}

//4.ʵ��ƽ�������








/*��������Ӧ��*/
//1.����ֵΪval�Ľ�㣻
//2.�����������T����ȣ�
//3.�����������T�Ŀ��(���������һ��)��
//4.�Ҹ������Node��˫�׽�㣻
//5.��ת������(������������������)��
//6.�ж϶������Ƿ�Ϊ��ȫ��������
//7.�ж������Ķ�����T�Ƿ���ƽ���������
//8.�ж������Ķ�����T�Ƿ��Ƕ�����������
//9.�ж������Ķ�����T�Ƿ�������������
//10.��ֵΪval�ĵ�һ�����
//11.ͳ�ƶ�����������

int countTree(BTree*root);  //����ԭ��(��Ϊ�����ں��,����Ҫ������һ��)
//1.����ֵΪval�Ľ��
BTNode* FindNode(BTree*root,int val){
    if(!root)return NULL;   //�ս�㷵��NULL
    if(root->data == val)return root;       //��ǰ���ֵ����val,����
    BTNode*lchild = FindNode(root->lchild,val); //�ݹ����������
    BTNode*rchild= FindNode(root->rchild,val);//�ݹ����������
    return lchild?lchild:rchild?rchild:NULL;      //������������������
}

//2.�����������T�����
int Depth(BTree*root){
    if(!root)return 0;   //�������Ϊ0
    int lchild = Depth(root->lchild);   //�ݹ������������
    int rchild = Depth(root->rchild); //�ݹ������������
    return lchild>rchild?lchild+1:rchild+1;
}

//3.�����������T�Ŀ��(���������һ��)
//˼·��������T�߶�,��ʹ��������ͳ��ÿһ��Ľ����,�����Ҫʹ�ø�������
void levelCount(BTree*root,int *depthArr,int level){
    //depthArr��ͳ�Ƶ�����,level�ǵ�ǰ���ڲ�
    if(!root)return;   //��������
    depthArr[level]++; //ͳ�Ƶ�ǰ��Ľ����
    levelCount(root->lchild,depthArr,level+1); //�ݹ�������
    levelCount(root->rchild,depthArr,level+1); //�ݹ�������    
}
int Width(BTree*root){
    //1.�����߶�(���)
    int depth = Depth(root);    //ֱ�����ϱ��ֳɴ�����,���ԾͰ��ϱ�Depth�Ĵ��볭�����
    //2.�������¼ÿһ��Ľ����
    int *arr = (int*)malloc(sizeof(int)*depth);
    memset(arr, 0, depth);      //��ʼ��Ϊ0
    //3.�ø�������ͳ��ÿһ��Ľ���� - root�������ڵ�0��
    levelCount(root,arr,0);
    //4.�������
    int max = arr[0];
    for(int i = 1;i < depth;i++)
        if(arr[i]>max) max = arr[i];
    return max; //���������
}

//4.�Ҹ������Node��˫�׽��
BTNode* FindParent(BTree*root,BTNode*node){
    if(!root)return NULL;   //��������NULL
    if(root == node)return node;    //��ǰ����Ǵ�����node,�򷵻ص�ǰ���
    BTNode*lchild = FindParent(root->lchild,node);  //�ݹ����������
    if(lchild)return lchild == node?root:lchild;      //��������node,��root���丸���,�����϶�����node
    BTNode*rchild = FindParent(root->rchild,node);//�ݹ����������
    if(rchild)return rchild == node?root:rchild;   //��������node,ͬ��,ֱ�ӷ���root
    return NULL;
}

//5.��ת������(������������������)
void ReverseTree(BTree*root){
    if(!root)return;            //��������
    BTNode*lchild = root->lchild;   //��ס������
    root->lchild = root->rchild;   //����������������ȥ
    root->rchild = lchild;         //����������������ȥ
    ReverseTree(root->lchild);    //�������ϼ���ת��
    ReverseTree(root->rchild);   //�������ϼ���ת��
}

//6.�ж϶������Ƿ�Ϊ��ȫ������
bool IsCompleteTree(BTree*root){
    int flag = 0;   //��ʾ������ȫ������
    //˼·:�½���������,�������������,����������һ��С��1�����ӵĽ��ʱ,�����㶼������Ҷ�ڵ�
    int num = countTree(root);  //���������
    BTree**arr = (BTree**)malloc(sizeof(BTree*)*num);
    for(int i = 0;i < num;i++)arr[i] = NULL;    //��ʼ������
    int top = 0,rear = 0;   //��ʾ���е�ͷβ
    arr[rear++] = root;     //��������
    while(top < rear){      //���зǿ�ʱ
        BTNode*cur = arr[top++];    //ȡ����ͷ���
        if(flag)            //�˽ڵ�ֻ����Ҷ�ڵ�
            if(cur->lchild||cur->rchild)return false;  //���к���������ȫ������
        else {              //��δ�ߵ����һ�����
            if(!cur->lchild || !cur->rchild)flag = 1;    //�˽���ǵ�һ��С��1�����ӵĽ��
        }
        if(cur->lchild)arr[rear++] = cur->lchild; //�������
        if(cur->rchild)arr[rear++] = cur->rchild; //�Һ������
    }
    return true;            //�Ƚ����,�ö���������ȫ������
}

//7.�ж������Ķ�����T�Ƿ���ƽ�������
bool IsBalanceTree(BTree*root){
    if(!root)return true;           //��������true
    int lchild = Depth(root->lchild);   //�����������
    int rchild = Depth(root->rchild); //�����������
    int delta = lchild>rchild?lchild-rchild:rchild-lchild;   //ƽ������
    return delta <= 1 && IsBalanceTree(root->lchild) && IsBalanceTree(root->rchild);
}

//8.�ж������Ķ�����T�Ƿ��Ƕ���������
bool IsSortTree(BTree*root){
    if(!root)return true;   //��������true
    if(root->lchild)if(root->lchild->data>root->data)return false;//���������ڸ���㷵��false
    if(root->rchild)if(root->rchild->data<root->data)return false;//������С�ڸ���㷵��false
    return IsSortTree(root->lchild)&&IsSortTree(root->rchild); //�����ݹ���������
}

//9.�ж������Ķ�����T�Ƿ�����������
//9.1ͨ���ݹ����ʵ��
bool IsFullTree(BTree*root){
    if(!root)return false;   //��������false
    int lchild = Depth(root->lchild);    //�����������
    int rchild = Depth(root->rchild); //�����������
    return lchild == rchild;
}
//9.2ͨ��ͳ�Ƹ߶�ʵ��
bool IsFullTree2(BTree*root){
    //1.�������
    int depth = Depth(root);
    //2.�����Ϊdepthʱ�Ľ�����
    int num = 1;
    for(int i = 0;i < depth;i++)num*=2;
    num-=1;
    //3.�ж��Ƿ���������
    return num == countTree(root);
}

//10.��ֵΪval�ĵ�һ�����
BTNode* FindFirstNode(BTree*root,int val){
    if(!root)return NULL;   //��������NULL
    if(root->data == val)return root;       //��ǰ���ֵ����val,����
    BTNode*lchild = FindFirstNode(root->lchild,val); //�ݹ����������
    BTNode*rchild= FindFirstNode(root->rchild,val);//�ݹ����������
    return lchild?lchild:rchild?rchild:NULL;      //������������������
}

//11.ͳ�ƶ�����������
int countTree(BTree*root){
    if(!root)return 0;  //��������0
    int lchild = countTree(root->lchild);   //�ݹ�������
    int rchild= countTree(root->rchild);  //�ݹ�������
    return lchild+rchild+1;//��������������+����������+��ǰ���
}


//---------------------------------6.ͼ-----------------------------------------
/*ͼ�Ļ�������*/
//1.����ͼ���ڽӾ���
//2.����ͼ���ڽ�����
//3.ʮ����������ͼ
//4.�ڽӶ��ر�Ĺ���
//5.ͼ��������ȱ���(DFS)�͹�����ȱ���(BFS)
//6.��ͼĳһ���������
//7.��ͼĳһ�����ĳ���

//1.1.����ͼ���ڽӾ���
#define MAX_VERTICES 100
typedef struct {    //�ڽӾ���Ľṹ
    int vertices;   //ͼ�ж��������
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];   //�ڽӾ���
}adJacencyGraph;
void initAdJacencyGraph(adJacencyGraph*graph,int vertices){
    graph->vertices = vertices; //��ʼ��ͼ�Ķ�������
    for(int i = 0;i < vertices;i++)
        for(int j = 0;j < vertices;j++)
            graph->adjacencyMatrix[i][j] = 0;
    //2.�û������ڽӾ����ֵ
    puts("ͼ����һ�ɴ�1��ʼ.");
    for(int i = 0;i < graph->vertices;i++){
        for(int j = 0;j < graph->vertices;j++){//i==jʱȨֵΪ0
            if(i == j) graph->adjacencyMatrix[i][j] = 0;
            else{
                printf("�����붥��%d������%d��Ȩֵ:(û��·����-1)",i+1,j+1);
                scanf("%d",&graph->adjacencyMatrix[i][j]);
            }
        }
    }
    puts("ͼ���ڽӾ��������.");
}
//1.2.����ڽӾ���
void displayAdJacencyMatrix(const adJacencyGraph*const graph){
    if(!graph->vertices)return ;
    //1.�����ͷ
    printf("  ");
    for(int i = 0;i < graph->vertices;i++)
        printf("%d ",i+1);
    printf("\n");
    //2.�������
    for(int i = 0;i < graph->vertices;i++){
        printf("%d ",i+1);
        for(int j = 0;j < graph->vertices;j++){
            if(graph->adjacencyMatrix[i][j] == -1)printf("�� ");
            else printf("%d ",graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

//2.1����ͼ���ڽ�����
typedef struct adjacencyNode{   //������
    int vertex;     //������
    struct adjacencyNode*next;  //ָ����һ�������ָ��
}AdjNode;           //ͼ����Ľṹ
typedef struct {    //�ڽ�����Ľṹ
    int vertices;   //ͼ�ж��������
    struct adjacencyNode*adjacencyList[MAX_VERTICES];   //�ڽ�����
    //��ͳ�ڽ�������������¼��Ȩͼ��,���ͨ�����߱���ѯȨֵ�Ĺ���,���������·�ʽ����:
    int EdgeArray[MAX_VERTICES][MAX_VERTICES];  //Ȩ�ر�-������¼ÿ��������֮���Ȩֵ
}AdjListGraph;      //�ڽ�����Ľṹ
void initAdjListGraph(AdjListGraph*graph,int vertices){ //��ʼ���ڽ�����
    graph->vertices = vertices; //��ʼ��ͼ�Ķ�������
    for(int i = 0;i < vertices;i++) //��ʼ��ͼ��ÿ������
        graph->adjacencyList[i] = NULL;
    //2.�û������ڽ������ֵ
    AdjNode*rear = NULL;        //�����ҵ�ǰ��������һ������
    puts("ͼ����һ�ɴ�1��ʼ.");
    for(int i = 0;i < graph->vertices;i++){
        rear = graph->adjacencyList[i];
        while(rear->next)rear = rear->next;
        for(int j = 0;j < graph->vertices;j++){//i==jʱȨֵΪ0
            if(i != j) {    //����㲻ͬʱ���ڵ�i����������������
                printf("�����붥��%d������%d��Ȩֵ:(û��·����-1)",i+1,j+1);
                int weight = -1;
                scanf("%d",&weight);
                if(weight != -1){   //Ȩֵ��Ϊ-1,����·������,���붥��
                    rear->next = (AdjNode*)malloc(sizeof(AdjNode));
                    rear->next->vertex = j; //����¶���ı��
                    rear->next->next = NULL;//�¶����ָ����Ϊ��
                    rear = rear->next;      //rear����ָ����һ������
                    graph->EdgeArray[i][j] = weight;//����Ȩ�ر�
                }else graph->EdgeArray[i][j] = -1;   //ȨֵΪ-1,ֻ����Ȩ�ر�
            }else graph->EdgeArray[i][j] = 0;   //i==jʱҲֻ����Ȩ�ر�
        }
    }
    puts("ͼ���ڽ����������.");
}
//2.2.����ڽ�����
void displayAdjListGraph(const AdjListGraph*const graph){
    if(!graph->vertices)return ;
    //1.����ڽ�����ṹ:
    for(int i = 0;i < graph->vertices;i++){     //һ���ж������
        printf("%d:",i+1);  //�����i+1���������
        AdjNode*rear = graph->adjacencyList[i]; //rear�����ӵ���i������ĵ�һ�����㿪ʼ
        while(rear){        //�����������ÿ������
            printf("%d->",rear->vertex);    //�������
            rear = rear->next;
        }
        printf("\n");
    }
    //2.�����ͷ
    printf("  ");
    for(int i = 0;i < graph->vertices;i++)
        printf("%d ",i+1);
    printf("\n");
    //3.���Ȩ�ر������-���ʾ��Ǳ���һ����ά����
    for(int i = 0;i < graph->vertices;i++){
        printf("%d ",i+1);
        for(int j = 0;j < graph->vertices;j++){
            if(graph->EdgeArray[i][j] == -1)printf("�� ");
            else printf("%d ",graph->EdgeArray[i][j]);
        }
        printf("\n");
    }
}

/*ͼ�Ļ���Ӧ��*/
//1.Prim�㷨����С������
//2.Kruskal�㷨����С������
//3.Floyd�㷨�����·��
//4.Dijkstra�㷨�����·��
//5.��ͼ����������
//6.��ͼ�Ĺؼ�·��


//---------------------------------7.���̡�-----------------------------------------
/*���Ĵ洢�ṹ*/
//1.���Ķ����洢
//2.���ĶѴ洢

/*���Ļ���Ӧ��*/
//1.�����Ӵ�s1,��s1�ĳ���
//2.�����Ӵ�s1��s2,��s1��s2�е�һ�γ��ֵ��±�
//3.�����Ӵ�s1��s2,��s1��s2�����һ�γ��ֵ��±�
//4.KMP�㷨��s1��s2�е�һ�γ��ֵ�λ��
//5.KMP�㷨��s1��s2�����һ�γ��ֵ�λ��

//1.�����Ӵ�s1,��s1�ĳ��� - �ñ����ƽⷨ
int getStrLength(char*str){ //�ַ�����'\0'��β
    int count = 0;
    while(str[count]!='\0')count++;
    return count;
}

//2.������s1��s2,��s2��s1�е�һ�γ��ֵ��±�
int locateStrFirst(char*s1,int n,char*s2,int m){ //��s2����s1
    if(!s1 ||!s2||n-m<0)return -1;  //����
    for(int i = 0;i < n-m+1;i++){   //i������s1�ĵ�ǰλ��
        int p = i,flag = 0; //flag��ʾ�Ƿ��ҵ��Ӵ�s2
        for(int j = 0;j < m;j++){   //��ʼƥ���������Ӵ�
            if(s1[p]!=s2[j]){       //��ƥ��
                flag = 1;
                break;
            }
            p++;            //ƥ����p++
        }
        if(!flag)return i;  //�ҵ��Ӵ�,��ʼλ��Ϊi
    }
    return -1;  //�����궼û�ҵ�,����-1
}

//3.�����Ӵ�s1��s2,��s1��s2�����һ�γ��ֵ��±�
int locateStrLast(char*s1,int n,char*s2,int m){
    if(!s1||!s2||n-m<0)return -1;   //����
    int last = -1;  //���ڼ�¼���һ��ƥ���λ��
    for(int i = 0;i < n-m+1;i++){   //i������s1�ĵ�ǰλ��
        int p = i,flag = 0; //flag��ʾ�Ƿ��ҵ��Ӵ�s2
        for(int j = 0;j < m;j++){   //��ʼƥ���������Ӵ�
            if(s1[p]!=s2[j]){       //��ƥ��
                flag = 1;
                break;
            }
            p++;            //ƥ����p++
        }
        if(!flag) last = i; //��¼��ǰiλ��
    }
    return last;    //��������¼��ƥ��λ�ü��ɣ�
}

//4.KMP�㷨��s1��s2�е�һ�γ��ֵ�λ��
//4.1��next����
int* getNext(char*str,int n){   //KMP�㷨��next����
    int *next = (int*)malloc(sizeof(int)*n);    //next����
    //for(int i = 0;i<n;i++)next[i] = -1;   //��ʼ��next����,���п���,�����±߻����
    next[0] = -1;           //0λ�õ������ǰ��׺������,��Ϊ�����-1
    next[1] = 0;            //1λ�õ������ǰ��׺ֻ��һ����ĸ,��Ϊ�����0
    int i = 2,cmp = 0;      //�ӵ�i��λ�ÿ�ʼ�������ǰ��׺,cmp����iλ�ý��бȽϵ�λ��
    while(i<n && cmp<n){    //��ʼ��next
        if(str[i-1] == str[cmp])//��str[i-1]��cmpλ���ַ���ͬʱ
            next[i++] = ++cmp;  //nextֵ��cmp+1,��Ϊcmp��ǰ׺�����һ��λ��,���+1��ʾǰ׺�ĳ���
        else if(cmp>0)cmp = next[cmp];  //�����ܻ���ʱ���л���
        else next[i++] = 0;     //�����ǰ��׺��0
    }
    return next;
}
//4.2KMP�㷨
int KMP(char*str,int n,char*sub_str,int m){
    if(!str || !sub_str)return -1;  //����
    //1.��next�������
    int *next = getNext(sub_str,m);
    //2.��ʼKMP��
    int i = 0,j = 0;    //�ֱ����������Ӵ���ָ��
    while(i<n && j<m){
        if(str[i] == sub_str[j]){   //��ͬ������
            i++;
            j++;
        }else if(j>=0) j = next[j]; //����
        else {          //�Ѿ����ܻ�����(j==-1),�����һ��λ�ÿ�ʼ�Ƚ�
            i++;
            j++;
        }
    }
    return j==m?i-j:-1;
}

//5.KMP�㷨�����һ�γ��ֵ��±�
int KMPLast(char*str,int n,char*sub_str,int m){
    if(!str || !sub_str)return -1;  //����
    //1.��next�������
    int *next = getNext(sub_str,m);
    //2.��ʼKMP��
    int i = 0,j = 0;    //�ֱ����������Ӵ���ָ��
    int index = -1;     //��¼�����
    while(i<n){
        if(str[i] == sub_str[j]){   //��ͬ������
            i++;
            j++;
        }else if(j>=0) j = next[j]; //����
        else {          //�Ѿ����ܻ�����(j==-1),�����һ��λ�ÿ�ʼ�Ƚ�
            i++;
            j++;
        }
        if(j>m)break;   //�Ӵ��Ѿ���������,����
        else if(j == m){
            index = i-j;//��¼��ǰƥ��Ĵ�����ʼ�±�
            i = i-j+1;  //��ֹ��ƥ�䴮���к���ƥ�䴮�е��ַ�
            j = 0;      //j�ص���ͷ
        }
    }
    return index;
}

//---------------------------------8.ɢ�б�(Hash)-----------------------------------------
/*��ϣ���Ӧ��*/
//1.ʵ��hash��-ʹ������̽�ⷨ(�����ڿ��Ŷ�ַ��)
//2.ʵ��hash��-ʹ��ƽ��̽�ⷨ(�����ڿ��Ŷ�ַ��)
//3.ʵ��hash��-ʹ����ɢ�з�(�����ڿ��Ŷ�ַ��)
//4.ʵ��hash��-����ַ��


//---------------------------------9.����̡�-----------------------------------------
/*�����㷨*/
//1.ð������
//2.��������
//3.ѡ������
//4.��������
//5.�۰��������
//6.ϣ������
//7.�鲢����
//8.������
//9.��������

//1.ð������
bool BubbleSort(DataType*arr,int n){    //Ĭ������
    if(!arr)return false;
    DataType temp;          //��ʱ����
    for(int i = n-1;i>0;i--){       //���ѭ��
        for(int j = 0;j < i;j++){   //�ڲ�ѭ��
            if(arr[j]>arr[j+1]){    //�Ƚϲ�����
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return true;
}

//2.��������
bool InsertSort(DataType*arr,int n){    //Ĭ������
    if(!arr)return false;
    DataType temp;          //��ʱ����
    for(int i = 1;i<n;i++){         //���ѭ��
        for(int j = i;j>0;j--){     //�ڲ�ѭ��
            if(arr[j]<arr[j-1]){    //�Ƚϲ�����
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }else break;            //���ź���,�˳�ѭ��
        }
    }
    return true;
}

//3.ѡ������
bool SelectSort(DataType*arr,int n){    //Ĭ������
    if(!arr)return false;
    for(int i = 0;i<n-1;i++){         //���ѭ��
        int min = i;                  //��¼��Сֵ���±�
        for(int j = i+1;j<n;j++){     //�ڲ�ѭ��
            if(arr[j]<arr[min]){      //�Ƚϲ�����
                min = j;
            }
        }
        if(min!=i){                   //����
            DataType temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return true;
}

//4.��������
void partition(DataType*arr,int L,int R){//����������
    if(L>=R)return;             //�Ѿ�����,ֱ�ӷ���-�ݹ��������
    int min = L-1,max = R+1;    //����С�ڲ��֡����ڲ���
    int cur = L;                //��ǰָ��
    int baseVal = arr[L+(R-L)/2];   //ȡ����Ļ�׼ֵ,����partition�Ὣ��׼ֵ�ŵ����ʵ�λ��
    while(cur<max){
        if(arr[cur]<baseVal){    //С�ڻ�׼ֵ,�ŵ�С�ڲ���
            DataType tmp = arr[++min];
            arr[min] = arr[cur];
            arr[cur++] = tmp;   //�����cur++����Ϊcurǰ�߻�������ֵ�Ѿ��ȽϹ���
        }else if(arr[cur]>baseVal){     //���ڻ�׼ֵ,�ŵ����ڲ���
            DataType tmp = arr[--max];
            arr[max] = arr[cur];
            arr[cur] = tmp;
            //���ﲻ��cur++,��Ϊ��cur��߻�������ֵ��δ���бȽ�
        }else cur++;            //���ڻ�׼ֵ,ֱ��cur++,��min��cur֮���ֵ������baseVal
    }
    //ͨ����������,����׼ֵ�ŵ����ʵ�λ��,���������ҿ���,�ݹ齫С�����ʹ��������ֱ����partition
    partition(arr,L,min);       //��С����Ҳ����
    partition(arr,max,R);       //�ô�����Ҳ����
}
void quickSort(DataType*arr,int n){ //����������
    partition(arr,0,n-1);   //���ÿ��������̽��п���
}

//5.�۰��������
int BinarySort(DataType*arr,int n,int val){    //Ĭ������-�۰����������۰����,���ز���λ�õ��±�
    if(n == 1) return arr[0]<val?1:0;  //ֻ��һ��Ԫ��ʱ
    int L = 0,R = n-1;
    while(L<=R){    //���ֲ���
        int mid = (L+R)/2;
        if(arr[mid]<val) L = mid+1;     //С�ھ����Ҹ���ĵط���
        else if(arr[mid]>val) R = mid-1;//���ھ������С�ĵط���
        else{       //��Ⱦ��ҵ�һ���ʺϲ����λ��-���ƻ��ȶ���
            while(arr[mid--]==val);
            return ++mid;
        }
    }
    return L;   //����L,L��ʼ��ָ����ȷ�Ĳ���λ��,�����ֶ�ģ��һ�¸������
}
void BinaryInsertSort(DataType*arr,int n){    //Ĭ������-�۰��������
    for(int i = 1;i<n;i++){
        DataType val = arr[i];  //������ֵ
        int index = BinarySort(arr,i,val); //�۰����ǰi��Ԫ��,�ҵ�����λ�õ��±�
        for(int j = i;j>index;j--) //�ƶ�Ԫ��
            arr[j] = arr[j-1];
        arr[index] = val;       //����val
    }
}

//6.ϣ������
void ShellSort(DataType*arr,int n){
    int gap = n/2;  //����ļ��
    while(gap>0){
        for(int i=0;i<gap;i++){ //��gap����в�������
            for(int j = i+gap;j<n;j+=gap){  //��ʼֱ�Ӳ�������
                for(int k = j;k>0;k-=gap){
                    if(arr[k]<arr[k-gap]){  //�Ƚϲ�����,Ĭ������
                        DataType temp = arr[k];
                        arr[k] = arr[k-gap];
                        arr[k-gap] = temp;
                    }else break;
                }
            }
        }
        gap/=2; //ÿ�μ��ټ��
    }
}

//7.�鲢����
void merge(DataType*arr,int lchild,int rchild){
    if(lchild>=rchild)return;      //�ݹ��������
    int mid = (lchild+rchild)/2;   //�е�
    merge(arr,lchild,mid);        //��߹鲢����
    merge(arr,mid+1,rchild);     //�ұ߹鲢����
    int i = lchild,j = mid+1,k = 0;    //���Ҳ��ֿ�ʼ���Ĺ���
    DataType *temp_arr = (DataType*)malloc(sizeof(DataType)*(rchild-lchild+1));//��ʱ����
    while(i<=mid&&j<=rchild){    //˭С˭��д
        if(arr[i]<arr[j]) temp_arr[k++] = arr[i++];
        else temp_arr[k++] = arr[j++];
    }
    while(i<=mid) temp_arr[k++] = arr[i++]; //��ʣ��Ԫ�ز���
    while(j<=rchild) temp_arr[k++] = arr[j++];//��ʣ��Ԫ�ز���
    for(int i = lchild;i<=rchild;i++) arr[i] = temp_arr[i-lchild];   //Ԫ�ؿ�����arr��
}
void MergeSort(DataType*arr,int n){ //�鲢����������
    merge(arr,0,n-1);   //����merge�������й鲢
}

//8.������
void HeapSort(DataType*arr,int n){//Ĭ������
    DataType*heap = (DataType*)malloc(sizeof(DataType)*n); //������
    //1.�Ƚ��û�����ת����С����
    heap[0] = arr[0];
    for(int i=1;i<n;i++){   //�ӵڶ���Ԫ�ؿ�ʼ��������
        heap[i] = arr[i];   
        int fa = (i-1)/2;   //��ʼ�͸��ڵ����Ƚ�
        for(int j = i;j>0;){
            if(heap[fa]>heap[j]){  //��������ͻ�����
                DataType temp = heap[fa];
                heap[fa] = heap[j];
                heap[j] = temp;
                j = fa;
                fa = (fa-1)/2;
            }else break;           //����ȽϽ���
        }
    }
    //2.��ʼ������
    int count = n;  //���ڼ�¼��ǰ�Ѹ���
    int cur = 0;    //���ڼ�¼��ǰarr��Ԫ�ص�λ��
    while(count>0){   //�Ѹ�������1ʱ
        arr[cur++]=heap[0]; //�Ѷ���СԪ�ط���arr��
        heap[0] = heap[--count];  //���һ��Ԫ�ط���Ѷ�
        if(count == 0)break;
        //��ʼ���½��ѵ���ΪС����,���±Ƚ�
        int h_i = 0;  //h_iΪ�Ѷ�,��ʱ�Ǵ��������
        int L_child = 2*h_i+1,R_child=2*h_i+2;  //���Һ���
        while(h_i<count){       //��ǰ������ڶ���
            if(L_child<count){  //��������ʱ
                if(R_child>=count){  //���Һ��Ӳ�����ʱ
                    if(heap[h_i]>heap[L_child]){  //���Ӹ�Сʱ����
                        DataType tmp = heap[h_i];
                        heap[h_i] = heap[L_child];
                        heap[L_child] = tmp;
                        h_i = L_child;
                    }
                }else{  //��heap[h_i]�����ӻ��Һ���Сʱ,��С�ĺ�������
                    if(heap[L_child]<heap[R_child]){    //���Ӹ�Сʱ
                        if(heap[h_i]>heap[L_child]){    //��heap[h_i]�����򽻻�
                            DataType tmp = heap[h_i];
                            heap[h_i] = heap[L_child];
                            heap[L_child] = tmp;
                            h_i = L_child;
                        }//����Ͳ���
                    }else{  //�Һ��Ӹ�С�����ʱ,ͳһ���Һ���
                        if(heap[h_i]>heap[R_child]){    //��heap[h_i]�����򽻻�
                            DataType tmp = heap[h_i];
                            heap[h_i] = heap[R_child];
                            heap[R_child] = tmp;
                            h_i = R_child;
                        }
                    }
                }
            }
            break;//û������ʱֱ�ӽ�����һ��ѭ��
        }
    }
}

//9.��������
void CountSort(DataType*arr,int n){
    DataType max = arr[0];
    //1.�����ֵ
    for(int i=1;i<n;i++) if(arr[i]>max) max = arr[i];
    //2.���븨������ռ�
    DataType *temp = (DataType*)malloc(sizeof(DataType)*(max+1));
    for(int i=0;i<max+1;i++) temp[i] = 0;   //��ʼ��Ϊ0
    //3.ͳ������
    for(int i=0;i<n;i++) temp[arr[i]]++;
    //4.������ԭ����
    int i = 0,j = 0;    //i���arr��ǰ����,j��ǵ�ǰtemp���±�
    while(j<max+1){     //j��0��max+1���β鿴temp����
        while(temp[j]-->0)   //temp����ֵ�ǿ�ʱ�����±굽arr��
            arr[i++] = j;
        j++;
    }
}


//---------------------------------10.�����-----------------------------------------
/*�����Ļ�������*/
//1.������˳��洢
//2.��������ʽ�洢
//3.���ͷ
//4.���β

//---------------------------------11.����-----------------------------------------
/*�����㷨*/
//1.�۰����
//2.����Ӧ�����ϣ���ҵ�,���ڴ˴��漰

//�۰���� - ֻ���������
int BinarySearch(DataType*arr,int n,DataType val){
    DataType lchild=0,rchild=n-1;      //�����ұ߽�
    while(lchild<=rchild){             //�ж����ұ߽��Ƿ����
        DataType mid=(lchild+rchild)/2;     //�����м�ֵ
        if(arr[mid]==val){          //�ҵ�val
            return mid;
        }else if(arr[mid]>val){     //�м�ֵ����val,����߲���
            rchild=mid-1;
        }else{                      //�м�ֵС��val,���ұ߲���
            lchild=mid+1;
        }
    }
    return arr[lchild]==val?lchild:-1;                      //û�ҵ�,����-1
}


//---------------------------------12.��չ-----------------------------------------
//1.���鼯-UnionFindSet
/*���鼯����*/
//1.Union���� - ������Ԫ�غϲ���ͬһ������
//2.isSame��ѯ���� - ��ѯ����Ԫ���Ƿ���ͬһ��������
typedef struct UFSNode{ //���鼯�Ľṹ
    DataType data;
    struct UFSNode *parent; //�����
}UFS;
//�Ⱦ�����,�ҽ��node����ϵĸ����
UFSNode*find(UFSNode*node){ //���ҵĹ����м����Ż�(·��ѹ��)����
    //1.������ϵĸ����
    if(!node)return NULL;   //�ս�㷵��NULL
    UFSNode*f = node;       //f��node��ʼ
    while(f->parent!=f) f=f->parent;    //f���ϼ�����
    //2.�Ż�guoc
    UFSNode*cur = node,*p = node->parent;
    while(cur!=f){          //��ƽ��,·��������node��parent��ָ��f      
        cur->parent = f;
        cur = p;
        p = p->parent;
    }
    return f;
}
//1.Union����
bool isSame(UFSNode*node1,UFSNode*node2);
bool Union(UFSNode*node1,UFSNode*node2){    //���������node1��node2�ϲ���ͬһ������
    //1.��node1��node2�Ƿ�ͬһ������:
    if(isSame(node1,node2))return true;
    //2.�ϲ� - �����ڲ��ҹ����л�����Ż�(·��ѹ��)����,��˽�һ������㲢����һ��������ϼ���
    node2->parent = node1;
    //3.����Ƿ�ϲ��ɹ�
    return isSame(node1,node2);
}
//2.isSame��ѯ����
bool isSame(UFSNode*node1,UFSNode*node2){
    //1.���������ĸ���� - �������Ż�����
    UFSNode*f1 = find(node1),*f2 = find(node2); 
    //2.�Ƚ���������parent�Ƿ���ͬ
    return f1 == f2?true:false;
}

/*Manacher-�����Ӵ��㷨*/
/*
    ˵����Manacher(������)�㷨�������ַ���str���ҳ���Ļ����Ӵ�
    1.i>R:������,narr[i] = 2j-1,c=i,R=i+(j-1)//j��1��ʼ
    2.i��R:��i����c�ĶԳƵ�i1,L=2c-R,L1=i1-narr[i1]/2;
        2.1.i1�ķ�Χ��L-R��:narr[i]=narr[i1];
        2.2.i1����߽����L:��R����i�ĶԳƵ�R1,R1=2i-R;
          a.R+j��R1-j���,������(j��1��ʼ)
          b.����Ȼ����ʱ:narr[i]=narr[i1]+(j-1)*2
          R=R+j-1,c=i
        2.3.i1��߽�<L: 
        j=R-i+1,��i+j<nʱ����j��ʼ�Ƚ�str[i-j]��str[i+j]
        ��Ⱦ�j++,����narr[i] = 1+(j-1)*2;
*/
bool Manacher(char*str,int n,int*index,int*len){
    //index��ʾÿ�����Ĵ����е��±�,len��ʾ���Ĵ�����
    if(!str || n<=0)return false;
    //�����ַ���,�罫1221���#1#2#2#1#,���ڿ�ʼ��������ÿ���ַ�֮�����ָ���#
    char *s = (char*)malloc(sizeof(char)*(n*2+1));
    for(int i = 0;i < 2*n+1;i++){
        if(i%2==0)s[i] = '#';   //ż��λ��'#'
        else s[i] = str[i/2];   //����λ��str�е�ֵ
    }
    // //����
    // for(int i = 0;i < 2*n+1;i++)cout<<s[i]<<" ";
    // cout<<endl;
    // //����
    int *narr = (int*)malloc(sizeof(int)*n);   //�洢ÿ���ַ��Ļ��İ뾶
    int i = 0,j = 0,c = -1,R = -1;  //������Ϸ�ע��
    while(i<2*n+1){ //��ʼ��narr����
        // //����
        // cout<<"��ǰ�ߵ�"<<s[i]<<":"<<endl;
        // cout<<"i = "<<i<<",j = "<<j<<",c = "<<c<<",R = "<<R<<"narr[i] = "<<narr[i]<<endl;
        // //����
        if(i>R){//1.��i�Ƿ����R,����R������չ
            j = 1;
            while(i-j>=0 && i+j<2*n+1 && s[i-j]==s[i+j])
                j++;
            narr[i] = 2*j-1;
            if(R<i+j-1){
                R = i+j-1;
                c = i;
            }
        }else{  //2.i��R��,��ʼ�ҶԳƵ㲢���жϣ�
            int i1 = 2*c-i; //i����c�ĶԳƵ�
            int L = 2*c-R;  //��ǰ��Ӵ�����߽�
            int L1 = i1-narr[i1]/2;  //i1����߽�
            int R1 = 2*i-R;  //��R����i�ĶԳƵ�
            if(L1>L)    //2.1.i1�ķ�Χ��L-R��
                narr[i] = narr[i1];
            else if(L1==L){ //2.2.i1����߽����L
                j = 1;
                while(R1-j>=0 && (R+j<i+j)&&(i+j<2*n+1) && s[R1-j]==s[R+j])  //��ȼ�����
                    j++;
                narr[i] = 2*(j-1)+narr[i1];   //���������չ
                if(R<R+j-1){//���ұ߽�仯,����������������
                    R = R+j-1;
                    c = i;
                }
            }else{      //2.3.i1����߽����L
                j = 1;
                while(R1-j>=0 && (R+j<i+j)&&(i+j<2*n+1) && s[R1-j]==s[R+j])  //��ȼ�����
                    j++;
                narr[i] = 2*(j-1)+narr[i1];   //���������չ
                if(R<R+j-1){//���ұ߽�仯,����������������
                    R = R+j-1;
                    c = i;
                }
            }
        }
        // //����
        // cout<<"��ǰ��β"<<s[i]<<":"<<endl;
        // cout<<"i = "<<i<<",j = "<<j<<",c = "<<c<<",R = "<<R<<"narr[i] = "<<narr[i]<<endl;
        // //����
        i++;    //��������Ƚ�
    }
    //�ҳ�����Ĵ�
    *index = -1;
    *len = -1;
    //����
    // cout<<"***************"<<endl;
    // for(int i = 0;i < 2*n+1;i++)cout<<narr[i]<<" ";
    // cout<<"***************"<<endl;
    //����
    for(int i = 1;i < 2*n+1;i+=2){
        if(narr[i]>*len){
            *index = i/2;
            *len = narr[i]/2;
        }
    }
    return true;
}



