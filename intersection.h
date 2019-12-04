#ifndef _INTERSECTION_H_
#define _INTERSECTION_H_

#include "vec.h"
#include "constant.h"

namespace edupt{

/*------------------------------------------------------------*/
// レイと物体の交差点の幾何学的情報を格納
// distance : レイの始点から交差点までの距離
// normal   : 交差点における物体法線
// position : 交差点のワールド座標系での位置
/*------------------------------------------------------------*/
struct Hitpoint{
  double distance;
  Vec normal;
  Vec position;

  Hitpoint()
    :distance(kINF)
    , normal()
    , position(){}
};

/*------------------------------------------------------------*/
// 幾何学的情報（Hitpoint構造体）に加え、物体のIDも格納
/*------------------------------------------------------------*/
struct Intersection{
  Hitpoint hitpoint;
  int object_id;

  Intersection() : object_id(-1){}
};

};

#endif
