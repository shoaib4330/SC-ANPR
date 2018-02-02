//
// Created by shoaib on 12/28/17.
//

#include "CamVidInterface.h"
#include "VidFrame.h"

CamVidInterface::CamVidInterface()
{
    this->videoCapture = nullptr;
    this->consumedupto = 0;
}

CamVidInterface::CamVidInterface(int interfaceID,std::string locationName,std::string fullyQualifiedSource)
{
    this->videoCapture = nullptr;
    this->consumedupto = 0;
    this->interfaceID = interfaceID;
    this->interfacelocationName = locationName;
    this->fullyQualifiedSource = fullyQualifiedSource;
}

int CamVidInterface::id()
{
    return this->interfaceID;
}

std::string CamVidInterface::locationName()
{
    return this->interfacelocationName;
}

VidFrame* CamVidInterface::nextFrame()
{
    if (this->videoCapture == nullptr)
    {
        this->videoCapture = new VideoCapture();
        //this->videoCapture->open(fullyQualifiedSource);
    }

    if (!this->videoCapture->isOpened())
    {
        this->videoCapture->open(fullyQualifiedSource);
    }

    if (this->videoCapture->isOpened())
    {
        VidFrame* vidFrame = new VidFrame();
        bool success = this->videoCapture->read(vidFrame->frame);
        if (success)
            return vidFrame;
        //*this->videoCapture>>vidFrame->frame;
    }
    return nullptr;
}