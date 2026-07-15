/*
 * In The Name Of God
 * ========================================
 * [] File Name : multiplicationtable.c
 *
 * [] Creation Date : 17-03-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <gsl/gsl_matrix.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  gsl_matrix *m = gsl_matrix_alloc(20, 15);
  gsl_matrix_set_all(m, 1);

  for (size_t i = 0; i < m->size1; i++) {
    gsl_vector_view row = gsl_matrix_row(m, i);
    gsl_vector_scale(&row.vector, i + 1);
  }

  for (size_t i = 0; i < m->size2; i++) {
    gsl_vector_view col = gsl_matrix_column(m, i);
    gsl_vector_scale(&col.vector, i + 1);
  }

  for (size_t i = 0; i < m->size1; i++) {
    for (size_t j = 0; j < m->size2; j++) {
      printf("%g ", gsl_matrix_get(m, i, j));
    }
    printf("\n");
  }

  gsl_matrix_free(m);
  return 0;
}
