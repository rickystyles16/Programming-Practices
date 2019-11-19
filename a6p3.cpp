#include<iostream>
using namespace std;
template <class T>
class array
{
	T *a;
	int size;
	public :
		array(int n)
		{
			size=n;
			a = new T[n];
			for (int i=0;i<n;i++)
			a[i]=0; 
		}
		~array()
		{
			delete a;
		}
		
        void getdata()
		{
			for (int i=0;i<size;i++)
			{
				cout << "Enter Element "<<i+1<<" : ";
				cin >> a[i];
			}
		}
		T max()
		{
			
			T max=0;
			for (int i=0;i<size;i++)
			{
				if (max < a[i])
				max = a[i];
			}
			return max;
		}
		T sum()
		{
			
			T sums=0;
			for (int i=0;i<size;i++)
			    sums += this->a[i];
			    return sums;
		    
		}
		
};
int main ()
{
	int n;
	cout << "How many elements?";
	cin >> n;
	array <int> a(n);
	a.getdata();
	cout <<"Max among the elements is "<< a.max()<<endl;
	cout <<"Sum of the elements is "<<a.sum();
	return 0;
}
