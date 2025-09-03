#include <stdio.h>
//Bubble sort
int main(){
    int n;
    int arr[100];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0 ;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Sorted Elements: \n");
    for (int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }

    return 0;
}

