//#include<iostream>
//using namespace std;
//// �ڵ�ṹ��
//struct SinglyListNode
//{
//	int a;
//	SinglyListNode *pNext;
//};
////����ȫ��ͷ��βָ��
//SinglyListNode* g_pHead = NULL;
//SinglyListNode* g_pEnd = NULL;
//
////******��������******
////��ͷ�����ʼ��
//void InitListHead();
////�����ڵ�
//struct SinglyListNode* CreatNode(int a);
////β���
//void AddListTail(int a);
////ͷ���
//void AddListHead(int a);
////��������
//void ScanList();
////����λ����ӽڵ�
//void AddListRand(int index, int a);
////����ָ���ڵ㲢���ؽڵ��ַ
//struct SinglyListNode* selectNode(int a);
////ɾͷ
//void deletehead();
////ɾ��β��
//void deleteTail();
////ɾ������ڵ�
//void deleteNodeRand(int a);
////�ͷ�����
//void FreeList();
//
//int main()
//{
//	//��ʼ����ͷ����
//	InitListHead();
//	//��������
//	for (int i = 0; i < 10; i++)
//	{
//		AddListTail(i);
//	}
//	ScanList();
//	AddListRand(4, 14);
//	AddListRand(9, 10);
//	AddListRand(11, 15);
//	ScanList();
//	deletehead();
//	ScanList();
//	deleteNodeRand(5);
//	ScanList();
//	FreeList();
//	system("pause");
//	return 0;
//}
//
////��ͷ�����ʼ��
//void InitListHead()
//{
//	//�����ͷ
//	g_pHead = new SinglyListNode;
//	g_pHead->pNext = NULL;
//	g_pEnd = g_pHead;
//}
//
////�����ڵ�
//struct SinglyListNode* CreatNode(int a)
//{
//	//����һ���ڵ�
//	SinglyListNode* pTemp = new SinglyListNode;
//	if (NULL == pTemp)
//	{
//		cout << "Not enough memory,we fail to creat a node!!!  " << endl;
//		return NULL;
//	}
//	//�ڵ��Ա��ֵ
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//	return pTemp;
//}
//
////β���
//void AddListTail(int a)
//{
//	//����һ���ڵ�
//	SinglyListNode* pTemp= CreatNode(a);
//	if (NULL == pTemp)
//	{
//		cout << "Not enough memory,we fail to creat a node!!!" << endl;
//		return;
//	}
//	//���� 
//	g_pEnd->pNext = pTemp;
//	g_pEnd = pTemp;
//}
//
////ͷ���
//void AddListHead(int a)
//{
//    //����һ���ڵ�
//	SinglyListNode* pTemp = CreatNode(a);
//	if (NULL == pTemp)
//	{
//		cout << "Not enough memory,we fail to creat a node!!!" << endl;
//		return;
//	}
//	//����
//	pTemp->pNext = g_pHead->pNext;
//	g_pHead->pNext = pTemp;
//}
////��������
//void ScanList()
//{
//	SinglyListNode* pTemp = g_pHead->pNext;
//	while (pTemp != NULL)
//	{
//		cout << pTemp->a << " ";
//		pTemp = pTemp->pNext;
//	}
//	cout << "" << endl;
//}
//
////����ָ���ڵ㲢���ص�ַ
//struct SinglyListNode* selectNode(int a)
//{
//	SinglyListNode* pTemp = g_pHead->pNext;
//	while (pTemp != NULL)
//	{
//		if (a == pTemp->a)
//		{
//			return pTemp;
//		}
//		pTemp = pTemp->pNext;
//	}
//	return NULL;
//}
//
////����λ����ӽڵ�
//void AddListRand(int index,int a)
//{
////�ж������Ƿ�Ϊ��
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//���ҽڵ�
//	SinglyListNode* pTemp= selectNode(index);
//	if (NULL == pTemp)
//	{
//		cout << "we did not find the node!!!" << endl;
//		return;
//	}
//	//���ҵ������ӵ�ָ��λ��
//	//�����ڵ�
//	SinglyListNode* pNode = CreatNode(a);
//	if (g_pEnd == pTemp)//��ǰ�ڵ���β
//	{
//		AddListTail(a);
//	}
//	else 
//	{
//		pNode->pNext = pTemp->pNext;
//		pTemp->pNext= pNode;
//	}
//}
//
////ɾ��ͷ���
//void deletehead()
//{
//	//�ж������Ƿ�Ϊ��
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//ɾ���ڵ�
//	SinglyListNode* pTemp = g_pHead->pNext;//���м������סg_pHead->pNext
//	g_pHead->pNext = pTemp->pNext;//�任ͷ���
//	delete pTemp;//�ͷ�
//}
//
//void deleteTail()
//{
//	//�ж������Ƿ�Ϊ��
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//ɾ���ڵ�
//	if (g_pHead->pNext == g_pEnd)//ֻ��һ���ڵ�
//	{
//		delete g_pEnd;
//		g_pHead->pNext = NULL;
//		g_pEnd = g_pHead;
//	}
//	else//��β������һ��
//	{
//		SinglyListNode* pTemp = g_pHead->pNext;
//		while (pTemp != NULL)//�ҽ�β��ǰһ���ڵ�
//		{
//			if (g_pEnd == pTemp->pNext)
//			{
//				break;
//			}
//			pTemp = pTemp->pNext;
//		}
//		delete g_pEnd;//�ͷ�
//		g_pEnd = pTemp;//�任β���
//		g_pEnd->pNext = NULL;//β�͵���һ���ÿ�
//	}	
//}
////ɾ������ڵ�
//void deleteNodeRand(int a)
//{
//	//�ж������Ƿ�Ϊ��
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//���ҽڵ�
//	SinglyListNode* pTemp = selectNode(a);
//	if (NULL == pTemp)
//	{
//		cout << "we did not find the node!!!" << endl;
//		return;
//	}
//	//���ҵ���ɾ��
//	if (pTemp==g_pEnd)//��ǰ�ڵ���β���
//	{
//		deleteTail();
//	}
//	else//�ýڵ㲻��β�ڵ㣬�Ҹýڵ��ǰһ���ڵ�
//	{
//		SinglyListNode* pt = g_pHead;
//		while (pt !=pTemp)
//		{
//			if (pTemp == pt->pNext)
//			{
//				break;
//			}
//			pt = pt ->pNext;
//		}
//		pt->pNext = pTemp->pNext;
//		delete pTemp;
//	}
//}
////�ͷ�����
//void FreeList()
//{
//	SinglyListNode* pTemp = g_pHead;
//	while (pTemp != NULL)
//	{
//		SinglyListNode* pt = pTemp;
//		pTemp = pTemp->pNext;
//		delete pt;
//	}
//	g_pEnd = NULL;
//	g_pHead = NULL;
//}
