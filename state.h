/*
* state.h is part of a project.
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
* Created on 2017/06/25 at 07:48:02 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2021/03/27 at 15:49:54 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef STATE_H
# define STATE_H

# include <stdbool.h>

typedef unsigned short	id_t;
typedef struct state_s	state_t;
typedef id_t			(state_fct_t)(id_t);

struct					state_s {
	id_t				id;
	id_t				nids;
	state_fct_t			**fcts;
};

void					state_init(state_t *state, state_fct_t *fcts[], id_t nids);
void					state_reset(state_t *state);
void					state_stop(state_t *state);
bool					state_isstopped(state_t state);
void					state_exec(state_t *state);

#endif	/* STATES_H */
