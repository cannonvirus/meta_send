#include "meta_edge.h"

using namespace std;

int main() {

    My_Meta_EG My_metadata;
    My_metadata.Input_Metadata(1, 100, 200);
    My_metadata.Input_Metadata(1, 150, 300);
    My_metadata.Input_Metadata(2, 500, 800);
    My_metadata.Input_Metadata(2, 900, 400);    
    My_metadata.Input_Metadata(1, 70, 80);

    My_metadata.Up_Count();
    My_metadata.Up_Count();
    My_metadata.Up_Count();
    My_metadata.Up_Count();
    My_metadata.Up_Count();
    My_metadata.Up_Count();

    My_metadata.Up_Frame();
    My_metadata.Up_Frame();
    My_metadata.Up_Frame();

    cout << "MAIN : " << My_metadata.extract_total_activity() << endl;
    cout << My_metadata.Extract_Count() << endl;
    cout << My_metadata.Extract_Frame() << endl;

    cout << My_metadata.Extract_Avg_Activity() << endl;

    return 1;
}