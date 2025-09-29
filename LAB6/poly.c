#include <stdio.h>
#include <stdlib.h>

typedef struct P{int c,e;struct P *p,*n;}P;

P*ins(P*h,int c,int e){
    P*t=malloc(sizeof(P)); t->c=c;t->e=e;t->p=t->n=0;
    if(!h) return t;
    P*x=h,*pr=0; 
    while(x && x->e>e) pr=x,x=x->n;
    if(x && x->e==e){x->c+=c;free(t);return h;}
    t->n=x; t->p=pr;
    if(pr) pr->n=t; else h=t;
    if(x) x->p=t;
    return h;
}

P*add(P*a,P*b){
    P*r=0;
    while(a||b){
        if(b && (!a||b->e>a->e)) r=ins(r,b->c,b->e), b=b->n;
        else if(a && (!b||a->e>b->e)) r=ins(r,a->c,a->e), a=a->n;
        else r=ins(r,a->c+b->c,a->e), a=a->n, b=b->n;
    }
    return r;
}

void disp(P*h){
    while(h){printf("%dx^%d ",h->c,h->e);h=h->n;}
    printf("\n");
}

int main(){
    P*a=0,*b=0,*s;
    a=ins(a,3,3); a=ins(a,2,2); a=ins(a,1,0);
    b=ins(b,4,3); b=ins(b,5,1); b=ins(b,6,0);
    s=add(a,b);
    disp(a); disp(b); disp(s);
}
