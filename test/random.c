#include "mlx.h"

int main(void)
{
	void *ptr;
	void *win;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 400, 400, "TEST");
	mlx_loop(ptr);
}
