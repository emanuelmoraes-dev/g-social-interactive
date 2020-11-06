#ifndef GSI_PERSON_H_INCLUDED
#define GSI_PERSON_H_INCLUDED

#include "gsi_annotations.h"
#include "linked_list.h"
#include "dynamic_string.h"

typedef struct st_person {
    char name[100]; // nome completo de Person
    char nickname[20]; // nome curto para se referir a Person
    owner LinkedList* events; // LinkedList<borrowed Event>: lista de eventos que afeta ou afetou essa pessoa
    owner LinkedList* contacts; // LinkedList<owner Contact>: Lista de contatos com outras pessoas
} Person;

typedef struct st_relationship {
    owner String* description; // descrição do relacionamento
} Relationship;

typedef struct st_contact {
    borrowed Person* person; // Pessoa do contato
    owner LinkedList* relationships; // LinkedList<owner Relationship>: lista de relacionamentos mantidos para a pessoa do contato
} Contact;

/**
 * Inicializa um relacionamento
 *
 * @param relationship relacionamento a ser inicializado
 * @param description descrição do relacionamento
 */
void relationship_init(Relationship* relationship, const char* description);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Relationship
 *
 * @param relationship instância de Relationship
 */
void relationship_clear(Relationship* relationship);
void relationship_destructor(void* relationship);

/**
 * Inicializa um contato
 *
 * @param contact instância de Contact a ser inicializada
 * @param person instância de Person
 * @param relationships relacionamentos iniciais para o contato
 */
void contact_init(Contact* contact, Person* person, LinkedList* relationships);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Contact
 *
 * @param contact instância de Contact
 */
void contact_clear(Contact* contact);
void contact_destructor(void* contact);

/**
 * Inicializa uma pessoa
 *
 * @param person instância de Person a ser inicializada
 * @param name nome completo de Person
 * @param nickname nome curto para se referir a Person
 */
void person_init(Person* person, char name[100], char nickname[20]);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Person
 *
 * @param person instância de Person
 */
void person_clear(Person* person);
void person_destructor(void* person);

#endif // GSI_PERSON_H_INCLUDED