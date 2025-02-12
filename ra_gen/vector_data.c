/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = glcdc_line_detect_isr, /* GLCDC LINE DETECT (Specified line) */
            [1] = mipi_dsi_seq0, /* MIPIDSI SEQ0 (Sequence operation channel 0 interrupt) */
            [2] = mipi_dsi_seq1, /* MIPIDSI SEQ1 (Sequence operation channel 1 interrupt) */
            [3] = mipi_dsi_vin1, /* MIPIDSI VIN1 (Video-Input operation channel1 interrupt) */
            [4] = mipi_dsi_rcv, /* MIPIDSI RCV (DSI packet receive interrupt) */
            [5] = mipi_dsi_ferr, /* MIPIDSI FERR (DSI fatal error interrupt) */
            [6] = mipi_dsi_ppi, /* MIPIDSI PPI (DSI D-PHY PPI interrupt) */
            [7] = drw_int_isr, /* DRW INT (DRW interrupt) */
            [8] = r_icu_isr, /* ICU IRQ3 (External pin interrupt 3) */
            [9] = iic_master_rxi_isr, /* IIC1 RXI (Receive data full) */
            [10] = iic_master_txi_isr, /* IIC1 TXI (Transmit data empty) */
            [11] = iic_master_tei_isr, /* IIC1 TEI (Transmit end) */
            [12] = iic_master_eri_isr, /* IIC1 ERI (Transfer error) */
            [13] = rtc_alarm_periodic_isr, /* RTC PERIOD (Periodic interrupt) */
            [14] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
        };
        #if BSP_FEATURE_ICU_HAS_IELSR
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_VECT_ENUM(EVENT_GLCDC_LINE_DETECT,GROUP0), /* GLCDC LINE DETECT (Specified line) */
            [1] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_SEQ0,GROUP1), /* MIPIDSI SEQ0 (Sequence operation channel 0 interrupt) */
            [2] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_SEQ1,GROUP2), /* MIPIDSI SEQ1 (Sequence operation channel 1 interrupt) */
            [3] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_VIN1,GROUP3), /* MIPIDSI VIN1 (Video-Input operation channel1 interrupt) */
            [4] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_RCV,GROUP4), /* MIPIDSI RCV (DSI packet receive interrupt) */
            [5] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_FERR,GROUP5), /* MIPIDSI FERR (DSI fatal error interrupt) */
            [6] = BSP_PRV_VECT_ENUM(EVENT_MIPIDSI_PPI,GROUP6), /* MIPIDSI PPI (DSI D-PHY PPI interrupt) */
            [7] = BSP_PRV_VECT_ENUM(EVENT_DRW_INT,GROUP7), /* DRW INT (DRW interrupt) */
            [8] = BSP_PRV_VECT_ENUM(EVENT_ICU_IRQ3,GROUP0), /* ICU IRQ3 (External pin interrupt 3) */
            [9] = BSP_PRV_VECT_ENUM(EVENT_IIC1_RXI,GROUP1), /* IIC1 RXI (Receive data full) */
            [10] = BSP_PRV_VECT_ENUM(EVENT_IIC1_TXI,GROUP2), /* IIC1 TXI (Transmit data empty) */
            [11] = BSP_PRV_VECT_ENUM(EVENT_IIC1_TEI,GROUP3), /* IIC1 TEI (Transmit end) */
            [12] = BSP_PRV_VECT_ENUM(EVENT_IIC1_ERI,GROUP4), /* IIC1 ERI (Transfer error) */
            [13] = BSP_PRV_VECT_ENUM(EVENT_RTC_PERIOD,GROUP5), /* RTC PERIOD (Periodic interrupt) */
            [14] = BSP_PRV_VECT_ENUM(EVENT_RTC_CARRY,GROUP6), /* RTC CARRY (Carry interrupt) */
        };
        #endif
        #endif
