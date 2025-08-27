#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* tranfer2nums(int l1[],int l2[],int len1,int len2)
{
    int* num=(int*)malloc(2*sizeof(int));
    num[0]=0;num[1]=0;
    for(int i=0;i<len1;i++){num[0]+=l1[i]*pow(10,len1-i-1);}
    for(int i=0;i<len2;i++){num[1]+=l2[i]*pow(10,len2-i-1);}

    return num;
}
int count(int n)
{
    if (n==0) return 1;
    int i=0;
    while (n>0){n/=10;  i++;}
    return i;
}
int* add2nums(int l1[],int l2[],int len1,int len2,int* outlen)
{
    int size;
    int* num= tranfer2nums(l1,l2,len1,len2);
    int sum=num[0]+num[1];
    free(num);
    int n=count(sum);
    *outlen=n;
    int* result=(int*)malloc(n*sizeof(int));
    while(n>0){result[n-1]=sum%10;    sum/=10;    n--;}
    return result;
}

int main()
{
    int l1[100],l2[100];
    int len1,len2;
    printf("Nhap so len1:");
    scanf("%d",&len1);
    for (int i=0;i<len1;i++) scanf("%d",&l1[i]);
    printf("Nhap so len2:");
    scanf("%d",&len2);
    for (int i=0;i<len2;i++) scanf("%d",&l2[i]);
    int outlen;
    int* result=add2nums(l1,l2,len1,len2,&outlen);
    for (int i=0;i<outlen;i++) printf("%d ",result[i]);
    free(result);

}