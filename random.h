/*--------------------------------------------------------------------*/
// XorShift
// 周期が2^128でSFMTほど良質ではないらしいが、超高速に生成できる
// シードは４要素の配列。
//
//
/*--------------------------------------------------------------------*/




#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <climits>

namespace edupt{

class XorShift{
  // シードを定義
  unsigned int seed_[4];

public:
  unsigned int next(void){
    const unsigned int t = seed_[0] ^ (seed_[0] << 11);
    seed_[0] = seed_[1];
    seed_[1] = seed_[2];
    seed_[2] = seed_[3];
    return seed_[3] = (seed_[3] ^ (seed_[3] >> 19)) ^ (t ^ (t >> 8));
  }

  // [0.0, 1.0]の範囲で乱数を得る
  double next01(void){
    return (double)next() / UNIT_MAX;
  }

  // シードを与える関数
  XorShift(const unsigned int initial_seed){
    unsigned int s = initial_seed;
    for(int i=1; i<=4; ++i){
      seed_[i-1] = s = 1812433253U * (s ^ (s >> 30)) + i;
    }
  }
};

// Random型にtypedefして他の場所で使用
typedef XorShift Random;
};

#endif
