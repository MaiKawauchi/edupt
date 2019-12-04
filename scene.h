#ifndef _SCENE_H_
#define _SCENE_H_

#include "constant.h"
#include "sphere.h"
#include "intersection.h"

namespace edupt{

// // レンダリングするシーンデータ
const Sphere spheres[] = {
  Sphere(1e5, Vec(1e5+1, 40.8, 81.6), Color(), Color(0.75, 0.25, 0.25), REFLECTION_TYPE_DIFFUSE)
};

// シーンに存在する各物体とレイとの交差判定関数
inline bool intersect_scene(const Ray& ray, Intersection* intersection){
  const double n = sizeof(spheres) / sizeof(Sphere);

  // 初期化
  intersection -> hitpoint.distance = kINF;
  intersection -> object_id = -1;

  // 線形探索
  for(int i=0; i<(int)n; ++i){
    Hitpoint hitpoint;
    if(spheres[i].intersect(ray, &hitpoint)){
      if(hitpoint.distance < intersection -> hitpoint.distance){
        intersection->hitpoint = hitpoint;
        intersection -> object_id = i;
      }
    }
  }
  return (intersection->object_id != -1);
}

};

#endif
