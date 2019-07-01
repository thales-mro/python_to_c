#include <stdio.h>

int main() {
	float operando1, operando2;
	float resultado;
	char operador;
	int numOps;

	scanf("%d", &numOps);

	while(numOps > 0) {
		numOps--;
		scanf("%f %c %f", &operando1, &operador, &operando2);
		
		if (operador == '/') {
			resultado = operando1 / operando2;
		} else if (operador == '*') {
			resultado = operando1 * operando2;
		} else if (operador == '+') {
			resultado = operando1 + operando2;
		} else if (operador == '-') {
			resultado = operando1 - operando2;
		} else {
			printf("Erro: operador não reconhecido\n");
			continue;
		}
		printf("%f\n", resultado);
	}

	return 0;
}
