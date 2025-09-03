#include <stdio.h>
struct data{
    char name[10];
    int roll_no;
    int GRADE;

}records[100];
int read(struct data *r){
    int n;
    printf("n:");
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        getchar();
        printf("\nname roll_no GRADE:");
        scanf("%s%i%i",&r[i].name,&r[i].roll_no,&r[i].GRADE);
    }
    return n;
}
void display(struct data *r,int n){
    for(int i=0;i<n;i++){
        printf("\nname:%s roll_no:%i GRADE:%i",r[i].name,r[i].roll_no,r[i].GRADE);
    }
}
void sort(struct data *r,int n){
    for(int i=0;i<n;i++){
        for(int j=0 ;j<n-i-1;j++){
            if(r[j].roll_no>r[j+1].roll_no){
                struct data temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
}

int main(){
    int n=read(records);
    display(records,n);
    sort(records,n);
    printf("\n Sorted data:\n");
    display(records,n);
    return 0;
}
