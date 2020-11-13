#include "cemdutil/linked_list.h"
#include "cemdutil/dynamic_string.h"

#include "gsi/event.h"

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
void event_init(Event* event, String* description, EventEffect* fromPerson, LinkedList* toPersons) {
    event->description = description;
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

    String* description = event->description;
    event->description = NULL;
    if (description != NULL)
        string_free(description);

    EventEffect* fromPerson = event->fromPerson;
    event->fromPerson = NULL;
    if (fromPerson != NULL)
        event_effect_free(fromPerson);

    LinkedList* toPersons = event->toPersons;
    event->toPersons = NULL;
    if (toPersons != NULL)
        linked_list_free_eraser_destructor(toPersons, event_effect_free);
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