#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    *a^=*b;
    *b^=*a;
    *a^=*b;

}
void sort(int* arr,int s,int e){
    if(s>=e-1){return;}
    int min_i=s;
    for(int i=s+1;i<e;i++){
        if(*(arr+i)<*(arr+min_i)){min_i=i;}
    }
    if(min_i!=s){swap(arr+s,arr+min_i);}
    sort(arr,s+1,e);
}
int main(){
    int n,min;
    printf("n:");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    sort(arr,0,n);
    printf("sorted array:");
    for (int i=0;i<n;i++){
        printf("\t%d\t",*(arr+i));
    }
    return 0;
}
