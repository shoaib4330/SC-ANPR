cmake_minimum_required(VERSION 3.8)
project(ClassifierTesting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(OpenCV_DIR /home/abdul/opencv-3.1.0/build/)

find_package( OpenCV REQUIRED )
#find_package( tesseract REQUIRED )

find_package(PkgConfig REQUIRED)

#pkg_search_module( TESSERACT REQUIRED tesseract )

include_directories(${OpenCV_INCLUDE_DIRS})

#include_directories(${tesseract_INCLUDE_DIRS})

link_libraries( ${OpenCV_LIBS} )

#link_libraries( ${tesseract_LIBS} )
#target_link_libraries(testapp ${SDL2_LIBRARIES})
#target_include_directories(testapp PUBLIC ${SDL2_INCLUDE_DIRS})
#target_compile_options(testapp PUBLIC ${SDL2_CFLAGS_OTHER})

set(SOURCE_FILES src/detector/main.cpp src/detector/Detector_ensemble.cpp src/detector/Detector_ensemble.h src/detector/TesseractCustom.cpp src/detector/TesseractCustom.h src/detector/Constants.h src/detector/entities/VideoInterface.h src/detector/entities/CamVidInterface.cpp src/detector/entities/CamVidInterface.h src/detector/entities/VidFrame.cpp src/detector/entities/VidFrame.h src/detector/factories/StreamInputFactory.cpp src/detector/factories/StreamInputFactory.h src/segmenter/srcFiles/SegmenterInterface.cpp src/segmenter/headers/SegmenterInterface.h src/segmenter/srcFiles/DetectChars.cpp src/segmenter/headers/DetectChars.h src/segmenter/srcFiles/DetectPlates.cpp src/segmenter/headers/DetectPlates.h src/segmenter/headers/PossibleChar.h src/segmenter/srcFiles/PossibleChar.cpp src/segmenter/headers/PossiblePlate.h src/segmenter/srcFiles/PossiblePlate.cpp src/segmenter/headers/Preprocess.h src/segmenter/srcFiles/Preprocess.cpp src/segmenter/srcFiles/Main.cpp src/segmenter/headers/Main.h)
add_executable(ClassifierTesting ${SOURCE_FILES} src/detector/entities/VideoInterface.h)

target_link_libraries( ClassifierTesting ${OpenCV_LIBS} )

#target_link_libraries( ClassifierTesting libtesseract.a liblept.a)
target_link_libraries( ClassifierTesting liblept.a)
target_link_libraries( ClassifierTesting libjpeg.a)
target_link_libraries( ClassifierTesting libpng.a)
target_link_libraries( ClassifierTesting libtiff.a)
target_link_libraries( ClassifierTesting libz.a)
target_link_libraries( ClassifierTesting liblzma.a)
#target_link_libraries( ClassifierTesting libwebp.a)
#target_link_libraries( ClassifierTesting libgif.a)
target_link_libraries( ClassifierTesting libjbig.so.0)




#target_link_libraries( ClassifierTesting liblept.a)


#target_compile_options(ClassifierTesting PUBLIC ${tesseract_CFLAGS_OTHER})