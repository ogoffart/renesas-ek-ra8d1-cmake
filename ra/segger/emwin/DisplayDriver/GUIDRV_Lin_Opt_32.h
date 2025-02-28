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
File        : GUIDRV_Lin_Opt_32.h
Purpose     : Optimized routines, included by GUIDRV_Lin_..._32.c
---------------------------END-OF-HEADER------------------------------
*/

/*********************************************************************
*
*       Static functions
*
**********************************************************************
*/
/*********************************************************************
*
*       _DrawHLineOpt32
*/
static void _DrawHLineOpt32(GUI_DEVICE * pDevice, int y, int x0, int x1) {
  DRIVER_CONTEXT * pContext;
  register LCD_PIXELINDEX ColorIndex;
  U32 * pDest;
  U32 Off, RemPixels;
  LCD_PIXELINDEX IndexMask;

  pContext  = (DRIVER_CONTEXT *)pDevice->u.pContext;
  RemPixels = x1 - x0 + 1;
  Off       = XY2OFF32(pContext->vxSizePhys, x0, y);
  pDest     = OFF2PTR32(pContext->VRAMAddr, Off);
  if (GUI_pContext->DrawMode & LCD_DRAWMODE_XOR) {
    IndexMask = pDevice->pColorConvAPI->pfGetIndexMask() & 0x00FFFFFF;
    do {
      ColorIndex  = READ_MEM32P(pDest);
      ColorIndex ^= IndexMask;
      WRITE_MEM32P(pDest, ColorIndex);
      pDest++;
    } while (--RemPixels);
  } else {
    ColorIndex = LCD__GetColorIndex();
    if (RemPixels >= 16) {
      do {
        WRITE_MEM32P(pDest     , ColorIndex);
        WRITE_MEM32P(pDest +  1, ColorIndex);
        WRITE_MEM32P(pDest +  2, ColorIndex);
        WRITE_MEM32P(pDest +  3, ColorIndex);
        WRITE_MEM32P(pDest +  4, ColorIndex);
        WRITE_MEM32P(pDest +  5, ColorIndex);
        WRITE_MEM32P(pDest +  6, ColorIndex);
        WRITE_MEM32P(pDest +  7, ColorIndex);
        WRITE_MEM32P(pDest +  8, ColorIndex);
        WRITE_MEM32P(pDest +  9, ColorIndex);
        WRITE_MEM32P(pDest + 10, ColorIndex);
        WRITE_MEM32P(pDest + 11, ColorIndex);
        WRITE_MEM32P(pDest + 12, ColorIndex);
        WRITE_MEM32P(pDest + 13, ColorIndex);
        WRITE_MEM32P(pDest + 14, ColorIndex);
        WRITE_MEM32P(pDest + 15, ColorIndex);
        pDest     += 16;
        RemPixels -= 16;
      } while (RemPixels >= 16);
      RemPixels -= (RemPixels >> 4) << 4;
    }
    while (RemPixels--) {
      WRITE_MEM32P(pDest, ColorIndex);
      pDest++;
    }
  }
}

/*********************************************************************
*
*       _DrawVLineOpt32
*/
static void _DrawVLineOpt32(GUI_DEVICE * pDevice, int x, int y0, int y1) {
  DRIVER_CONTEXT * pContext;
  register LCD_PIXELINDEX ColorIndex;
  U32 * pDest;
  U32 Off, NumLines, OffLine;
  LCD_PIXELINDEX IndexMask;

  pContext = (DRIVER_CONTEXT *)pDevice->u.pContext;
  NumLines = y1 - y0 + 1;
  OffLine  = pContext->vxSizePhys;
  Off      = XY2OFF32(pContext->vxSizePhys, x, y0);
  pDest    = OFF2PTR32(pContext->VRAMAddr, Off);
  if (GUI_pContext->DrawMode & LCD_DRAWMODE_XOR) {
    IndexMask = pDevice->pColorConvAPI->pfGetIndexMask() & 0x00FFFFFF;
    do {
      ColorIndex  = READ_MEM32P(pDest);
      ColorIndex ^= IndexMask;
      WRITE_MEM32P(pDest, ColorIndex);
      pDest += OffLine;
    } while (--NumLines);
  } else {
    ColorIndex = LCD__GetColorIndex();
    do {
      WRITE_MEM32P(pDest, ColorIndex);
      pDest += OffLine;
    } while (--NumLines);
  }
}

