#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor_compra;
    float valor_venda;

    printf("Insira o valor do produto: ");
    scanf("%f",&valor_compra);

    if(valor_compra < 20)
    {
        valor_venda = (valor_compra *145) / 100;
    }

    if(valor_compra >= 20)
    {
        valor_venda = (valor_compra * 130) / 100;
    }


    printf("O valor da venda sera: %.2f",valor_venda);

    return 0;
}
