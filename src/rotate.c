//
// Created by Halcyon abrah Ramirez on 6/27/18.
//


#include <math.h>
#include <fdf.h>
#include "rotate.h"


void rotate(t_sa_container* cont)
{
    int x;
    int y;

    y = 0;
    while (y < cont->height)
    {
        x = 0;
        while (x < cont->width)
        {
            cont->arr[y]->arr[x]->x -= cont->width / 2;
            cont->arr[y]->arr[x]->y -= cont->height / 2;
            cont->arr[y]->arr[x]->x *= ((1500 / cont->width) * .5);
            cont->arr[y]->arr[x]->y *= ((1500 / cont->height) * .2);
            cont->arr[y]->arr[x]->x = (cont->arr[y]->arr[x]->x - cont->arr[y]->arr[x]->y) / 10;
            cont->arr[y]->arr[x]->y = (cont->arr[y]->arr[x]->x - cont->arr[y]->arr[x]->y) / -15;
            cont->arr[y]->arr[x]->y -= ((cont->arr[y]->arr[x]->z * 10) / 2);
            x++;
        }
        y++;
    }
}





//float s = sin(angle);
//float c = cos(angle);
//
//// translate point back to origin:
//p.x -= cx;
//p.y -= cy;
//
//// rotate point
//float xnew = p.x * c - p.y * s;
//float ynew = p.x * s + p.y * c;
//
//// translate point back:
//p.x = xnew + cx;
//p.y = ynew + cy;
//return p;




//void rotate(t_sa_container* cont, double angle)
//{
//    int x;
//    int y;
//    float new_x;
//    float tmp_x;
//    double rad;
//
//
//
//    rad = angle * M_PI / 180;
//    y = 0;
//    while (y < cont->height)
//    {
//        x = 0;
//        while (x < cont->width)
//        {
//            tmp_x = cont->arr[y]->arr[x]->x;
//            cont->arr[y]->arr[x]->x = (cont->arr[y]->arr[x]->x - cont->arr[y]->arr[x]->y) / 30;
//            cont->arr[y]->arr[x]->x = (cont->arr[y]->arr[x]->x * cos(rad)) - (cont->arr[y]->arr[x]->y * sin(rad));
//            cont->arr[y]->arr[x]->y = (cont->arr[y]->arr[x]->y * cos(rad)) + (tmp_x * sin(rad));
//            x++;
//        }
//        y++;
//    }
//}


//void rotate(t_sa_container* cont, double angle)
//{
//    int x;
//    int y;
//    float new_x;
//    float tmp_x;
//    double rad;
//
//
//
//    rad = angle * M_PI / 180;
//    y = 0;
//    while (y < cont->height)
//    {
//        x = 0;
//        while (x < cont->width)
//        {
//            tmp_x = cont->arr[y]->arr[x]->x;
//            cont->arr[y]->arr[x]->x = (cont->arr[y]->arr[x]->x * cos(rad)) - (cont->arr[y]->arr[x]->y * sin(rad));
//            cont->arr[y]->arr[x]->y = (cont->arr[y]->arr[x]->y * cos(rad)) + (tmp_x * sin(rad));
//            x++;
//        }
//        y++;
//    }
//}

//map.Local[i].x -= (img.width / 2);
//map.Local[i].y -= (img.height / 2);
//map.Local[i].x *= ((W_WIDTH / img.width) * 15);
//map.Local[i].y *= ((W_HEIGHT / img.height) * 10);
//map.Local[i].x = (map.Local[i].x - map.Local[i].y) / 30;
//map.Local[i].y = (map.Local[i].x - map.Local[i].y) / -15;
//map.Local[i].z = (map.Local[i].z * 10) / 2;
//map.Local[i].y -= map.Local[i].z;
//i++;

//x=1;
//y=1;
//angle = 45;
//
//double rad = angle*M_PI/180;
//
//newX = x * cos(rad) - y * sin(rad);
//newY = y * cos(rad) + x * sin(rad);