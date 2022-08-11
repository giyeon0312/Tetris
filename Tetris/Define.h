#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}

const int STAGE_HEIGHT = 40;
const int STAGE_WIDTH =  20;