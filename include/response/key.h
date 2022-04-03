#ifndef ___KEY___
#define ___KEY___
#include		<lapin.h>
#include		"t_prog.h"

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*data);

#endif
