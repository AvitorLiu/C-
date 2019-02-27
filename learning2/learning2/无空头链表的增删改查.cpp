#include<iostream>
#include<stdlib.h>
using namespace std;

// �ڵ�ṹ��
struct SinglyListNode
{
	int a;
	SinglyListNode *pNext;
};

//����ȫ��ͷ��βָ��
SinglyListNode* g_pHead = NULL;
SinglyListNode* g_pEnd = NULL;

//******��������******

//�����ڵ㣬β�����ͷ���
void AddNodeTotail(int a);//β���
void AddNodeTohead(int a);//ͷ���

//��������  �� ��ѯָ���Ľڵ� �޸��ƶ��ڵ�
void scanList();//��������
struct SinglyListNode* selectNode(int a);//��ѯָ���Ľڵ�

//�������
void Freelist();

//ָ��λ�ò���ڵ�
void AddListRand(int index, int a);

//�ڵ��ɾ��
void DeleteListHead();//ͷɾ��
void DeleteListTail();//βɾ��

//ɾ��ָ���ڵ�
void DeleteListNode(int a);

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int a[2] = { 1,2 };
	for (int i = 0; i < 10; i++)
	{
		AddNodeTohead(a[i]);
	}	
	scanList();
	//SinglyListNode *pFind = selectNode(15);
	//if (pFind != NULL)
	//{
	//	cout << "we found it"<<pFind->a << endl;
	//}
	//else
	//{
	//	cout << "did not find!!!" << endl;
	//}
	//AddListRand(4,14);
	//scanList();
	//AddListRand(1, 14);
	//scanList();
	DeleteListHead();
	scanList();
	DeleteListTail();
	scanList();
	DeleteListNode(10);
	scanList();
	Freelist();
	system("pause");
	return 0;
}
//*******�����ڵ㣬β�����ͷ���*******

//��������������������һ������ **β���**
void AddNodeTotail(int a)
{
	//����һ���ڵ�
	SinglyListNode* pTemp = new  SinglyListNode;

	//�ڵ����ݽ��и�ֵ
	pTemp->a = a;
	pTemp->pNext = NULL;

	//���ڵ����ӵ�������
	if (NULL == g_pHead || NULL == g_pEnd)//���ԭ�ڵ�Ϊ��,�������Ľڵ����ͷҲ��β
	{
		g_pHead = pTemp;//��ͷָ���¼ӽ����Ľڵ�
	}
	else//���������(����Ϊ��)�����Ľڵ�ֱ�ӽ���β��
	{
		g_pEnd->pNext = pTemp;//��βָ���¼ӽ����Ľڵ�
	}
	g_pEnd = pTemp;//�¼���Ľڵ�����β��β��һֱָ�����һ���ڵ�
}

//��������������������һ������ **ͷ���**
void AddNodeTohead(int a)
{
	//����һ���ڵ�
	SinglyListNode* pTemp = new  SinglyListNode;

	//�ڵ����ݸ�ֵ
	pTemp->a = a;
	pTemp->pNext = NULL;

	//����������
	if (NULL == g_pHead)//���������ͷҲ��β
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else
	{
		pTemp->pNext = g_pHead;
		g_pHead = pTemp;//��ͷ��ǰ�ƶ�
	}
}

//*******��������  �� ��ѯָ���Ľڵ�*******

//��������
void scanList()
{
	SinglyListNode *pTemp = g_pHead;//��������ʱ��Ҫ�ı�ͷָ�룬�����������֮�ı䣬��Ҫ�����м�ָ����в���
	while (pTemp != NULL)
	{
		cout << pTemp->a << " ";
		pTemp = pTemp->pNext;
	}
	cout << "" << endl;
}

//��ѯָ���Ľڵ�
struct SinglyListNode* selectNode(int a)
{
	SinglyListNode* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		if (a == pTemp->a)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	//û�ҵ��򷵻ؿ�ָ��
	return NULL;

}

