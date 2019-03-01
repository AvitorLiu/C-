#include"list.h"
int main()
{
	List ls;//通过构造函数生成初始化链表
	for (int i = 0; i < 10; i++)//通过数组添加链表
	{
		ls.AddListTail(i);
	}
	ls.ScanList();
	ls.AddListHead(15);//在头部添加15
	ls.ScanList();
	ls.AddListTail(17);//在尾部添加17
	ls.ScanList();
	ls.deleteNodeRand(4);//删除4
	ls.ScanList();
	ls.AddListRand(5, 17);//在5后面添加17
	ls.ScanList();
	system("pause");
	return 0;//通过析构函数将链表释放
}