/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:49 by heson             #+#    #+#             */
/*   Updated: 2023/01/27 17:07:27 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

volatile sig_atomic_t flag = -1;
volatile sig_atomic_t c_pid;

void	signal_handler(int sig, siginfo_t *siginfo, void *p)
{
	flag = sig;
	c_pid = siginfo->si_pid;
	p = 0;
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_sigaction = signal_handler;
	sigemptyset(&(sa->sa_mask));
	sigaddset(&(sa->sa_mask), SIGUSR1);
	sigaddset(&(sa->sa_mask), SIGUSR2);
	sa->sa_flags = SIGINFO | SA_RESTART;
}

void	bit_2char()
{
	static int		recv_cnt;
	static char		ch;
	int				bit;

	bit = (flag == ONE);
	ch = (ch << 1) | bit;
	recv_cnt++;
	if (recv_cnt == 8)
	{
		if (!ch)
			ch = '\n';
		write(1, &ch, 1);
		write(1, "\n", 1);
		ch = 0;
		recv_cnt = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;	

    init_sigaction(&sa);
	pid = getpid();
	ft_printf("server PID: %d\n", pid);
	while (1)
	{
		sigaction(ZERO, &sa, 0);
		sigaction(ONE, &sa, 0);
		while (flag < 0);
		if (flag >= 0)
		{
			ft_printf("%d ", flag - 30);
			bit_2char();
			kill(c_pid, flag);
			flag = -1;
		}
	}
	return (0);
}


/*
전역변수 - 정수 flag

client가 처음에 보내기 전에 시작을 알림 0으로

<receive func>
server가 0 받으면 handler 내에서 
	client pid 저장하고
	sigaction으로 8비트 받기 -> 배열에 저장
	8비트 다 받으면
		정상 신호 kill 0
		다시 역순으로 bit kill
		정상 신호 오면 종료
	일정 시간 내에 안오면 
		에러 kill 1, handler 종료
	
	
	
client - server의 신호 기다리다가
신호가 오면 
	0 이면 
		모두 받은 거니까 신호 char 변환해서 확인
		맞았으면 sigaction으로 정상 신호 보냄
	1 이면 
		에러 발생이므로 해당 char 다시 보냄


*/