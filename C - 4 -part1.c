#include <stdio.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>

int c1=1,c2=1;
int nullOp = NULL;
int *array1=&nullOp,*array2=&nullOp;
void take(){
  	int * Array = 0;
  	int counter = 0;
  	int n,temp;


  	while(1 == 1) 			{
    		 printf ("enter number : ");

    		 scanf ("%d", &temp);
    		 counter++;
     Array = (int*) realloc (Array, counter * sizeof(int));
     if (Array==NULL)
       { puts ("error");
            exit (1); }
     Array[counter-1]=temp;

  printf ("the mid is  %d \n",Array[counter/2]);
 					 }
  free (Array);


}




void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);  

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//i used quickSort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int take2(int number){
    if(array2==&nullOp)
        array2=(int*)malloc(sizeof(int));
    else
        array2=(int*)realloc(array2,sizeof(int)*c2);
    array2[c2-1]=number;
    int len =(c2-1)/2;
    quickSort(array2,0,c2-1);
    c2++;

    return array2[len];
}
int main ()
{

    printf("take2 : \n");
    printf("%d\n",take2(30));
    printf("%d\n",take2(15));
    printf("%d\n",take2(2));
    printf("%d\n",take2(8));
    printf("%d\n",take2(40));
    puts("take 1 :");
 take();


  return 0;
}