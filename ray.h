/*--------------------------------------------------------------*/
// レイ（光線）を表現する構造体
// org : 始点, dir : 向き
// 始点は位置ベクトルとしてVecで表現
// 基本的にdirの長さは1
/*--------------------------------------------------------------*/


#ifndef _RAY_H_
#define _RAY_H_

#include "vec.h"

namespace edupt{

struct Ray{
  Vec org, dir;
  Ray(const Vec& org, const Vec& dir)
    : org(org)
    , dir(dir){}
};

};


#endif
