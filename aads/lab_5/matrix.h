#ifndef MATRIX_H

#define MATRIX_H

#include <complex.h>

/*
 * Matrix (numbers stored column-wise).
 */
struct matrix {
    size_t rows;
    size_t columns;
    double _Complex *values;
};

/*
 * Pair of numbers for Givens rotation, where c = cos(theta), s = sin(theta).
 */ 
struct givens_pair {
    double _Complex c;
    double _Complex s;
};

int matrix_fread(FILE *mtrx_file, struct matrix **mtrx);
struct matrix *matrix_sum(struct matrix *mtrx_1, struct matrix *mtrx_2);
struct matrix *matrix_dif(struct matrix *mtrx_1, struct matrix *mtrx_2);
struct matrix *matrix_mul(struct matrix *mtrx_1, struct matrix *mtrx_2);
struct matrix *matrix_get_identity_matrix(size_t order);
struct matrix *matrix_cut_matrix(struct matrix * mtrx, size_t row, 
    size_t end_row, size_t column, size_t end_column);
int matrix_paste_matrix(struct matrix *mtrx_1, struct matrix *mtrx_2,
    size_t row, size_t column);
double _Complex matrix_determinant(struct matrix *mtrx);
struct matrix *matrix_get_minor_matrix(struct matrix *mtrx, size_t row, 
    size_t column);
struct matrix *matrix_dot_mirror(struct matrix *mtrx);
struct matrix *matrix_const_mul(struct matrix *mtrx, double _Complex number);
struct givens_pair *givens_pair_find(double _Complex a, double _Complex b);
struct matrix *matrix_givens_left_mul(struct matrix *mtrx, 
                                        struct givens_pair *givens_pair);
struct matrix *matrix_givens_right_mul(struct matrix *mtrx, 
                                        struct givens_pair *givens_pair);
int matrix_vector_norm(struct matrix *vector, double _Complex *norm);
struct matrix *matrix_housholder_vector(struct matrix *vector);
struct matrix *matrix_housholder_left_mul(struct matrix *mtrx, 
                                            struct matrix* housholder_vector);
struct matrix *matrix_housholder_right_mul(struct matrix *mtrx, 
                                            struct matrix* housholder_vector);
void matrix_housholder_transformation(struct matrix *mtrx, 
                                        struct matrix **houshold_matrix);
void matrix_hessenberg_triangular_transformation(struct matrix **mtrx_a, 
    struct matrix *mtrx_b);
struct matrix *matrix_inverse(struct matrix *mtrx);
void qz_step(struct matrix **mtrx_a, struct matrix **mtrx_b);
void qz_process(struct matrix **mtrx_a, struct matrix **mtrx_b);
void complex_print(double _Complex num);
void matrix_free(struct matrix *mtrx);

#endif

