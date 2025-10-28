/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:05:41 by zali              #+#    #+#             */
/*   Updated: 2025/10/27 07:33:11 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <unistd.h>
#include "mlx.h"
#include "math.h"


#define WIDTH 300
#define HEIGHT 720

// #define WIDTH 1920
// #define HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct s_vec3
{
	float x;
	float y;
	float z;
}	t_vec3;

// int	raytrace_color(t_vec3 vec)
// {
// 	float radius = .6f;
// 	t_vec3 origin = {0.0, 0.0, 1.0};
// 	float a = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
// 	float b = 2.0 * (origin.x * vec.x  + origin.y *vec.y +  origin.z * vec.z);
// 	float c = origin.x * origin.x + origin.y * origin.y + origin.z * origin.z - radius * radius; 

	
// 	if (b*b-(4.0*a*c) >= 0)
// 		return (0xffff00ff);
// 	return (0xff000000);
// }

int raytrace_color(t_vec3 vec)
{
	float radius = .5;
	t_vec3 origin = {0, 0, 2.0};
	float a = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	float b = 2.0 * (origin.x * vec.x + origin.y * vec.y + origin.z * vec.z);
	float c = origin.x * origin.x + origin.y * origin.y + origin.z * origin.z - radius * radius;
	if (b*b-(4.0*a*c) > 0)
		return (0xffff00ff);
	return (0xff000000);
}
int main(void)
{
	int x;
	int y;
	float	scaled_x;
	float	scaled_y;

	x = 0;
	y = 0;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "hi");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (y < HEIGHT)
	{
		x = 0;
	    while (x < WIDTH)
		{
			// We need to scale the x and y to be between -1 and 1
			// We need a formula
			/*
			
								( cur_val  -   cur_low)
				x = scale_low +	------------------------ x (scale_max - (scale_low))
								(cur_max   -   cur_low)
				
				our case eg.
					scale_low = -1
					scale_max = 1
					cur_low = 0
					cur_max = WIDTH
					imagine cur_val is 50; (x = 50)
					-1 + ((50 - 0 ) / (600 - 0)) * (1 -(-1))
					formula: -1 + ((50/600) * 2)
					(x/300) - 1
					eg: x = 50 - 50/300 - 1 = -0.83
			
			*/
			float aspect;
			if (WIDTH > HEIGHT)
				aspect = (float)WIDTH / (float)HEIGHT;	
			else
				aspect = (float)HEIGHT / (float)WIDTH; 

			scaled_x = -1.0 + (2.0 * (x / (float)WIDTH));
			scaled_y = -1.0 + (2.0 * (y / (float)HEIGHT));
			if (WIDTH > HEIGHT)
				scaled_x *= aspect;
			else
				scaled_y *= aspect;
			t_vec3 vec = { scaled_x, scaled_y, -1.0f};
			int color = raytrace_color(vec); 
			my_mlx_pixel_put(&img, x, y, color);
			x++;
	    }
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


/*

	a = start point (-3, -3)
	b = (1, 1)
	t = scalar dist
	Formula for Ray : a + bt 
	Sphere :  (x^2 + y^2)^(1/2) = r -> if (0,0) is the midpoint
	
	unsimplified formula : (x-w)^2 + (y - h)^2 + (z - b)^2 = r^2 ( but since we start with point (0,0,0);
	its easily simplied into (x^2 + y^2 + z^2) = r^2 (we dont use z yet.. lets deal with a circle first)
	
	radius = 10
	x^2 + y^2= 100
	y = (100 - x^2) ^ 1/2 -> Equation!

	Since x,y are vectors. 
	a + bt -> 
				ax + bx*t
				ay + by*t
	put x and y in the equation:

	x^2 + y^2 + r^2

	(ax + bx)^2 + (ay + ay)^2 + r ^2 -> Expand that and later put a, b, r values inside.

	it turns out:
		2(t^2) - 12t + 14 = 0

	a = 2
	b = -12
	c = 14
	
	how many solutions?
	b^2 - 4ac
	-12^2 - 4(2)(14)
	144 - 112
	32 -> Positive so 2 solutions
	> 0 - 2
	= 0 - 1
	< 0 - 0


	(-b +- (32)^1/2) / 2
	t = 4.415, 1.585
	whats t?- Scalar distance - magnitude
	We can use t to see if it intercets with the circle:
	
	a + bt -> 
					ax + bx*t
					ay + by*t
					a(-3,-3), b(1,1) 
					1. Solution
						-3 + 1(4.415) -> (x) = 1.415
						-3 + 1(4.415) -> (y) = 1.415 -> (1.415, 1.415)
					2. Solution
						-3 + 1(1.585) -> (x) = -1.415
						-3 + 1(1.585) -> (y) = -1.415 -> (-1.415, -1.415)
*/
