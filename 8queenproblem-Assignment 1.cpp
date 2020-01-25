#include <iostream>
#include<stdlib.h>
#define N 8
using namespace std;

struct node{
	int arr[8];
	struct node *next;	
};
struct node *front = NULL;
struct node *back = NULL;
struct node* tmp;
void push(int val,int ar[N]);
int *pop();
void print(int board[N][N],int ls[N]);
bool isSafe(int board[N][N], int colmn, int l[N]);
void solveNQ(int board[N][N],bool cond);



int main()
{

    int board[N][N] = {{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0},
    					{0, 0, 0, 0,0, 0, 0, 0} };

    solveNQ(board, true);
    
    	return 0;
}

void solveNQ(int board[N][N],bool cond)
{
	int arr[N]= {0}; 
    if(!cond)
    {
    	int *ptr;
    	ptr = pop();
    	for(int i=0;i<N;i++)
    	{
    		arr[i]=*ptr;
    		ptr++;
		}
		
		for(int i=0;i<N;i++)
		{
			if(isSafe(board,i,arr))
			{
			push(i+1,arr);
			}
		}
		
		
	}
	
    if(cond)
    {
    	for (int i = 0; i < N; i++)
    	{
          		push(i+1,arr);
    	}
    	cond=false;
    }
	solveNQ(board,cond);
}


bool isSafe(int board[N][N], int colmn, int l[N])
{
	int flag = 0;
	
    int i, j,row,b[8][8]={0};

    for(int i=0;i<N;i++)
    {
    	if(l[i]==0 && flag==0)
    	{
    		row=i;
    		break;	
		}
		if(l[i]!=0)
		{
			b[i][l[i]-1]=1;
		}
	}
    for (i = 0; i < row; i++)
        if (b[i][colmn])
            return false;

    for (i = row, j = colmn; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return false;

    for (i = row, j = colmn; i >= 0 && j < N; i--, j++)
        if (b[i][j])
            return false;
            
    if(row==7)
    {
    	l[row]=colmn+1;
    	print(board,l);
	}

    return true;
}
void print(int board[N][N],int ls[N])
{
	for(int i=0;i<N;i++)
	{
		board[i][ls[i]-1]=1;
	}
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << "" << board[i][j];
        cout << "\n";
    }
    exit(0);
	
}
void push(int val,int ar[N]) {
	int flag =0;
   if (back == NULL) {
      back = (struct node *)malloc(sizeof(struct node));
      back->next = NULL;
      for(int i=0;i<N;i++)
      {
      	if(ar[i]==0 && flag==0)
      	{
      		back->arr[i]=val;
      		flag++;
		  }
		else
		{
			back->arr[i]=ar[i];
		}
	  }
      front = back;
   } else {
      tmp=(struct node *)malloc(sizeof(struct node));
      back->next = tmp;
       for(int i=0;i<N;i++)
      {
      	if(ar[i]==0 && flag==0)
      	{
      		tmp->arr[i]=val;
      		flag++;
		  }
		else
		{
			tmp->arr[i]=ar[i];
		}
	  }
      tmp->next = NULL;
      back = tmp;
   }
}
int *pop() {
   tmp = front;
   if (tmp->next != NULL) {
      front=front->next;
      return tmp->arr;
   } else {
   	  tmp = front;
      front = NULL;
      back = NULL;
      return tmp->arr;
      
   }
   
}
