//! \file GiCanvasAdapter.h
//! \brief 定义画布适配器类 GiCanvasAdapter
// Copyright (c) 2012-2013, https://github.com/rhcad/touchvg

#ifndef TOUCHVG_IOS_CANVASADAPTER_H
#define TOUCHVG_IOS_CANVASADAPTER_H

#include "gicanvas.h"
#include <CoreGraphics/CoreGraphics.h>

@class ImageCache;

int giGetScreenDpi();

//! 使用 Quartz 2D 实现的画布适配器类
/*! \ingroup GROUP_IOS
 */
class GiCanvasAdapter : public GiCanvas
{
public:
    GiCanvasAdapter(ImageCache *cache = (ImageCache *)0);
    virtual ~GiCanvasAdapter();
    
    //! 在给定上下文上开始绘制
    bool beginPaint(CGContextRef context);
    
    //! 结束绘制
    void endPaint();
    
    //! 返回绘图上下文
    CGContextRef context();
    
    static const float* const LINEDASH[];     //!< 虚线定义, 0..4
    static float colorPart(int argb, int byteOrder);
    
public:
    void setPen(int argb, float width, int style, float phase, float orgw);
    void setBrush(int argb, int style);
    void clearRect(float x, float y, float w, float h);
    void drawRect(float x, float y, float w, float h, bool stroke, bool fill);
    void drawLine(float x1, float y1, float x2, float y2);
    void drawEllipse(float x, float y, float w, float h, bool stroke, bool fill);
    void beginPath();
    void moveTo(float x, float y);
    void lineTo(float x, float y);
    void bezierTo(float c1x, float c1y, float c2x, float c2y, float x, float y);
    void quadTo(float cpx, float cpy, float x, float y);
    void closePath();
    void drawPath(bool stroke, bool fill);
    void saveClip();
    void restoreClip();
    bool clipRect(float x, float y, float w, float h);
    bool clipPath();
    void drawHandle(float x, float y, int type);
    void drawBitmap(const char* name, float xc, float yc, float w, float h, float angle);
    float drawTextAt(const char* text, float x, float y, float h, int align);
    bool beginShape(int type, int sid, int version, float x, float y, float w, float h);
    
private:
    CGContextRef    _ctx;
    bool            _fill;
    ImageCache      *_cache;
    CGGradientRef   _gradient0;
    CGGradientRef   _gradient;
};

#endif // TOUCHVG_IOS_CANVASADAPTER_H
