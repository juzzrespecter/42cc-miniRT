#include "minirt.h"

static t_point *collision_loops_5(t_objects *o_lst, t_ray *ray, t_point *point)
{
	t_tr *tr_aux;
	float t;

	tr_aux = o_lst->tr;
        while (tr_aux)
        {
                t = collision_triangle(tr_aux, ray, point);
		if (t > 0 && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = normal_triangle(cy_aux, ray, point);
		}
		tr_aux = tr_aux->next;
        }
	return (point);
}

static t_point *collision_loops_4(t_objects *o_lst, t_ray *ray, t_point *point)
{
	t_cy *cy_aux;
	float t;

	cy_aux = o_lst->cy;
        while (cy_aux)
        {
                t = collision_cylinder(cy_aux, ray);
		if (t > 0 && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = normal_cylinder(cy_aux, point);
		}
		cy_aux = cy_aux->next;
        }
	point = collision_loops_5(o_lst, ray, point);
}

static t_point *collision_loops_3(t_objects *o_lst, t_ray *ray, t_point *point)
{
	t_sq *sq_aux;
	float t;

	sq_aux = o_lst->sq;
        while (sq_aux)
        {
                t = collision_square(sq_aux, ray);
		if (t > 0 && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = sq->orientation;
		}
		sq_aux = sq_aux->next;
        }
	point = collision_loops_4(o_lst, ray, point);
	return (point);
}

static t_point *collision_loops_2(t_objects *o_lst, t_ray *ray, t_point *point)
{
	t_pl *pl_aux;
	float t;

	pl_aux = o_lst->pl;
        while (pl_aux)
        {
                t = collision_plane(pl_aux, ray);
		if (t > 0 && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = pl->orientation;
		}
		pl_aux = pl_aux->next;
        }
	point = collision_loops_3(o_lst, ray, point);
	return (point);
}

t_point *collision_loops(t_objects *o_lst, t_ray *ray)
{
        bool found_point;
        t_sp *sp_aux;
	float t;
        t_point *point;

        if (!(point = calloc(sizeof(t_point), 1)))
                return (NULL);
        point->t = -1;
        while (sp_aux)
        {
                t = collision_sphere(aux, ray);
		if (t > 0 && (point->t > t || point->t == -1))
		{
			point->t = t;
			point->coord = v_add(ray->origin, v_scalar(ray->dir, t));
			point->normal = v_normalize(v_sub(point->coord, sp_aux->center));
		}
		sp_aux = sp_aux->next;
        }
	point = collision_loops_2(o_lst, ray, point);
        return (point);
}
