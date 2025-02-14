// ppath.h
// Path operations
// 
// Copyright 2012 - 2014 Future Interface. 
// This software is licensed under the terms of the MIT license.
//
// Hongwei Li lihw81@gmail.com
//

#ifndef PPATH_H
#define PPATH_H

#include <PFoundation/pglobal.h>

P_EXTERN const pchar * P_APIENTRY pPathGetSystemDirectory();
P_EXTERN const pchar * P_APIENTRY pPathGetDelimiter();
P_EXTERN const pchar * P_APIENTRY pPathGetSDCardPath();

#endif // !PPATH_H
