/* generated configuration header file - do not edit */
#ifndef RM_EMWIN_PORT_CFG_H_
#define RM_EMWIN_PORT_CFG_H_
#include "common_data.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Library build settings */
#define GUI_OS                (1) // Context switch support enabled
#define GUI_MAXTASK           (1) // One task supported by default (can be increased at runtime via GUITASK_SetMaxTask())
#define GUI_NUM_LAYERS        (3) // Up to three displays supported
#define GUI_SUPPORT_TOUCH     (1) // Support touch screens
#define GUI_SUPPORT_MOUSE     (1) // Support a mouse
#define GUI_SUPPORT_MEMDEV    (1) // Memory devices available
#define GUI_WINSUPPORT        (1) // Window manager available
#define GUI_SUPPORT_BIDI      (1) // Bidirectional text enabled
#define GUI_DEBUG_LEVEL       (2) // Parameter and consistency checks enabled (no logging)

/* Define the available number of bytes available for the GUI */
#define GUI_NUMBYTES     (0x80000)
#define GUI_HEAPSECTION  ".bss"

/* RTOS support */
#ifndef EMWIN_CFG_RTOS
#define EMWIN_CFG_RTOS     (BSP_CFG_RTOS)
#endif

/* Wait for Vertical Sync */
#define EMWIN_LCD_VSYNC_WAIT ((1))

/* AA Font rendering */
#define EMWIN_LCD_AA_FONT_CONV_BUFFER_SIZE  (400)

/* JPEG Decode settings */
#if EMWIN_JPEG_USE_HW
 #define EMWIN_JPEG_NOCOPY               ((1))
 #define EMWIN_JPEG_DOUBLE_BUFFER_OUTPUT ((1))
 #define EMWIN_JPEG_TIMEOUT              (50)
 #if !EMWIN_JPEG_NOCOPY
  #define EMWIN_JPEG_NUMBYTES_INBUFFER    (0x1000)
 #else
  #define EMWIN_JPEG_NUMBYTES_INBUFFER    (0xFFFFFFF8U)
 #endif
 #define EMWIN_JPEG_NUMBYTES_OUTBUFFER   (0x3C00)
 #define EMWIN_JPEG_BUFFER_SECTION       ".bss"
#endif

#ifdef __cplusplus
}
#endif
#endif /* RM_EMWIN_PORT_CFG_H_ */
