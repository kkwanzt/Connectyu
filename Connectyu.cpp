// Connectyu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Myconnnect(Mat Graysrc);
void bondBox(Mat conPicstates);
void xingtaixue(Mat src, Mat Graysrc);

cv::Mat keneral = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

int main()
{
    cv::Mat Graysrc;
    cv::Mat src = imread("D:\\opencv\\myproject\\timg.jpg");
    if (!src.data)
    {
        printf("can't get the picture");
        return -1;
    }

    xingtaixue(src, Graysrc);
    Myconnnect(Graysrc);
    return -1;
}

void xingtaixue(Mat src,Mat Graysrc)
{
    cv::Mat dilPic;
    cv::Mat eroPic;
    cv::Mat srcOpen;
    cv::Mat srcClose;

    cv::cvtColor(src, Graysrc, CV_BGR2GRAY);
    dilate(src, dilPic, keneral);
    erode(dilPic, srcClose, keneral);//闭操作
    erode(src, eroPic, keneral);
    dilate(eroPic, srcOpen, keneral);//开操作

    imshow("dilpic", dilPic);
    imshow("eropic", eroPic);
    imshow("srcOpen", srcOpen);
    imshow("srcClose", srcClose);

    waitKey(0);

}

void Myconnnect(Mat Graysrc)
{
    cv::Mat connectedPic, conPicstats, conPiccent;
    int num = connectedComponentsWithStats(Graysrc, connectedPic, conPicstats, conPiccent, 8, 4);
    bondBox(connectedPic);
    std::cout << "The number is" << num-1 << endl;
    imshow("Graysrc", Graysrc);
    waitKey(0);
}

void bondBox(Mat conPicstates)
{
    int ncomp = conPicstates;
        Scalar color = Scalar(255, 0, 0);
        for (int i = 0; i < ncomp; i++)
        {
            Rect bodbox;
            bodbox.x = conPicstates.at<int>(i, 0);
            bodbox.y = conPicstates.at<int>(i, 1);
            bodbox.width = conPicstates.at<int>(i, 2);
            bodbox.height = conPicstates.at<int>(i, 3);
            rectangle(conPicstates, bodbox, 1, 8, 0);
         }
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
