//
// Created by shoaib on 12/28/17.
//

#include "StreamInputFactory.h"
#include "../entities/CamVidInterface.h"
#include <vector>
using namespace std;

StreamInputFactory:: StreamInputFactory()
{
    this->idCount =0;
}

std::vector<VideoInterface*>* StreamInputFactory :: listOfInterfaces()
{
    vector<VideoInterface*>* videoInterfacesList = new vector<VideoInterface*>();

    VideoInterface* camInterface0= new CamVidInterface(idCount++,"faisaltown","/home/abdul/CLionProjects/ClassifierTesting/detectorfiles/videos/a.mp4");
    VideoInterface* camInterface1= new CamVidInterface(idCount++,"modeltown","/home/abdul/CLionProjects/ClassifierTesting/detectorfiles/videos/b.mp4");
    VideoInterface* camInterface2= new CamVidInterface(idCount++,"garishahu","/home/abdul/CLionProjects/ClassifierTesting/detectorfiles/videos/c.mp4");
    VideoInterface* camInterface3= new CamVidInterface(idCount++,"samanabad","/home/abdul/CLionProjects/ClassifierTesting/detectorfiles/videos/d.mp4");

    videoInterfacesList->push_back(camInterface0);
    videoInterfacesList->push_back(camInterface1);
    videoInterfacesList->push_back(camInterface2);
    videoInterfacesList->push_back(camInterface3);

    return videoInterfacesList;
}