
#include "hal_data.h"
#include <stdint.h>

void R_BSP_WarmStart(bsp_warm_start_event_t event);

/* Warm start function */
void R_BSP_WarmStart(bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
        /* Handle warm start reset */
    }
}

void delay_ms(uint32_t ms)
{
    R_BSP_SoftwareDelay(ms, BSP_DELAY_UNITS_MILLISECONDS);
}

int main(void)
{
    /* Initialize LED pin as output */
    R_IOPORT_PinCfg(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_06, IOPORT_CFG_PORT_DIRECTION_OUTPUT);

    while (1)
    {
        /* Toggle LED */
        R_BSP_PinWrite(BSP_IO_PORT_01_PIN_06, BSP_IO_LEVEL_HIGH);
        delay_ms(500);
        R_BSP_PinWrite(BSP_IO_PORT_01_PIN_06, BSP_IO_LEVEL_LOW);
        delay_ms(500);
    }

    return 0;
}
