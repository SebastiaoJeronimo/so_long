/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scosta-j <scosta-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:28:06 by scosta-j          #+#    #+#             */
/*   Updated: 2023/07/27 15:22:54 by scosta-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_bfs(t_Queue *q, int *set)
{
	free(q->array);
	free(q);
	free(set);
	return (1);
}

t_Queue	*create_queue(int capacity)
{
	t_Node	*node;
	t_Queue	*queue;

	node = (t_Node *) malloc (capacity * sizeof(t_Node));
	if (!node)
	{
		free(node);
		write(1, "malloc failed\n", 15);
		return (NULL);
	}
	queue = (t_Queue *) malloc(sizeof(t_Queue));
	if (!queue)
	{
		free(node);
		free(queue);
		write(1, "malloc failed\n", 15);
		return (NULL);
	}
	queue->array = node;
	queue->front = 0;
	queue->rear = -1;
	queue->capacity = capacity;
	queue->size = 0;
	return (queue);
}

int	is_queue_empty(t_Queue *queue)
{
	return (queue->size);
}

/**
 * Circular queue
*/
void	enqueue(t_Queue *queue,	t_Node node)
{
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = node;
	queue->size++;
}

/**
 * Circular queue
*/
t_Node	dequeue(t_Queue	*queue)
{
	t_Node	item;

	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return (item);
}
