#ifndef _PPM_H_
#define _PPM_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>


//#include "material.h"

namespace edupt{

/*----------------------------------------------------*/
// 各値xはclamp()によって0から1の範囲に詰められる
/*----------------------------------------------------*/
inline double clamp(double x){
  if(x < 0.0){ return 0.0; }
  if(x > 1.0){ return 1.0; }
  return x;
}

/*----------------------------------------------------*/
// (1/2.2)乗する...ガンマ補正
// 255倍する...0から255の範囲になる
/*----------------------------------------------------*/
inline int to_int(double x){
  return int(pow(clamp(x), 1/2.2) * 255 + 0.5);
}

/*----------------------------------------------------*/
// レンダリングした結果を保存するための関数
// -Color型の配列を受け取る
// -Color型はRGBデータをそれぞれx,y,zメンバ変数で保存
/*----------------------------------------------------*/
void save_ppm_file(const std::string &filename, const Color* image,
                   const int width, const int height){
  File* f = fopen(filename.c_str(), "wb");
  std::cout << f << "P3" << std::endl << width << ", " << height
            << std::endl << 255 << std::endl;
  for(int i = 0; i < width*height; ++i){
    std::cout << f << to_int(image[i].x) << to_int(image[i].y)
              << to_int(image[i].z) << std::endl;
  }
  fclose(f);
}

};

#endif
