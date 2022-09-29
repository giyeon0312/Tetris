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

    m_tPos.x = 4;
    m_tPos.y = 0;

    m_iDir = RD_DOWN;

    return true;
}

void CShapeLine::Rotation()
{
    m_iDir = (m_iDir == RD_DOWN) ? RD_UP : RD_DOWN;

    for (int i = 0; i < MAX_SHAPE_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
            m_cShape[i][j] = '1';
        
    }

    switch (m_iDir)
    {
    case RD_UP:
        m_cShape[0][0] = '0';
        m_cShape[1][0] = '0';
        m_cShape[2][0] = '0';
        m_cShape[3][0] = '0';
        m_nWidth = 1;
        break;
    case RD_DOWN:
        m_cShape[3][0] = '0';
        m_cShape[3][1] = '0';
        m_cShape[3][2] = '0';
        m_cShape[3][3] = '0';
        m_nWidth = 4;
        break;
    }
}