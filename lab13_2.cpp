#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[][M])
{
    cout << "------------------------------------------------------------------------" << endl ;
    
    for(int row = 0; row < 30; row++){
        cout << "|";
        for(int col = 0; col < 70; col++){
            if(image[row][col] == 1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << "|";
        cout << endl;
    }
    
    
    
    cout << "------------------------------------------------------------------------" << endl;
    
}



void updateImage(bool image[][M],int s,int x,int y){
    
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 70; j++){
            if( (i - x)*(i - x) + (j - y)*(j - y) <= (s - 1)*(s - 1) ){
                image[i][j] = 1;
            }
        }
    }
}
