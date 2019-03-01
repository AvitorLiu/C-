//#include<iostream>
//using namespace std;
//// 节点结构体
//struct SinglyListNode
//{
//	int a;
//	SinglyListNode *pNext;
//};
////定义全局头、尾指针
//SinglyListNode* g_pHead = NULL;
//SinglyListNode* g_pEnd = NULL;
//
////******函数声明******
////空头链表初始化
//void InitListHead();
////创建节点
//struct SinglyListNode* CreatNode(int a);
////尾添加
//void AddListTail(int a);
////头添加
//void AddListHead(int a);
////遍历链表
//void ScanList();
////任意位置添加节点
//void AddListRand(int index, int a);
////查找指定节点并返回节点地址
//struct SinglyListNode* selectNode(int a);
////删头
//void deletehead();
////删除尾巴
//void deleteTail();
////删除任意节点
//void deleteNodeRand(int a);
////释放链表
//void FreeList();
//
//int main()
//{
//	//初始化空头链表
//	InitListHead();
//	//操作链表
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
////空头链表初始化
//void InitListHead()
//{
//	//链表空头
//	g_pHead = new SinglyListNode;
//	g_pHead->pNext = NULL;
//	g_pEnd = g_pHead;
//}
//
////创建节点
//struct SinglyListNode* CreatNode(int a)
//{
//	//创建一个节点
//	SinglyListNode* pTemp = new SinglyListNode;
//	if (NULL == pTemp)
//	{
//		cout << "Not enough memory,we fail to creat a node!!!  " << endl;
//		return NULL;
//	}
//	//节点成员赋值
//	pTemp->a = a;
//	pTemp->pNext = NULL;
//	return pTemp;
//}
//
////尾添加
//void AddListTail(int a)
//{
//	//创建一个节点
//	SinglyListNode* pTemp= CreatNode(a);
//	if (NULL == pTemp)
//	{
//		cout << "Not enough memory,we fail to creat a node!!!" << endl;
//		return;
//	}
//	//链接 
//	g_pEnd->pNext = pTemp;
//	g_pEnd = pTemp;
//}
//
////头添加
//void AddListHead(int a)
//{
//    //创建一个节点
//	SinglyListNode* pTemp = CreatNode(a);
//	if (NULL == pTemp)
//	{
//		cout << "Not enough memory,we fail to creat a node!!!" << endl;
//		return;
//	}
//	//链接
//	pTemp->pNext = g_pHead->pNext;
//	g_pHead->pNext = pTemp;
//}
////遍历链表
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
////查找指定节点并返回地址
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
////任意位置添加节点
//void AddListRand(int index,int a)
//{
////判断链表是否为空
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//查找节点
//	SinglyListNode* pTemp= selectNode(index);
//	if (NULL == pTemp)
//	{
//		cout << "we did not find the node!!!" << endl;
//		return;
//	}
//	//查找到并连接到指定位置
//	//创建节点
//	SinglyListNode* pNode = CreatNode(a);
//	if (g_pEnd == pTemp)//当前节点是尾
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
////删除头结点
//void deletehead()
//{
//	//判断链表是否为空
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//删除节点
//	SinglyListNode* pTemp = g_pHead->pNext;//用中间变量记住g_pHead->pNext
//	g_pHead->pNext = pTemp->pNext;//变换头结点
//	delete pTemp;//释放
//}
//
//void deleteTail()
//{
//	//判断链表是否为空
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//删除节点
//	if (g_pHead->pNext == g_pEnd)//只有一个节点
//	{
//		delete g_pEnd;
//		g_pHead->pNext = NULL;
//		g_pEnd = g_pHead;
//	}
//	else//找尾结点的上一个
//	{
//		SinglyListNode* pTemp = g_pHead->pNext;
//		while (pTemp != NULL)//找结尾的前一个节点
//		{
//			if (g_pEnd == pTemp->pNext)
//			{
//				break;
//			}
//			pTemp = pTemp->pNext;
//		}
//		delete g_pEnd;//释放
//		g_pEnd = pTemp;//变换尾结点
//		g_pEnd->pNext = NULL;//尾巴的下一个置空
//	}	
//}
////删除任意节点
//void deleteNodeRand(int a)
//{
//	//判断链表是否为空
//	if (NULL == g_pHead->pNext)
//	{
//		cout << "this list is empty!!!" << endl;
//		return;
//	}
//	//查找节点
//	SinglyListNode* pTemp = selectNode(a);
//	if (NULL == pTemp)
//	{
//		cout << "we did not find the node!!!" << endl;
//		return;
//	}
//	//查找到并删除
//	if (pTemp==g_pEnd)//当前节点是尾结点
//	{
//		deleteTail();
//	}
//	else//该节点不是尾节点，找该节点的前一个节点
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
////释放链表
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
