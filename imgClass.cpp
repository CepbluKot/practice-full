#include <iostream>
#include <fstream>
#include <string>



class Image
{

public:


    
    
    void createImage(int, int);
    void showImage();
    void setPointImage(int, int, int);
    int getPointImage(int, int);
    void saveToPnmFile(std::string filename);


private:
    class img
    {
    public:
        int* points;
        int mx;
        int my;
        
        img(int mx = int(), int my = int(), int* points = int())
        {
            this->mx = mx;
            this->my = my;
            this->points = points;
            
        }
    };
    
};

    void Image::createImage( int tmx, int tmy) {
        img* image = new img();
        image->points = new int[tmx * tmy]{ 0 };
        image->mx = tmx;
        image->my = tmy;


    }




    void Image::showImage() {
        int transit = 0;
        img* image = new img();
        for (int n = 0; n < (image->mx * image->my); n++) {
            if (transit != image->mx) {
             std::   cout << image->points[n];
                transit += 1;
            }
            else {

              std::  cout << image->points[n];
                std::cout << "\n";
                transit = 0;


            }


        }

    }



    void Image::setPointImage(int x, int y, int color) {
        img* image = new img();
        image->points[image->mx * y + x] = color;
    }


    int Image::getPointImage(int x, int y) {
        img* image = new img();
        return image->points[image->mx * y + x];

    }


    void Image::saveToPnmFile( std::string fileName) {
        img* image = new img();
        std::ofstream fout;
        fout.open(fileName);

        int transit = 0;
        for (int n = 0; n < (image->mx * image->my); n++) {
            if (transit != image->mx - 1) {
                fout << image->points[n];
                transit += 1;
            }
            else {

                fout << image->points[n];
                fout << std::endl;
                transit = 0;


            }


        }

        fout.close();
    }




int main() {


    return 0;
}
