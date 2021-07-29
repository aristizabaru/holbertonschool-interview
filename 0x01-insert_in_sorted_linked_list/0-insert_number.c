#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
listint_t *insert_node(listint_t **head, int number) {
    listint_t *new_node = NULL;
    listint_t *temp = NULL;

    if ((head == NULL)) {
        return (NULL);
    }
    /* add first node if there's no other*/
    if (*head == NULL) {
        new_node = create_node(number);
        *head = new_node;
        return (new_node);
    }
    temp = *head;
    /* add first node */
    if (number <= temp->n) {
        new_node = create_node(number);
        new_node->next = temp;
        *head = new_node;
        return (new_node);
    }

    /* add sorted node */
    /* traverse list */
    while(temp->next) {
        if (number <= temp->next->n) {
            break;
        }
        temp = temp->next;
    }

    /* add last node */
    if (!temp->next) {
        new_node = create_node(number);
        temp->next = new_node;
        return (new_node);
    } 
    /* add node in the middle */
    new_node = create_node(number);
    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);

}

listint_t *create_node(int number) {
    listint_t *new_node = NULL;

    new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
    
    new_node->n = number;
    new_node->next=NULL;

    return (new_node);
}
