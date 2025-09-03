#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,min;
    printf("n:");
    scanf("%d",&n);
    int *arr=(int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    min=*arr;
    for (int i=0;i<n;i++){
        if(*(arr+i)<min){
            min=*(arr+i);
        }
    }
    printf("min:%d",min);
    return 0;
}
