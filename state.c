/* 
 * File:   state.c
 * Author: bhivert
 *
 * Created on June 25, 2017, 7:48 PM
 */

#include "state.h"

void					state_init(state_t *state, state_fct_t *fcts[], id_t nids) {
	state->id = (id_t)~0;
	state->fcts = fcts;
	state->nids = nids;
}

void					state_reset(state_t *state) {
	state->id = 0;
}

void					state_stop(state_t *state) {
	state->id = (id_t)~0;
}

bool					state_isstopped(state_t state) {
	return state.id == (id_t)~0 || !(state.id < state.nids);
}

void					state_exec(state_t *state) {
	if (!state_isstopped(*state)) {
		state->id = state->fcts[state->id](state->id);
	}
}
