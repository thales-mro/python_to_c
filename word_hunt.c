#include <stdio.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_WORD 15

int str_len(char word[]) {
	int length = 0;
	while(word[length] != '\0') {
		length++;
	}
	return length;
}

void copy_inverse(char word[], char inverse[]) {
	int word_length = str_len(word);
	for(int i = 0; i <= word_length/2; i++) {
		inverse[i] = word[word_length -i -1];
		inverse[word_length -i - 1] = word[i];
	}
	inverse[word_length] = '\0';
}

void read_matrix(char matrix[MAX_HEIGHT][MAX_WIDTH], int m, int n) {
	char letter;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			scanf(" %c", &letter);
			matrix[i][j] = letter;
		}
	}

}

void create_dot_matrix(char matrix[MAX_HEIGHT][MAX_WIDTH], int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			matrix[i][j] = '.';
		}
	}
}

void print_matrix(char matrix[MAX_HEIGHT][MAX_WIDTH], int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}

void mark_horizontal_occurences(char word[], char matrix[MAX_HEIGHT][MAX_WIDTH], char answer[MAX_HEIGHT][MAX_WIDTH], int m, int n, int i, int j) {
	int word_length = str_len(word);
	if (j + word_length - 1 >= n)
		return;

	for(int idx = 0; idx < word_length; idx++) {
		if (word[idx] != matrix[i][idx + j])
			return;
	}

	for(int k = j; k < j + word_length; k++) {
		answer[i][k] = matrix[i][k];
	}
}

void mark_vertical_occurences(char word[], char matrix[MAX_HEIGHT][MAX_WIDTH], char answer[MAX_HEIGHT][MAX_WIDTH], int m, int n, int i, int j) {
	int word_length = str_len(word);
	if (i + word_length - 1 >= m)
		return;
	
	for(int idx = 0; idx < word_length; idx++) {
		if (word[idx] != matrix[idx + i][j])
			return;
	}

	for(int k = i; k < i + word_length; k++) {
		answer[k][j] = matrix[k][j];
	}
}

void mark_diagonal_occurences(char word[], char matrix[MAX_HEIGHT][MAX_WIDTH], char answer[MAX_HEIGHT][MAX_WIDTH], int m, int n, int i, int j) {
	int word_length = str_len(word);
	if ((j + word_length - 1 >= n) || (i + word_length - 1 >= m))
		return;
	
	for(int idx = 0; idx < word_length; idx++) {
		if (word[idx] != matrix[idx + i][idx + j])
			return;
	}

	for(int k = i, l = j; k < i + word_length; k++, l++) {
		answer[k][l] = matrix[k][l];
	}

}

void mark_occurences(char word[], char matrix[MAX_HEIGHT][MAX_WIDTH], char answer[MAX_HEIGHT][MAX_WIDTH], int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			mark_horizontal_occurences(word, matrix, answer, m, n, i, j);
			mark_vertical_occurences(word, matrix, answer, m, n, i, j);
			mark_diagonal_occurences(word, matrix, answer, m, n, i, j);
		}
	}
}

int main() {

	int m, n, w;
	char matrix[MAX_HEIGHT][MAX_WIDTH], answer[MAX_HEIGHT][MAX_WIDTH];
	char word[MAX_WORD], inverse_word[MAX_WORD];

	scanf("%d %d", &m, &n);
	read_matrix(matrix, m, n);
	create_dot_matrix(answer, m, n);
	
	scanf("%d", &w);
	for(int i = 0; i < w; i++) {
		scanf("%s", word);
		mark_occurences(word, matrix, answer, m, n);
		copy_inverse(word, inverse_word);
		mark_occurences(inverse_word, matrix, answer, m, n);
	}

	print_matrix(answer, m, n);

	return 0;
}
