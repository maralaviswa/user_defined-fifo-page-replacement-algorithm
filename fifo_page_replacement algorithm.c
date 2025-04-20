#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int main()
{
        static int arr1[MAX]={-1},max=0,fault,cnt=-1;
        int *ptr=NULL,n,temp,k=0,i=0,j=0,flag=1;
        int arr[MAX]={-1};
        for(int i=1;i<MAX;i++)
        arr[i]=-1;
        printf("enter number of processors\n");
        scanf("%d",&n);
        ptr=calloc(1,(sizeof(int)*n));
        for(i=0;i<n;i++)
        {
          scanf("%d",&ptr[i]);
        }
        printf("the processors are\n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",ptr[i]);
        }
        printf("\n");
        for(j=0;j<n;j++)
        {
                flag=1;
                temp=ptr[j];
                for(i=0;i<MAX;i++)
                {
                 if(arr[i]==temp)
                 {
                    flag=0;
                    break;
                 }
                }
                if(flag==1 && k<MAX)
                {
                  arr[k++]=temp;
                  fault++;
                }
                else if(k==MAX && flag==1)
                {
                        for(i=0;i<MAX;i++)
                        {
                             if(arr1[i]>max)
                             {
                                     max=arr1[i];
                                     cnt=i;
                             }
                        }
                        arr[cnt]=temp;
                        fault++;
                        arr1[cnt]=0;
                        max=0;
                }
                for(i=0;i<MAX;i++)
                {
                        if(arr[i]>=0)
                                arr1[i]++;
                }
                printf("the processors running are:\n");
                for(i=0;i<k;i++)
                        printf("%d ",arr[i]);
                printf("\n");
        }
        printf("\n the page faults are %d\n",fault);
}