#include <stdio.h>
//linear search
int main(){
    int n,key;
    int arr[100];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter Elements:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter Key to search:");
    scanf("%d",&key);
    printf("Enter Elements:");
    for (int i=0;i<n;i++){
        if(arr[i]==key){printf("%d found at index %d",key,i);return 0;}
    }
    printf("Not found!");
    return 0;
}
