// pglerror_es20.cpp
// To detect and return the error generated by OpenGL.
// 
// Copyright 2012 - 2014 Future Interface. 
// This software is licensed under the terms of the MIT license.
// 
// Hongwei Li lihw81@gmail.com
// 

#include "../pglerror.h"

#include <PFoundation/plog.h>
#include <PFoundation/passert.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h> 


pbool P_APIENTRY pGlErrorCheck(const pchar* file, puint32 line, PLogVerbosityEnum logLevel)
{
    GLenum err = glGetError();
    if (err == GL_NO_ERROR)
    {
        return true;
    }

    pint32 errmsg = 0;

    static const pchar* ERRMSG[] =
    {
        "GL_INVALID_ENUM",
        "GL_INVALID_FRAMEBUFFER_OPERATION",
        "GL_INVALID_VALUE",
        "GL_INVALID_OPERATION",
        "GL_OUT_OF_MEMORY",
    };

    switch (err)
    {
        case GL_INVALID_ENUM: errmsg = 0;  break;
        case GL_INVALID_FRAMEBUFFER_OPERATION: errmsg = 1; break;
        case GL_INVALID_VALUE: errmsg = 2;  break;
        case GL_INVALID_OPERATION: errmsg = 3;  break;
        case GL_OUT_OF_MEMORY: errmsg = 4;  break;
    }

    pLog(logLevel, P_LOG_CHANNEL_OPENGLEGL, file, line, "%s", ERRMSG[errmsg]); 
    if (logLevel >= P_LOG_ERROR)
    {
        pAssertFunction(file, line, g_assertStyle, ERRMSG[errmsg], 0);
    }

    return false;
}

