#include "awshell.h"

/**
* add_node_end - adds a new node at the end of a linked list
* @head: head of the list
* @str: element to put in the new node
* Return: the address of the new element, or NULL if it failed
*                     _
*     /\             | |
*    /  \   _ __   __| |_   _
*   / /\ \ | '_ \ / _` | | | |
*  / ____ \| | | | (_| | |_| |
* /_/    \_\_|_|_|\__, |\__, | _   _
* \ \        / (_)   | | __/ || \ | |
*  \ \  /\  / / _ ___| ||___/ |  \| |
*   \ \/  \/ / | / __| __/ _ \| . ` |
*    \  /\  /  | \__ \ || (_) | |\  |
*     \/  \/   |_|___/\__\___/|_| \_| |- Nov 2020 -|
*
*/
p_list *add_list(p_list **head, const char *str)
{
	p_list *newnode = NULL;
	p_list *lastnode = *head;

	newnode = malloc(sizeof(p_list));
	if (!newnode)
	{
		return (NULL);
	}
	(*newnode).str = _strdup(str);
	(*newnode).next = NULL;
	if (!*head)
	{
		*head = newnode;
	}
	else
	{
		while ((*lastnode).next != NULL)
		{
			lastnode = (*lastnode).next;
		}
		(*lastnode).next = newnode;
	}
	return (newnode);
}
