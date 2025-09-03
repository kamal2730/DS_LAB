#include <stdio.h>
#include <stdlib.h>
int main(){
    //matrix declaration a*b=c
    int m,n,p,q;
    printf("enter m n p q:");
    scanf("%d%d%d%d",&m,&n,&p,&q);
    if(n!=p){
        printf("can't multiply");
        return 1;
    }
    int **a= (int **)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        *(a+i)=(int *)malloc(n*sizeof(int));
    }
    int **b= (int **)malloc(p*sizeof(int*));
    for(int i=0;i<p;i++){
        *(b+i)=(int *)malloc(q*sizeof(int));
    }
    int **c= (int **)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        *(c+i)=(int *)malloc(q*sizeof(int));
    }
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            printf("\nEnter a[%d][%d]:",i,j);
            scanf("%d",(*(a+i)+j));
        }
    }
    for(int i=0;i<p;i++){
        for (int j=0;j<q;j++){
            printf("\nEnter b[%d][%d]:",i,j);
            scanf("%d",(*(b+i)+j));
        }
    }
    for(int i=0;i<m;i++){
        for (int j=0;j<q;j++){
            *(*(c+i)+j)=0;
            for(int k=0;k<n;k++){
                *(*(c+i)+j)+=(*(*(a+i)+k))*(*(*(b+k)+j));
            }
        }
    }
    for(int i=0;i<m;i++){
        printf("\n");
        for (int j=0;j<q;j++){
            printf("%d\t",*(*(c+i)+j));
        }
    }

    return 0;
}
