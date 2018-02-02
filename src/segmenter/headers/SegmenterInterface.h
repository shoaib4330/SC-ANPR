//
// Created by abdul on 12/29/17.
//

#ifndef CLASSIFIERTESTING_SEGMENTERINTERFACE_H
#define CLASSIFIERTESTING_SEGMENTERINTERFACE_H

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "DetectPlates.h"
#include "PossiblePlate.h"
#include "DetectChars.h"
#include<iostream>


class SegmenterInterface {

public:

    void applySegmentation(cv::Mat plateImage, std::string imageName) {

        cv::Mat imgOriginalScene;           // input image
        cv::Mat resizedIMg;

        imgOriginalScene = plateImage;         // open image

        // convert image into our standard size
        cv::resize(imgOriginalScene, resizedIMg, cv::Size(210, 100));

        cv::Rect roi = cv::Rect(40, 0, 125, 100); // crop image to avoid false values
        cv::Mat cropped = cv::Mat(resizedIMg, roi);

        //cv::imshow("resized", resizedIMg);
        //cv::imshow("cropped", cropped);

        //cv::waitKey(0);
        if (imgOriginalScene.empty()) {                             // if unable to open image
            std::cout << "error: image not read from file\n\n";     // show error message on command line
            system("pause");                                               // may have to modify this line if not using Windows
            // and exit program
            return;
        }

        PossiblePlate *plate = new PossiblePlate();
        plate->imgPlate = cropped;
        plate = detectCharsInPlates(plate,imageName);// detect chars in plates

        if (plate != nullptr) {
            std::cout << "Successfully generated!!! for-->"+imageName << std::endl;
        }
    }
};


#endif //CLASSIFIERTESTING_SEGMENTERINTERFACE_H
