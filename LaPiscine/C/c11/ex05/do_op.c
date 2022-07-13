/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:21:46 by heson             #+#    #+#             */
/*   Updated: 2022/05/05 20:01:50 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ADD '+'
# define SUB '_'
# define MUL '*'
# define DIV '/'
# define MOD '%'

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	sign = 1;
	while (*str == '+' || *str '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

char	*ft_itoa(int nbr, char *res)
{
	

	
}

int	main(int ac, char *av[])
{
	int		num1;
	int		num2;
	//char	op[4];

	if (ac != 4)
		return (0);
	num1 = ft_atoi(av[1]);
	num2 = ft_atoi(av[3]);

	if (av[2] == ADD)
		return (num1 + num2);
	if (av[2] == SUB)
		return (num1 - num2);
	if (av[2] == MUL)
		return (num1 * num2);
	if (av[2] == DIV && num2 != 0)
		return (num1 / num2);
	else if (av[2] == DIV && num2 == 0)
		print_res("Stop : division by zero\n");
	else 

