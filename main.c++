#include "Functions.c++"

int main(int argc, const char** argv) {

    int T;
    cin>>T;

    for (int i= 0; i< T; i++){
        take_case();
        solve_case();
    }

    for (int i= 0; i< T; i++)
       display_result_case(i);

return 0;
}