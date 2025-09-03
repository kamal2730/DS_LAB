#include <stdio.h>
int main(){
    int n;
    int arr[100];
    int bn=0,sn=0,in=0;
    int bc=0,sc=0,ic=0;
    int ba[100],sa[100],ia[100];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        ba[i]=arr[i];
        sa[i]=arr[i];
        ia[i]=arr[i];
    }

    for(int i = 1; i < n; i++) {
        int key = ia[i];
        int j = i - 1;
        while(j >= 0 && ia[j] > key) {
            ia[j + 1] = ia[j];
            j--;
            in++;
            ic++
        }
       ia[j + 1] = key;
    }

    for(int i=0;i<n;i++){
        for(int j=0 ;j<n-i-1;j++){
            bc++;
            if(ba[j]>ba[j+1]){
                bn++;
                int temp=ba[j];
                ba[j]=ba[j+1];
                ba[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        int min_i=i;
        for(int j=i+1 ;j<n;j++){
            if(sa[j]<sa[min_i]){
                min_i=j;
            }
        }
        if(min_i!=i){
        int temp=sa[min_i];
        arr[min_i]=arr[i];
        arr[i]=temp;
        }
    }

    printf("Sorted Elements: \n");


    return 0;
}


