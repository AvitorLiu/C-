#include"list.h"
int main()
{
	List ls;//ͨ�����캯�����ɳ�ʼ������
	for (int i = 0; i < 10; i++)//ͨ�������������
	{
		ls.AddListTail(i);
	}
	ls.ScanList();
	ls.AddListHead(15);//��ͷ�����15
	ls.ScanList();
	ls.AddListTail(17);//��β�����17
	ls.ScanList();
	ls.deleteNodeRand(4);//ɾ��4
	ls.ScanList();
	ls.AddListRand(5, 17);//��5�������17
	ls.ScanList();
	system("pause");
	return 0;//ͨ�����������������ͷ�
}