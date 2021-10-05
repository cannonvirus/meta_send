#include "meta_edge.h"

using namespace std;

My_Meta_EG::My_Meta_EG() {
    total_activity = 0.0;
    total_obj_count = 0;
    total_frame = 0;
}


float My_Meta_EG::extract_total_activity() {
    return total_activity;
}

void My_Meta_EG::Input_Metadata(int id_, int cenX, int cenY) {

    if (Meta_Position.find(id_) != Meta_Position.end()) {
        cout << "find" << endl;

        my_point position;
        position.center_x = cenX;
        position.center_y = cenY;

        Calc_activity(position, Meta_Position[id_]);

        Meta_Position[id_] = position;

    } else {
        my_point position;
        position.center_x = cenX;
        position.center_y = cenY;
        Meta_Position.insert({id_, position});
    }
    
}

void My_Meta_EG::Debug_Position(){
    for (auto iter = Meta_Position.begin(); iter != Meta_Position.end(); iter++) { 
        cout << "----------------------------------" << endl;
        cout << "IDX : " << iter->first << endl;
        cout << "center X : " << (iter->second).center_x << endl;
        cout << "center Y : " << (iter->second).center_y << endl;
        cout << "----------------------------------" << endl;
    }
}

void My_Meta_EG::Calc_activity(my_point t1, my_point t2) {
    double dist = Calc_Dist(t1.center_x, t1.center_y, t2.center_x, t2.center_y);
    cout << "DISTANCE : " <<  dist << endl;
    total_activity += dist;
}

double My_Meta_EG::Calc_Dist(int t1_x, int t1_y, int t2_x, int t2_y) {

    double x1 = static_cast<double>(t1_x);
    double y1 = static_cast<double>(t1_y);
    double x2 = static_cast<double>(t2_x);
    double y2 = static_cast<double>(t2_y);

	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);                  

	return dist;
}

void My_Meta_EG::Reset_Posion_Map(){
    Meta_Position.clear();
    total_activity = 0.0;
    total_obj_count = 0;
    total_frame = 0;
}

void My_Meta_EG::Up_Count() {
    total_obj_count += 1;
}

int My_Meta_EG::Extract_Count() {
    return total_obj_count;
}

void My_Meta_EG::Up_Frame() {
    total_frame += 1;
}

int My_Meta_EG::Extract_Frame() {
    return total_frame;
}

double My_Meta_EG::Extract_Avg_Activity() {
    double avg_obj_per_frame = total_obj_count / total_frame;
    double avg_activity = total_activity / avg_obj_per_frame;
    return avg_activity;
}