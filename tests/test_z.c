#include <stdio.h>
#include <math.h>

double norm(float *v1)
{
	return (sqrt(pow(v1[0], 2) + pow(v1[1], 2) + pow(v1[2], 2)));
}

double escalar(float *v1, float *v2)
{
	return ((v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]));
}

int main()
{
	float norma[3];
	float rayo[3];

	float centro[3];
	float colision[3];
	float luz[3];

	double rayo_len;
	double norma_len;

	centro[0] = 0;
	centro[1] = 0;
	centro[2] = 50;

	colision[0] = 3;
	colision[1] = 4;
	colision[2] = 46;

	luz[0] = 50;
	luz[1] = 50;
	luz[2] = 42;

	norma[0] = colision[0] - centro[0];
	norma[1] = colision[1] - centro[1];
	norma[2] = colision[2] - centro[2];

	rayo[0] = luz[0] - colision[0];
	rayo[1] = luz[1] - colision[1];
	rayo[2] = luz[2] - colision[2];

	rayo_len = norm(rayo);
	norma_len = norm(norma);

	rayo[0] /= rayo_len;
	rayo[1] /= rayo_len;
	rayo[2] /= rayo_len;

	norma[0] /= norma_len;
	norma[1] /= norma_len;
	norma[2] /= norma_len;

	printf("producto escalar: (%f)\n", escalar(rayo, norma));
}
