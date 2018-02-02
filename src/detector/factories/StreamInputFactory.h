//
// Created by shoaib on 12/28/17.
//

#ifndef CLASSIFIERTESTING_STREAMINPUTFACTORY_H
#define CLASSIFIERTESTING_STREAMINPUTFACTORY_H

#include <vector>
class VideoInterface;

class StreamInputFactory {
private:
    long idCount;
public:
    StreamInputFactory();
    std::vector<VideoInterface*>* listOfInterfaces();
};


#endif //CLASSIFIERTESTING_STREAMINPUTFACTORY_H
