/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/07/05 18:39:12 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

t_coord suma_vect(t_coord vec1, t_coord vec2)
{
    t_coord vec;

    vec.x = vec1.x + vec2.x;
    vec.y = vec1.y + vec2.y;
    vec.z = vec1.z + vec2.z;
    return (vec);
}

t_coord resta_vect(t_coord vec1, t_coord vec2)
{
    t_coord vec;

    vec.x = vec1.x - vec2.x;
    vec.y = vec1.y - vec2.y;
    vec.z = vec1.z - vec2.z;
    return (vec);
}

t_coord div_vect(t_coord vec1, double d)
{
    t_coord vec;

    vec.x = vec1.x / d;
    vec.y = vec1.y / d;
    vec.z = vec1.z / d;
    return (vec);
}

t_coord prod_vect(t_coord vec1, double d)
{
    t_coord vec;

    vec.x = vec1.x * d;
    vec.y = vec1.y * d;
    vec.z = vec1.z * d;
    return (vec);
}

t_coord new_coord(double x, double y, double z)
{
    t_coord vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;

    return (vec);
}

t_color new_color(int r, int g, int b)
{
    t_color color;
    
    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}

t_coord unit_vector(t_coord vec)
{
    t_coord unt;
    double length;

    length = 0;
    length += vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;
    length = sqrt(length);
    unt.x = vec.x / length; unt.y = vec.y / length; unt.z = vec.z / length;
    return (unt);
}

double	dot(const t_coord u, const t_coord v)
{
    return u.x * v.x
         + u.y * v.y
         + u.z * v.z;
}

t_coord	cross(const t_coord u, const t_coord v)
{
    return new_coord(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}

double	hit_sphere(const t_coord center, double radius, const t_ray r)
{
    t_coord oc = resta_vect(r.origin, center);
    double a = dot(r.direction, r.direction);
    double b = dot(oc, r.direction);
    double c = dot(oc, oc) - radius*radius;
    double discriminant = b*b - a*c;
    
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (b - sqrt(discriminant) ) / a;
    }	
        
    
}

t_coord t_f(t_ray ray, double t)
{
	return (suma_vect(ray.origin, prod_vect(ray.direction, t)));
}
