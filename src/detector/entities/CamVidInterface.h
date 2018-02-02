//
// Created by shoaib on 12/28/17.
//

#ifndef CLASSIFIERTESTING_ROADSIDECAMVIDEOINPUT_H
#define CLASSIFIERTESTING_ROADSIDECAMVIDEOINPUT_H

#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include "VideoInterface.h"

using namespace cv;

class CamVidInterface: public VideoInterface{
private:
    int interfaceID;
    std::string interfacelocationName;
    std::string fullyQualifiedSource;
    VideoCapture* videoCapture;
    long consumedupto;
public:
    CamVidInterface ();
    CamVidInterface (int interfaceName,std::string locationName,std::string fullyQualifiedSource);
    int id();
    std::string locationName();
    VidFrame* nextFrame();
};


#endif //CLASSIFIERTESTING_ROADSIDECAMVIDEOINPUT_H
