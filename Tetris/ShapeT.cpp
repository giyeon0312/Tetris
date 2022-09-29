#include "ShapeT.h"


bool CShapeT::Init()
{
    if (!CShape::Init())
        return false;

    // T¸ð¾ç
    m_cShape[2][0] = '0';
    m_cShape[2][1] = '0';
    m_cShape[2][2] = '0';
    m_cShape[3][1] = '0';

    //m_tPivot.x = 0;
    //m_tPivot.y = 3;

    m_iDir = RD_DOWN;
    m_nWidth = 3;

    return true;
}

void CShapeT::Rotation()
{
    ++m_iDir;

    m_iDir %= RD_END;

    for (int i = 0; i < MAX_SHAPE_SIZE; ++i)
    {
        for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
            m_cShape[i][j] = '1';
    }

    switch (m_iDir)
    {
    case RD_UP:
        m_cShape[2][1] = '0';
        m_cShape[3][0] = '0';
        m_cShape[3][1] = '0';
        m_cShape[3][2] = '0';
        m_nWidth = 3;
        break;
    case RD_RIGHT:
        m_cShape[1][0] = '0';
        m_cShape[2][0] = '0';
        m_cShape[3][0] = '0';
        m_cShape[2][1] = '0';
        m_nWidth = 2;
        break;
    case RD_DOWN:
        m_cShape[2][0] = '0';
        m_cShape[2][1] = '0';
        m_cShape[2][2] = '0';
        m_cShape[3][1] = '0';
        m_nWidth = 3;
        break;
    case RD_LEFT:
        m_cShape[1][1] = '0';
        m_cShape[2][1] = '0';
        m_cShape[3][1] = '0';
        m_cShape[2][0] = '0';
        m_nWidth = 2;
        break;
    }
}