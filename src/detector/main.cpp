#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "TesseractCustom.h"
#include "Detector_ensemble.h"
#include "factories/StreamInputFactory.h"
#include "entities/CamVidInterface.h"
#include "entities/VidFrame.h"
#include <chrono>
#include <thread>
#include "../segmenter/headers/SegmenterInterface.h"

using namespace std::chrono;
using namespace std::this_thread;

using namespace std;
using namespace cv;

//cascade8 is best till now
//cascade11 is best till now with new pics
void replaceJPG (string& gname)
{
    int len = gname.size();
    for (int i = 0; i < len; ++i) {
        if (gname[i]=='.')
        {
            //if ()
        }
    }
}

void Log(string functionName, string message)
{
    cout<<endl<<functionName<<": "<<message;
}

void getdirFiles (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (string(dirp->d_name).length()>2)
        {
            files.push_back(string(dirp->d_name));
        }
    }
    closedir(dp);
}

string removeSubstring (string text,string substring)
{
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::transform(substring.begin(), substring.end(), substring.begin(), ::tolower);

    int startPos = text.find(substring);
    text.erase(startPos,substring.length());
    return text;
}
/* Data fields and constants */
int globalCounter=0;
string extracted_img_naming_prefix="extracted";
string directoryTestImages = "testone";
string olx_images = "img_olx";
string hq_mc_pics = "hq_pics";
string few_pics_for_test_directory = "plate_pic";
string directory_in_use;

//string applyOCR (TesseractCustom tess,string imgname)
//{
//    string plateNumber = tess.applyOCR(imgname);
//    return plateNumber;
//}

//void extractPlates(Detector_Ensemble detectorEnsemble,TesseractCustom tess,const vector<string> & imagesFileNames)
//{
//    for (int i = 0; i < imagesFileNames.size() ; ++i) {
//        cout<<endl<<"Image Name: "<<imagesFileNames.at(i)<<endl;
//        Mat frame = imread("/home/abdul/CLionProjects/ClassifierTesting/"+directory_in_use+"/"+imagesFileNames.at(i),CV_LOAD_IMAGE_COLOR);
//        vector<Mat> regionsFromFrame = detectorEnsemble.detect(frame);
//        int counter = 0;
//        for (int j = 0; j < regionsFromFrame.size(); ++j) {
//            //string imgname = imagesFileNames.at(i)+to_string(counter)+".jpg";
//            string imgname = extracted_img_naming_prefix+"_"+removeSubstring(imagesFileNames.at(i),".jpg")+"_"+to_string(counter)+".png";
//            globalCounter++;
//            counter++;
//            imwrite("/home/abdul/CLionProjects/ClassifierTesting/extracted_plates/"+imgname,regionsFromFrame.at(j));
//            //string licenseNumber = applyOCR(tess,imgname);
//            //cout<<endl<<"image: "<<imgname<<", number: "<<licenseNumber;
//            cout<<endl<<"image: "<<imgname;
//        }
//    }
//}

/* Function to run a complete Plate-Extraction to OCR on given image */
void start(Detector_Ensemble &detectorEnsemble,StreamInputFactory*& factory)
{
    //creating an instance of segmenter to segment number plate character
    //for number plates detected from this video input source
    SegmenterInterface segmenterInterface;
    vector<VideoInterface*>* inputSourceList = factory->listOfInterfaces();
    int i= 2;
    long counter = 0;
    while(true)
    {
        string vidname = inputSourceList->at(0)->locationName()+to_string(inputSourceList->at(0)->id());
        int target = 111;
        if (target%i==0)
        {
            i=2;
            VidFrame* frame = inputSourceList->at(0)->nextFrame();
            if (frame== nullptr)
                break;
            vector<Mat> regionsFromFrame = detectorEnsemble.detect(frame->frame);
            for (int j = 0; j < regionsFromFrame.size(); ++j)
            {
                counter++;
                string imgname = "/home/abdul/CLionProjects/ClassifierTesting/detectorfiles/extracted_plates/"+vidname+to_string(counter)+".png";
                //writing image just for visibility and checking
                imwrite(imgname,regionsFromFrame.at(j));
                cout<<endl<<"image created: "<<imgname;
                //passing image to segmenter for segmentation
                segmenterInterface.applySegmentation(regionsFromFrame.at(j),vidname+to_string(counter));
            }
        }
        i++;
//        VidFrame* frame = inputSourceList->at(0)->nextFrame();
//        if (frame== nullptr)
//            break;
//        //namedWindow("frameShow",10);
//        imshow("frame",frame->frame);
//        waitKey(150);
    }
    Log("start","stream discontinued");
}

void printList (vector<string> list,string tagForListItems)
{
    for (int i = 0; i < list.size() ; ++i) {
        cout<<endl<<tagForListItems<<": "<<list.at(i)<<endl;
    }
}

/** @function main */
int main( int argc, const char** argv )
{
    //TesseractCustom tesseractCustom;
    Detector_Ensemble detectorEnsemble;

    StreamInputFactory* streamInputFactory = new StreamInputFactory();

    /* Initialize Tesseract, with default configuration*/
    //tesseractCustom.init();

    if (detectorEnsemble.init()==-1)
        cout<<"Loading classifier failed"<<endl;

    directory_in_use = few_pics_for_test_directory;

    vector<string> imagesFileNames;
    /* read file names from a given directory to vector: imagesFileNames */
    getdirFiles("/home/abdul/CLionProjects/ClassifierTesting/detectorfiles/"+directory_in_use+"/",imagesFileNames);

    //extractPlates(detectorEnsemble,tesseractCustom,imagesFileNames);
    start(detectorEnsemble,streamInputFactory);

    /*________ */
    cout<<endl<<"---plates extraction done on given images_for_segmentation_tesing--------";
    cout<<endl<<"Actual plates: "<<globalCounter;
    cout<<endl<<"Expected plates: "<<imagesFileNames.size();
    /* wait until user exits program by pressing Esc key */
//    while (true)
//    {
//        char c = (char)waitKey(10);
//        if( c == 27 )
//        { break; } // escape
//    }
    return 0;
}