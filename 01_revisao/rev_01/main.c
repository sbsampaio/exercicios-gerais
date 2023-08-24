#include <stdio.h>
#include <math.h>

#define PI 3.1415

typedef struct
{
    float x;
    float y;
    float radius;
} tCirc;

/**
 * Lê da entrada padrão o centro e o raio da circunferência
 *
 * @return Retorna o objeto do tipo tCirc inicializado
 */

tCirc ReadCircInfo();

/**
 * Calcula a distância em x entre dois pontos
 *
 * @param target Recebe o alvo
 * @param bullet Recebe o projétil
 * @return Retorna a distância entre os pontos
 */

float CalcDistance(tCirc target, tCirc bullet);

int main()
{
    tCirc target = ReadCircInfo();
    tCirc bullet = ReadCircInfo();

    float distance = CalcDistance(target, bullet);

    if (distance > target.radius + bullet.radius)
        printf("ERROU");
    else
        printf("ACERTOU");

    return 0;
}

tCirc ReadCircInfo()
{
    tCirc circ;

    scanf("%f %f %f\n", &circ.x, &circ.y, &circ.radius);

    return circ;
}

float CalcDistance(tCirc target, tCirc bullet)
{
    float delta_x = target.x - bullet.x;
    float delta_y = target.y - bullet.y;

    float distance = sqrt(delta_x * delta_x + delta_y * delta_y);

    return distance;
}