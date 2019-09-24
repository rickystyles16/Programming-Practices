  
#include<iostream>
using namespace std;
#define max_size 10
class STACK{
    int array[max_size];
    int pushed;
public:
    void get_data()
    {
        cout<<"Enter the first element: ";
        cin>>array[0];
        pushed=1;
    }
    void push()
    {
        if(pushed==max_size)
        {
            cout<<"Error: OVERFLOW detected\n";
            return;
        }
        cout<<"Enter the data: ";
        cin>>array[pushed];
        pushed++;
    }
    void pop()
    {
        if(pushed==0)
        {
            cout<<"Error: UNDERFLOW detected\n";
            return ;
        }
        pushed--;
    }
    void show()
    {
    	for (int i =0 ; i<pushed;i++)
    	cout << array[i]<<"\n";
	}
       
};

int menu()
 {
     int choice;
      printf ("\nMenu\n");
      printf ("1.Push\n");
      printf ("2.Pop\n");
      printf ("3.Show Elements\n");     
	  printf ("4.Exit\n");
	  scanf ("%d",&choice);     
	 return choice;
}


int main()
{
    class STACK s;
    int choice;
do
	{
	    choice = menu();
		switch(choice)
	    {
		case 1 : s.push(); 
		           break;
	    case 2 : s.pop();
	               break;
	    case 3 : s.show();
	               break;
		case 4  : printf ("System exit!\n");
	               break;
		default : printf("\nPlease try again with a valid choice\n");    
		}
	}
	while (choice != 4);
		
	
    return 0;
}

