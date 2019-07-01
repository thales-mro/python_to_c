#include <stdio.h>

#define MAX_ALUNOS 100

float read_mean(int m) {
	float mean, grade;
	mean = 0;
	for(int i = 0; i < m; i++) {
		scanf("%f", &grade);
		mean += grade;
	} 
	mean = mean / m;
	return mean;
}

void read_grades(float vector[], int n, int m) {
	for(int i = 0; i < n; i++) {
		vector[i] = read_mean(m);
	}
}


float find_greatest(float vector[], int n) {
	float greatest = 0.0f;
	for(int i = 0; i < n; i++) {
		if (vector[i] > greatest)
			greatest = vector[i];
	}
	return greatest;
}

void recalc_t(float vector[], int n) {
	float greatest = find_greatest(vector, n);
	for(int i = 0; i < n; i++) {
		vector[i] = 10*vector[i]/greatest;
	}
}

void recalc_p(float vector[], int n, float factor) {
	for(int i = 0; i < n; i++) {
		vector[i] *= factor;
	}
}	

void calc_mean_grades(float mean[], float v1[], float v2[], int n) {
	for(int i = 0; i < n; i++) {
		mean[i] = (v1[i] + v2[i])/2;
		printf("%.1f\n", mean[i]);
	}
}

float calc_mean(float vector[], int n) {
	float mean = 0.0f;
	for(int i = 0; i < n; i++) {
		mean += vector[i];
	}
	return mean/n;
}

int main() {
	int n;
	float p[MAX_ALUNOS], t[MAX_ALUNOS], mean[MAX_ALUNOS];
	
	scanf("%d", &n);

	read_grades(p, n, 3);
	read_grades(t, n, 2);

	recalc_p(p, n, 1.1);
	recalc_t(t, n);

	calc_mean_grades(mean, p, t, n);
	
	printf("Max P: %.1f\n", find_greatest(p, n));
	printf("Max T: %.1f\n", find_greatest(t, n));
	printf("Média P: %.1f\n", calc_mean(p, n));
	printf("Média T: %.1f\n", calc_mean(t, n));
	return 0;

}
