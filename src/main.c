#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 20

// numero de primos e numero de threads simultaneas
int ndp, ndt;

void *primo (void* n){

	int *numero;
	int i, j=0;
	numero=(int*) n;
	for(i=2; i<(*numero); i++){
		if((*numero)%i==0){
			ndt--;
			return NULL;
		}
	}
	if(j==0 && (*numero)>1){
		ndp++;
	}
	ndt--;	
	return NULL;
}

int main() {
	pthread_t threads[MAX];
	int ndv=0, i;
	int *valores;
	char c='\0';
	ndp=0;ndv=0;
	valores=(int*) malloc(MAX*sizeof(int));

// lendo os numeros e descobrindo quantos sao
	while(c!='\n'){
		scanf("%d%c", &valores[ndv], &c);
		ndv++;
	}
// criando as threads
	for(i=0; i<ndv; i++){
		while(ndt>=4){
		}
		ndt++;
		pthread_create((&threads[i]), NULL, primo, (&valores[i]));
	}
// esperando as threads terminarem	
	for(i=0; i<ndv; i++){
		pthread_join(threads[i], NULL);
	}
	printf("%d\n", ndp);  	  	
 	free(valores);
	return 0;
}







