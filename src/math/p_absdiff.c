#include <pal.h>

/**
 *
 * Compute an element wise absolute difference of two vectors 'a' and 'b'.
 *
 * @param a     Pointer to input vector
 *
 * @param b     Pointer to input vector
 *
 * @param c     Pointer to output vector
 *
 * @param n     Size of 'a' and 'c' vector.
 *
 * @param p     Number of processor to use (task parallelism)
 *
 * @param team  Team to work with 
 *
 * @return      None
 *
 */

void p_absdiff_f32(const float *a, const float *b, float *c,
                   int n, int p, p_team_t team)
{

    int i;
    for (i = 0; i < n; i++) {
        float v = *(a + i) - *(b + i);
        *(c + i) = (1 - ((v < 0) << 1)) * v;
    }
}
