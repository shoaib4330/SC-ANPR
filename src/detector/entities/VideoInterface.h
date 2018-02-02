//
// Created by shoaib on 12/28/17.
//
#ifndef CLASSIFIERTESTING_VIDEOINTERFACE_H
#define CLASSIFIERTESTING_VIDEOINTERFACE_H

#include <string>

class VidFrame;

class VideoInterface {
public:
    virtual int id()=0;
    virtual std::string locationName()=0;
    virtual VidFrame* nextFrame()=0;
};
#endif //CLASSIFIERTESTING_VIDEOINTERFACE_H
