#ifndef GSI_PERSON_H_INCLUDED
#define GSI_PERSON_H_INCLUDED

#include "types/person.h"

#include "cemdutil/linked_list.h"

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
 * @param _person instância de Person
 */
void person_clear(void* _person);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Person
 *
 * @param _person instância de Person
 */
void person_free(void* _person);

/**
 * Inicializa tipo de relacionamento
 *
 * @param relationship_type instância de RelationshipType
 * @param name nome do tipo de relacionamento
 * @param description descrição do tipo de relacionamento
 */
void relationship_type_init(RelationshipType* relationship_type, const char* name, const char* description);

/**
 * Libera da memória os espaços alocaos, porém NÃO desaloca da memória a instância de RelationshipType
 *
 * @param _relationship_type instância de RelationshipType
 */
void relationship_type_clear(void* _relationship_type);

/**
 * Libera da memória os espaços alocaos e desaloca da memória a instância de RelationshipType
 *
 * @param _relationship_type instância de RelationshipType
 */
void relationship_type_free(void* _relationship_type);

/**
 * Inicializa um relacionamento
 *
 * @param relationship relacionamento a ser inicializado
 * @param relationship_type tipo do relacionamento
 * @param history_events lista de relacionamentos mantidos para a pessoa do contato
 */
void relationship_init(Relationship* relationship, RelationshipType* relationship_type, LinkedList* history_events);

/**
 * Libera da memória os espaços alocados, porém NÃO desaloca da memória a instância de Relationship
 *
 * @param _relationship instância de Relationship
 */
void relationship_clear(void* _relationship);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Relationship
 *
 * @param _relationship instância de Relationship
 */
void relationship_free(void* _relationship);

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
 * @param _contact instância de Contact
 */
void contact_clear(void* _contact);

/**
 * Libera da memória os espaços alocados e desaloca da memória a instância de Contact
 *
 * @param _contact instância de Contact
 */
void contact_free(void* _contact);

#endif // GSI_PERSON_H_INCLUDED