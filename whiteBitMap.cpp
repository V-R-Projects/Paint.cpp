#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main(){
    FILE *fp;
    fp = fopen("white.bmp", "wb");
    
    unsigned char bmpfileheader[14] = {'B','M', 78,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 4,0,0,0, 2,0,0,0, 1,0, 24,0, 0,0,0,0, 24,0,0,0, 19,11,0,0, 19,11,0,0, 0,0,0,0, 0,0,0,0};
    unsigned char bmppixel[24]={255,0,0, 0,255,0, 0,0,255, 255,0,0, 0,255,0, 0,0,255, 255,0,0, 0,255,0,};

    int c = 0;
    for(int i = 0; i < 28; i++){
        if(c < 12){
            bmppixel[i] = 255;
            c++;
        }
        else{
            bmppixel[i] = 255;
            c = 0;
        }
    }
    // Printing the bmppixel array in numbers
    for(int i = 0; i < 28; i++){
        int number = bmppixel[i];
        std::cout << number << " ";
    }
    
    
    

    fwrite(bmpfileheader, 1, sizeof(bmpfileheader), fp);
    fwrite(bmpinfoheader, 1, sizeof(bmpinfoheader), fp);
    fwrite(bmppixel, 1, sizeof(bmppixel), fp);

    return 0;
}