// mycontext.h
// "Cubemap" example
//
// Copyright 2012 - 2024 Future Interface. All rights reserved.
// This software is licensed under the terms of the MIT license.
//
// Hongwei Li lihw81@gmail.com
//

#ifndef MYCONTEXT_H
#define MYCONTEXT_H

#include <PFoundation/pcontext.h>
#include <PFoundation/pcontextproperties.h>
#include <PFoundation/parcball.h>

class MyScene;

class MyContext : public PContext
{
public:
    MyContext(const PContextProperties &properties);
    ~MyContext();
    
    virtual pbool onInitialized();
    virtual pbool onUpdate();
    virtual void onDestroy();
    
    virtual pbool onKeyboard(PEvent *event);

private:
    MyScene *m_scene;
    PArcball m_arcball;
};

#endif
