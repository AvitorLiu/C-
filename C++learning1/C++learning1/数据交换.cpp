//#include<iostream> 
//using namespace std;
//template <typename T>
//void  fun(T &a, T &b)//此处写作T fun( )则要求必须返回参数
//{
//	T tmp;
//	tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a1 = 4, b1 = 5;
//	fun(a1, b1);
//	cout << "fun(a1,b1)=" << a1<<" "<< b1 << endl;
//	char a2 ='a'  , b2 ='b' ;
//	fun(a2, b2);
//	cout << "fun(a2,b2)="  << a2 << " " << b2 << endl;
//
//	//cout << a1 << endl;
//	//cout << b1 << endl;
//	system("pause");
//	return 0;
//}