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
File        : WINDOW_Private.h
Purpose     : WINDOW private header file
--------------------END-OF-HEADER-------------------------------------
*/

#ifndef WINDOW_PRIVATE_H
#define WINDOW_PRIVATE_H

#if GUI_WINSUPPORT

/*********************************************************************
*
*       Object definition
*
**********************************************************************
*/

typedef struct {
  WIDGET Widget;
  WM_CALLBACK * cb;
  WM_HWIN hFocusedChild;
  WM_DIALOG_STATUS * pDialogStatus;
  GUI_COLOR BkColor;
} WINDOW_OBJ;

/*********************************************************************
*
*       Externals
*
**********************************************************************
*/

extern GUI_COLOR WINDOW__DefaultBkColor;

#endif   /* GUI_WINSUPPORT */
#endif   /* WINDOW_PRIVATE_H */

/*************************** End of file ****************************/
