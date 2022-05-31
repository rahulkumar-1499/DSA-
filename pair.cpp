#include<iostream>
using namespace std;

template<typename T,typename V>

class pair1
{
	T x;
	V y;
	public:
		void setX(T x)
		{
			this->x=x;
		}
		T getX()
		{
			return x;
		}
		void setY(V y)
		{
			this->y=y;
		}
		V getY()
		{
			return y;
		}
};
int main()
{
	pair1 <int,int>p1;
	p1.setX(12);
	p1.setY(15);
	cout<<"x "<<p1.getX()<<" y "<<p1.getY()<<endl;
	
	pair1 <int,char>p2;
	p2.setX(12);
	p2.setY('A');
	cout<<"x "<<p2.getX()<<" y "<<p2.getY()<<endl;
	
	pair1 <pair1<int,double>,char>p3;
	p3.setY('C');
	pair1 <int,double>p4;
	p4.setX(10);
	p4.setY(5.43);
	p3.setX(p4);
	
	cout<<"first element "<<p3.getX().getX()<<" second element "<<p3.getX().getY()<<" third elt "<<p3.getY();
	return 0;
}
