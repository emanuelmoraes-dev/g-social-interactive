#ifndef GSI_EVENT_H_INCLUDED
#define GSI_EVENT_H_INCLUDED

#include "gsi_annotations.h"
#include "gsi_person.h"
#include "linked_list.h"
#include "dynamic_string.h"

typedef struct st_event_effects {
    borrowed Person* person; // Pessoa afetada pelo evento
} EventEffect;

typedef struct st_event {
    owner String* description; // Descrição do evento
    owner EventEffect* fromPerson; // Efeitos para a pessoa que gerou o evento
    owner LinkedList* toPersons; // LinkedList<owner EventEffect>: Efeitos para outras pessoas
} Event;

/**
 * Inicializa um EventEffect
 *
 * @param effect instância de EventEffect a ser inicializado
 * @param person Pessoa afetada pelo evento
 */
void event_effect_init(EventEffect* effect, Person* person);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de EventEffect
 *
 * @param effect instância de EventEffect
 */
void event_effect_clear(EventEffect* effect);

/**
 * Inicializa Event
 *
 * @param event instância de Event a ser inicializado
 * @param description descrição do evento
 * @param fromPerson efeitos para a pessoa que gerou o evento
 * @param toPersons efeitos para as outras pessoas
 */
void event_init(Event* event, const char* description, EventEffect* fromPerson, LinkedList* toPersons);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Event
 *
 * @param event instância de Event
 */
void event_clear(Event* event);

#endif // GSI_EVENT_H_INCLUDED