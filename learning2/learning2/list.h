#pragma once
#include<cstdlib>
#include<cstdio>
#include <iostream>
using namespace std;

//�ڵ�ṹ��
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

	//ɾͷ
	void deletehead();
	//ɾ��β��
	void deleteTail();
	//�ͷ�����
	void FreeList();
public:
	List();
	~List();

private:
	//��ͷ�����ʼ��
	void InitListHead();
	//�����ڵ�
	struct SinglyListNode* CreatNode(int a);
	//β���
public:
	void AddListTail(int a);
	//ͷ���
	void AddListHead(int a);
	//��������
	void ScanList();
	//����λ����ӽڵ�
	void AddListRand(int index, int a);
	//����ָ���ڵ㲢���ؽڵ��ַ
	struct SinglyListNode* selectNode(int a);
	//ɾ������ڵ�
	void deleteNodeRand(int a);
};

