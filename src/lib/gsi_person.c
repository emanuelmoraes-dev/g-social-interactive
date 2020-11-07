#include <string.h>
#include "gsi_person.h"
#include "gsi_event.h"

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
 * @param _person instância de Person
 */
void person_clear(void* _person) {
    Person* person = (Person*) _person;
    strcpy(person->name, "");
    strcpy(person->nickname, "");

    if (person->events != NULL) {
        linked_list_free(person->events);
        person->events = NULL;
    }

    if (person->contacts != NULL) {
        linked_list_free_eraser_destructor(person->contacts, contact_free);
        person->contacts = NULL;
    }
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Person
 *
 * @param _person instância de Person
 */
void person_free(void* _person) {
    person_clear(_person);
    free(_person);
}

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
 * @param _relationship instância de Relationship
 */
void relationship_clear(void* _relationship) {
    Relationship* relationship = (Relationship*) _relationship;
    if (relationship->description != NULL) {
        string_free(relationship->description);
        relationship->description = NULL;
    }
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Relationship
 *
 * @param _relationship instância de Relationship
 */
void relationship_free(void* _relationship) {
    relationship_clear(_relationship);
    free(_relationship);
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
 * @param _contact instância de Contact
 */
void contact_clear(void* _contact) {
    Contact* contact = (Contact*) _contact;
    contact->person = NULL;

    if (contact->relationships != NULL) {
        linked_list_free_eraser_destructor(contact->relationships, relationship_free);
        contact->relationships = NULL;
    }
}

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Contact
 *
 * @param _contact instância de Contact
 */
void contact_free(void* _contact) {
    contact_clear(_contact);
    free(_contact);
}