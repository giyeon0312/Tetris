#include "ShapeT.h"


bool CShapeT::Init()
{
    if (!CShape::Init())
        return false;

    // T���
    m_cShape[2][0] = '0';
    m_cShape[2][1] = '0';
    m_cShape[2][2] = '0';
    m_cShape[3][1] = '0';

    //m_tPivot.x = 0;
    //m_tPivot.y = 3;

    m_nWidth = 3;

    return true;
}
