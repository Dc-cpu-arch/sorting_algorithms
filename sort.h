#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Double linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void pivot_recursion(int *array, int low, int high, size_t size);
int splition(int *array, int low, int high, size_t size);
void selection_sort(int *array, size_t size);
listint_t *change(listint_t *larger, listint_t *small, listint_t **list);
void insertion_sort_list(listint_t **list);

#endif /* SORT_H */
