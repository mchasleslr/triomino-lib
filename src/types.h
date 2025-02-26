#ifndef _TYPES_H
#define _TYPES_H

#define ID_NDEF __UINT32_MAX__
#define COORD_X_NDEF __UINT32_MAX__
#define COORD_Y_NDEF __UINT32_MAX__

enum _rot_t
{
  ROT_45,
  ROT_135,
  ROT_225,
  ROT_270,
  ROT_NDEF
};

enum _slot_t
{
  SLOT_BOTTOM,
  SLOT_TOP,
  SLOT_NDEF
};

typedef enum _rot_t rot_t;

typedef enum _slot_t slot_t;

typedef unsigned int coord_t;

typedef unsigned int id_t;

#endif // _TYPES_H
