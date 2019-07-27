//-----------------------------------------------------------------------------
#include "hanlib.h"
//-----------------------------------------------------------------------------
//	①초성의 벌수 결정 : [중성종류][종성유무] */
//-----------------------------------------------------------------------------
static byte _F1_by_F2F3[22][2] = {    /* 벌수는 0 ~ 7까지 8벌 */
    {0, 0},     /* [ 0]    */
    {0, 0},     /* [ 1] ㅏ */
    {0, 0},     /* [ 2] ㅐ */
    {0, 0},     /* [ 3] ㅑ */
    {0, 0},     /* [ 4] ㅒ */
    {0, 0},     /* [ 5] ㅓ */
    {0, 0},     /* [ 6] ㅔ */
    {0, 0},     /* [ 7] ㅕ */
    {0, 0},     /* [ 8] ㅖ */
    {1, 1},     /* [ 9] ㅗ */
    {0, 0},     /* [10] ㅘ */
    {0, 0},     /* [11] ㅙ */
    {0, 0},     /* [12] ㅚ */
    {1, 1},     /* [13] ㅛ */
    {1, 1},     /* [14] ㅜ */
    {0, 0},     /* [15] ㅝ */
    {0, 0},     /* [16] ㅞ */
    {0, 0},     /* [17] ㅟ */
    {1, 1},     /* [18] ㅠ */
    {1, 1},     /* [19] ㅡ */
    {0, 0},     /* [20] ㅢ */
    {0, 0}      /* [21] ㅣ */
};
//-----------------------------------------------------------------------------
//	②중성의 벌수 결정 : [초성종류][종성유뮤] */
//-----------------------------------------------------------------------------
static byte _F2_by_F1F3[20][2] = {    /* 벌수는 0 ~ 3까지 4벌 */
    {0, 0},     /* [ 0]   */
    {0, 0},     /* [ 1] ㄱ*/
    {0, 0},     /* [ 2] ㄲ*/
    {0, 0},     /* [ 3] ㄴ*/
    {0, 0},     /* [ 4] ㄷ*/
    {0, 0},     /* [ 5] ㄸ*/
    {0, 0},     /* [ 6] ㄹ*/
    {0, 0},     /* [ 7] ㅁ*/
    {0, 0},     /* [ 8] ㅂ*/
    {0, 0},     /* [ 9] ㅃ*/
    {0, 0},     /* [10] ㅅ*/
    {0, 0},     /* [11] ㅆ*/
    {0, 0},     /* [12] ㅇ*/
    {0, 0},     /* [13] ㅈ*/
    {0, 0},     /* [14] ㅉ*/
    {0, 0},     /* [15] ㅊ*/
    {0, 0},     /* [16] ㅋ*/
    {0, 0},     /* [17] ㅌ*/
    {0, 0},     /* [18] ㅍ*/
    {0, 0}      /* [19] ㅎ*/
};
//-----------------------------------------------------------------------------
//	③종성의 벌수 결정 : [중성종류] */
//-----------------------------------------------------------------------------
static byte _F3_by_F2[22] = {   /* 벌수는 0 ~ 3까지 4벌 */
    0,  /* [ 0]    */
    1,  /* [ 1] ㅏ */
    1,  /* [ 2] ㅐ */
    1,  /* [ 3] ㅑ */
    1,  /* [ 4] ㅒ */
    1,  /* [ 5] ㅓ */
    1,  /* [ 6] ㅔ */
    1,  /* [ 7] ㅕ */
    1,  /* [ 8] ㅖ */
    1,  /* [ 9] ㅗ */
    0,  /* [10] ㅘ */
    1,  /* [11] ㅙ */
    1,  /* [12] ㅚ */
    0,  /* [13] ㅛ */
    0,  /* [14] ㅜ */
    1,  /* [15] ㅝ */
    1,  /* [16] ㅞ */
    1,  /* [17] ㅟ */
    0,  /* [18] ㅠ */
    0,  /* [19] ㅡ */
    1,  /* [20] ㅢ */
    1   /* [21] ㅣ */
};
//-----------------------------------------------------------------------------
/* ①초성의 벌수 결정 : [중성종류][종성유무] */
/* ②중성의 벌수 결정 : [초성종류][종성유뮤] */
/* ③종성의 벌수 결정 : [중성종류] */

byte *_F1B_2x1x2 = &_F1_by_F2F3[0][false];
byte *_F2B_2x1x2 = &_F2_by_F1F3[0][false];
byte *_F3B_2x1x2 = &_F3_by_F2[0];
//-----------------------------------------------------------------------------
