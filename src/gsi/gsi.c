#include <stddef.h>
#include "gsi/gsi.h"
#include "gsi/person.h"

/**
 * Inicializa uma instância de GSI
 *
 * @param gsi instância de GSI a ser inicializada
 */
void gsi_init(GSI* gsi) {
    gsi->player = NULL;
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de GSI
 *
 * @param _gsi instância de GSI
 */
void gsi_clear(void* _gsi) {
    GSI* gsi = (GSI*) _gsi;

    Person* player = gsi->player;
    gsi->player = NULL;
    if (player != NULL)
        person_free(player);
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de GSI
 *
 * @param _gsi instância de GSI
 */
void gsi_free(void* _gsi) {
    gsi_clear(_gsi);
    free(_gsi);
}