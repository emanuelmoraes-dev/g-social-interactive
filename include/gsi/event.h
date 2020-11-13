#ifndef GSI_EVENT_H_INCLUDED
#define GSI_EVENT_H_INCLUDED

#include "gsi/annotations.h"
#include "types/event.h"
#include "types/person.h"

#include "cemdutil/linked_list.h"

struct event_effect {
    borrowed Person* person; // Pessoa afetada pelo evento
};

struct event {
    owner String* description; // Descrição do evento
    owner EventEffect* fromPerson; // Efeitos para a pessoa que gerou o evento
    owner LinkedList* toPersons; // LinkedList<owner EventEffect>: Efeitos para outras pessoas
};

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
 * @param _effect instância de EventEffect
 */
void event_effect_clear(void* _effect);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de EventEffect
 *
 * @param _effect instância de EventEffect
 */
void event_effect_free(void* _effect);

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
 * @param _event instância de Event
 */
void event_clear(void* _event);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Event
 *
 * @param _event instância de Event
 */
void event_free(void* _event);

#endif // GSI_EVENT_H_INCLUDED