/* 
 * File:   state.h
 * Author: bhivert
 *
 * Created on June 25, 2017, 7:48 PM
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
