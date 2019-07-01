#include <stdio.h>

#define MAX_SNAILS 100

int main() {
	int n, duration, limit, champion;
	int snails[MAX_SNAILS];

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &snails[i]);
	}

	scanf("%d", &duration);

	if (duration == 1) {
		limit = 100;
	} else if (duration == 2) {
		limit = 20;
	} else {
		limit = 10;
	}

	champion = 0;
	for(int i = 0; i < n; i++) {
		if (snails[i] > champion && snails[i] < limit) {
			champion = snails[i];
		}
	}
	printf("%d\n", champion);
	
	return 0;
}
