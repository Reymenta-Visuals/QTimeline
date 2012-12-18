/*
 *  QTimelineModule.h
 *
 *  Created by Andrea Cuius
 *  Nocte Studio Ltd. Copyright 2012 . All rights reserved.
 *
 *  www.nocte.co.uk
 *
 */

#ifndef QTIMELINE_MODULE
#define QTIMELINE_MODULE

#pragma once

#include "QTimelineModuleItem.h"


class QTimelineModule
{
    
public:
    
    QTimelineModule( std::string name, std::string type ) : mName(name), mType(type) {}
    
    ~QTimelineModule() {}
    
    virtual void update() {}
    
    virtual void render() {}
    
    virtual void init() {}
    
    std::string getName() { return mName; }
    
    void setItemRef( QTimelineModuleItemRef ref )
    {
        mModuleItemRef = ref;
    }
    
    QTimelineModuleItemRef getItemRef() { return mModuleItemRef; }
    
    int getParamsN() { return mModuleItemRef->mParams.size(); }
    
    std::vector<QTimelineParamRef> getParams() { return mModuleItemRef->mParams; }
    
    float getParamValue( std::string name ) { return mModuleItemRef->getParamValue( name ); }

    bool isPlaying() { return mModuleItemRef->isPlaying(); }
    
    std::string getType() { return mType; }
    
protected:
    
    std::string             mName;
    std::string             mType;
    
    QTimelineModuleItemRef  mModuleItemRef;
    
};

#endif