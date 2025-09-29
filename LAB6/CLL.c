#include <stdio.h>
#include <stdlib.h>

typedef struct N {int d; struct N *n;}N;
N *f=0,*l=0;

void ins(int v){
    N *t=malloc(sizeof(N)); t->d=v;
    if(!f) f=l=t, l->n=f;
    else l->n=t, l=t, l->n=f;
}

void delbeg(){
    if(!f) return;
    if(f==l) free(f), f=l=0;
    else {N*t=f; f=f->n; l->n=f; free(t);}
}

void delend(){
    if(!f) return;
    if(f==l) free(f), f=l=0;
    else {N*t=f; while(t->n!=l) t=t->n; t->n=f; free(l); l=t;}
}

void disp(){
    if(!f){printf("Empty\n"); return;}
    N*t=f; do{printf("%d ",t->d); t=t->n;}while(t!=f);
    printf("\n");
}

int main(){
    ins(10); disp();
    ins(20); disp();
    ins(30); disp();
    delbeg(); disp();
    delend(); disp();
}
