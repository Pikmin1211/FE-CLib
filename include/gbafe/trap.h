#ifndef GBAFE_TRAPS_H
#define GBAFE_TRAPS_H

// bmtrap.c?

#include <stdint.h>

#include "common.h"

typedef struct EventTrapData EventTrapData;

typedef struct Trap Trap;
typedef struct Trap ActorTile; // because speedruns are neat

struct EventTrapData {
	/* 00 */ u8 type;
	/* 01 */ u8 data[5];
} __attribute__((packed));

struct Trap {
	/* 00 */ u8 xPosition;
	/* 01 */ u8 yPosition;
	
	/* 02 */ u8 type;
	
	/* 03 */ u8 data[5];
};

extern struct Trap gTrapArray[]; //! FE8U = (0x0203A614)

struct Trap* GetTrapAt(int x, int y); //! FE8U = (0x0802E1F0+1)
struct Trap* GetSpecificTrapAt(int x, int y, int type); //! FE8U = (0x0802E24C+1)

struct Trap* AddTrap(int x, int y, int type, int ext); //! FE8U = (0x0802E2B8+1)
struct Trap* AddTrapExt(int x, int y, int type, int ext1, int ext24, int ext3, int ext5); //! FE8U = (0x0802E2E0+1)
void RemoveTrap(struct Trap* trap); //! FE8U = (0x0802E2FC+1)
void AddFireTrap(int x, int y, int startCountDown, int resetCountDown); //! FE8U = (0x0802E314+1)
void AddGasTrap(int x, int y, int direction, int startCountDown, int resetCountDown); //! FE8U = (0x0802E330+1)
void AddArrowTrap(int x, int startCountDown, int resetCountDown); //! FE8U = (0x0802E350+1)
void AddTrap8(int x, int y); //! FE8U = (0x0802E388+1)
void AddTrap9(int x, int y, int ext); //! FE8U = (0x0802E398+1)

// map changes -> map.h?
void ApplyTrapMapChanges(void); //! FE8U = (0x0802E430+1)

void ApplyMapChangesById(int id); //! FE8U = (0x0802E58C+1)
void AddMapChange(int id); //! FE8U = (0x0802E5F8+1)
void RemoveMapChange(int id); //! FE8U = (0x0802E60C+1)
int AreMapChangeTriggered(int id); //! FE8U = 0x802E639

void HideIfUnderRoof(struct Unit*); //! FE8U = (0x0802E660+1)
void UpdateUnitsUnderRoof(void); //! FE8U = (0x0802E690+1)

// other file?
void AddGorgonEggTrap(int a, int b, int c, int d, int e); //! FE8U = (0x08037928+1)
struct Trap* AddBallista(int x, int y, int itemIndex); //! FE8U = (0x08037A04+1)

#endif // GBAFE_TRAPS_H
