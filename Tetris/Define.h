#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}

const int STAGE_HEIGHT = 17;
const int STAGE_WIDTH =  10;

const int MAX_SHAPE_SIZE = 4;

typedef struct tagPosition
{
	int x;
	int y;

	tagPosition():	x(0), y(0)  {}

	tagPosition(const tagPosition& pos)
    {	*this = pos;    }

    tagPosition(int _x, int _y) : x(_x), y(_y) {}

    tagPosition operator +(const tagPosition& pos)
    {
        tagPosition p;
        p.x = x + pos.x, p.y = y + pos.y;
        return p;
    }

    tagPosition operator +(int a)
    {
        tagPosition p;
        p.x = x + a, p.y = y + a;
        return p;
    }
    
    void operator +=(const tagPosition& pos)
    {
        x += pos.x;
        y += pos.y;
    }

    void operator +=(int a)
    {
        x += a;
        y += a;
    }

    tagPosition operator -(int a)
    {
        tagPosition p;
        p.x = x - a, p.y = y - a;
        return p;
    }

    tagPosition operator -(const tagPosition& pos)
    {
        tagPosition p;
        p.x = x - pos.x, p.y = y - pos.y;
        return p;
    }

    void operator -=(int a)
    {
        x -= a, y -= a;
    }

    void operator -=(const tagPosition& pos)
    {
        x -= pos.x;
        y -= pos.y;
    }

    void operator =(const tagPosition& pos)
    {
        x = pos.x, y = pos.y;
    }

}POSITION, * PPOSITIOPN;

enum SHAPE_TYPE
{
    ST_RECT,
    ST_GUN,
    ST_RGUN,
    ST_LINE,
    ST_S,
    ST_T,
    ST_Z,
    ST_END,
};