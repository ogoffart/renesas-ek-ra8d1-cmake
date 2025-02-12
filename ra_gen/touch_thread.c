/* generated thread source file - do not edit */
#include "touch_thread.h"

#if 1
static StaticTask_t touch_thread_memory;
#if defined(__ARMCC_VERSION)           /* AC6 compiler */
                static uint8_t touch_thread_stack[0x4000] BSP_PLACE_IN_SECTION(BSP_UNINIT_SECTION_PREFIX ".stack.thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
                #else
static uint8_t touch_thread_stack[0x4000] BSP_PLACE_IN_SECTION(BSP_UNINIT_SECTION_PREFIX ".stack.touch_thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
#endif
#endif
TaskHandle_t touch_thread;
void touch_thread_create(void);
static void touch_thread_func(void *pvParameters);
void rtos_startup_err_callback(void *p_instance, void *p_data);
void rtos_startup_common_init(void);
iic_master_instance_ctrl_t g_i2c_gt911_ctrl;
const iic_master_extended_cfg_t g_i2c_gt911_extend =
{ .timeout_mode = IIC_MASTER_TIMEOUT_MODE_SHORT,
  .timeout_scl_low = IIC_MASTER_TIMEOUT_SCL_LOW_ENABLED,
  .smbus_operation = 0,
  /* Actual calculated bitrate: 98945. Actual calculated duty cycle: 51%. */.clock_settings.brl_value = 15,
  .clock_settings.brh_value = 16,
  .clock_settings.cks_value = 4,
  .clock_settings.sddl_value = 0,
  .clock_settings.dlcs_value = 0, };
const i2c_master_cfg_t g_i2c_gt911_cfg =
{ .channel = 1, .rate = I2C_MASTER_RATE_STANDARD, .slave = 0x14, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .p_callback = touch_i2c_callback,
  .p_context = NULL,
#if defined(VECTOR_NUMBER_IIC1_RXI)
    .rxi_irq             = VECTOR_NUMBER_IIC1_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TXI)
    .txi_irq             = VECTOR_NUMBER_IIC1_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_TEI)
    .tei_irq             = VECTOR_NUMBER_IIC1_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_IIC1_ERI)
    .eri_irq             = VECTOR_NUMBER_IIC1_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
  .ipl = (6),
  .p_extend = &g_i2c_gt911_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_gt911 =
{ .p_ctrl = &g_i2c_gt911_ctrl, .p_cfg = &g_i2c_gt911_cfg, .p_api = &g_i2c_master_on_iic };
extern uint32_t g_fsp_common_thread_count;

const rm_freertos_port_parameters_t touch_thread_parameters =
{ .p_context = (void*) NULL, };

void touch_thread_create(void)
{
    /* Increment count so we will know the number of threads created in the RA Configuration editor. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

#if 1
    touch_thread = xTaskCreateStatic (
#else
                    BaseType_t touch_thread_create_err = xTaskCreate(
                    #endif
                                      touch_thread_func,
                                      (const char*) "Touch Thread", 0x4000 / 4, // In words, not bytes
                                      (void*) &touch_thread_parameters, //pvParameters
                                      11,
#if 1
                                      (StackType_t*) &touch_thread_stack,
                                      (StaticTask_t*) &touch_thread_memory
#else
                        & touch_thread
                        #endif
                                      );

#if 1
    if (NULL == touch_thread)
    {
        rtos_startup_err_callback (touch_thread, 0);
    }
#else
                    if (pdPASS != touch_thread_create_err)
                    {
                        rtos_startup_err_callback(touch_thread, 0);
                    }
                    #endif
}
static void touch_thread_func(void *pvParameters)
{
    /* Initialize common components */
    rtos_startup_common_init ();

    /* Initialize each module instance. */

#if (1 == BSP_TZ_NONSECURE_BUILD) && (1 == 1)
                    /* When FreeRTOS is used in a non-secure TrustZone application, portALLOCATE_SECURE_CONTEXT must be called prior
                     * to calling any non-secure callable function in a thread. The parameter is unused in the FSP implementation.
                     * If no slots are available then configASSERT() will be called from vPortSVCHandler_C(). If this occurs, the
                     * application will need to either increase the value of the "Process Stack Slots" Property in the rm_tz_context
                     * module in the secure project or decrease the number of threads in the non-secure project that are allocating
                     * a secure context. Users can control which threads allocate a secure context via the Properties tab when
                     * selecting each thread. Note that the idle thread in FreeRTOS requires a secure context so the application
                     * will need at least 1 secure context even if no user threads make secure calls. */
                     portALLOCATE_SECURE_CONTEXT(0);
                    #endif

    /* Enter user code for this thread. Pass task handle. */
    touch_thread_entry (pvParameters);
}
