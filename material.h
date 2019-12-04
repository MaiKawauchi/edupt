#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "vec.h"

/*-----------------------------------------------------------------*/
// Vec構造体を使ってColorを定義
// 材質ReflectionTypeと屈折率
// ガラスに対する屈折率がkIor
/*-----------------------------------------------------------------*/



namespace edupt{

typedef Vec Color;

  enum ReflectionType{
    REFLECTION_TYPE_DIFFUSE,    // 完全拡散面(Lambertain)
    REFLECTION_TYPE_SPECULAR,   // 完全鏡面
    REFLECTION_TYPE_REFRACTION, // ガラス面
};

const double kIor = 1.5;   // 屈折率(Index of refraction)

};

#endif
