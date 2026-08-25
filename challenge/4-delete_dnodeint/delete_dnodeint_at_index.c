int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	dlistint_t *prev_node, *next_node;
	unsigned int p;

	if (*head == NULL)
		return (-1);

	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}

	if (p != index || *head == NULL)
	{
		*head = saved_head;
		return (-1);
	}

	if (index == 0)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
			tmp->prev = NULL;
	}
	else
	{
		prev_node = (*head)->prev;
		next_node = (*head)->next;
		prev_node->next = next_node;
		if (next_node != NULL)
			next_node->prev = prev_node;
		free(*head);
		*head = saved_head;
	}

	return (1);
}