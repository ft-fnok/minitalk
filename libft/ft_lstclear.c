/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleike <nlalleik@students.42wolfsbur    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:39:18 by nlalleik          #+#    #+#             */
/*   Updated: 2021/12/08 22:44:25 by nlalleike        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_tmp;

	if (*lst != NULL)
	{
		lst_tmp = *lst;
		while (lst_tmp != NULL)
		{
			lst_tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst_tmp;
		}
		*lst = NULL;
	}
}
