#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv/cvaux.h>
#include <opencv2/opencv.hpp>
#include <string>
#include <array>
#include <iostream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace cv;


#pragma once
class diptools
{

private:
	cv::Mat markers;


public:
	void diprefreshwindow(cv::String window)
	{
		destroyWindow(window);
		ResizeWin(window);
	}

	void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
	{
		System::Drawing::Graphics^ graphics = control->CreateGraphics();
		System::IntPtr ptr(colorImage.ptr());
		System::Drawing::Bitmap^ b;
		switch (colorImage.type())
		{
		case CV_8UC3: // non-grayscale images are correctly displayed here
			b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
				System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			break;
		case CV_8UC1: // grayscale images are incorrectly displayed here 
			b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
				System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
			break;
		default:
			// error message
			break;
		}

		System::Drawing::RectangleF rect(0, 0, (float)control->Width, (float)control->Height);
		graphics->DrawImage(b, rect);
	}

	char* ConvertString2Char(System::String^ str)
	{	// Marshal method
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		return str2;
	}
	void ResizeWin(cv::String Window)
	{
		namedWindow(Window, WINDOW_NORMAL);
		resizeWindow(Window, 800, 600);
	}

	void setMarkers(cv::Mat& markerImage)
	{
		markerImage.convertTo(markers, CV_32S);
	}

	cv::Mat process(cv::Mat &image)
	{
		cv::watershed(image, markers);
		markers.convertTo(markers, CV_8U);
		return markers;
	}
	diptools();
	~diptools();
};

