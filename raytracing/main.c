/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:05:41 by zali              #+#    #+#             */
/*   Updated: 2025/11/27 18:57:46 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"
#include <unistd.h>
#include "mlx.h"
#include "math.h"


#define WIDTH 600
#define HEIGHT 600

// #define WIDTH 1920
// #define HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vec3
{
	float x;
	float y;
	float z;
}	t_vec3;



// Vector Funcs

t_vec3	vec_add(t_vec3 vec1, t_vec3 vec2)
{
	float	x;
	float	y;
	float	z;
	
	x = vec1.x + vec2.x;
	y = vec1.y + vec2.y;
	z = vec1.z + vec2.z;
	t_vec3 vec = {x, y, z};
	return (vec);
}

t_vec3	vec_mult(t_vec3 vec1, t_vec3 vec2)
{
	float	x;
	float	y;
	float	z;
	
	x = vec1.x * vec2.x;
	y = vec1.y * vec2.y;
	z = vec1.z * vec2.z;
	t_vec3 vec = {x, y, z};
	return (vec);
}

t_vec3	vec_sub(t_vec3 vec1, t_vec3 vec2)
{
	float	x;
	float	y;
	float	z;
	
	x = vec1.x - vec2.x;
	y = vec1.y - vec2.y;
	z = vec1.z - vec2.z;
	t_vec3 vec = {x, y, z};
	return (vec);
}

t_vec3 vec_scale(t_vec3 v, float s)
{
    return (t_vec3){ v.x * s, v.y * s, v.z * s };
}

int to_rgb(t_vec3 c)
{

    int r = (int)(fminf(fmaxf(c.x, 0.0f), 1.0f) * 255.0f);
    int g = (int)(fminf(fmaxf(c.y, 0.0f), 1.0f) * 255.0f);
    int b = (int)(fminf(fmaxf(c.z, 0.0f), 1.0f) * 255.0f);
    return (r << 16) | (g << 8) | b;
}


// Rendering

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int raytrace_sphere(t_vec3 dir, t_vec3 center, t_vec3 light)
{
    // Camera at origin
    t_vec3 ray_origin = {0,0,0};

    // Sphere radius
    float radius = 0.5f;

    // Quadratic coefficients
    t_vec3 oc = { ray_origin.x - center.x, ray_origin.y - center.y, ray_origin.z - center.z };
    float a = dir.x*dir.x + dir.y*dir.y + dir.z*dir.z;
    float b = 2.0f * (oc.x*dir.x + oc.y*dir.y + oc.z*dir.z);
    float c = oc.x*oc.x + oc.y*oc.y + oc.z*oc.z - radius*radius;

    float disc = b*b - 4*a*c;
    if (disc < 0.0f) return 0x000000; // no hit

    float sqrtD = sqrtf(disc);
    float t0 = (-b - sqrtD) / (2*a);
    float t1 = (-b + sqrtD) / (2*a);

    // Pick nearest positive intersection
    float t = (t0 > 0) ? t0 : t1;
    if (t < 0) return 0x000000;

    // Hitpoint
    t_vec3 hit = { ray_origin.x + dir.x*t, ray_origin.y + dir.y*t, ray_origin.z + dir.z*t };

    // Normal at hitpoint
    t_vec3 normal = { hit.x - center.x, hit.y - center.y, hit.z - center.z };
    float nl = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
    normal.x /= nl; normal.y /= nl; normal.z /= nl;

    // Normalize light
    float ll = sqrtf(light.x*light.x + light.y*light.y + light.z*light.z);
    t_vec3 L = { light.x/ll, light.y/ll, light.z/ll };

    // Diffuse
    float diffuse = - (normal.x*L.x + normal.y*L.y + normal.z*L.z);
    if (diffuse < 0) diffuse = 0;

    // Specular
    t_vec3 view = { -hit.x, -hit.y, -hit.z }; // camera at origin
    float vl = sqrtf(view.x*view.x + view.y*view.y + view.z*view.z);
    view.x /= vl; view.y /= vl; view.z /= vl;

    // reflect(L, N) = L - 2*dot(L,N)*N
    float dotLN = L.x*normal.x + L.y*normal.y + L.z*normal.z;
    t_vec3 reflect = { L.x - 2*dotLN*normal.x, L.y - 2*dotLN*normal.y, L.z - 2*dotLN*normal.z };

    float spec = reflect.x*view.x + reflect.y*view.y + reflect.z*view.z;
    if (spec < 0) spec = 0;
    float shininess = 50.0f;
    spec = powf(spec, shininess);
    float spec_strength = 0.5f;

    // Base color
    int base = 0xFF5500;
    float r = ((base>>16)&0xFF)/255.0f;
    float g = ((base>>8 )&0xFF)/255.0f;
    b = ((base    )&0xFF)/255.0f;

    // Apply diffuse
    r *= diffuse; g *= diffuse; b *= diffuse;

    // Add specular (white)
    r += spec_strength*spec;
    g += spec_strength*spec;
    b += spec_strength*spec;

    // Clamp
    if (r>1) r=1; if (g>1) g=1; if (b>1) b=1;

    // Convert to int RGB
    int ir = (int)(r*255);
    int ig = (int)(g*255);
    int ib = (int)(b*255);

    return (ir<<16)|(ig<<8)|ib;
}

/*

int raytrace_sphere(t_vec3 dir, t_vec3 sphere_center, t_vec3 light)
{
    float radius = 0.5f;

    // camera is always at (0,0,0)
    t_vec3 ray_origin = (t_vec3){0,0,0};

    // oc = O - C
    t_vec3 oc = vec_sub(ray_origin, sphere_center);

    float a = dir.x*dir.x + dir.y*dir.y + dir.z*dir.z;
    float b = 2 * (oc.x*dir.x + oc.y*dir.y + oc.z*dir.z);
    float c = oc.x*oc.x + oc.y*oc.y + oc.z*oc.z - radius*radius;

    float disc = b*b - 4*a*c;
    if (disc < 0)
        return 0; // miss

    float sq = sqrtf(disc);
    float t0 = (-b - sq) / (2*a);
    float t1 = (-b + sq) / (2*a);

    float t = t0;
    if (t < 0) t = t1;
    if (t < 0) return 0;

    // Hitpoint = O + dir * t
    t_vec3 hitpoint = vec_add(ray_origin, vec_scale(dir, t));

    // Normal = hitpoint - sphere_center
    t_vec3 normal = vec_sub(hitpoint, sphere_center);

    float nl = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
    normal.x /= nl;
    normal.y /= nl;
    normal.z /= nl;

    // normalize light
    float ll = sqrtf(light.x*light.x + light.y*light.y + light.z*light.z);
    light.x /= ll;
    light.y /= ll;
    light.z /= ll;

    // lambert
    float lf = normal.x * -light.x + normal.y * -light.y + normal.z * -light.z;
    if (lf < 0) lf = 0;

    // base color
    int base = 0xFF5500;
    float r = ((base>>16)&0xFF)/255.0f * lf;
    float g = ((base>>8 )&0xFF)/255.0f * lf;
    float b2= ((base    )&0xFF)/255.0f * lf;

    return ((int)(r*255)<<16) | ((int)(g*255)<<8) | (int)(b2*255);
}
*/
/*
int raytrace_sphere(t_vec3 vec, t_vec3 origin, t_vec3 light)
{
	int		i = 0;
	float	radius = .5;
	float	a = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	float	b = 2.0 * (origin.x * vec.x + origin.y * vec.y + origin.z * vec.z);
	float	c = origin.x * origin.x + origin.y * origin.y + origin.z * origin.z - radius * radius;
	float	disc = b*b - (4.0 * a * c);
	if (disc >= 0)
	{
		float t[2];

		t[0] = (-b - sqrt(disc)) / (2 * a);
		t[1] = (-b + sqrt(disc)) / (2 * a);
		float color[2];


		if (t[0] < 0.0f)
			t[0] = t[1];
		if (t[0] < 0.0f)
			return (0);
		t_vec3 hitpoint = vec_add(origin, vec_scale(vec,t[0]));
		t_vec3 normal = vec_sub(hitpoint, origin);
		float normalize = sqrt((normal.x*normal.x) + (normal.y * normal.y) + (normal.z * normal.z));
		normal.x = normal.x/normalize;  
		normal.y = normal.y/normalize;  
		normal.z = normal.z/normalize;

		float lightNormalize = sqrt((light.x*light.x) + (light.y*light.y) + (light.z * light.z));
		light.x = light.x / lightNormalize;
		light.y = light.y / lightNormalize;
		light.z = light.z / lightNormalize;
		float lf = (normal.x * -light.x) + (normal.y * -light.y) + (normal.z * -light.z); 
		if (lf < 0.0)
			lf = 0.0;
		int base_color = 0xFF5500; 
		float r = ((base_color >> 16) & 0xFF) / 255.0f;
	    float g = ((base_color >>  8) & 0xFF) / 255.0f;
	    float b = ( base_color        & 0xFF) / 255.0f;

	    r *= lf;
	    g *= lf;
	    b *= lf;
		int ir = (int)(r * 255.0f);
	    int ig = (int)(g * 255.0f);
	    int ib = (int)(b * 255.0f);

		return (ir << 16) | (ig << 8) | ib;
	}
	return (0);
}
*/
/*
int raytrace_sphere(t_vec3 dir)
{
    t_vec3 camera = {0, 0, 0};
    t_vec3 center = {0, 0, -1};
    float radius = 0.5f;

    t_vec3 oc = vec_sub(camera, center);

    float a = dir.x*dir.x + dir.y*dir.y + dir.z*dir.z;
    float b = 2.0f * (oc.x*dir.x + oc.y*dir.y + oc.z*dir.z);
    float c = oc.x*oc.x + oc.y*oc.y + oc.z*oc.z - radius*radius;

    float disc = b*b - 4.0f*a*c;
    if (disc < 0) return 0;

    float t1 = (-b - sqrtf(disc)) / (2.0f * a);
    float t2 = (-b - sqrtf(disc)) / (2.0f * a);
    if (t1 < 0 && t2 < 0) return 0;

    // intersection point
    t_vec3 hit = vec_add(camera, vec_scale(dir, t));

    // normal = (hit - center)
    t_vec3 normal = vec_sub(hit, center);
    float len = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
    normal.x /= len;
    normal.y /= len;
    normal.z /= len;

    // map [-1,1] → [0,1]
    normal.x = normal.x * 0.5f + 0.5f;
    normal.y = normal.y * 0.5f + 0.5f;
    normal.z = normal.z * 0.5f + 0.5f;

    return to_rgb(normal);
}
*/


