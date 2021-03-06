#include <stdlib.h>
#include "stack.h"
#include "item.h"

static link head;

void forget_item(Item item)
{
  link h = head, t;
  
  if (h->next != NULL)
  do
    if (h->next->item == item)
      {
	t = h->next;
	h->next = h->next->next;
	free(t);
	return;
      }
  while (h->next != NULL);
}

link new(Item item, link next)
{
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

void STACKinit(int maxn)
{
  head = NULL;
}

int STACKempty(void)
{
  return head == NULL;
}

void STACKpush(Item item)
{
  head = new(item, head);
  forget_old(item);
}

Item STACKpop()
{
  Item item = head->item;
  link t = head->next;

  free(head);
  head = t;
  return item;
}
