#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED
typedef struct ArvoreBinaria{
    int info;
    struct ArvoreBinaria *esq,*dir;
    int cor;

}NODE;

typedef struct Aluno{
    int mat;
    double cr;
}TA;

NODE* insere(int info, NODE *no);
NODE* busca(int info, NODE *no);
void imprime(NODE *no);
NODE* espelho(NODE *a);
NODE* maior(NODE *a);
int igual(NODE *a,NODE *b);
NODE *remove_no(NODE *a,int elem);
NODE* retira_impares(NODE *a);
void colore(NODE *a);
void colore_aux(NODE *a,int cor);
int ni(NODE *a);
int nf(NODE *a);
#endif // ARVORE_BINARIA_H_INCLUDED
