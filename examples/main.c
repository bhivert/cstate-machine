/*
* main.c is part of a project.
* Copyright (C) 2021 Benoit Hivert <hivert.benoit@gmail.com>
*
* This project is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This project is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this project. If not, see <http://www.gnu.org/licenses/>
*
* Created on 2021/03/27 at 15:42:12 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2021/03/27 at 15:47:36 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "state.h"
#include <stdio.h>

static unsigned int	tmp;

static id_t	fct0(id_t id) {
	printf("state %d\n", id);
	tmp = 0;
	return (++id);
}

static id_t	fct1(id_t id) {
	printf("state %d\n", id);
	if (++tmp < 3)
		return (id);
	return (++id);
}

static id_t	fct2(id_t id) {
	printf("state %d\n", id);
	return (++id);
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
