#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura do processo
typedef struct processo {
    int t_admissao;
    char *nome;
    int prioridade;
    int t_burst;
    int t_io;
    int id;
} TProcesso;

//Estrutura do no
typedef struct no {
    TProcesso *processo;
    struct no *prox;
} TNo;

//Estrutura da fila
typedef struct fila {
    TNo *inicio;
    TNo *fim;
} TFila;

//Função para ler os processos do arquivo
TProcesso *le_processo (FILE *in) {
    TProcesso *proc = (TProcesso *) malloc(sizeof(TProcesso));
    char linha[150];
    if (fgets (linha, 150, in) == NULL) {
        free(proc);
        return NULL;
    }
    char delimitador[] = " ";
    char *ptr;
    int cod;

    //quebra a linha
    ptr = strtok(linha, delimitador);
    cod = atoi(ptr);
    proc->t_admissao = cod;
    ptr = strtok(NULL, delimitador);
    proc->nome = strcpy(proc->nome, ptr);
    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    proc->prioridade = cod;
    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    proc->t_burst = cod;
    ptr = strtok(NULL, delimitador);
    cod = atoi(ptr);
    proc->t_io = cod;

    return proc;
}

//Escrevendo no arquivo de saída
void salva_processo(TProcesso *proc, FILE *out) {
    fprintf(out, "PID: %d, ", proc->id);
    fprintf(out, "Nome: %s, ", proc->nome);
    fprintf(out, "Tempo Admissão: %d, ", proc->t_admissao);
    fprintf(out, "Prioridade: %d\n", proc->prioridade);
}

void inicializa_fila(TFila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfilera(TProcesso *processo, TFila *f) {
    TNo *no = (TNo*) malloc(sizeof(TNo));
    if(no != NULL) {
        printf("Falha na alocação de memoria\n");
    } else {
        no->processo = processo;
        no->prox = NULL;
        if(f->inicio == NULL) {
            f->inicio = no;
        }
        f->fim = no;
    }
}

TProcesso *desenfilera(TFila *f) {
    TNo *no = f->inicio;
    TProcesso *proc;
    if (no != NULL) {
        f->inicio = no->prox;
        no->prox = NULL;
        proc = no->processo;
        free(no);
        if(f->inicio == NULL){
            f->fim = NULL;
        }
        return proc;
    } else {
        printf("A fila está vazia\n");
        exit(0);
    }
}

void escreve_fila(TFila *f) {
    TNo *no = f->inicio;
    if(no != NULL) {
        while (no != NULL) {
            salva_processo(no->processo);
            no = no->prox;
        }
    }
}

int main() {

}
    if(no != NULL) {
        printf("Falha na alocação de memoria\n");
    } else {
        no->processo = processo;
        no->prox = NULL;
        if(f->inicio == NULL) {
            f->inicio = no;
        }
        f->fim = no;
    }
}

TProcesso *desenfilera(TFila *f) {
    TNo *no = f->inicio;
    TProcesso *proc;
    if (no != NULL) {
        f->inicio = no->prox;
        no->prox = NULL;
        proc = no->processo;
        free(no);
        if(f->inicio == NULL){
            f->fim = NULL;
        }
        return proc;
    } else {
        printf("A fila está vazia\n");
        exit(0);
    }
}

void imprime_fila(TFila *f) {
    TNo *no = f->inicio;
    if(no != NULL) {
        while (no != NULL) {
            imprime_processo(no->processo);
            no = no->prox;
        }
    } else {
        printf("A fila está vazia\n");
    }
}

int main() {

}