/*********************************************************************
*
*       _FillRectOpt32
*
* Purpose:
*   Optimized filling routine for 32 bpp
*/
static void _FillRectOpt32(GUI_DEVICE * pDevice, int x0, int y0, int x1, int y1) {
  DRIVER_CONTEXT * pContext;
  register LCD_PIXELINDEX ColorIndex;
  U32 * pDest;
  U32 * pDest0;
  U32 Off, Off0, RemPixels, NumLines, RemLines, OffLine, RemItems;
  LCD_PIXELINDEX IndexMask;

  pContext  = (DRIVER_CONTEXT *)pDevice->u.pContext;
  RemPixels = x1 - x0 + 1;
  NumLines  = y1 - y0 + 1;
  OffLine   = pContext->vxSizePhys;
  pDest     = NULL;
  if (GUI_pContext->DrawMode & LCD_DRAWMODE_XOR) {
    IndexMask = pDevice->pColorConvAPI->pfGetIndexMask() & 0x00FFFFFF;
    Off0      = XY2OFF32(pContext->vxSizePhys, x0, y0);
    if (RemPixels) {
      for (RemLines = NumLines; RemLines; RemLines--) {
        RemItems = RemPixels;
        Off = Off0 + OffLine * (RemLines - 1);
        do {
          ColorIndex  = READ_MEM32(pContext->VRAMAddr, Off);
          ColorIndex ^= IndexMask;
          WRITE_MEM32(pContext->VRAMAddr, Off, ColorIndex);
          Off++;
        } while (--RemItems);
      }
    }
  } else {
    Off        = XY2OFF32(pContext->vxSizePhys, x0, y0);
    pDest0     = OFF2PTR32(pContext->VRAMAddr, Off);
    ColorIndex = LCD__GetColorIndex();
    if (RemPixels >= 16) {
      for (RemLines = NumLines; RemLines; RemLines--) {
        RemItems = RemPixels;
        pDest    = pDest0 + OffLine * (RemLines - 1);
        do {
          WRITE_MEM32P(pDest     , ColorIndex);
          WRITE_MEM32P(pDest +  1, ColorIndex);
          WRITE_MEM32P(pDest +  2, ColorIndex);
          WRITE_MEM32P(pDest +  3, ColorIndex);
          WRITE_MEM32P(pDest +  4, ColorIndex);
          WRITE_MEM32P(pDest +  5, ColorIndex);
          WRITE_MEM32P(pDest +  6, ColorIndex);
          WRITE_MEM32P(pDest +  7, ColorIndex);
          WRITE_MEM32P(pDest +  8, ColorIndex);
          WRITE_MEM32P(pDest +  9, ColorIndex);
          WRITE_MEM32P(pDest + 10, ColorIndex);
          WRITE_MEM32P(pDest + 11, ColorIndex);
          WRITE_MEM32P(pDest + 12, ColorIndex);
          WRITE_MEM32P(pDest + 13, ColorIndex);
          WRITE_MEM32P(pDest + 14, ColorIndex);
          WRITE_MEM32P(pDest + 15, ColorIndex);
          pDest     += 16;
          RemItems -= 16;
        } while (RemItems >= 16);
      }
      pDest0 = pDest;
      RemPixels -= (RemPixels >> 4) << 4;
    }
    if (RemPixels) {
      for (RemLines = NumLines; RemLines; RemLines--) {
        RemItems = RemPixels;
        pDest    = pDest0 + OffLine * (RemLines - 1);
        do {
          WRITE_MEM32P(pDest, ColorIndex);
          pDest++;
        } while (--RemItems);
      }
    }
  }
}

/*************************** End of file ****************************/
