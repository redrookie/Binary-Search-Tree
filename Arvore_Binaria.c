#include "Arvore_Binaria.h"
#include<stdlib.h>

NODE* insere(int info, NODE *no){
    if(!no){
        NODE *novo = (NODE*)malloc(sizeof(NODE));
        novo->info=info;
        novo->esq=NULL;
        novo->dir=NULL;
        return novo;
    }
    else if(info>no->info){
        no->dir = insere(info,no->dir);
    }
    else if(info<no->info){
        no->esq = insere(info,no->esq);
    }
}

NODE* busca(int info, NODE *no){
    if(!no) return;
    if(no->info==info){
        return no;
    }
    if(info>no->info) return busca(info,no->dir);
    if(info<no->info) return busca(info,no->esq);
}

NODE *remove_no(NODE *a,int elem){
    if(!a) return;
    if(a->info>elem) a->esq = remove_no(a->esq,elem);
    if(a->info<elem) a->dir = remove_no(a->dir,elem);
    else{
        if(!a->esq && !a->dir){
            free(a);
            return NULL;
        }
        else if(!a->esq){
            NODE *b = a;
            a = a->dir;
            free(b);
        }
        else if(!a->dir){
            NODE *b = a;
            a = a->esq;
            free(b);
        }
        else{
            NODE *f = a->esq;
            while(f->dir) f = f->dir;
            a->info = f->info;
            f->info = elem;
            a->esq = remove_no(a->esq,elem);
        }
        return a;
    }
}

void imprime(NODE *no){
    if(!no) return;
    printf("%d ",no->info);
    imprime(no->esq);
    imprime(no->dir);
}

NODE* espelho(NODE *a){
    if(!a) return;
    NODE *mirror = (NODE*)malloc(sizeof(NODE));
    mirror->info = a->info;
    mirror->dir = espelho(a->esq);
    mirror->esq = espelho(a->dir);
    return mirror;
}

NODE* maior(NODE *a){
    if(!a) return;
    if(a->dir==NULL) return a;
    return maior(a->dir);
}

int igual(NODE *a,NODE *b){
    if(!a && !b) return 1;
    if(a->info!=b->info) return 0;
    return (igual(a->dir,b->dir) && igual(a->esq,b->esq));

}

NODE* retira_impares(NODE *a){
    if(!a) return;
    while(a && a->info%2!=0){
        if(!a->esq && !a->dir){
	    free(a);
	    return NULL;
	}
	a = remove_no(a,a->info);

    }
    if(!a) return;
    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);
    return a;
}

void colore(NODE *a){
    if(!a) return;
    colore_aux(a,0);
}

void colore_aux(NODE *a, int cor){
    if(!a) return;
    a->cor=cor;
    if(cor==0){
        colore_aux(a->esq,1);
        colore_aux(a->dir,1);
    }
    else if(cor==1){
        colore_aux(a->esq,0);
        colore_aux(a->dir,0);
    }
}

int ni(NODE *a){
    if(!a) return 0;
    if(!a->dir && !a->esq) return 0;
    return ni(a->esq)+ni(a->dir)+1;
}
int nf(NODE *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1;
    return nf(a->esq)+nf(a->dir);
}

int cmp_Aluno(const void *a, const void *b){
    TA *a1 = *(TA**)a;
    TA *a2 = *(TA**)b;
    if(a1->cr > a2->cr) return -1;
    if(a1->cr < a2->cr) return 1;
    else{
        if(a1->mat > a2->mat) return -1;
        if(a1->mat < a2->mat) return 1;
        return 0;
    }
}

