#include "Rectangle.h"

bool CRectangle::Init()
{
    if (!CShape::Init())
        return false;

    //�����
    m_cShape[2][0] = '0';
    m_cShape[2][1] = '0';
    m_cShape[3][0] = '0';
    m_cShape[3][1] = '0';

    m_tPivot.x =  0;
    m_tPivot.y = 3;

    m_nWidth = 2;

    m_tPos.x = 4;
    m_tPos.y = 0;

    return true;
}