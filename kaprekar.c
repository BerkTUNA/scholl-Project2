#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **Matama(int satir,int b);
int Transpoze(int** a, int satir,int sutun);
void Kaprekar(int* a, int boyut);
void siralamayazdirma(int** a, int satir, int sutun);
void Trayazdirma(int** a, int satir, int sutun);
void texthata(int* a, int boyut);
void siralama(int** a, int satir, int sutun);
void tek(int** a, int satir, int sutun);

int main(){
    int satir,sutun;
    printf("Satiri Giriniz : ");
    scanf("%d",&satir);
    printf("Sutunu Giriniz :");
    scanf("%d",&sutun);
    int **a=Matama(satir,sutun);
    siralama(a,satir,sutun);
    siralamayazdirma(a,satir,sutun);
    int **Tdizi = Transpoze(a,satir,sutun);
    Trayazdirma(Tdizi,sutun,satir);
    tek(Tdizi,sutun,satir);
    return 0;
}
void siralama(int** a,int satir,int sutun){
int i,j,z,t;
for(z=1; z<(satir*sutun); z++)
    {
        for(i=0; i<satir; i++)
        {
            for(j=0; j<sutun-1; j++)
            {
                if (a[i][j]>a[i][j+1])
                {
                    t=a[i][j];
                    a[i][j]=a[i][j+1];
                    a[i][j+1]=z;
                }
            }
        }
        for(i=0; i<satir-1; i++)
        {
            if (a[i][sutun-1]>a[i+1][0])
            {
                t=a[i][sutun-1];
                a[i][sutun-1]=a[i+1][0];
                a[i+1][0]=t;
            }
        }
    }
}
void tek(int** a, int satir, int sutun){
int boyut=satir*sutun;
int *tdizi;;
 tdizi=malloc(boyut*sizeof(int));
 int i,j;
 int sayac=0;
 for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        tdizi[sayac]=a[i][j];
        sayac++;
    }
 }
 Kaprekar(tdizi,boyut);
}
void Kaprekar(int* a, int boyut){
    int kdizi[50];
    int j=10;
    int i,c,k;
    int bak=0;
    for(c=0;c<boyut;c++)
        {
            j=10;
            int kare=(a[c]*a[c]);

        }
    if(bak>0)
        {
            texthata(kdizi,bak);
    }
    else{
        printf("\nBu Matriste Kaprekar Sayi Yoktur.\n");
    }

}
int **Matama(int satir,int sutun){
srand(time(NULL));
int i,j;
int **a;
    a=malloc(satir*sizeof(int));
    for(i=0;i<satir;i++){
        a[i]=malloc(sutun*sizeof(int));
    }
    for(i=0;i<satir;i++){
        for(j=0;j<sutun;j++){
            a[i][j]=rand()%40000+5;
        }
    }
return a;
}
int Transpoze(int** a, int satir,int sutun){
int i,j;
int ** Ydizi;
Ydizi=malloc(sutun*sizeof(int));
for(i=0;i<sutun;i++){
    Ydizi[i]=malloc(satir*sizeof(int));
}
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        Ydizi[j][i]=a[i][j];
    }
}
return Ydizi;
}
void siralamayazdirma(int** a, int satir, int sutun){
int i,j;
    FILE *text= fopen("transpoze.txt","w");
    if(text==NULL){
        printf("Islem Basarisiz.\n");
    }
    else{
            fprintf(text,"Siralanmis hali\n");
        for(i=0;i<satir;i++){
                fprintf(text,"\n");
            for(j=0;j<sutun;j++){
                fprintf(text,"%d \t",a[i][j]);
            }
        }
    }
    fprintf(text,"\n\n\n");
}
void Trayazdirma(int** a, int satir, int sutun){
int i,j;
    FILE *text= fopen("transpoze.txt","a+");
    if(text==NULL){
        printf("islem Basarisiz.\n");
    }
    else{
            printf("\nYazdirma islemi Tamam!\n");
            fprintf(text,"Transpozeli Hali\n");
        for(i=0;i<satir;i++){
                fprintf(text,"\n");
            for(j=0;j<sutun;j++){
                fprintf(text,"%d \t",a[i][j]);
            }
        }
    }
    fprintf(text,"\n\n");
  }
void texthata(int* a, int boyut){
  int i;
  FILE *text = fopen("kaprekar.txt","w");
  if(text== NULL){
    printf("Kaprekar Yazdirma islemi Basarisiz!\n");
    }
    else{
        fprintf(text,"Kaprekar Sayilar\n");
        for(i=0;i<boyut;i++){
         fprintf(text,"%d\n",a[i]);
        }
    }

  }
