#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <time.h>
#include <regex>
#include <queue>
#include <chrono>
#include <random>
#include <stdio.h>
#include <opencv2/core.hpp> 
#include <opencv2/opencv.hpp> 
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp>

using namespace std;

struct my_point {
    int center_x;
    int center_y;
};

typedef vector<string> stringvec;

class My_Meta_EG {
    public:
        My_Meta_EG();
        float extract_total_activity();
        void Input_Metadata(int id_, int cenX, int cenY);
        void Debug_Position();
        void Calc_activity(my_point t1, my_point t2);
        double Calc_Dist(int x1, int y1, int x2, int y2);
        
        void Reset_Posion_Map();

        void Up_Count();
        int Extract_Count();
        void Up_Frame();
        int Extract_Frame();

        double Extract_Avg_Activity();
    private:
        double total_activity;
        int total_obj_count;
        int total_frame;
        map<int,my_point> Meta_Position;
};