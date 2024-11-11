#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    std::vector<std::vector<cv::Point>> contours;
    cv::cvtColor(input,input, cv::COLOR_BGR2GRAY);
    cv::findContours(input,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(input,contours,-1,cv::Scalar(255,255,255),2);
    cv::Rect rect = cv::boundingRect(contours[0]);
    cv::RotatedRect rotatedRect = cv::minAreaRect(contours[0]);
    res.first = rect;
    res.second = rotatedRect;
    // IMPLEMENT YOUR CODE HERE
    return res;
}