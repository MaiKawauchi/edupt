#ifndef _SPHERE_H_
#define _SPHERE_H

#include <cmath>

#include "vec.h"
#include "ray.h"
#include "material.h"
#include "constant.h"
#include "intersection.h"


/*--------------------------------------------------------------------*/
// position : 中心座標
// radius   : 半径
// emission : 発光色
// color    : 反射率
// reflection_type : 材質(表面における反射の種類)
/*--------------------------------------------------------------------*/

namespace edupt{

struct Sphere{
  double radius;
  Vec position;
  Color emission;
  Color color;
  ReflectionType reflection_type;

  Sphere(const double radius, const Vec& position, const Color& emission,
         const Color& color, const ReflectionType reflection_type)
    : radius(radius)
    , position(position)
    , emission(emission)
    , color(color)
    , reflection_type(reflection_type){}

  // 入力のrayに対する交差点までの距離を返す.
  // rayとの交差判定を行う.交差したらtrue,
  // 判別式を用いて解の存在を判定
  bool intersect(const Ray& ray, Hitpoint* hitpoint) const {
    const Vec p_o = position - ray.org;
    const double b = dot(p_o, ray.dir);
    const double D4 = b * b - (dot(p_o, p_o) + radius * radius);

    // 交差しなかったらfalseを返す
    if(D4 < 0.0){ return false; }

    // 判別式を使って解を計算する
    const double sqrt_D4 = sqrt(D4);
    const double t1 = b - sqrt_D4;
    const double t2 = b + sqrt_D4;

    // 解がkEPS未満ならレイの始点が相手の球の表面と非常に近い場所に存在.
    // 球の表面から離れていく方向にレイが発射されている.
    // 得られた二つの解がkEPS未満なら交差点は一つもない.
    if(t1 < kEPS && t2 < kEPS){ return false; }

    if(t1 > kEPS){ hitpoint -> distance = t1; }
    else { hitpoint -> distance = t2; }


    // 交差点までの距離.位置.法線をHitpoint構造体に格納
    hitpoint -> position = ray.org + hitpoint -> distance * ray.dir;
    hitpoint -> normal   = normalize(hitpoint -> position - position);
    return true;
  }
};

};


#endif
