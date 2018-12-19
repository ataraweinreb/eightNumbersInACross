
#include <cstdlib>
#include <iostream>
using namespace std;
//backtrack and try again
void backtrack(int &square){
    square--;
    if(square==-1) exit(1); //if you backtracked all the way then end the program
};
//ok function to check the neighbor list
//neighbor means they are touching eachother in the cross
//when you reach -1 it means that there are no more neighbors
bool ok(int q[8], int square){
    int adjacents[8][4]={{-1, -1, -1, -1}, //0 has no neighbors
                        {0, -1, -1, -1}, //0 is 1's neighbor
                        {1, -1, -1, -1}, //1 is 2's neighbor
                        {0, 1, 2, -1}, //0, 1, and 2 are 3's neighbors
                        {1, 2, 3, -1}, //1, 2, and 3 are 4's neighbors
                        {0, 3, 4, -1}, //0, 3, and 4 are 5's neighbors
                        {3, 4, 5, -1}, //3, 4, and 5 are 6's neighbors
                        {2, 4, 6, -1}}; //2, 4, and 6 are 7's neighbors
    for(int i=0; i<square; i++){
        if(q[i]==q[square]) return false; //row test
    }
    for(int j=0; adjacents[square][j]!=-1; j++){
        if(abs(q[square]-q[adjacents[square][j]])==1) return false; //if the absolute value of q[square] - q[adjacents[square][j]] equals 1, then it means they are neighbors
    }
    return true;
};
 
//print function
void print(int q[8]){
    static int count=0;
    cout << endl;
    //prints out the solution in a cross shape
    cout << "  " << q[1] << " " << q[2] << endl;
    cout << q[0] << " " << q[3] << " " << q[4] << " " << q[7] << endl;
    cout << "  " << q[5] << " " << q[6] << endl;
}
int main(){
    int q[8]={0}, square=0;
    bool from_backtrack=false; //sets from_backtrack to false because you have not backtracked yet
    while(true){ //will keep running until the loop is no longer true
        while(square<8){
        if(!from_backtrack) //if you did not backtrack
            q[square]=0;
            while(q[square]<9){ 
                q[square]++; //increment it
                if(q[square]==9){
                    backtrack(square);
                    continue;
                }
                if(ok(q,square)) break; //call the ok function to see if the number is ok in this spot
            }
            square++;
            from_backtrack=false;
        }
        print(q); //print your answer out
        backtrack(square); //backtrack to get another answer
        from_backtrack=true; //set backtrack to true because you just backtracked 
    }
return 0;
}
