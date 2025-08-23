#include<stdio.h>
#include<string.h>
typedef struct library
{
    char name[50];
    char author[50];
    char code[10];
}lib;

void scan(lib a[15],int b)
{
    getchar();    
    for (int i=5;i<b;i++)
    {
        printf("Nhap ten sach: ");
        gets(a[i].name);
        printf("Nhap ten tac gia: ");
        gets(a[i].author);
        printf("Nhap ma vach: ");
        gets(a[i].code);        
    }

}

void delet(lib a[15],int &b)
{
    char code1[10];
    lib temp;
    printf("Nhap ma sach muon xoa: ");
    getchar();
    gets(code1);
    code1[strcspn(code1, "\n")] = '\0';
    for (int i=0;i<b;i++)
    {
        if (strcmp(code1,a[i].code)==0)
        {

            for (int j=i;j<b-1;j++)
            {
                // a[j]=temp;
                a[j]=a[j+1];
                // a[j+1]=temp;
            }
            b--;  
            printf("Da xoa sach thanh cong\n");     
        }
    }
}
void find(lib a[15],int b)
{
    printf("Nhap ten sach muon tim: ");
    char name1[50];
    getchar();
    gets(name1);
    for (int i=0;i<b;i++)
    {
        if (strcmp(name1,a[i].name)==0)
        {
            printf("Ten sach: %s\n",a[i].name);
            printf("Tac gia: %s\n",a[i].author);
            printf("Ma vach: %s\n",a[i].code);
        }
    }
}
void table(lib a[15],int b)
{
    int width=73;
    for (int i=0;i<width;i++) printf("_");
    printf("\n");
    printf("| Stt |           Ten           |         Tac gia         |   Ma vach   |");
    printf("\n");
    for (int i=0;i<width;i++) printf("_");
    printf("\n");
    for (int i=0;i<b;i++)
    {
        printf("|%5d|%25s|%25s|%13s|",i+1,a[i].name,a[i].author,a[i].code);
        printf("\n");
        for (int j=0;j<width;j++) printf("_");
        printf("\n");
    }
}

void order(lib a[15],int &book,bool &c)
{
    char order;
    printf("Nhap lenh ban muon thuc hien X(xoa sach), F(tim sach), T(hien bang), E(ket thuc): ");
    scanf("%c",&order);
    if (order=='X'||order=='x') delet(a,book);
    else if (order=='T'||order=='t')    table(a,book);
    else if (order=='F'||order=='f')    find(a,book);
    else if (order=='E'||order=='e')    c=false;
    else printf("Lenh khong hop le\n");
}
int main()
{
    int book;
    lib a[15]={{"Dac nhan tam","Dale Carnegie","123456"},
    {"Nha gia kim","Paulo Coelho","654321"},
    {"Nguoi giau mat","Dan Brown","456789"},
    {"Nguoi thay","Robin Sharma","987654"},
    { "Think again","Adam Grant","741852"}};
    bool play=true;
    printf("==== Thu vien ====\n");
    printf("Nhap so luong sach muon nhap: ");
    scanf("%d",&book);
    book+=5;
    scan(a,book);   table(a,book);
    do
    {
        order(a,book,play);
    } while (play==true);
    

} 