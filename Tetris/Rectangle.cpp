#include "Rectangle.h"

bool CRectangle::Init()
{
    //�����
    m_cShape[2][0] = 0;
    m_cShape[2][1] = 0;
    m_cShape[3][0] = 0;
    m_cShape[3][1] = 0;

    m_tPivot.x = 1;
    m_tPivot.y = 3;

    return false;
}

void CRectangle::Render()
{
}
