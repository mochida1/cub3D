void	key_esc(void *mlx_context)
{
	ft_putstr_fd("\033[31;1mClosing Cub32...\033[0m\n", 1);

	// mlx_destroy_image(context->mlx_ptr, context->img);
	// mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	// mlx_destroy_display(context->mlx_ptr);
	// ft_putstr_fd("\033[32;1mCub3D closed successfully.\033[0m\n", 1);
	exit (0);
}

void	red_x_close(void *context_to_free)
{
	ft_putstr_fd("\033[31;1mClosing Cub32...\033[0m\n", 1);

	// mlx_destroy_image(img->mlx_ptr, img->img);
	// mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	// mlx_destroy_display(img->mlx_ptr);
	ft_putstr_fd("\033[32;1mCub3D closed successfully.\033[0m\n", 1);
	exit (0);
}
