#include "sort.h"

/**
 * cocktail_sort_list - sorts doubly linked list ascending order
 * @list: List
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *H = *list, *Temp;
	bool k = true;

	if (!list)
	{return; }
	else
	{
		while (k)
		{
			k = false;
			while (H->next)
			{
				if ((H->n) > (H->next->n))
				{
					Temp = H->next, SwapLR(list, H, Temp);
					print_list(*list), k = true;
				}
				else
				{H = H->next; }
			}

			k = false;
			while (H->prev)
			{
				if ((H->prev->n) > (H->n))
				{SwapRL(list, H, Temp), print_list(*list), k = true; }
				else
				{H = H->prev; }
			}
		}
	}
}

/**
 * SwapLR - makes swap from left to right
 * @list: List
 * @H: Head
 * @Temp: Temporary pointer
 * Return: Void
 */
void SwapLR(listint_t **list, listint_t *H, listint_t *Temp)
{
	if (H->prev)
	{H->prev->next = Temp; }
	else
	{*list = Temp; }

	if (Temp->next)
	{Temp->next->prev = H; }

	H->next = Temp->next;
	Temp->prev = H->prev;
	Temp->next = H;
	H->prev = Temp;
}

/**
 * SwapRL - makes swap from right to Left
 * @list: List
 * @H: Head
 * @Temp: Temporary pointer
 * Return: Void
 */
void SwapRL(listint_t **list, listint_t *H, listint_t *Temp)
{
	Temp = H->prev;
	Temp->next->prev = Temp->prev;
	if (Temp->prev)
	{Temp->prev->next = Temp->next; }
	else
	{*list = Temp->next; }
	Temp->prev = Temp->next;
	Temp->next = Temp->next->next;
	Temp->prev->next = Temp;
	if (Temp->next)
	{Temp->next->prev = Temp; }
}
