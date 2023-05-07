#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct hokejista
{
	char jmeno[20];
	int pocetGolu;
	int pocetAsistenci;

}HOKEJISTA;

int spocitejKanadskeBody(HOKEJISTA hokejista) {
	return hokejista.pocetGolu + hokejista.pocetAsistenci;
}

int main(void) {

	FILE* f = fopen("hokejisti.txt", "r");
	if (f == NULL) {
		printf("CHYBA CTENI\n");
		return 1;
	}
	int n;
	fscanf(f, "%d", &n);
	HOKEJISTA* arr = malloc(sizeof(HOKEJISTA) * n);
	if (arr == NULL) {
		printf("CHYBA ALLOKOVANI\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		fscanf(f, "%s", arr[i].jmeno);
		fscanf(f, "%d", &arr[i].pocetGolu);
		fscanf(f, "%d", &arr[i].pocetAsistenci);
	}
	printf("VSECHNY:\n");
	for (int i = 0; i < n; i++) {
		printf("%s %d %d\n", arr[i].jmeno,arr[i].pocetGolu,arr[i].pocetAsistenci);
	}
	printf("VICE GOLU NEZ ASSISTS:\n");
	for (int i = 0; i < n; i++) {
		if(arr[i].pocetGolu>arr[i].pocetAsistenci) printf("%s %d %d\n", arr[i].jmeno, arr[i].pocetGolu, arr[i].pocetAsistenci);
	}
	int pocet = 0;
	for (int i = 0; i < n; i++) {
		int j = spocitejKanadskeBody(arr[i]);
		if (j > pocet) pocet = j;
	}
	printf("NEJVIC: %d\n", pocet);
	fclose(f);
	free(arr);
	return 0;
}