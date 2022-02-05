#include <stdio.h>

int main() {
	FILE* soubor = fopen("vystup.txt", "w");

	if (soubor == NULL) {
		printf("Chyba: Soubor nelze otevřít pro zápis.\n");
		return 1;
	}

	int ascii = 0x40;

	fprintf(soubor, "Znak-Hex\n");

	for (int i = 0; i < 26; i++) {
		ascii += 1;
		fwrite(&ascii, sizeof(int), 1, soubor);
		fprintf(soubor, "0x%x\n", ascii);
	}

	if (fclose(soubor) == EOF) {
		printf("Chyba: Soubor se nepodařilo otevřít.\n");
		return 1;
	}

	return(0);
}
