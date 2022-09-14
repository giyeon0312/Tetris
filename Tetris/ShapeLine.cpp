#include "ShapeLine.h"


bool CShapeLine::Init()
{
    if (!CShape::Init())
        return false;

    //¤Ñ¸ð¾ç
    m_cShape[3][0] = '0';
    m_cShape[3][1] = '0';
    m_cShape[3][2] = '0';
    m_cShape[3][3] = '0';

    //m_tPivot.x = 0;
    //m_tPivot.y = 3;

    m_nWidth = 4;

    return true;
}