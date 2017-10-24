#include<stdio.h>

// A function to implement swapping of two variables

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)

{
  //i and j are dummy variables

  int i, j;
  for (i = 0; i < n-1; i++)
    // Last i elements are already in place
      for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
          swap(&arr[j], &arr[j+1]);
}

int main()
{
  //n denotes total number of processes
  //h denotes total head Movement
  //i,k,j denote dummy variables
  //x denotes extreme head position
  //flag denotes how many times you want to enter processes

  int n,i,h=0,x,k,j;
  char flag = 'f';

  label:printf("\nEnter number of processes:");
  scanf("%d",&n);
  printf("\nEnter extreme head position:");
  scanf("%d",&x);

  if(flag == 'f')
    n=n+1;

  int a[n];

  if(flag == 'f')
  {
    a[n-1]=0;

    //taking input of processes track location from user

    printf("\nEnter processes in request order");
    for(i=0;i<n-1;i++)
    {
      scanf("%d",&a[i]);
    }
  }
  else
  {
    //taking input of processes track location from user

    printf("\nEnter processes in request order");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  }

  //sorting and calculating total head movements

  bubbleSort(a, n);

  for(i=0;i<n-1;i++)
    h+=(a[i+1]-a[i]);

  //output of the order in which Processing is done

  printf("\nProcessing order:");
  for(i=0;i<n;i++)
    printf("\t%d",a[i]);

  //display the graph

  printf("\n   ^ head position\n");
  for(i=x/4;i>0;i--)
  {
    if(i==x/4)
      printf("%d|",x);
    else if(i==x/8)
      printf("%d|",x/2);
    else
      printf("   |");
    for(j=0;j<n;j++)
    {
      if(a[j]/4==i)
      {
        for(k=0;k<j*10;k++)
        {
          printf(" ");
        }
        printf("* %d",a[j]);
      }
    }
    printf("\n");
  }
  printf("   ");
  for(i=0;i<x/2;i++)
  {
    printf("-");
  }
  printf("> scheduling");

  printf("\nDo you want to continue(y/n)");
  scanf(" %c",&flag);
  if(flag == 'y')
    goto label;

  printf("\nTotal Head Movement:%d\n",h);

  return 0;
}
