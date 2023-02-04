/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:01:52 by dongyshi          #+#    #+#             */
/*   Updated: 2023/02/04 22:31:15 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	heap[8] = {0, 1, 7, 3, 9, 6, 4, 8};

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	heapify(int p, int max_val)
{
	int	child_idx;

	if (p * 2 > max_val)
		return ;
	heapify(p * 2, max_val);
	heapify(p * 2 + 1, max_val);
	child_idx = p * 2;
	if (p * 2 + 1 <= max_val)
		child_idx = (heap[child_idx] > heap[p * 2 + 1] ? child_idx : p * 2 + 1);
	if (heap[p] < heap[child_idx])
		swap(&heap[p], &heap[child_idx]);
}

int	main(void)
{
	heapify(1, 8);
	// heapify(1, 8);
	// heapify(1, 8);
	// heapify(1, 8);

	for (int i = 1; i <= 8; i++)
		printf("%d ", heap[i]);
	return (0);
}
