#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <windows.h>
#include <fstream>


#define Quant 10000
using namespace std;

void bucket_sort(int v[], int tam);

void bucket_sort(int v[],int tam){

    int i,j,k,l;
    int maior = 0, proximo = 0;
    double maximo = 1;

    for(i=0;i<tam; i++){  //achar o maior e o menor valor, para ver o intervalo dos valores
        proximo = v[i];
        if(maior<proximo){
            maior=proximo;
        }
    }
    j=-1;

    for(i=1; i<1000000; i *= 10){  //achar o maior intervalo
        if((maior/i) != 0 ){
            j++;
        }


        if((maior/i) == 0 ){
            k=j;
            while(j != 0){
                maximo *= 10;
                j--;
            }
            break;
        }
    }

    int bancas[10][tam];
    int aux[10];
    int num;
    int w;
    maximo=1;
    for(l=0;l<=k;l++){
        for(i=0;i<10;i++){          //inicializar
            for(j=0; j<tam;j++){
                bancas[i][j]=-1;
            }
        }
        for(i=0;i<10;i++){
            aux[i]=0;
        }
        j=0;
        for(i=0; i<tam; i++){
            num =(v[i]/maximo);
            num = num%10;
            bancas[num][aux[num]]=v[i];
            aux[num]++;
        }
        w=0;
        for(i=0;i<10;i++){
            for(j=0;j<tam;j++){
                if(bancas[i][j] != -1){
                    v[w] = bancas[i][j];
                    w++;
                }
            }
        }
    maximo= maximo*10;

    }
}
double performancecounter_diff(LARGE_INTEGER *a,
                               LARGE_INTEGER *b)
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) /
           (double)freq.QuadPart;
}

using namespace std;

int main()
{
     LARGE_INTEGER t_ini, t_fin;
    double secs;
    int arrAleatorio[Quant], arrCrescente[Quant], arrDecrescente[Quant], arrCrescenteDecrescente[Quant], arrDecrescenteCrescente[Quant],i,j;
    for(i=0; i<Quant; i++){
        arrAleatorio[i] = rand() % Quant;
    }

    for(i=0;i<Quant;i++){
        arrCrescente[i]=i;
    }

    j=Quant;
    for(i=0;i<Quant;i++){
        j--;
        arrDecrescente[i]=Quant;
    }

    for(i=0;i<(Quant/2);i++){
        arrCrescenteDecrescente[i]=i;
    }

    for(i=Quant;i>(Quant/2);i--){
        arrCrescenteDecrescente[i]=i;
    }

    for(i=(Quant/2);i>0;i--){
        arrDecrescenteCrescente[i]=i;
    }
    for(i=(Quant/2);i<Quant;i++){
        arrDecrescenteCrescente[i]=i;
    }

    QueryPerformanceCounter(&t_ini);
    bucket_sort(arrAleatorio,Quant);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tempo Aleatorico(s):" << secs*1000 << endl;

    QueryPerformanceCounter(&t_ini);
    bucket_sort(arrCrescente,Quant);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tempo Crescente(s):" << secs*1000 << endl;


    QueryPerformanceCounter(&t_ini);
    bucket_sort(arrDecrescente,Quant);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tempo Decrescente(s):" << secs*1000 << endl;


    QueryPerformanceCounter(&t_ini);
    bucket_sort(arrCrescenteDecrescente,Quant);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tempo Crescente Decrescente(s):" << secs*1000 << endl;


    QueryPerformanceCounter(&t_ini);
    bucket_sort(arrDecrescenteCrescente,Quant);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tempo Decrescente Crescente(s):" << secs*1000 << endl;



    return 0;
}
