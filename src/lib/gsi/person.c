#include <string.h>

#include "cemdutil/linked_list.h"
#include "cemdutil/dynamic_string.h"

#include "gsi/person.h"

/**
 * Inicializa uma pessoa
 *
 * @param person instância de Person a ser inicializada
 * @param name nome completo de Person
 * @param nickname nome curto para se referir a Person
 */
void person_init(Person* person, const char name[100], const char nickname[20]) {
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

    LinkedList* events = person->events;
    person->events = NULL;
    if (events != NULL)
        linked_list_free(events);

    LinkedList* contacts = person->contacts;
    person->contacts = NULL;
    if (contacts != NULL)
        linked_list_free_eraser_destructor(contacts, contact_free);
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
 * Inicializa tipo de relacionamento
 *
 * @param relationship_type instância de RelationshipType
 * @param name nome do tipo de relacionamento
 * @param description descrição do tipo de relacionamento
 */
void relationship_type_init(RelationshipType* relationship_type, const char name[100], String* description) {
    strcpy(relationship_type->name, name);
    relationship_type->description = description;
}

/**
 * Libera da memória os espaços alocaos, porém NÃO desaloca da memória a instância de RelationshipType
 *
 * @param _relationship_type instância de RelationshipType
 */
void relationship_type_clear(void* _relationship_type) {
    RelationshipType* relationship_type = (RelationshipType*) _relationship_type;
    strcpy(relationship_type->name, "");

    String* description = relationship_type->description;
    relationship_type->description = NULL;
    if (description != NULL)
        string_free(description);
}

/**
 * Libera da memória os espaços alocaos e desaloca da memória a instância de RelationshipType
 *
 * @param _relationship_type instância de RelationshipType
 */
void relationship_type_free(void* _relationship_type) {
    relationship_type_clear(_relationship_type);
    free(_relationship_type);
}

/**
 * Inicializa um relacionamento
 *
 * @param relationship relacionamento a ser inicializado
 * @param relationship_type tipo do relacionamento
 * @param history_events lista de relacionamentos mantidos para a pessoa do contato
 */
void relationship_init(Relationship* relationship, RelationshipType* relationship_type, LinkedList* history_events) {
    if (history_events == NULL)
        history_events = new_linked_list();

    relationship->relationship_type = relationship_type;
    relationship->history_events = history_events;
}

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Relationship
 *
 * @param _relationship instância de Relationship
 */
void relationship_clear(void* _relationship) {
    Relationship* relationship = (Relationship*) _relationship;
    relationship->relationship_type = NULL;

    LinkedList* history_events = relationship->history_events;
    relationship->history_events = NULL;
    if (history_events != NULL)
        linked_list_free(history_events);
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

    LinkedList* relationships = contact->relationships;
    contact->relationships = NULL;
    if (relationships != NULL)
        linked_list_free_eraser_destructor(relationships, relationship_free);
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