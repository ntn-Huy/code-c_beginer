#include<stdio.h>
#include<stdlib.h>
int* twosum (int nums[],int numSize,int target)
{
    int* result= (int*)malloc(2*sizeof(int));
    for(int i=0;i<numSize;i++)
    {
        for (int j=i+1;j<numSize;j++)
        {
           if (nums[i]+nums[j]==target)
           {
                result[0]=i;
                result[1]=j;
                return result;
           }
            
        }
    }
    free(result);
    return NULL;
}
int main()
{
    int nums[10],numSize,target;
    printf("Nhap so luong: ");
    scanf("%d",&numSize);
    for(int i=0;i<numSize;i++)scanf("%d",&nums[i]);
    printf("Nhap so target: ");
    scanf("%d",&target);
    
    int* res=twosum(nums,numSize,target);
    printf("%d, %d",res[0],res[1]);
}