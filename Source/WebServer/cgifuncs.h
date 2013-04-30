/************************************************************************************
** File: - E:\ARM\lm3s8962projects\WebServer_IO\Source\WebServer\cgifuncs.h
**  
** Copyright (C), Long.Luo, All Rights Reserved!
** 
** Description: 
**      cgifuncs.c - Helper functions related to CGI script parameter parsing.
** 
** Version: 1.0
** Date created: 16:23:29,30/04/2013
** Author: Long.Luo
** 
** --------------------------- Revision History: --------------------------------
** 	<author>	<data>			<desc>
** 
************************************************************************************/

#ifndef __CGIFUNCS_H__
#define __CGIFUNCS_H__


//*****************************************************************************
//
// Prototypes of functions exported by this module.
//
//*****************************************************************************
int FindCGIParameter(const char *pcToFind, char *pcParam[], int iNumParams);
tBoolean IsValidHexDigit(const char cDigit);
unsigned char HexDigit(const char cDigit);
tBoolean DecodeHexEscape(const char *pcEncoded, char *pcDecoded);
unsigned long EncodeFormString(const char *pcDecoded, char *pcEncoded,
                               unsigned long ulLen);
unsigned long DecodeFormString(const  char *pcEncoded, char *pcDecoded,
                               unsigned long ulLen);
tBoolean CheckDecimalParam(const char *pcValue, long *plValue);
long GetCGIParam(const char *pcName, char *pcParams[], char *pcValue[],
                 int iNumParams, tBoolean *pbError);

#endif // __CGIFUNCS_H__

