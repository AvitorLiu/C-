#pragma once
#include<cstdlib>
#include<cstdio>
#include <iostream>
using namespace std;

//节点结构体
struct SinglyListNode
{
	int a;
	SinglyListNode *pNext;
};

class List
{
private:
	SinglyListNode* g_pHead = NULL;
	SinglyListNode* g_pEnd = NULL;

	//删头
	void deletehead();
	//删除尾巴
	void deleteTail();
	//释放链表
	void FreeList();
public:
	List();
	~List();

private:
	//空头链表初始化
	void InitListHead();
	//创建节点
	struct SinglyListNode* CreatNode(int a);
	//尾添加
public:
	void AddListTail(int a);
	//头添加
	void AddListHead(int a);
	//遍历链表
	void ScanList();
	//任意位置添加节点
	void AddListRand(int index, int a);
	//查找指定节点并返回节点地址
	struct SinglyListNode* selectNode(int a);
	//删除任意节点
	void deleteNodeRand(int a);
};

