#ifndef GSI_H_INCLUDED
#define GSI_H_INCLUDED

#include "gsi/types/gsi.h"
#include "gsi/types/person.h"
#include "gsi/annotations.h"

typedef struct gsi {
    owner struct person* player; // jogador
} GSI;

/**
 * Inicializa uma instância de GSI
 *
 * @param gsi instância de GSI a ser inicializada
 */
void gsi_init(GSI* gsi);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de GSI
 *
 * @param _gsi instância de GSI
 */
void gsi_clear(void* _gsi);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de GSI
 *
 * @param _gsi instância de GSI
 */
void gsi_free(void* _gsi);

#endif // GSI_H_INCLUDED