int raytrace_cylinder_infi(t_vec3 vec, t_vec3 origin)
{
	/*
		infinite cylinder x*x + z * z = r * r

		(2)t^2 + (2az + 2ax)t + (ax^2 + az^2 - r^2) = 0

	*/
	float radius = 0.5;
	float a = (vec.x * vec.x) + (vec.z * vec.z);
	float b = (2 * origin.x * vec.x) + (2 * origin.z * vec.z);
	float c = (origin.x * origin.x) + (origin.z * origin.z) - (radius * radius);
	if (b*b-(4.0*a*c) >= 0)
		return (0x0000ff99);
	return (0);
}





int raytrace_cylinder(t_vec3 dir, t_vec3 origin, t_vec3 light)
{
    float radius = 0.5;
    float height = 1.0f;

    t_vec3 ray_origin = (t_vec3){0,0,0};

    // Convert ray origin to cylinder local space:
    t_vec3 oc = vec_sub(ray_origin, origin);

    float a = dir.x*dir.x + dir.z*dir.z;
    float b = 2 * (oc.x*dir.x + oc.z*dir.z);
    float c = oc.x*oc.x + oc.z*oc.z - radius*radius;

    float disc = b*b - 4*a*c;
    if (disc < 0) return 0;

    float sq = sqrtf(disc);
    float t1 = (-b - sq) / (2*a);
    float t2 = (-b + sq) / (2*a);

    float half = height/2;

    float t = -1;

    // Check t1
    float y1 = oc.y + t1*dir.y;
    if (t1 >= 0 && y1 >= -half && y1 <= half)
        t = t1;

    // Check t2
    float y2 = oc.y + t2*dir.y;
    if (t2 >= 0 && y2 >= -half && y2 <= half)
        if (t < 0 || t2 < t) t = t2;

    if (t < 0)
        return 0;

    // Hit point in world:
    t_vec3 hit = vec_add(ray_origin, vec_scale(dir, t));

    // Now compute normal in cylinder local space:
    t_vec3 p = vec_sub(hit, origin); // convert to local cylinder coords

    t_vec3 normal = { p.x, 0, p.z };

    float nl = sqrt(normal.x*normal.x + normal.z*normal.z);
    normal.x /= nl;
    normal.z /= nl;

    // Light
    float ll = sqrt(light.x*light.x + light.y*light.y + light.z*light.z);
    t_vec3 L = { light.x/ll, light.y/ll, light.z/ll };

    float lf = normal.x*(-L.x) + normal.y*(-L.y) + normal.z*(-L.z);
    if (lf < 0) lf = 0;

    // Base color (red)
    int base = 0xFF0000;

    float r = ((base>>16)&0xFF)/255.0f * lf;
    float g = ((base>>8 )&0xFF)/255.0f * lf;
    float b2= ((base    )&0xFF)/255.0f * lf;

    return ((int)(r*255)<<16) | ((int)(g*255)<<8) | (int)(b2*255);
}
/*

int raytrace_cylinder(t_vec3 dir, t_vec3 origin)
{
    float radius = 0.5;
    float height = 1;

    // Cylinder aligned along Y-axis now
    float a = dir.x * dir.x + dir.z * dir.z;
    float b = 2.0 * (origin.x * dir.x + origin.z * dir.z);
    float c = origin.x * origin.x + origin.z * origin.z - radius * radius;

    float discriminant = b*b - 4*a*c;
    if (discriminant < 0.0)
        return 0; // no hit

    float sqrtD = sqrt(discriminant);
    float t1 = (-b - sqrtD) / (2*a);
    float t2 = (-b + sqrtD) / (2*a);

    // Check both intersections
    float y1 = origin.y + t1 * dir.y;
    float y2 = origin.y + t2 * dir.y;

    // Cylinder extends from -height/2 to +height/2 along Y
    float half = height / 2.0;

    int hit = 0; // default: no hit
    if (y1 >= -half && y1 <= half)
        hit = 1;
    else if (y2 >= -half && y2 <= half)
        hit = 1;

    if (hit)
        return 0xffff0000; // cylinder color
    return 0;     // background
}


*/

int	rt(t_vec3 vec)
{
	t_vec3 light = {-1, -1, -1};
	t_vec3 origin_cylinder = {1, 0, -2};
	t_vec3 origin_sphere = {0, 0, -1};
	int sphere_col = raytrace_sphere(vec, origin_sphere, light);
	int cylinder_col = raytrace_cylinder(vec, origin_cylinder, light);
	if (sphere_col && !cylinder_col)	
		return (sphere_col);
	if (cylinder_col && !sphere_col)
		return (cylinder_col);
	if (sphere_col && cylinder_col)
	{
		if (origin_cylinder.z < origin_sphere.z)
			return (cylinder_col);
		else
			return (sphere_col);
	}
	return (0x00000000);
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
			int color;
			color = rt(vec);
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
