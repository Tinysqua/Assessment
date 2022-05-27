#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    //"assets/src.jpg"`
    //"/home/fang/practise/Assessment/opencv/assets/src.jpg"
    Mat src = imread("../assets/src.jpg");

    Mat grey, dst, dst1;
    cvtColor(src, grey, COLOR_BGR2GRAY);
    threshold(grey, dst, 190, 255,THRESH_BINARY);

    //I will disappear the noise
    Mat k = getStructuringElement(MORPH_RECT, Size(2, 2));
    Mat big_element = getStructuringElement(MORPH_RECT, Size(8,8));
    morphologyEx(dst, dst1, MORPH_OPEN, k, Point(-1,-1), 5);
    morphologyEx(dst1, dst, MORPH_CLOSE, big_element, Point(-1,-1), 3);

    //then we will find the contours
    vector<vector<Point>> contours;
    vector<Vec4i> hierachy;
    findContours(dst, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));


    //This is the approximate of the Poly
    vector<vector<Point>> approx(contours.size());
    for(int i=0;i<contours.size();i++)
    {
        approxPolyDP(contours[i], approx[i], contours.size(),true );
    }


    //I'll take the useful information
    vector<Point> cache;
    cache = approx[8];
   



    //It's for the transformation
    int constant = 87;
    Mat success = Mat::zeros(constant*17-25, constant*9-10, CV_8UC3);
    vector<Point2f> before(4);
    before[0] = cache[0];
    before[1] = cache[3];
    before[2] = cache[1];
    before[3] = cache[2];

    vector<Point2f> after(4);
    after[0] = Point(0,0);
    after[1] = Point(779.24, 0);
    after[2] = Point(0, 1446);
    after[3] = Point(779.24, 1446);

    
    Mat M;
    M = getPerspectiveTransform(before, after);
    warpPerspective(src, success, M, success.size());

    namedWindow("Final_effect", WINDOW_NORMAL);
    imshow("Final_effect", success);
    imwrite("result_,made_by_FangZhaojie.png",success);
    waitKey(0);
    return 0;
}