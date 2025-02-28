/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2024  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V6.44 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only  be used  in accordance  with  a license  and should  not be  re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Software GmbH
Licensed to:              Renesas Electronics America Inc., 1001 Murphy Ranch Road, Milpitas, California 95035, USA
Licensed SEGGER software: emWin
License number:           GUI-00785
License model:            emWin License and Service Agreement, signed May 9th, 2019 
                          and Amendment No. 1, signed June 29, 2021
                          and Amendment No. 2, signed June 27, 2022       
Licensed platform:        ARM Cortex-M4, -M33, -M23 and -M85 based devices of the RA family of the 32-bit Microcontroller Units, designed, marketed and manufactured by LICENSEE only
----------------------------------------------------------------------
File        : GUI_SVG_Global.h
Purpose     : Global public definitions used by SVG drivers
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUI_SVG_GLOBAL_H
#define GUI_SVG_GLOBAL_H

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Standard library fixed size types
*
**********************************************************************
*/
#ifdef WIN32
  #if (_MSC_VER <= 1900)                      // Older compiler version do not know about the header
    typedef char                 int8_t;
    typedef unsigned char        uint8_t;
    typedef short                int16_t;
    typedef unsigned short       uint16_t;
    typedef int                  int32_t;
    typedef unsigned int         uint32_t;
    #if (_MSC_VER > 1200)                     // VC6 does not support typedef (unsigned) long long 
      typedef long long          int64_t;
      typedef unsigned long long uint64_t;
    #endif
  #else
    #include <stdint.h>
  #endif
#else
  #include <stdint.h>
#endif

/*********************************************************************
*
*       Macros
*
**********************************************************************
*/
//
// Redirect 3rd party typename to the same type defined as GUI_...
//
#define REDIRECT_TYPE(TYPE_NAME)    typedef GUI_##TYPE_NAME TYPE_NAME
//
// Used to define a given 3rd party type with private members
// with the same size of given type if source is not available.
//
#define DEFINE_TYPE_PRIVATE(TYPE_NAME, NUM_BYTES)   \
  typedef struct {                                  \
    U32 a[NUM_BYTES / 4];                           \
  } GUI_##TYPE_NAME;                                \
  REDIRECT_TYPE(TYPE_NAME)
//
// Used to define a given 3rd party type with public members,
// required when the named members are used in the source file.
//
#define DEFINE_TYPE_PUBLIC(TYPE_NAME, MEMBERS)   \
  typedef struct {                               \
    MEMBERS                                      \
  } GUI_##TYPE_NAME;                             \
  REDIRECT_TYPE(TYPE_NAME)


#if defined(__cplusplus)
}
#endif

#endif /* GUI_SVG_GLOBAL_H */

/*************************** End of file ****************************/
