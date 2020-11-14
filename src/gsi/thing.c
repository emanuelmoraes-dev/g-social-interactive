#include <string.h>
#include "gsi/thing.h"

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
) {
    strcpy(thing_type->name, name);
    thing_type->description = description;
    thing_type->rarity = rarity;
    thing_type->monetary_value = monetary_value;
    thing_type->liquidity = liquidity;
    thing_type->utility_value = utility_value;
    thing_type->durability = durability;
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de ThingType
 *
 * @param _thing_type instância de ThingType
 */
void thing_type_clear(void* _thing_type) {
    ThingType* thing_type = (ThingType*) _thing_type;
    strcpy(thing_type->name, "");

    String* description = thing_type->description;
    thing_type->description = NULL;
    if (description != NULL)
        string_free(description);
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de ThingType
 *
 * @param _thing_type instância de ThingType
 */
void thing_type_free(void* _thing_type) {
    thing_type_clear(_thing_type);
    free(_thing_type);
}

/**
 * Inicializa um Thing
 *
 * @param thing instância de Thing a ser inicializado
 * @param type tipo
 * @param name nome
 * @param description descrição
 */
void thing_init(Thing* thing, ThingType* type, char name[100], String* description) {
    thing->type = type;
    strcpy(thing->name, name);
    thing->description = description;
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Thing
 *
 * @param _thing instância de Thing
 */
void thing_clear(void* _thing) {
    Thing* thing = (Thing*) _thing;
    strcpy(thing->name, "");
    thing->type = NULL;

    String* description = thing->description;
    thing->description = NULL;
    if (description != NULL)
        string_free(description);
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Thing
 *
 * @param _thing instância de Thing
 */
void thing_free(void* _thing) {
    thing_clear(_thing);
    free(_thing);
}