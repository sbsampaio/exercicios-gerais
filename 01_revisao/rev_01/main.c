#include <stdio.h>

#define PI 3.1415

typedef struct {
    float x;
    float y;
    float radius
} tCirc;

/**
* Lê da entrada padrão o centro e o raio da circunferência
*
* @param x Informa a coordenada X da circunferência
* @param y Informa a coordenada Y da circunferência
* @param radius Informa o raio da circunferência
*/

void ReadCircInfo(tCirc circ);

int main()
{
    tCirc target;
    tCirc bullet;

    ReadCircInfo(target);
    ReadCircInfo(bullet);

    return 0;
}

void ReadCircInfo(tCirc circ) {
    scanf("%f %f %f", &circ.x, &circ.y, &circ.radius);
}
