#ifndef DistanceUnits_h
#define DistanceUnits_h

class DistanceUnits
{
public:
	typedef enum eDistanceUnits
	{
		eDistanceUnitMeter,
		eDistanceUnitMillimeter,
		eDistanceUnitCentimeter,
		eDistanceUnitInch,
		eDistanceUnitFeet,
		eDistanceUnitPoints
	};

	static int GetDistanceUnitsCount(void);

	static double ConvertBetweenDistanceUnits(double distance, enum eDistanceUnits sourceUnit, enum eDistanceUnits targetUnit);
	static int GetDistanceUnitIndex(enum eDistanceUnits unit);
	static const char* GetDistanceUnitName(enum eDistanceUnits unit);
	static enum eDistanceUnits GetDistanceUnitForName(const char* name);
	static enum eDistanceUnits GetDistanceUnitForIndex(int index);
};

#endif