/*
For implementation "*.c" file part use:
#define VIEWPORT_RECT
*/


#ifndef VIEWPORT_RECT_H
#define VIEWPORT_RECT_H

#include "raylib.h"

Rectangle KeepAspectCentered(int scr_w, int scr_h, int view_w, int view_h, Rectangle* source_rect);
Rectangle KeepHeightCentered(int scr_w, int scr_h, int view_w, int view_h, Rectangle* source_rect);
Rectangle KeepWidthCentered(int scr_w, int scr_h, int view_w, int view_h, Rectangle* source_rect);

#endif

#ifdef VIEWPORT_RECT
#undef VIEWPORT_RECT

Rectangle KeepAspectCentered(int scr_w, int scr_h, int view_w, int view_h, Rectangle* source_rect){
    source_rect->x = 0.f;
    source_rect->y = view_h;
    source_rect->width = view_w;
    source_rect->height = -view_h;

    const int ratio_x = (scr_w/view_w);
    const int ratio_y = (scr_h/view_h);
    const float resize_ratio = (float)(ratio_x < ratio_y ? ratio_x : ratio_y);
    Rectangle result = {
        (scr_w - view_w * resize_ratio) * 0.5,
        (scr_h - view_h * resize_ratio) * 0.5,
        view_w * resize_ratio,
        view_h * resize_ratio
    };
    return result;
}

Rectangle KeepHeightCentered(int scr_w, int scr_h, int view_w, int view_h, Rectangle* source_rect){
    const float resize_ratio = (float)(scr_h/view_h);
    source_rect->x = 0.f;
    source_rect->y = 0.f;
    source_rect->width = (float)(int)(scr_w / resize_ratio);
    source_rect->height = -view_h;

    Rectangle result = {
        (scr_w - source_rect->width * resize_ratio) * 0.5,
        (scr_h - view_h * resize_ratio) * 0.5,
        source_rect->width * resize_ratio,
        view_h * resize_ratio
    };
    return result;
}

Rectangle KeepWidthCentered(int scr_w, int scr_h, int view_w, int view_h, Rectangle* source_rect){
    const float resize_ratio = (float)(scr_w/view_w);
    source_rect->x = 0.f;
    source_rect->y = 0.f;
    source_rect->width = view_w;
    source_rect->height = -(float)(int)(scr_h / resize_ratio);

    Rectangle result = {
        (scr_w - view_w * resize_ratio) * 0.5,
        (scr_h - -source_rect->height * resize_ratio) * 0.5,
        view_w * resize_ratio,
        -source_rect->height * resize_ratio
    };
    return result;
}

#endif