#include <stdio.h>
//Binary search
int main(){
    int n,low,high,key,mid;
    int arr[100];
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter Elements  in sorted order:");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter Key to search:");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<high){
        mid=(high+low)/2;
        if(key>arr[mid]){
            low=mid+1;
        }else if(key<arr[mid]){
            high=mid-1;
        }else if(key==arr[mid]){
            printf("%d found at index %d",key,mid);
            return 0;
        }
    }
    printf("Not found!");
    return 0;
}