//*******�������*******
void Freelist()
{
	SinglyListNode* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		SinglyListNode* pt = pTemp;
		pTemp = pTemp->pNext;
		delete pt;
	}
	//�ÿ�ͷβָ�룬������һ�δ�������
	g_pHead = NULL;
	g_pEnd = NULL;
}

//*******ָ��λ�ò���ڵ�*******
void AddListRand(int index, int a)
{
	//����Ϊ��
	if (NULL == g_pHead)
	{
		cout << "this list is empty " << endl;
		return;
	}
	//��λ��,��ѯָ���Ľڵ�
	SinglyListNode* pt = selectNode(index);
	if (NULL == pt)
	{
		cout << "we did not find the node!!!" << endl;
		return;
	}
	//�д˽ڵ㣬��a�����ڵ�
	SinglyListNode* pTemp = new  SinglyListNode;
	//�ڵ��Ա���и�ֵ
	pTemp->a = a;
	pTemp->pNext = NULL;
	//���ӵ�������
	if (pt == g_pEnd)//��ǰ�ڵ���β��㣨������ϣ�
	{
		g_pEnd->pNext = pTemp;//β�͵���һ��ָ���µĽڵ�
		g_pEnd = pTemp;//�½ڵ������һ�������β
	}
	else//��ǰ�ڵ㲻��β���
	{
		pTemp->pNext = pt->pNext;//�Ƚ�������
		pt->pNext = pTemp;//���,�ٽ�������
	}
}

//******ͷɾ��******
void DeleteListHead()
{
	//������
	if (NULL == g_pHead)
	{
		cout << "this list is empty,does not need this operation!!!" << endl;
	}
	//��ס�ɵ�ͷ
	SinglyListNode* pTemp = g_pHead;
	//ͷ����һ���ڵ����µ�ͷ
	g_pHead = g_pHead->pNext;
	//�ͷžɵ�ͷ
	delete pTemp;
}
//******βɾ��******
void DeleteListTail()
{
	//������
	if (NULL == g_pHead)
	{
		cout << "this list is empty,does not need this operation!!!" << endl;
	}
	//����Ϊ��
	//����ֻ��һ���ڵ�
	if (g_pHead == g_pEnd)
	{
		delete g_pHead;
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	//�����ж���ڵ�
	else
	{
     //�ҵ�β�͵�ǰһ���ڵ�
	SinglyListNode* pTemp = g_pHead;
	while (pTemp->pNext != g_pEnd)//ͨ��������¼��β�͵�ǰһ���ڵ�
	{
		pTemp = pTemp->pNext;
	}
	//�ҵ��ˣ�����ɾβ
	delete g_pEnd;//�ͷ�β��
	g_pEnd = pTemp;//β��ǰ��
	g_pEnd->pNext = NULL;//β�͵���һ��ָ�븳ֵΪ��
	}
}
//******ɾ��ָ���ڵ�******
void DeleteListNode(int a)
{
	//������
	if (NULL == g_pHead)
	{
		cout << "this list is empty,does not need this operation!!!" << endl;
	}
	//����Ϊ��
	SinglyListNode* pTemp = selectNode(a);
	//�Ҳ����ýڵ�
	if (NULL == pTemp)
	{
		cout << "we did not find the node!!!"<<endl;
		return;
	}
	//�ܹ��ҵ��ýڵ�
	//ֻ��һ���ڵ�
	if(g_pHead == g_pEnd)
	{
		delete g_pHead;
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	//ֻ�������ڵ�
	else if (g_pHead->pNext == g_pEnd)
	{
		if (g_pHead == pTemp)
		{
			DeleteListHead();
		}
		else
		{
			DeleteListTail();
		}
	}
	//�ж���ڵ�
	else
	{
		if (g_pHead == pTemp)
		{
			DeleteListHead();
		}
		else if (g_pEnd == pTemp)
		{
			DeleteListTail();
		}
		else
		{
			//�ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�
			SinglyListNode* pt = g_pHead;
			while (pt->pNext != pTemp)//ͨ��������¼��β�͵�ǰһ���ڵ�
			{
				pt = pt->pNext;
			}
			pt->pNext = pTemp->pNext;//����
			delete pTemp;//�ͷ�
		}
	}
}