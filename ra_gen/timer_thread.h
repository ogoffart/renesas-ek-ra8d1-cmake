/* generated thread header file - do not edit */
#ifndef TIMER_THREAD_H_
#define TIMER_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void timer_thread_entry(void * pvParameters);
                #else
extern void timer_thread_entry(void *pvParameters);
#endif
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_rtc.h"
#include "r_rtc_api.h"
FSP_HEADER
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer_PWM;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_timer_PWM_ctrl;
extern const timer_cfg_t g_timer_PWM_cfg;

#ifndef NULL
void NULL(timer_callback_args_t *p_args);
#endif
/* RTC Instance. */
extern const rtc_instance_t g_rtc_timer;

/** Access the RTC instance using these structures when calling API functions directly (::p_api is not used). */
extern rtc_instance_ctrl_t g_rtc_timer_ctrl;
extern const rtc_cfg_t g_rtc_timer_cfg;

#ifndef timer_rtc_callback
void timer_rtc_callback(rtc_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* TIMER_THREAD_H_ */
