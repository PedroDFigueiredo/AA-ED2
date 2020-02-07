// gcc -o main main.c hashTable.c linkedList.c client.c fileManager.c && ./main


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"
#include "fileManager.h"

// todo remove this
// #include <conio.h>


int main(int argc, char** argv) {
	int size = 15;
	char *str[28] = {"a_name", "b_name", "c_name", "e_name", "f_name", "g_name", "h_name", "i_name", "j_name", "k_name", "l_name", "m_name", "n_name", "o",
	"a2_name", "b2_name", "c2_name", "e2_name", "f2_name", "g2_name", "h2_name", "i2_name", "j2_name", "k2_name", "l2_name", "m2_name", "n2_name", "o2"};

	HashTable *hashTable = HashTable_new(7);
	for (int i = 0; i < size; i++) {
		int codCLinet = i+1;
		// INSERIR CLIENTE
		hashTable_insert(hashTable, codCLinet, str[i]);
	};

	// BUSCAR CLIENTE na hash
	Client *client = hashTable_get(hashTable, 23);

	hashTable_fm_write(hashTable, 
		"compartimento_hash.dat", 
		"clientes.dat");
	
	HashTable *newHashTable = hashTable_fm_read(
		"compartimento_hash.dat", 
		"clientes.dat");

	// DELETAR CLIENTE na hash
	hashTable_delete(hashTable, 10);

	hashTable_fm_write(hashTable, 
		"compartimento_hash.dat", 
		"clientes.dat");
	
	newHashTable = hashTable_fm_read(
		"compartimento_hash.dat", 
		"clientes.dat");

	return 0;
};
