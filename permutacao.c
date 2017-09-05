#include <stdio.h>
#include <stdlib.h>

void troca(int vetor[], int indiceAtual, int proximoIndice);
void permutacao(int vetor[], int indiceAtual, int tamanhoDoVetor, int posicaoDaPermutacaoDesejada, int *posicaoAtual);
void imprimirResultado(int vetor[], int tamanhoDoVetor);

int main () {
  int vetor[] = {1, 2, 3, 4};
  int tamanhoDoVetor = sizeof(vetor) / sizeof(int);
  int posicaoDaPermutacaoDesejada = tamanhoDoVetor;
  int posicaoInicial = 0;
  int *posicaoAtual = &posicaoInicial;

  permutacao(vetor, 0, tamanhoDoVetor - 1, posicaoDaPermutacaoDesejada, posicaoAtual);
  return 0;
}

void troca(int vetor[], int indiceAtual, int proximoIndice)
{
	int aux = vetor[indiceAtual];
	vetor[indiceAtual] = vetor[proximoIndice];
	vetor[proximoIndice] = aux;
}

void permutacao(int vetor[], int indiceAtual, int tamanhoDoVetor, int posicaoDaPermutacaoDesejada, int *posicaoAtual) {
  if (indiceAtual == tamanhoDoVetor) {
    *posicaoAtual += 1;
    if (posicaoDaPermutacaoDesejada == *posicaoAtual) {
      imprimirResultado(vetor, tamanhoDoVetor);
      return;
    }
  } else {
    for (int indice = indiceAtual; indice <= tamanhoDoVetor; indice++) {
      troca(vetor, indiceAtual, indice);
      permutacao(vetor, indiceAtual + 1, tamanhoDoVetor, posicaoDaPermutacaoDesejada, posicaoAtual);
      troca(vetor, indiceAtual, indice);
    }
  }
}

void imprimirResultado(int vetor[], int tamanhoDoVetor) {
  for(int indice = 0; indice <= tamanhoDoVetor; indice++) {
    printf("%d ", vetor[indice]);
  }
}