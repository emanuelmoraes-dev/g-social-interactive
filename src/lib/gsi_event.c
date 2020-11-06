#include "gsi_event.h"

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
 * @param effect instância de EventEffect
 */
void event_effect_clear(EventEffect* effect) {
    effect->person = NULL;
} void event_effect_destructor(void* effect) {
    event_effect_clear((EventEffect*) effect);
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
 * @param event instância de Event
 */
void event_clear(Event* event) {
    if (event->description != NULL) {
        string_clear(event->description);
        free(event->description);
        event->description = NULL;
    }

    if (event->fromPerson != NULL) {
        event_effect_clear(event->fromPerson);
        free(event->fromPerson);
        event->fromPerson = NULL;
    }

    if (event->toPersons != NULL) {
        linked_list_clear_eraser_destructor(event->toPersons, event_effect_destructor);
        free(event->toPersons);
        event->toPersons = NULL;
    }
} void event_destructor(void* event) {
    event_clear((Event*) event);
}