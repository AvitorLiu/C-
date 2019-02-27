#include<iostream>
#include<stdlib.h>
using namespace std;

// 节点结构体
struct SinglyListNode
{
	int a;
	SinglyListNode *pNext;
};

//定义全局头、尾指针
SinglyListNode* g_pHead = NULL;
SinglyListNode* g_pEnd = NULL;

//******函数声明******

//创建节点，尾添加与头添加
void AddNodeTotail(int a);//尾添加
void AddNodeTohead(int a);//头添加

//遍历链表  与 查询指定的节点 修改制定节点
void scanList();//遍历链表
struct SinglyListNode* selectNode(int a);//查询指定的节点

//链表清空
void Freelist();

//指定位置插入节点
void AddListRand(int index, int a);

//节点的删除
void DeleteListHead();//头删除
void DeleteListTail();//尾删除

//删除指定节点
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
//*******创建节点，尾添加与头添加*******

//创建链表，在链表中增加一个数据 **尾添加**
void AddNodeTotail(int a)
{
	//创建一个节点
	SinglyListNode* pTemp = new  SinglyListNode;

	//节点数据进行赋值
	pTemp->a = a;
	pTemp->pNext = NULL;

	//将节点链接到链表上
	if (NULL == g_pHead || NULL == g_pEnd)//如果原节点为空,则新来的节点既是头也是尾
	{
		g_pHead = pTemp;//将头指向新加进来的节点
	}
	else//正常情况下(链表不为空)新来的节点直接接在尾部
	{
		g_pEnd->pNext = pTemp;//将尾指向新加进来的节点
	}
	g_pEnd = pTemp;//新加入的节点变成了尾，尾巴一直指向最后一个节点
}

//创建链表，在链表中增加一个数据 **头添加**
void AddNodeTohead(int a)
{
	//创建一个节点
	SinglyListNode* pTemp = new  SinglyListNode;

	//节点数据赋值
	pTemp->a = a;
	pTemp->pNext = NULL;

	//接在链表上
	if (NULL == g_pHead)//空链表既是头也是尾
	{
		g_pHead = pTemp;
		g_pEnd = pTemp;
	}
	else
	{
		pTemp->pNext = g_pHead;
		g_pHead = pTemp;//将头向前移动
	}
}

//*******遍历链表  与 查询指定的节点*******

//遍历链表
void scanList()
{
	SinglyListNode *pTemp = g_pHead;//操作链表时不要改变头指针，否则链表会随之改变，需要利用中间指针进行操作
	while (pTemp != NULL)
	{
		cout << pTemp->a << " ";
		pTemp = pTemp->pNext;
	}
	cout << "" << endl;
}

//查询指定的节点
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
	//没找到则返回空指针
	return NULL;

}

//*******链表清空*******
void Freelist()
{
	SinglyListNode* pTemp = g_pHead;
	while (pTemp != NULL)
	{
		SinglyListNode* pt = pTemp;
		pTemp = pTemp->pNext;
		delete pt;
	}
	//置空头尾指针，方便下一次创建链表
	g_pHead = NULL;
	g_pEnd = NULL;
}

//*******指定位置插入节点*******
void AddListRand(int index, int a)
{
	//链表为空
	if (NULL == g_pHead)
	{
		cout << "this list is empty " << endl;
		return;
	}
	//找位置,查询指定的节点
	SinglyListNode* pt = selectNode(index);
	if (NULL == pt)
	{
		cout << "we did not find the node!!!" << endl;
		return;
	}
	//有此节点，给a创建节点
	SinglyListNode* pTemp = new  SinglyListNode;
	//节点成员进行赋值
	pTemp->a = a;
	pTemp->pNext = NULL;
	//链接到链表上
	if (pt == g_pEnd)//当前节点是尾结点（先连后断）
	{
		g_pEnd->pNext = pTemp;//尾巴的下一个指向新的节点
		g_pEnd = pTemp;//新节点是最后一个，变成尾
	}
	else//当前节点不是尾结点
	{
		pTemp->pNext = pt->pNext;//先进行链接
		pt->pNext = pTemp;//后断,再进行链接
	}
}

//******头删除******
void DeleteListHead()
{
	//链表检测
	if (NULL == g_pHead)
	{
		cout << "this list is empty,does not need this operation!!!" << endl;
	}
	//记住旧的头
	SinglyListNode* pTemp = g_pHead;
	//头的下一个节点变成新的头
	g_pHead = g_pHead->pNext;
	//释放旧的头
	delete pTemp;
}
//******尾删除******
void DeleteListTail()
{
	//链表检测
	if (NULL == g_pHead)
	{
		cout << "this list is empty,does not need this operation!!!" << endl;
	}
	//链表不为空
	//链表只有一个节点
	if (g_pHead == g_pEnd)
	{
		delete g_pHead;
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	//链表有多个节点
	else
	{
     //找到尾巴的前一个节点
	SinglyListNode* pTemp = g_pHead;
	while (pTemp->pNext != g_pEnd)//通过遍历记录下尾巴的前一个节点
	{
		pTemp = pTemp->pNext;
	}
	//找到了，进行删尾
	delete g_pEnd;//释放尾巴
	g_pEnd = pTemp;//尾巴前移
	g_pEnd->pNext = NULL;//尾巴的下一个指针赋值为空
	}
}
//******删除指定节点******
void DeleteListNode(int a)
{
	//链表检测
	if (NULL == g_pHead)
	{
		cout << "this list is empty,does not need this operation!!!" << endl;
	}
	//链表不为空
	SinglyListNode* pTemp = selectNode(a);
	//找不到该节点
	if (NULL == pTemp)
	{
		cout << "we did not find the node!!!"<<endl;
		return;
	}
	//能够找到该节点
	//只有一个节点
	if(g_pHead == g_pEnd)
	{
		delete g_pHead;
		g_pHead = NULL;
		g_pEnd = NULL;
	}
	//只有两个节点
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
	//有多个节点
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
			//找到要删除的节点的前一个节点
			SinglyListNode* pt = g_pHead;
			while (pt->pNext != pTemp)//通过遍历记录下尾巴的前一个节点
			{
				pt = pt->pNext;
			}
			pt->pNext = pTemp->pNext;//链接
			delete pTemp;//释放
		}
	}
}