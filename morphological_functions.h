#include<bits/stdc++.h>
#include "imageIO.h"
using namespace std;
#define pii pair<int,int>
#define vpp vector<pii>
#define mp make_pair

bool in_range(int curr_x,int curr_y,int h,int w)
{
    if(curr_x>=0 && curr_x<h && curr_y>=0 && curr_y<w)
    return true;
    else return false;
}

vector<vpp> make_structure(int s_row,int s_col,int s_x,int s_y)
{
    vector< vpp > structure(s_row,vector<pii>(s_col,mp(0,0)));
    for(int i=0;i<s_row;i++)
    {
        for(int j=0;j<s_col;j++)
        {
            structure[i][j]=mp(j-s_x,i-s_y);
            //cout<<structure[i][j].first<<","<<structure[i][j].second<<"   ";
        }
        //cout<<endl;
    }
    return structure;
}



Image erosion(Image &img,int s_row,int s_col,int s_x,int s_y,int highpow)
{
    Image e_image;

    int height = img.get_height();
	int width = img.get_width();

	e_image= e_image.duplicate_image(img);

	vvi temp= img.get_bitmap();

    int range=highpow;

  //  cout<<e_image.get_height()<<" "<<e_image.get_width()<<endl;

    vector<vpp> structure_dup = make_structure(s_row,s_col,s_x,s_y);
  //  cout<<height<<" "<<width<<" "<<s_row<<" "<<s_col<<endl;

    for(int i=0;i<height;i++)
    {
    	
        for(int j=0;j<width;j++)
        {
       		//cout<<i<<" "<<j<<endl;
            //place the origin of the structure at i,j
            for(int ii=0;ii<s_row;ii++)
            {
          //  	cout<<"c";
                for(int jj=0;jj<s_col;jj++)
                {
            //    	cout<<"d";
                    int x=i+structure_dup[ii][jj].first;
                    int y=j+structure_dup[ii][jj].second;

                    if(in_range(x,y,height,width))
                    {

		                temp[i][j]= min(temp[i][j], img.get_bitmap()[x][y]);
		            	if(temp[i][j]<0) temp[i][j]=0;
						else if(temp[i][j]>highpow-1) temp[i][j]=highpow-1;

                    }
                }
            }
        }
    }
    e_image.set_bitmap(temp);
    return e_image;
}



Image dilation(Image &img,int s_row,int s_col,int s_x,int s_y,int highpow)
{
    Image e_image;

    int height = img.get_height();
	int width = img.get_width();

	e_image = e_image.duplicate_image(img);

	vvi temp= img.get_bitmap();

    int range=highpow;

    vector<vpp> structure_dup = make_structure(s_row,s_col,s_x,s_y);

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            //place the origin of the structure at i,j
            for(int ii=0;ii<s_row;ii++)
            {
                for(int jj=0;jj<s_col;jj++)
                {
                    int x=i+structure_dup[ii][jj].first;
                    int y=j+structure_dup[ii][jj].second;

                    if(in_range(x,y,height,width))
                    {

		                temp[i][j]= max(temp[i][j], img.get_bitmap()[x][y]);
		            	if(temp[i][j]<0) temp[i][j]=0;
						else if(temp[i][j]>highpow-1) temp[i][j]=highpow-1;

                    }
                }
            }
        }
    }
    e_image.set_bitmap(temp);
    return 	e_image;
}

Image open_recons(Image &img, int s_row,int s_col,int s_x,int s_y, int highpow) {

	Image erode= erosion(img, s_row, s_col, s_x, s_y ,highpow);
	Image dilate= dilation(erode,s_row, s_col, s_x, s_y ,highpow);
	return dilate;
}


Image close_recons(Image &img,int s_row,int s_col,int s_x,int s_y, int highpow) {

	Image dilate= dilation(img,s_row, s_col, s_x, s_y , highpow);

	Image erode= erosion(dilate,s_row, s_col, s_x, s_y ,highpow);
	return erode;
}

