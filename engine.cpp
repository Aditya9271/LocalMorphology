#include "imageIO.h"
#include "morphological_functions.h"


int main()
{
    string file_src="lenna.ppm";
    Image img=read_image(file_src);
    // int s_row,s_col,s_x,s_y;
    // cout<<"Enter the number of row in the structuring element: ";
    // cin>>s_row;
    // cout<<"Enter the number of column in the structuring element: ";
    // cin>>s_col;
    // cout<<"Enter the x coordinate of origin: ";
    // cin>>s_x;
    // cout<<"Enter the y coordinate of origin: ";
    // cin>>s_y;


   // img.write_image("duplicate.ppm");
 //  cout<<img.get_height()<<" "<<img.get_width();
    img.write_image("dup.ppm");
   //  Image e_img1=erosion(img,s_row,s_col,s_x,s_y,256);

   //  e_img1.write_image("eroded_lenna1.ppm");

   //  Image d_img1=dilation(img,s_row,s_col,s_x,s_y,256);
   //  d_img1.write_image("dilated_lenna1.ppm");

   
   //  Image o_img1=open_recons(img,s_row,s_col,s_x,s_y,256);
   //  Image c_img1=close_recons(img,s_row,s_col,s_x,s_y,256);

   //  o_img1.write_image("opening_lenna1.ppm");
   //  c_img1.write_image("closing_lenna1.ppm");

   //  c_img1=d_img1-e_img1;
   //  c_img1.write_image("outline.ppm");

   // Image white_top_hat1 = img-o_img1;
   //  white_top_hat1.write_image("white_top_hat1.ppm");

   //  Image black_top_hat1 = c_img1 - img;
   //  black_top_hat1.write_image("black_top_hat1.ppm");

   //  Image opti_image = img+white_top_hat1-black_top_hat1;
   //  opti_image.write_image("opti_image.ppm");

}