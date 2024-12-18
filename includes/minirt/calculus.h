/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npirard <npirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:05 by lmahe             #+#    #+#             */
/*   Updated: 2024/02/28 10:55:31 by npirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULUS_H
# define CALCULUS_H

# include <math.h>
# include <minirt/types.h>

# ifndef M_PI
#  define M_PI 3.141592653589793
# endif

# ifndef T_MIN
#  define T_MIN 0.00000000001f
# endif

/* ------------------------------ GEOMETRY OPE ------------------------------ */

double		scalar_product(t_vec3f *t_u, t_vec3f *t_v);
void		normalize_vec(t_vec3f *t_u);
t_vec3f		vector_product(t_vec3f *t_u, t_vec3f *t_v);
t_vec3f		vec3_sum(t_vec3f *t_u, t_vec3f *t_v);
t_vec3f		vec3_diff(t_vec3f *t_u, t_vec3f *t_v);
t_vec3f		vec3_scale(t_vec3f *vector, double scale);
t_vec3f		vec3f_matrix4f(t_vec3f *vec, t_matrix4f *matrix);
double		distance(t_vec3f *a, t_vec3f *b);
t_vec3f		vec3f_get_dir(t_coord3f *a, t_coord3f *b);

/* -------------------------------- EQUATION -------------------------------- */

int			quadra_solver(t_double3 *coeff, double *t, double t_min);
int			linear_solver(double a, double b, double *t);
t_vec3f		get_inter_point(t_ray *ray, double t);
void		display_vector(t_vec3f	*vec);
double		sign(double x);
int			quadra_cone_solver(t_double3 *coeff, t_double3 *t);

/* ---------------------------------- PLANE --------------------------------- */

void		plane_intersec(t_object *plane, t_ray *ray);

/* --------------------------------- SPHERE --------------------------------- */

void		sphere_intersec(t_object *sphere, t_ray *ray);

/* -------------------------------- CYLINDER -------------------------------- */

int			top_cap_intersec(t_object *cyld, t_ray *ray, double *t);
int			bot_cap_intersec(t_object *cyld, t_ray *ray, double *t);
void		cylinder_intersec(t_object *cylinder, t_ray *ray);
void		cylinder_update_normal(t_object *cyld, t_ray *ray, t_vec3f *temp);

/* ---------------------------------- CONE ---------------------------------- */

void		cone_intersec(t_object *cone, t_ray *ray);
int			examine_sol(t_double3 *t, t_object *cone, t_ray *ray);
int			check_sol_body(t_object *cone, t_vec3f *sol);

/*--------------------------------TRIANGLE------------------------------------*/

void		triangle_inter(t_object *tr, t_ray *ray);

/* --------------------------------- MATRIX --------------------------------- */

t_vec3f		vec3f_rotate(t_vec3f *vec, double x, double y, double z);
t_matrix3f	matrix_rotate(double x, double y, double z);
t_matrix3f	matrix_sum(t_matrix3f *a, t_matrix3f *b);
t_matrix3f	matrix_transpose(t_matrix3f *m);
t_vec3f		vec3f_matrix3f(t_vec3f *vec, t_matrix3f *matrix);
void		display_matrix(t_matrix3f *m);
t_matrix3f	matrix_product(t_matrix3f *a, t_matrix3f *b);

/* ------------------------------ MULTIPLE OPE ------------------------------ */

int			get_sup_multiple(int n, int comp, int max);
int			get_inf_multiple(int n, int comp);

/* ----------------------------- GET_ROT MATRIX ----------------------------- */

t_matrix3f	rotation_matrix(t_vec3f	*cam_dir);
t_matrix3f	cam_rotation(t_vec3f *dir);
t_matrix3f	get_rotation_matrix(t_vec3f *axis, double theta);

/* --------------------------------- MAPPING -------------------------------- */

void		get_local_base(t_object *obj);
t_double2	revolution_map(t_object *obj, t_vec3f *p);
t_double2	plane_map(t_object *plane, t_vec3f *p);
t_double2	sphere_map(t_object *sph, t_vec3f *p);
void		coord_abs(t_coord2f *coord);
int			get_pixel_dame(t_double2 *uv, double square_size);

#endif
