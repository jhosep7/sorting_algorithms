#include "sort.h"

/**
 * insertion_sort_list - sorts a DoublyLinked list ascending order
 * @list:doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *Temp = NULL;

	if (!list || !(*list) || !((*list)->next))
	{return; }

	Temp = (*list)->next;
	while (Temp)
	{
		while (Temp->prev && (Temp->n) < (Temp->prev->n))
		{
			Temp->prev->next = Temp->next;
			if (Temp->next)
			{Temp->next->prev = Temp->prev;}
			Temp->next = Temp->prev;
			Temp->prev = Temp->prev->prev;
			Temp->next->prev = Temp;
			if (!(Temp->prev))
			{*list = Temp;}
			else
			{Temp->prev->next = Temp;}
			print_list(*list);
		}
		Temp = Temp->next;
	}
}
