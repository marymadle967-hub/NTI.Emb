#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

void LED_voidInit(u8 PortID, u8 PinID)
{
    /* ضبط البن الخاص بالـ LED كـ OUTPUT */
    DIO_voidSetPinDirection(PortID, PinID, OUTPUT);
}

void LED_voidTurnOn(u8 PortID, u8 PinID, u8 ActiveState)
{
    if (ActiveState == ACTIVE_HIGH)
    {
        DIO_voidSetPinValue(PortID, PinID, HIGH);
    }
    else if (ActiveState == ACTIVE_LOW)
    {
        DIO_voidSetPinValue(PortID, PinID, LOW);
    }
}

void LED_voidTurnOff(u8 PortID, u8 PinID, u8 ActiveState)
{
    if (ActiveState == ACTIVE_HIGH)
    {
        DIO_voidSetPinValue(PortID, PinID, LOW);
    }
    else if (ActiveState == ACTIVE_LOW)
    {
        DIO_voidSetPinValue(PortID, PinID, HIGH);
    }
}