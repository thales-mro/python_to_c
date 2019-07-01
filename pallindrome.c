#include <stdio.h>
#include <string.h>

#define MAX_WORD 15

int str_len(char string[]) {
	int len = 0;
	while(string[len] != '\0') {
		len++;
	}
	return len;

}

void copy_inverse(char original[], char inverse[]) {
	int i, j = 0;
	i = str_len(original) - 1;
	while (i >= 0) {
		inverse[j] = original[i];
		i--;
		j++;
	}
	inverse[j] = '\0';
}

int main() {
	char word[MAX_WORD], inverse[MAX_WORD];

	scanf("%s", word);
	copy_inverse(word, inverse);
	printf("String length: %d, inverse: %s, palindrome: %d\n", str_len(word), inverse, strcmp(word, inverse));
}
