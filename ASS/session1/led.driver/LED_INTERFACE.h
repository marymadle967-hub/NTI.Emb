#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0

/* Prototypes */
void LED_voidInit(u8 PortID, u8 PinID);
void LED_voidTurnOn(u8 PortID, u8 PinID, u8 ActiveState);
void LED_voidTurnOff(u8 PortID, u8 PinID, u8 ActiveState);

#endif