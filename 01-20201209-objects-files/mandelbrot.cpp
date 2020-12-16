// g++ -std=c++11 mandelbrot.cpp -o m
// ./m

#include <iostream>

#include <cmath>
#include <vector>
#include <fstream>


#define resolution_x 2500
#define resolution_y 2500

#define min_x -2.0 //-0.5
#define max_x 2.0 //0.5
#define min_y -2.0 //-0.5
#define max_y 2.0 //0.5

#define crit 10.0 //2.0 // criterion for divergence
#define max_iter 100 // max number of calculation iterations

float crit2 = pow(crit, 2);

float range_x = max_x - min_x;
float step_x = range_x / resolution_x;
float range_y = max_y - min_y;
float step_y = range_y / resolution_y;



std::vector<int> getColor(int niter, int itermax ){
  std::vector<int> col(3);

  if ( niter < itermax ){
    col[0] = 200+(55*niter)/100;
    col[1] = (230*(100-niter))/100;
    col[2] = (230*(100-niter))/100 ;
  }
  else{
    col[0] = 0;
    col[1] = 255;
    col[2] = 255;
  }
  return col;
}



int mandelbrot(float x, float y) {
    float zr = 0.0; // real part
    float zi = 0.0; // imaginary part
    float val; // norm squared

    for (int i=1; i <= max_iter; i++) {

        // Complex number zr + i*zi
        zr = pow(zr, 2) - pow(zi, 2) + x;
        zi = 2 * zr * zi + y;

        // Norm
        val = pow(zr, 2) + pow(zi, 2);

        // Exiting function when the divergence occurs (based on crit)
        if (val >= crit2) {
            return i;
        }
    }
    
    return max_iter;
};



int main() {

    // Initialise image file
    std::ofstream file_out;
    file_out.open("mandelbrot.ppm");
    file_out << "P3" << std::endl;
    file_out << resolution_x << " " << resolution_y << std::endl;
    file_out << "255" << std::endl;

    float x = min_x; // initialise x-coordinate
    for (int xid=0; xid < resolution_x; xid++) {

        float y = min_y; // initialise y-coordinate

        for (int yid=0; yid < resolution_y; yid++) {

            int iter = mandelbrot(x, y); // get iterations of Mandelbrot series

            std::vector<int> color = getColor(iter, max_iter); // get color of point

            file_out << color[0] << " " << color[1] << " " << color[2]; // << " "; // write to file
            if (yid < resolution_y - 1) {file_out << " ";}; // add space between all color values except for at end of line
            
            y += step_y; // increment y-coordinate
            
        }

        file_out << std::endl; // end line

        x += step_x; // increment x-coordinate
    }

    file_out.close(); // close file

    return 0;
}

