#include"list.h"
int main()
{
	List ls;
	for (int i = 0; i < 10; i++)
	{
		ls.AddListHead(i);
	}
	ls.ScanList();
	ls.deleteNodeRand(4);
	ls.ScanList();
	system("pause");
	return 0;
}