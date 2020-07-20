#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
int array[8];
struct node *next;
};
struct node *frwd = NULL;
struct node *back = NULL;
struct node* temp;
void push(int value,int myAr[8]) {
int check =0;
   if (back == NULL) {
      back = (struct node *)malloc(sizeof(struct node));
      back->next = NULL;
      for(int i=0;i<8;i++)
      {
		  if(myAr[i]==0 && check==0)
		  {
			  back->array[i]=value;
			  check++;
		  }
		  else
		  {
			  back->array[i]=myAr[i];
		  }
      }
      frwd = back;
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      back->next = temp;
       for(int i=0;i<8;i++)
      {
      if(myAr[i]==0 && check==0)
      {
      temp->array[i]=value;
      check++;
 }
else
{
temp->array[i]=myAr[i];
}
 }
      temp->next = NULL;
      back = temp;
   }
}
int *pop() {
   temp = frwd;
   if (temp->next != NULL) {
      frwd=frwd->next;
      return temp->array;
   } else {
     temp = frwd;
      frwd = NULL;
      back = NULL;
      return temp->array;
     
   }
   
}
void dispState(int currBoards[8][8],int ls[8])
{
	for(int i=0;i<8;i++)
	{
	currBoards[i][ls[i]-1]=1;
	}
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << " " << currBoards[i][j];
        cout << "\n";
    }
    exit(0);

}

bool clear(int currBoards[8][8], int cols, int d[8])
{
int flag = 0;

    int i, j,rows,b[8][8]={0};

    for(int i=0;i<8;i++)
    {
    if(d[i]==0 && flag==0)
    {
    rows=i;
    break;
}
if(d[i]!=0)
{
b[i][d[i]-1]=1;
}
}
    for (i = 0; i < rows; i++)
        if (b[i][cols])
            return false;

    for (i = rows, j = cols; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return false;

    for (i = rows, j = cols; i >= 0 && j < 8; i--, j++)
        if (b[i][j])
            return false;
           
    if(rows==7)
    {
    d[rows]=cols+1;
    dispState(currBoards,d);
}

    return true;
}

void reccurciveAI(int currBoards[8][8],int flag)
{
int array[8]= {0};
    if(!flag)
    {
		int *currPtr;
		currPtr = pop();
		for(int i=0;i<8;i++)
		{
		array[i]=*currPtr;
		currPtr++;
		}

		for(int i=0;i<8;i++)
		{
			if(clear(currBoards,i,array))
				{
					push(i+1,array);
				}
		}
	}

		if(flag)
		{
			for (int i = 0; i < 8; i++)
			{
				  push(i+1,array);
			}
			flag=0;
		}
		reccurciveAI(currBoards,flag);
}

int main()
{

    int currBoards[8][8],i,j;
    for(i=0;i<8;i++)
	for(j=0;j<8;j++)
       currBoards[i][j]=0;

    reccurciveAI(currBoards, 1);
   
    return 0;
}