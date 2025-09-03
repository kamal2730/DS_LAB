#include <stdio.h>
//Insertion sort
int main(){
    int n;
    int arr[100];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
       arr[j + 1] = key;
    }


    printf("Sorted Elements: \n");
    for (int i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }

    return 0;
}

