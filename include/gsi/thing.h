#ifndef GSI_THING_H_INCLUDED
#define GSI_THING_H_INCLUDED

#include "gsi/types/thing.h"
#include "gsi/annotations.h"
#include "cemdutil/dynamic_string.h"

struct thing_type {
    char name[100]; // nome do tipo
    owner String* description; // descrição do tipo
    double rarity; // raridade

    double monetary_value; // valor monetário
    double liquidity; // liquidez: taxa por unidade de tempo de desvalorização do valor monetário

    double utility_value; // valor útil
    double durability; // durabilidade: taxa por unidade de tempo de desvalorização do valor útil
};

struct thing {
    borrowed ThingType* type; // tipo
    char name[100]; // nome
    owner String* description; // descrição
};

/**
 * Inicializa um ThingType
 *
 * @param thing_type instância de ThingType a ser inicializado
 * @param name nome
 * @param description descrição
 * @param rarity raridade
 * @param monetary_value valor monetário
 * @param liquidity liquidez: taxa por unidade de tempo de desvalorização do valor monetário
 * @param utility_value valor útil
 * @param durability durabilidade: taxa por unidade de tempo de desvalorização do valor útil
 */
void thing_type_init(
    ThingType* thing_type,
    const char name[100],
    String* description,
    double rarity,
    double monetary_value,
    double liquidity,
    double utility_value,
    double durability
);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de ThingType
 *
 * @param _thing_type instância de ThingType
 */
void thing_type_clear(void* _thing_type);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de ThingType
 *
 * @param _thing_type instância de ThingType
 */
void thing_type_free(void* _thing_type);

/**
 * Inicializa um Thing
 *
 * @param thing instância de Thing a ser inicializado
 * @param type tipo
 * @param name nome
 * @param description descrição
 */
void thing_init(Thing* thing, ThingType* type, char name[100], String* description);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Thing
 *
 * @param _thing instância de Thing
 */
void thing_clear(void* _thing);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Thing
 *
 * @param _thing instância de Thing
 */
void thing_free(void* _thing);

#endif // GSI_THING_H_INCLUDED