#pragma once

enum EnemyType{ASTEROID=0,MARS,MOON,BOSS,ROCKET,BADBALL,HEALBALL};

inline const char* toString(EnemyType type) {
	switch (type) {
	case ASTEROID: return "ASTEROID";
	case MARS: return "MARS";
	case MOON: return "MOON";
	case BOSS: return "BOSS";
	case ROCKET: return "ROCKET";
	case BADBALL: return "BADBALL";
	case HEALBALL: return "HEALBALL";
	}
}


enum BulletType{BASIC =0};

inline const char* toString(BulletType type) {
	switch (type)
	{
	case BASIC: return "BASIC";
			
	}
}