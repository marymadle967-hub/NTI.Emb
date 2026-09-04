#include "STD_TYPES.h"
#include "CALC.h"

s32 CALC_s32Calculate(s32 Num1, s32 Num2, u8 Operator)
{
    s32 Res = 0;

    switch(Operator)
    {
        case '+':
            Res = Num1 + Num2;
            break;

        case '-':
            Res = Num1 - Num2;
            break;

        case '*':
            Res = Num1 * Num2;
            break;

        case '/':
            if(Num2 != 0)
            {
                Res = Num1 / Num2;
            }
            else
            {
                Res = 0;
            }
            break;

        default:
            Res = 0;
            break;
    }

    return Res;
}