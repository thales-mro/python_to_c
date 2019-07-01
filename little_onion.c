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

void little_onion(char original[], char little_onion[]) {
	int length, j = 0, i = 0, last_was_r = 0;
	length = str_len(original) - 1;
	while(original[j] != '\0') {
		if (original[j] != 'R') {
			little_onion[i] = original[j];
			i++;
			last_was_r = 0;
		} else if (!last_was_r) {
			little_onion[i] = 'L';
			i++;
			last_was_r = 1;
		}
		j++;
	}
	little_onion[i] = '\0';
}

int main() {
	char word[MAX_WORD], little_o[MAX_WORD];

	scanf("%s", word);
	little_onion(word, little_o);
	printf("%s\n", little_o);
}
