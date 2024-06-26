/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragoncrv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:14:29 by pierre            #+#    #+#             */
/*   Updated: 2024/06/26 13:34:50 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char drawline(t_vars *data, int x, int y, char c)
{
	int i;

	i = 1;
	while (i <= 1)
	{
		if (c == 'U')
			y--;
		else if (c == 'D')
			y++;
		else if (c == 'L')
			x--;
		else if (c == 'R')
			x++;
		my_mlx_pixel_put(data->img_data, x, y, 0x0000FF00);
		i++;
	}
	if (c == 'U' || c == 'D')
		data->dragy = y;
	else
		data->dragx = x;
	return (c);
}
void	ft_swap(char *str)
{
	int	strlen;
	int	i;
	char	temp;
	if (!str)
		return ;
	if (!ft_strcmp(str, ""))
		return ;
	strlen = ft_strlen(str);
	i = 0;
	while (i < strlen / 2)
	{
		temp = str[i];
		str[i] = str[strlen - i - 1];
		str[strlen - 1 - i] = temp;
		i++;
	}	
}
void	ft_strrplc(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (*str)
	{
		if (*str == 'R')
			*str = 'L';
		else if (*str == 'L')
			*str = 'R';
		str++;
	}
}

char	*get_dragon(int i, char *str)
{
	char *temp;
	char *temp2;

	if (i == 0)
		return (str);
	else
	{
		temp = ft_strjoin(str, "R");
		ft_swap(str);
		ft_strrplc(str);
		temp2 = ft_strjoin(temp, str);
		free(str);
		free(temp);
		get_dragon(i - 1, temp2);
	}
}