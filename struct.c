#include "test.h"

t_player init_player(void)
{
	t_player    user;

	user.x = 0;
	user.y = 0;
	user.pos = 0;
	user.C = 0;
	user.moves = 0;
	return (user);
}

t_map init_map(void)
{
	t_map    map;

	map.x = 0;
	map.y = 0;
	map.px = 0;
	map.py = 0;
	map.Cmax = 0;
	map.Pmax = 0;
	map.Emax = 0;
	//map->user = init_player();
	return (map);
}
