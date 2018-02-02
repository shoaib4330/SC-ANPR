//
// Created by shoaib on 11/26/17.
//
#ifndef CLASSIFIERTESTING_DETECTOR_ENSEMBLE_H
#define CLASSIFIERTESTING_DETECTOR_ENSEMBLE_H

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "TesseractCustom.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include "iostream"
using namespace std;
using namespace cv;

/* Classifiers listing */
/*  -- better.xml -> 495 out of 520 detected, img_olx
 *
 *
 */

/* Ensemble detector class */
class Detector_Ensemble {

private:
    //string window_name; = "Capture - Plate detection";
    string classifierName;
    CascadeClassifier* classifier;
    RNG* rng;

    /* Required for reading frames */
    //CvCapture* capture;
    Mat* frame;

    /* Private Functions to detect and maybe display as-well*/


//    void detectAndDispay_With_Rect_Whole_Image(Mat frame,string name)
//    {
//        cout<<endl<<"processing file: "<<name;
//        std::vector<Rect> faces;
//        Mat frame_gray;
//
//        cvtColor( frame, frame_gray, CV_BGR2GRAY );
//        equalizeHist( frame_gray, frame_gray );
//
//        //Detect Number Plate
//        classifier.detectMultiScale( frame_gray, faces, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(38,18),Size(633,300) );
//        int numDet = faces.size();
//        cout<<endl<<" "<<numDet<<" plates detected";
//        for (int i = 0; i < faces.size() ; ++i) {
//            Point p1 (faces[i].x,faces[i].y);
//            Point p2 (faces[i].x+faces[i].width,faces[i].y+faces[i].height);
//            rectangle(frame,p1,p2,cv::Scalar(0,255,0),1);
//            Mat roi (frame,Rect(faces[i].x,faces[i].y,faces[i].width, faces[i].height));
//            string imgname = to_string(counterImage)+".jpg";
//            counterImage++;
//
//            imwrite("/home/shoaib/Desktop/clion-projs/ClassifierTesting/extracted_plates/"+imgname,frame);
//        }
//        //-- Show what you got
//        imshow( window_name, frame );
//    }

public:

    Detector_Ensemble()
    {
        classifierName = "/home/abdul/CLionProjects/ClassifierTesting/classifiers/better.xml";
        classifier = new CascadeClassifier();
        rng = new RNG();
        //capture = new CvCapture();
        frame = new Mat();
    }

    int init()
    {
        /* Lets load the classifier */
        if(!classifier->load(classifierName))
        {
            return -1;
        }
        return 1;
    }

    void init(string classifierName){}

    vector<Mat> detect(Mat frame)
    {
        if (frame.empty())
        {
            cout<<endl<<"Frame is empty"<<endl;
            while (true)
            {
                char c = (char)waitKey(10);
                if( c == 27 )
                { break; } // escape
            }
        }
        /* extracted regions of interests i.e. sub-images_for_segmentation_tesing
         * to return */
        std::vector<Mat> extractedRegions;

        cout<<endl<<"Detector_Ensemble: starting processing frame:"<<endl;
        /* vector to contain list of dected regions in given frame */
        std::vector<Rect> regions;
        /* to hold grayed frame */
        Mat frame_gray;
        /* convert frame to grayscale */
        //cvtColor( frame, frame_gray, CV_BGRA2GRAY );

        cvtColor(frame, frame_gray, CV_BGR2GRAY);

        /* doing some equlaizeHist thing */
        equalizeHist( frame_gray, frame_gray );

        /* apply detection Method of OpenCV with suitable parameters*/
        classifier->detectMultiScale( frame_gray, regions, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(69.3,33),Size(633,300) );

        /* There maybe more than one regions of interest detected
         * box them in a rectangle, crop them */
        for (int i = 0; i < regions.size() ; ++i)
        {
            /* Top left point p1 */
            Point p1 (regions[i].x,regions[i].y);
            /* Bottom right point p2 */
            Point p2 (regions[i].x+regions[i].width,regions[i].y+regions[i].height);
            /* rectangle draws a green colored rectangle on area of interest */
            //rectangle(frame,p1,p2,cv::Scalar(0,255,0),1);

            /* copy current region of interest to a new frame to save it
             * as an extracted region */
            /* Define region of interest in whole image */
            Mat roi (frame,Rect(regions[i].x,regions[i].y,regions[i].width, regions[i].height));
            /* new Mat to hold extracted portion */
            Mat croppedImage;
            /* extract the interest region */
            roi.copyTo(croppedImage);

            /* add to the list */
            extractedRegions.push_back(croppedImage);
        }
        return extractedRegions;
        //-- Show what you got
        //imshow( window_name, frame );
    }

    ~Detector_Ensemble(){
        delete classifier;
        delete rng;
        //delete capture;
        delete frame;
    }
};
#endif //CLASSIFIERTESTING_DETECTOR_ENSEMBLE_H
