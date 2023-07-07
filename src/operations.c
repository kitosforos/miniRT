/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/07/07 18:02:23 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <time.h>
#include <stdlib.h>
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

double length_squared(t_coord e)
{
    return e.x*e.x + e.y*e.y + e.z*e.z;
}

double randomize() {
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*randomize();
}

double  clamp(double x, double min, double max)
{
    if (x < min ) return min;
    if (x > max ) return max;
    return x;
}


int sphere_hit(const t_ray r, double t_min, double t_max, t_hit_record *rec, t_sphere sphere)  {
    t_coord oc = resta_vect(r.origin, sphere.coord);
    double a = dot(r.direction, r.direction);
    double b = dot(oc, r.direction);
    double c = dot(oc, oc) - (sphere.diametre / 2) * (sphere.diametre / 2);
    double discriminant = b*b - a*c;
    
    if (discriminant < 0)
        return -1.0;
    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return (0);
    }
    rec->origin = sphere.coord;
    rec->t = root;
    rec->p = t_f(r, rec->t);
    t_coord outward_normal = div_vect((resta_vect(rec->p, sphere.coord)), (sphere.diametre / 2));
    set_face_normal(r, outward_normal, rec);
    return (1);
}


void    add_sphere(t_hittables *world, t_sphere *sphere)
{
    world->spheres[world->n_spheres++] = sphere;
}

void set_face_normal(const t_ray r, const t_coord outward_normal, t_hit_record *rec) {
        rec->front_face = dot(r.direction, outward_normal) < 0;
        rec->normal = rec->front_face ? outward_normal : prod_vect(outward_normal, -1);
    }

t_coord t_f(t_ray ray, double t)
{
	return (suma_vect(ray.origin, prod_vect(ray.direction, t)));
}
