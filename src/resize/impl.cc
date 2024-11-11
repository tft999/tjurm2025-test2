#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            for (int c = 0; c < input.channels(); c++) {
                output.at<cv::Vec3b>(i, j)[c] = input.at<cv::Vec3b>(i / scale, j / scale)[c];

        }

    }
    }
    return output;
    // IMPLEMENT YOUR CODE HERE
}