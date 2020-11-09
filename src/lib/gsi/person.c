#include <string.h>

#include "cemdutil/linked_list.h"
#include "cemdutil/dynamic_string.h"

#include "gsi/annotations.h"
#include "gsi/person.h"

struct st_person {
    char name[100]; // nome completo de Person
    char nickname[20]; // nome curto para se referir a Person
    owner LinkedList* events; // LinkedList<borrowed Event>: lista de eventos que afeta ou afetou essa pessoa
    owner LinkedList* contacts; // LinkedList<owner Contact>: lista de contatos com outras pessoas
};

struct st_relationship_type {
    char name[100]; // nome do tipo de relacionamento
    owner String* description; // descrição do tipo de relacionamento
};

struct st_relationship {
    borrowed RelationshipType* relationship_type; // tipo do relacionamento
    owner LinkedList* history_events; // LinkedList<borrowed Event>: lista de eventos que ocorreram entre a pessoa e o contato
};

struct st_contact {
    borrowed Person* person; // pessoa do contato
    owner LinkedList* relationships; // LinkedList<owner Relationship>: lista de relacionamentos mantidos para a pessoa do contato
};

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
 * Inicializa tipo de relacionamento
 *
 * @param relationship_type instância de RelationshipType
 * @param name nome do tipo de relacionamento
 * @param description descrição do tipo de relacionamento
 */
void relationship_type_init(RelationshipType* relationship_type, const char* name, const char* description) {
    strcpy(relationship_type->name, name);
    relationship_type->description = new_string(description);
}

/**
 * Libera da memória os espaços alocaos, porém NÃO desaloca da memória a instância de RelationshipType
 *
 * @param _relationship_type instância de RelationshipType
 */
void relationship_type_clear(void* _relationship_type) {
    RelationshipType* relationship_type = (RelationshipType*) _relationship_type;
    strcpy(relationship_type->name, "");

    if (relationship_type->description != NULL) {
        string_free(relationship_type->description);
        relationship_type->description = NULL;
    }
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

    if (relationship->relationship_type != NULL)
        relationship->relationship_type = NULL;

    if (relationship->history_events != NULL) {
        linked_list_free(relationship->history_events);
        relationship->history_events = NULL;
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