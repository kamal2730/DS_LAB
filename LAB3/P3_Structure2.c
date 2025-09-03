#include <stdio.h>
struct data{
    char name[50];
    int roll_no;
    float marks;

}records[100];
int read(struct data *r){
    int n;
    printf("n:");
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        getchar();
        printf("\nname roll_no marks:");
        scanf("%s%i%f",&r[i].name,&r[i].roll_no,&r[i].marks);
    }
    return n;
}
void display(struct data *r,int n){
    for(int i=0;i<n;i++){
        printf("\nname:%s roll_no:%i marks:%f",r[i].name,r[i].roll_no,r[i].marks);
    }
}
void max_marks(struct data *r,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if((*(r+i)).marks>(*(r+max)).marks){max=i;}
    }
    printf("name:%s roll_no:%i marks:%f",r[max].name,r[max].roll_no,r[max].marks);
}

int main(){
    int n=read(records);
    display(records,n);
    printf("\n student with max marks:");
    max_marks(records,n);
    return 0;
}
