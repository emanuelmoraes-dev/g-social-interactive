#include "cemdutil/linked_list.h"
#include "cemdutil/dynamic_string.h"

#include "gsi/annotations.h"
#include "gsi/event.h"
#include "gsi/person.h"

struct st_event_effect {
    borrowed Person* person; // Pessoa afetada pelo evento
};

struct st_event {
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
void event_effect_init(EventEffect* effect, Person* person) {
    effect->person = person;
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de EventEffect
 *
 * @param _effect instância de EventEffect
 */
void event_effect_clear(void* _effect) {
    EventEffect* effect = (EventEffect*) _effect;
    effect->person = NULL;
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de EventEffect
 *
 * @param _effect instância de EventEffect
 */
void event_effect_free(void* _effect) {
    event_effect_clear(_effect);
    free(_effect);
}

/**
 * Inicializa Event
 *
 * @param event instância de Event a ser inicializado
 * @param description descrição do evento
 * @param fromPerson efeitos para a pessoa que gerou o evento
 * @param toPersons efeitos para as outras pessoas
 */
void event_init(Event* event, const char* description, EventEffect* fromPerson, LinkedList* toPersons) {
    event->description = new_string(description);
    event->fromPerson = fromPerson;
    event->toPersons = toPersons;
}

/**
 * Libera da memória espaços alocados, porém NÃO desaloca da memória a instância de Event
 *
 * @param _event instância de Event
 */
void event_clear(void* _event) {
    Event* event = (Event*) _event;
    if (event->description != NULL) {
        string_free(event->description);
        event->description = NULL;
    }

    if (event->fromPerson != NULL) {
        event_effect_free(event->fromPerson);
        event->fromPerson = NULL;
    }

    if (event->toPersons != NULL) {
        linked_list_free_eraser_destructor(event->toPersons, event_effect_free);
        event->toPersons = NULL;
    }
}

/**
 * Libera da memória espaços alocados e desaloca da memória a instância de Event
 *
 * @param _event instância de Event
 */
void event_free(void* _event) {
    event_clear(_event);
    free(_event);
}