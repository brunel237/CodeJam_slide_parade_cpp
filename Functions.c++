#include <iostream>
#include <vector>

using namespace std;
using std::string;

typedef struct Building{
    int ID;
    int visited_times =0;
    struct Building* next1 =NULL;
    struct Building* next2 =NULL;
    bool next1_visited= false, next2_visited= false;
}Building;

typedef struct TestCase{
    int num_steps;
    vector <int> steps;
    bool impossible;
}TestCase;

vector <Building> List_of_buildings;
vector <TestCase> cases;

bool impossible =false;

void explore(Building* B, vector<int>* path, Building* nextB = NULL){
    if (B->next1 ==NULL && B->next2 ==NULL){impossible= true; return;} 
    if (B->ID == 1){
        path->push_back(B->ID);//cout<<B->ID<<" ";
        B->visited_times +=1;
        if (B->next1_visited && B->next2_visited){ return;}
        else{           
            if ((not B->next1_visited)&&(B->next1 != NULL)) {
                B->next1_visited = true;
                if (B->next1->next1 != NULL && B->next1->next1->ID == B->ID){
                    B->visited_times +=1;//cout<<"OK\n";
                    B->next1->visited_times +=1;
                    path->push_back(B->next1->ID);//cout<<B->next1->ID<<" ";
                    path->push_back(B->ID);//cout<<B->ID<<" ";
                    if (B->next1->next2 != NULL) explore(B->next1, path, B->next1->next2);
                
                }
                else if (B->next1->next2 != NULL && B->next1->next2->ID == B->ID){
                    B->visited_times +=1;
                    B->next1->visited_times +=1;
                    path->push_back(B->next1->ID);//cout<<B->next1->ID<<" ";
                    path->push_back(B->ID);//cout<<B->ID<<" ";
                    if (B->next1->next1 != NULL) explore(B->next1, path, B->next1->next1);
                }
                else if (B->next1->next1 != NULL || B->next1->next2 != NULL){
                    if (B->next1->next1 != NULL) explore(B->next1, path, B->next1->next1);
                    else explore(B->next1, path, B->next1->next2);
                }
                else if (B->next1->next1 == NULL && B->next1->next2 == NULL)     
                    {impossible= true; return;}    
             
            }
            if ((not B->next2_visited)&&(B->next2 != NULL)){
                B->next2_visited = true;
                if (B->next2->next1 != NULL && B->next2->next1->ID == B->ID){
                    B->visited_times +=1;
                    B->next2->visited_times +=1;
                    path->push_back(B->next2->ID);//cout<<B->next2->ID<<" ";
                    path->push_back(B->ID);//cout<<B->ID<<" ";
                    if (B->next2->next2 != NULL) explore(B->next2, path, B->next2->next2);
                }
                else if (B->next2->next2 != NULL && B->next2->next2->ID == B->ID){
                    B->visited_times +=1;
                    B->next2->visited_times +=1;
                    path->push_back(B->next2->ID);//cout<<B->next2->ID<<" ";
                    path->push_back(B->ID);//cout<<B->ID<<" ";
                    if (B->next2->next1 != NULL) explore(B->next2, path, B->next2->next1);
                }
                else if (B->next2->next1 != NULL || B->next2->next2 != NULL){
                    if (B->next2->next1 != NULL) explore(B->next2, path, B->next2->next1);
                    else explore(B->next2, path, B->next2->next2);
                }
                else if (B->next2->next1 == NULL && B->next2->next2 == NULL) {impossible= true; return;}
               // explore(B->next2, path);
            }
        }
        if (B->next1_visited && B->next2_visited) { return;}
    }
    else{
        B->visited_times +=1;
        path->push_back(B->ID);//cout<<B->ID<<" ";
        if (nextB->next1 != NULL && nextB->next1->ID == B->ID && nextB->next1_visited ==false){
            if (nextB->ID == 1) nextB->next1_visited = true;
            B->visited_times +=1;//cout<<nextB->ID<<" ";
            nextB->visited_times +=1;//cout<<B->ID<<" ";  
            path->push_back(nextB->ID);
            path->push_back(B->ID);         
            if (nextB->next2 != NULL) explore(nextB, path, nextB->next2);
        }
        else if (nextB->next2 != NULL && nextB->next2->ID == B->ID && nextB->next2_visited ==false){
            if (nextB->ID == 1) nextB->next2_visited = true;
            B->visited_times +=1;
            nextB->visited_times +=1;
            path->push_back(nextB->ID);//cout<<nextB->ID<<" ";
            path->push_back(B->ID);//cout<<B->ID<<" ";           
            if (nextB->next1 != NULL) explore(nextB, path, nextB->next1);
        }
        else if (nextB->next1 != NULL || nextB->next2 != NULL){
            if (nextB->next1 != NULL) explore(nextB, path, nextB->next1);
            else explore(nextB, path, nextB->next2);
        }
        else if (nextB->next1 == NULL && nextB->next2 == NULL) {impossible= true; return;}
    }
}

void take_case(){
    int B, S;
    cin>>B>>S;

    for (int i= 1; i<= B; i++){
        Building Bld;
        Bld.ID = i;
        List_of_buildings.push_back(Bld);
   }

    int Ui, Vi;

    for (int i= 1; i<= S; i++){
        cin>>Ui>>Vi;
        if ( List_of_buildings.at(Ui-1).next1 == NULL)
            List_of_buildings.at(Ui-1).next1= &List_of_buildings.at(Vi-1);
        else if ( List_of_buildings.at(Ui-1).next2 == NULL)
            List_of_buildings.at(Ui-1).next2= &List_of_buildings.at(Vi-1);        
   }

}

void solve_case(){

    vector<int> path;
    vector<int>* path_ptr = &path;

    Building* list_ptr;
    list_ptr = &List_of_buildings.at(0);

    explore(list_ptr, path_ptr);
   
    int vst = List_of_buildings.at(0).visited_times -=1;
    int i= 1;

    while ( i< List_of_buildings.size()){
        if (List_of_buildings.at(i).visited_times == vst) i++;
        else {
            impossible = true;
            break;
        }       
    }

    TestCase case_rec;

    if (impossible) case_rec.impossible = true;
    else{
        case_rec.impossible = false;
        case_rec.num_steps = path.size();
        case_rec.steps = path;
    }

    cases.push_back(case_rec);

    impossible = false;
    List_of_buildings.clear();
}

void display_result_case(int case_num){
    cout<<"Case #"<<case_num+1;   
    
    if (cases.at(case_num).impossible ==true) cout<<": IMPOSSIBLE"<<endl;
    else{
        cout<<": "<<cases.at(case_num).num_steps<<endl;
        for (const int& i: cases.at(case_num).steps)
            cout<<i<<" ";
        cout<<endl;
    }
}

