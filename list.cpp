#include<stdio.h>
// Mã màu ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
struct sinhvien
{
	int maso;
	char ten[100];
	float diem;
}	sv[100];

void Danhsach (struct sinhvien sv[],int n)
{
	for (int i=0;i<38;i++)
		printf(CYAN"_");
	printf("\n");
	for (int i=0;i<n;i++)
	{
		if (i==0)
		{
			printf(CYAN"|" GREEN"%4s" CYAN"|" GREEN"%-25s" CYAN"|" GREEN"%5s" CYAN"|""\n","Mssv","Ho va ten","Diem");
			printf("|____|_________________________|_____|\n");			
		}
		printf(CYAN"|" WHITE"%4d" CYAN"|" WHITE"%-25s" CYAN"|" WHITE"%5.2f" CYAN"|""\n",sv[i].maso,sv[i].ten,sv[i].diem);
		if (i==n-1)	printf(CYAN"|____|_________________________|_____|\n"RESET);
	}
}

int main()
{
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("Mssv: ");
		scanf("%d",&sv[i].maso);
		getchar();
		printf("ten: ");
		gets(sv[i].ten);
		printf("Diem: ");
		scanf("%f",&sv[i].diem);
	}
	Danhsach(sv,n);
	printf("\nend.");

}
