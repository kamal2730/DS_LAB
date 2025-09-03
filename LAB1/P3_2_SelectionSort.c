#include <stdio.h>
//Selection sort
int main(){
    int n,j;
    int arr[100];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        int min_i=i;
        for(int j=i+1 ;j<n;j++){
            if(arr[j]<arr[min_i]){
                min_i=j;
            }
        }
        int temp=arr[min_i];
        arr[min_i]=arr[i];
        arr[i]=temp;


    }
    printf("Sorted Elements: \n");
    for (int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }

    return 0;
}

