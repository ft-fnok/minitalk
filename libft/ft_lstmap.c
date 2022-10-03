/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:16:52 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/17 23:07:59 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_f;
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		list_f = ft_lstnew(f(lst->content));
		if (lst->content != NULL)
			ft_lstadd_back(&head, list_f);
		else
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		list_f = list_f->next;
		lst = lst->next;
	}
	return (head);
}
