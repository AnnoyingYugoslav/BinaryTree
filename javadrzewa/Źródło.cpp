
#include<iostream>
#include<cstdlib>
#include<array>
#include<chrono>
using namespace std;

static int liczba = 10;

struct drzewo
{
	int pself = 3;
	drzewo *pleft = NULL;
	drzewo *pright = NULL;
};

drzewo *korzen = NULL;


void printInorder(struct drzewo* node)
{
	if (node != NULL) {
		printInorder(node->pleft);
		cout << node->pself << " ";
		printInorder(node->pright);
	}
}
//good
void printPreorder(struct drzewo* node) {
	if (node != NULL) {
		cout << node->pself << " ";
		printInorder(node->pleft);
		printInorder(node->pright);
	}
}
//good
void Big(struct drzewo* node) {
	if (node != NULL) {
		cout << node->pself << " ";
		Big(node->pright);
	}
}
//good
void Small(struct drzewo* node) {
	if (node != NULL) {
		cout << node->pself << " ";
		Small(node->pleft);
	}
}
//good
void del1(struct drzewo* node, int a) {

}
//nope
void delAll(struct drzewo* node, int a) {

}
//nope
void printFrom(struct drzewo* node, int a) {
	
}
//nope
void balance(struct drzewo* node) {

}
//nope
void drzewo1(int lista[], int a) { //generowanie drzewa z podanej listy
	drzewo *klucz = NULL;
	bool end = true;
	for (int i = 0; i < a; ++i) {
		klucz = korzen;
		end = true;
		if (klucz == NULL) {
			klucz = new drzewo;
			klucz->pself = lista[i];
			korzen = klucz;
		}
		else {
			klucz = korzen;
			while (end) {
				if (klucz->pself >= lista[i]) {
					if (klucz->pleft == NULL) {
						klucz->pleft = new drzewo;
						klucz = klucz->pleft;
						klucz->pself = lista[i];
						end = false;
					}
					else {
						klucz = klucz->pleft;
					}
				}
				else if (klucz->pself < lista[i]) {
					if (klucz->pright == NULL) {
						klucz->pright = new drzewo;
						klucz = klucz->pright;
						klucz->pself = lista[i];
						end = false;
					}
					else {
						klucz = klucz->pright;
					}
				}
			}
		}
	}
}
//good


void sortowanie(int lista[]) {
}
//nope

int main() {
	int lista[] = {2,5,1,0,4,6};
	int a = sizeof(lista) / sizeof(lista[0]);
	drzewo1(lista, a);
	Small(korzen);
}