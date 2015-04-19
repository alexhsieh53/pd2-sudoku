#include "Sudoku.h"
using namespace std;


bool Sudoku::backtrack()
{   int first;
     first=get_first();
     if(first==-2)
     {
	 if(iscorrect()==true)
	 {
	 	return true;
	 }
	 else
	  return false;
     	
	 }
	 
	 else
	 {
	 	for(int q=1;q<=9;q++)
	 	  {  int a=(first/12);
	 	  int b=(first%12);
	 	  setElement(first, q);
		   
	 	  if(check(a,b,q)==true)
	 	     {
			   if(backtrack())
			   		return true;
	 	      }
	 	      
	 	 }
	 	arr[first] = 0;
	 	 return false;
	 	 
	 }
	
}


 	

    

void Sudoku::setElement(int index, int value)
 {
 arr[index] = value;
 }





int Sudoku::get_first()
{
	for(int i=0;i<144;i++)
	
	if(arr[i]==0)
{

	 return i;
}
	 return  -2;
}


bool Sudoku::checkUnity(int arr[])
{
int arr_unity[12];
int arrcheck[12]={-1,-1,-1,1,2,3,4,5,6,7,8,9};
int f=0;

for(int i=0; i<12; ++i)
arr_unity[i] = 0; 
for(int i=0; i<12; ++i)
      arr_unity[i]=arr[i];
      
      sort(arr_unity,arr_unity+12);
 for(int i=0; i<12; ++i)
     {
	 if(arr_unity[i]==arrcheck[i])
        f++;
		}
 if(f!=12) 
 return false;
  
 return true;
 }



bool Sudoku::check(int a,int k,int i)

{     int l=0;
	 int charr[12];
	 int location;
	
	 
	for(int j=0;j<12;j++)
	{   
		charr[j]=arr[j+12*a];
	    if(charr[j]==i)
	    l++;
	}
	if(l>1)
	{
		return false;
	}	
				  
	l=0;
	  
	

   	   for(int j=0;j<12;j++)
   	   {
   	   	  charr[j]=arr[k+12*j];
   	   	  if(charr[j]==i)
	          l++;
			  }
			
			 if(l>1)
			  {return false;
				  }	
				 
		l=0;
		for(int j=0; j<9; ++j)
       {
       location = 36*(a/4) + 3*(a%4)+12*(j/3) + (j%3);
            charr[j] = arr[location];
            if(charr[j]==i)
	          l++;
            }
            if(l>1)
			  {return false;
				  }	
				  
            return true;
	
	
}



bool Sudoku::checkcell(int arr[])
{

int arr_unity[9];


for(int i=0; i<9; ++i)
{
arr_unity[i] = 0;

} 
for(int i=0; i<9; ++i)
 ++arr_unity[arr[i]-1]; 
 
 for(int i=0; i<9; ++i)
 if(arr_unity[i] != 1) // all element
 return false; // must be 1
 return true;
 }

bool Sudoku::right(int arr[])
{    int j=0;
	for(int i=0;i<9;i++)
	{ if(arr[i]==-1)
	    j++;
		
	}
	
	if(j!=9)
	return false;
	
	return true;
}


bool Sudoku::iscorrect ()
{
	bool check_result;
	bool checka;
 int check_arr[12];
 int location;
 for(int i=0; i<144; i+=12) // check rows
 {
 for(int j=0; j<12; ++j)
 check_arr[j] = arr[i+j];
 check_result = checkUnity(check_arr);
 if(check_result == false)
 return false;
 }
 for(int i=0; i<12; ++i) 
 {
 for(int j=0; j<12; ++j)
 check_arr[j] = arr[i+12*j];
 check_result = checkUnity(check_arr);
if(check_result == false)
 return false;
 }

 for(int i=0; i<16; ++i) 
 {
 for(int j=0; j<9; ++j)
 {
 location = 36*(i/4) + 3*(i%4)+12*(j/3) + (j%3);
 check_arr[j] = arr[location];
 }
 check_result =checkcell(check_arr);
checka=right(check_arr);
 if(check_result == false&&checka==false)
 return false;
}
 return true;
 }
 
 
 int Sudoku::Solve ()
{
	if(backtrack()==true)
	{    cout<<"1";
		for(int i=0;i<144;i++)
		{ 
		     int k=arr[i];
		     if(i%12 == 0)
		     {
		     	cout << endl;
			 }
		     cout<<k;
			
		}
		cout<<endl;
	}
	else
	{    
	  for(int i=0;i<144;i++)
		{ 
		     int k=arr[i];
		     if(i%12 == 0)
		    cout << endl;
		     cout<<k;
		     
			
		}
		cout<<"0";
		
	}
	
	
}


int Sudoku::GiveQuestion()
{   

int a[144]={4,2,6,8,7,3,9,5,1,-1,-1,-1,
8,7,3,9,5,1,6,2,4,-1,-1,-1,
9,5,1,6,2,4,8,7,3,-1,-1,-1,
-1,-1,-1,1,3,2,0,8,7,9,5,6,
-1,-1,-1,7,8,5,1,9,6,4,2,3,
-1,-1,-1,4,9,6,2,3,0,8,7,1,
1,3,7,2,4,8,-1,-1,-1,6,9,5,
2,8,4,5,6,9,-1,-1,-1,1,3,7,
6,9,5,0,1,7,-1,-1,-1,2,8,4,
3,1,2,-1,-1,-1,7,4,8,5,6,9,
7,4,8,-1,-1,-1,0,6,9,3,1,2,
5,6,9,-1,-1,-1,3,1,2,7,4,8};

   int b;
   int p=8;
 
 srand(time(NULL));
 
 
 while(p!=0)
 {  b=(rand()%140)+1;
    int g;
    g=a[b];
     if (g!=-1)
 	a[b]=0;
 	
 	p--;
 }
 
 
 	for(int i=0;i<144;i++)
		{ 
		     int k=a[i];
		     if(i%12 == 11)
		     {   
		     	cout <<k<<endl;
			 }
			 else
		     cout<<k<<" ";
			
		}


	
}


int Sudoku::Readin()
{
	for(int i = 0; i < sudokuSize; i++) 
	{
		
			cin >> arr[i];
		
	}
}
