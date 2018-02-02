//Created by Shoaib
#ifndef CLASSIFIERTESTING_TESSERACTCUSTOM_H
#define CLASSIFIERTESTING_TESSERACTCUSTOM_H

//#include <tesseract/baseapi.h>
//#include <leptonica/allheaders.h>
//#include <string>
//#include <iostream>
//#include <stdio.h>
//using namespace std;

#include "Constants.h"

class TesseractCustom {
//private:
//    tesseract::TessBaseAPI *api;
//public:
//    TesseractCustom()
//    {
//        api = new tesseract::TessBaseAPI();
//    }
//
//    void init()
//    {
//        /* Initialize tesseract-ocr with English, without specifying
//         * tessdata path */
//        if (api->Init(NULL, "eng"))
//        {
//            fprintf(stderr, "Could not initialize tesseract.\n");
//            exit(1);
//        }
//    }
//
//    char* applyOCR (string imageName)
//    {
//        string fullyQualifiedImagePath = Constants::project_dirs_abs_path+"/"+Constants::extracted_plates_dir_name+"/"+imageName;
//        /* Open input image with leptonica library */
//        const char* imagepath = fullyQualifiedImagePath.c_str();
//
//        Pix *image = pixRead(imagepath);
//
//        api->SetImage(image);
//        /* Get OCR result */
//        char* outputText = api->GetUTF8Text();
//        /* Destroy used object and release memory */
//        api->End();
//        pixDestroy(&image);
//        /* return the extract ocr text */
//        return outputText;
//    }
};


#endif //CLASSIFIERTESTING_TESSERACTCUSTOM_H
