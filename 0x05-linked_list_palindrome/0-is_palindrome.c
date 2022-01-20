#include "lists.h"

/**
 * is_palindrome - checks if a linked list is palindrome
 * @head: linked list head
 * Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head)
{
        int length = list_length(head);
        int h_length = length / 2;
        int i, if_palindrome = 1;
        listint_t *r_head;
        listint_t *current = *head;
        listint_t *c_reversed;

        r_head = *head;
        for (i = 0; i < h_length; i++)
                r_head = r_head->next;
        if (length % 2 != 0)
                r_head = r_head->next;
        r_head = reversed(&r_head);
        c_reversed = r_head;
        current = *head;
        while (c_reversed != NULL)
        {
                if (c_reversed->n != current->n)
                        if_palindrome = 0;
                c_reversed = c_reversed->next;
                current = current->next;
        }
        return (if_palindrome);
}

/**
 * list_length - Get the length of a linked list
 * @head: linked list head
 * Return: lenght
 */

int list_length(listint_t **head)
{
        int i;
        listint_t *current = *head;

        for (i = 0; current != NULL; i++)
                current = current->next;
        return (i);
}

/**
 * reversed - function that reversed a linked list
 * @head: double pointer
 * Return: Address of the new element
 */

listint_t *reversed(listint_t **head)
{
        listint_t *prev = NULL, *current = *head, *next = NULL;

        while (current != NULL)
        {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
        }
        *head = prev;
        return (*head);
}
