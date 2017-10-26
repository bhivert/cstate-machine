/* 
 * File:   main.c
 * Author: bhivert
 *
 * Created on June 25, 2017, 7:48 PM
 */

#include "state.h"
#include <stdio.h>

static unsigned int	tmp;

static id_t	fct0(state_t s) {
	printf("state %d\n", s.id);
	tmp = 0;
	return (++s.id);
}

static id_t	fct1(state_t s) {
	printf("state %d\n", s.id);
	if (++tmp < 3)
		return (s.id);
	return (++s.id);
}

static id_t	fct2(state_t s) {
	printf("state %d\n", s.id);
	return (++s.id);
}

static state_fct_t	* _fcts[] = {
	&fct0,
	&fct1,
	&fct2
};

int	main(int ac, char *av[]) {
	state_t	test;

	(void)ac;
	(void)av;

	state_init(&test, _fcts, sizeof(_fcts) / sizeof(state_fct_t *));
	state_reset(&test);

	while (!state_isstopped(test)) {
		state_exec(&test);
	}
	return (0);
}
