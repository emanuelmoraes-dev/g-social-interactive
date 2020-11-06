#include <string.h>
#include "gsi_person.h"
#include "gsi_event.h"

/**
 * Inicializa um relacionamento
 *
 * @param relationship relacionamento a ser inicializado
 * @param description descrição do relacionamento
 */
void relationship_init(Relationship* relationship, const char* description) {
    relationship->description = new_string(description);
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Relationship
 *
 * @param relationship instância de Relationship
 */
void relationship_clear(Relationship* relationship) {
    if (relationship->description != NULL) {
        string_clear(relationship->description);
        free(relationship->description);
        relationship->description = NULL;
    }
}

/**
 * Inicializa um contato
 *
 * @param contact instância de Contact a ser inicializada
 * @param person instância de Person
 * @param relationships relacionamentos iniciais para o contato
 */
void contact_init(Contact* contact, Person* person, LinkedList* relationships) {
    if (relationships == NULL)
        relationships = new_linked_list();

    contact->person = person;
    contact->relationships = relationships;
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Contact
 *
 * @param contact instância de Contact
 */
void contact_clear(Contact* contact) {
    contact->person = NULL;

    if (contact->relationships != NULL) {
        linked_list_clear_eraser_destructor(contact->relationships, relationship_clear);
        free(contact->relationships);
        contact->relationships = NULL;
    }
}

/**
 * Inicializa uma pessoa
 *
 * @param person instância de Person a ser inicializada
 * @param name nome completo de Person
 * @param nickname nome curto para se referir a Person
 */
void person_init(Person* person, char name[100], char nickname[20]) {
    strcpy(person->name, name);
    strcpy(person->nickname, nickname);
    person->events = new_linked_list();
    person->contacts = new_linked_list();
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Person
 *
 * @param person instância de Person
 */
void person_clear(Person* person) {
    strcpy(person->name, "");
    strcpy(person->nickname, "");

    if (person->events != NULL) {
        linked_list_clear(person->events);
        free(person->events);
        person->events = NULL;
    }

    if (person->contacts != NULL) {
        linked_list_clear_eraser_destructor(person->contacts, contact_clear);
        free(person->contacts);
        person->contacts = NULL;
    }
}