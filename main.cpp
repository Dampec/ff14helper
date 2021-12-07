// FF14 Helper App

// [0-9]+\t([a-zA-Z '-]+)\t([a-zA-Z '-]+)\t\(x([0-9.]+),y([0-9.]+)\)\t([a-zA-Z\n ]+)\t([0-9]+):00-([0-9]+):00\t\/([a-zA-Z]+)\t(.*)$

// https://github.com/eorzea-weather/eorzea-weather/blob/main/packages/eorzea-weather/src/chances.ts

#ifndef UNICODE
#define UNICODE
#endif 

#define STRICT

#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <map>

#include <math.h>
#include <windows.h>
#include <commCtrl.h>

#pragma comment (lib, "User32.lib")

class Weather {
	public:
		enum WeatherEnum : int { 
			Blizzards,
			ClearSkies,
			Clouds,
			DustStorms,
			FairSkies,
			Fog,
			Gales,
			Gloom,
			HeatWaves,
			Rain,
			Showers,
			Snow,
			Thunder,
			ThunderStorms,
			UmbralStatic,
			UmbralWind,
			Wind,
			Undefined,
		};
		Weather () {}
		Weather (WeatherEnum we) {
			weatherEnum = we;
		}

		bool operator==(const Weather& other) const {
			return weatherEnum == other.weatherEnum;
		}

		operator std::string() const {
			const static std::string weatherEnumStringArray[17] = {
				"Blizzards",
				"Clear Skies",
				"Clouds",
				"Dust Storms",
				"Fair Skies",
				"Fog",
				"Gales",
				"Gloom",
				"Heat Waves",
				"Rain",
				"Showers",
				"Snow",
				"Thunder",
				"Thunder Storms",
				"Umbral Static",
				"Umbral Wind",
				"Wind"
			};

			return weatherEnumStringArray[weatherEnum];
		};
	private:
		WeatherEnum weatherEnum = Undefined;
};

class Zone {
	public:
		enum ZoneEnum : int { 
			LimsaLominsaUpperDecks,
			LimsaLominsaLowerDecks,
			MiddleLaNoscea,
			LowerLaNoscea,
			EasternLaNoscea,
			WesternLaNoscea,
			UpperLaNoscea,
			OuterLaNoscea,
			OldGridania,
			NewGridania,
			CentralShroud,
			NorthShroud,
			EastShroud,
			SouthShroud,
			UlDah,
			NorthernThanalan,
			WesternThanalan,
			CentralThanalan,
			EasternThanalan,
			SouthernThanalan,
			CoerthasCentralHighlands,
			MorDhona,
			TheLavenderBeds,
			TheGoblet,
			Mist,
			Undefined
		};
		Zone () {}
		Zone (ZoneEnum ze) {
			zoneEnum = ze;
		}

		operator std::string() const {
			const static std::string zoneEnumStringArray[25] = {
				"Limsa Lominsa Upper Decks",
				"Limsa Lominsa Lower Decks",
				"Middle La Noscea",
				"Lower La Noscea",
				"Eastern La Noscea",
				"Western La Noscea",
				"Upper La Noscea",
				"Outer La Noscea",
				"Old Gridania",
				"New Gridania",
				"Central Shroud",
				"North Shroud",
				"East Shroud",
				"South Shroud",
				"Ul'Dah",
				"Northern Thanalan",
				"Western Thanalan",
				"Central Thanalan",
				"Eastern Thanalan",
				"Southern Thanalan",
				"Coerthas Central Highlands",
				"Mor Dhona",
				"The Lavander Beds",
				"The Goblet",
				"Mist",
			};
			return zoneEnumStringArray[zoneEnum];
		}

		Weather GetWeather(int chance) { 
			switch(zoneEnum) {
				case LimsaLominsaUpperDecks: case LimsaLominsaLowerDecks:
					if (chance < 20) { 
						return Weather::Clouds; 
					} else if (chance < 50) {
						return Weather::ClearSkies;
					} else if (chance < 80) {
						return Weather::FairSkies;
					} else if (chance < 90) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case MiddleLaNoscea:
				    if (chance < 20) {
						return Weather::Clouds;
					} else if (chance < 50) {
						return Weather::ClearSkies;
					} else if (chance < 70) {
						return Weather::FairSkies;
					} else if (chance < 80) {
						return Weather::Wind;
					} else if (chance < 90) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case LowerLaNoscea:
				    if (chance < 20) {
						return Weather::Clouds;
					} else if (chance < 50) {
						return Weather::ClearSkies;
					} else if (chance < 70) {
						return Weather::FairSkies;
					} else if (chance < 80) {
						return Weather::Wind;
					} else if (chance < 90) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case EasternLaNoscea:
				    if (chance < 5) {
						return Weather::Fog;
					} else if (chance < 50) {
						return Weather::ClearSkies;
					} else if (chance < 80) {
						return Weather::FairSkies;
					} else if (chance < 90) {
						return Weather::Clouds;
					} else if (chance < 95) {
						return Weather::Rain;
					}
					return Weather::Showers;
				case WesternLaNoscea:
				    if (chance < 10) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::ClearSkies;
					} else if (chance < 60) {
						return Weather::FairSkies;
					} else if (chance < 80) {
						return Weather::Clouds;
					} else if (chance < 90) {
						return Weather::Wind;
					}
					return Weather::Gales;
				case UpperLaNoscea:
				    if (chance < 30) {
						return Weather::ClearSkies;
					} else if (chance < 50) {
						return Weather::FairSkies;
					} else if (chance < 70) {
						return Weather::Clouds;
					} else if (chance < 80) {
						return Weather::Fog;
					} else if (chance < 90) {
						return Weather::Thunder;
					}
					return Weather::ThunderStorms;
				case OuterLaNoscea:
					if (chance < 30) {
						return Weather::ClearSkies;
					} else if (chance < 50) {
						return Weather::FairSkies;
					} else if (chance < 70) {
						return Weather::Clouds;
					} else if (chance < 85) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case OldGridania: case NewGridania:
					if (chance < 5) {
						return Weather::Rain;
					} else if (chance < 20) {
						return Weather::Rain;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::Clouds;
					} else if (chance < 55) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::ClearSkies;
					}
					return Weather::FairSkies;
				case CentralShroud:
				    if (chance < 5) {
						return Weather::Thunder;
					} else if (chance < 20) {
						return Weather::Rain;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::Clouds;
					} else if (chance < 55) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::ClearSkies;
					}
					return Weather::FairSkies;
				case NorthShroud:
				    if (chance < 5) {
						return Weather::Fog;
					} else if (chance < 10) {
						return Weather::Showers;
					} else if (chance < 25) {
						return Weather::Rain;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::Clouds;
					} else if (chance < 70) {
						return Weather::FairSkies;
					}
					return Weather::ClearSkies;
				case EastShroud:
				    if (chance < 5) {
						return Weather::Thunder;
					} else if (chance < 20) {
						return Weather::Rain;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::Clouds;
					} else if (chance < 55) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::ClearSkies;
					}
					return Weather::FairSkies;
				case SouthShroud:
				    if (chance < 5) {
						return Weather::Fog;
					} else if (chance < 10) {
						return Weather::ThunderStorms;
					} else if (chance < 25) {
						return Weather::Thunder;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::Clouds;
					} else if (chance < 70) {
						return Weather::FairSkies;
					}
					return Weather::ClearSkies;
				case UlDah:
					if (chance < 40) {
						return Weather::ClearSkies;
					} else if (chance < 60) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::Clouds;
					} else if (chance < 95) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case NorthernThanalan:
				    if (chance < 5) {
						return Weather::ClearSkies;
					} else if (chance < 20) {
						return Weather::FairSkies;
					} else if (chance < 50) {
						return Weather::Clouds;
					}
					return Weather::Fog;
				case WesternThanalan:
				    if (chance < 40) {
						return Weather::ClearSkies;
					} else if (chance < 60) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::Clouds;
					} else if (chance < 95) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case CentralThanalan:
				    if (chance < 15) {
						return Weather::DustStorms;
					} else if (chance < 55) {
						return Weather::ClearSkies;
					} else if (chance < 75) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::Clouds;
					} else if (chance < 95) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case EasternThanalan:
				    if (chance < 40) {
						return Weather::ClearSkies;
					} else if (chance < 60) {
						return Weather::FairSkies;
					} else if (chance < 70) {
						return Weather::Clouds;
					} else if (chance < 80) {
						return Weather::Fog;
					} else if (chance < 85) {
						return Weather::Rain;
					}
					return Weather::Showers;
				case SouthernThanalan:
				    if (chance < 20) {
						return Weather::HeatWaves;
					} else if (chance < 60) {
						return Weather::ClearSkies;
					} else if (chance < 80) {
						return Weather::FairSkies;
					} else if (chance < 90) {
						return Weather::Clouds;
					}
					return Weather::Fog;
				case CoerthasCentralHighlands:
				    if (chance < 20) {
						return Weather::Blizzards;
					} else if (chance < 60) {
						return Weather::Snow;
					} else if (chance < 70) {
						return Weather::FairSkies;
					} else if (chance < 75) {
						return Weather::ClearSkies;
					} else if (chance < 90) {
						return Weather::Clouds;
					}
					return Weather::Fog;
				case MorDhona:
					if (chance < 15) {
						return Weather::Clouds;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 60) {
						return Weather::Gloom;
					} else if (chance < 75) {
						return Weather::ClearSkies;
					}
					return Weather::FairSkies;
				case TheLavenderBeds:
				    if (chance < 5) {
						return Weather::Clouds;
					} else if (chance < 20) {
						return Weather::Rain;
					} else if (chance < 30) {
						return Weather::Fog;
					} else if (chance < 40) {
						return Weather::Clouds;
					} else if (chance < 55) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::ClearSkies;
					}
					return Weather::FairSkies;
				case TheGoblet:
				  	if (chance < 40) {
						return Weather::ClearSkies;
					} else if (chance < 60) {
						return Weather::FairSkies;
					} else if (chance < 85) {
						return Weather::Clouds;
					} else if (chance < 95) {
						return Weather::Fog;
					}
					return Weather::Rain;
				case Mist:
				  	if (chance < 20) {
						return Weather::Clouds;
					} else if (chance < 50) {
						return Weather::ClearSkies;
					} else if (chance < 70) {
						return Weather::FairSkies;
					} else if (chance < 80) {
						return Weather::FairSkies;
					} else if (chance < 90) {
						return Weather::Fog;
					}
					return Weather::Rain;
			}
			return Weather::Undefined;
		};
	private:
		ZoneEnum zoneEnum;
};

class Emote {
	public:
		enum EmoteEnum {
			Lookout,
			Pray,
			Sit,
			Salute,
			Comfort,
			Point,
			Psych,
		};
		Emote () {}
		Emote (EmoteEnum ee) {
			emoteEnum = ee;
		}

		operator std::string() const {
			const static std::map<EmoteEnum, std::string> emoteStringMap = {
				{Lookout, "/lookout"},
				{Pray, "/pray"},
				{Sit, "/sit"},
				{Salute, "/salute"},
				{Comfort, "/comfort"},
				{Point, "/point"},
				{Psych, "/psych"}
			};
			return emoteStringMap.find(emoteEnum)->second;
		}
	private:
		EmoteEnum emoteEnum;
};

class Period {
	public:
		Period () {}
		Period (auto start, auto end) {
			timeStart = start;
			timeEnd = end;
		}

		bool IsTimeInPeriod(const int time) {
			if (timeStart < timeEnd) {
				return (timeStart < time && time <= timeEnd ) ? true : false;
			}
			return (timeStart < time || time <= timeEnd ) ? true : false;
		};

		bool IsTimeInPeriod(std::chrono::system_clock::time_point time) {
			time_t tt = std::chrono::system_clock::to_time_t(time);
			tm utc_tm = *gmtime(&tt);
			int timeHour = utc_tm.tm_hour;

			if (timeStart < timeEnd) {
				return (timeStart < timeHour && timeHour <= timeEnd ) ? true : false;
			}
			return (timeStart < timeHour || timeHour <= timeEnd ) ? true : false;
		};

		operator std::string() const {
			std::ostringstream os;
			os << "" << timeStart%24 << ":00-" << timeEnd%24 << ":00";
			return os.str();
		};
	
	private:
		int timeStart;
		int timeEnd;
};

class Sight {
	public:
		bool found;

		Sight () {}
		Sight (const std::string n, const Zone z, const float x, const float y, const Weather w0, const Weather w1, const Period p, const Emote e, const std::string c, const bool f) {
			name = n;
			zone = z;
			x_coord = x;
			y_coord = y;
			weathers[0] = w0;
			weathers[1] = w1;
			period = p;
			emote = e;
			comment = c;
			found = f;
		}

		bool DoesWeatherMatch(Weather w) {
			return (weathers[0] == w || weathers[1] == w ) ? true : false ;
		}

		bool IsTimeInPeriod(int time) {
			return period.IsTimeInPeriod(time);
		}

		Weather GetZoneWeather(int magicNumber) {
			return zone.GetWeather(magicNumber);
		}

		std::string FoundSightToString(Weather w) {
			std::ostringstream os;
			os  << name
				<< ", "
				<< std::string(zone)
				<< ", (x"
				<< x_coord
				<< ", y"
				<< y_coord
				<< "), "
				<< std::string(w)
				<< ", "
				<< std::string(period)
				<< ", "
				<< std::string(emote)
				<< ", "
				<< comment;
			return os.str();
		}

	private:
		std::string name;
		Zone zone;
		float x_coord, y_coord;
		Weather weathers[2];
		Period period;
		Emote emote;
		std::string comment;
};

enum FishingType {
	Fresh,
	Ocean,
	Dune,
	Sky,
	Cloud,
	Hell,
	Aether,
	Salt
};

class FishingPoint {
	public:

		FishingPoint () {}
		FishingPoint (const int l, const std::string n, const Zone z, const FishingType t) {
			level = l;
			name = n;
			zone = z;
			type = t;
		}
		FishingPoint (const int l, const std::string n, const Zone z, const FishingType t, const float x, const float y, const float r) {
			level = l;
			name = n;
			zone = z;
			type = t;
			x_coord = x;
			y_coord = y;
			radius = r;
		}

	private:
		int level;
		float x_coord, y_coord, radius;
		Zone zone;
		FishingType type;
		std::string name;
};

enum MoonPhase {
	NewMoon,
	WazingCrecent,
	WaxingHalfMoon,
	WaxingGibbous,
	FullMoon,
	WaningGibbous,
	WaningHalfMoon,
	WaningCrescent,
};

class Fish {
	public:
		bool interested;

	private:
		std::string name;
		FishingPoint fishingPoints[5];
		Weather weathers[2];
		Period period;
		int gatheringRequired;	
		MoonPhase moonPhase;	
};

std::chrono::system_clock::time_point getEorzeaTime(std::chrono::system_clock::time_point time) {
	constexpr auto eorzea_time_constant = 3600.0/175.0;
	const uint64_t eorzeaUnix = floor(std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count() * eorzea_time_constant);
	return std::chrono::system_clock::from_time_t(eorzeaUnix);
};

/* Old TS function that the function below is based on
function  getMagicNumber(date: Date): number {
  const unixtime = Math.floor(date.getTime() / 1000);

  
  // Get Eorzea hour for weather start
  const bell = unixtime / 175;
  
  // Do the magic 'cause for calculations 16:00 is 0, 00:00 is 8 and 08:00 is 16
  const increment = (bell + 8 - (bell % 8)) % 24;
  
  // Take Eorzea days since unix epoch
  let totalDays = unixtime / 4200;
  totalDays = (totalDays << 32) >>> 0; // eslint-disable-line no-bitwise

  const calcBase = totalDays * 0x64 + increment;
  
  // eslint-disable no-bitwise /
  const step1 = ((calcBase << 0xb) ^ calcBase) >>> 0;
  console.log("step1: " + step1)
  const step2 = ((step1 >>> 8) ^ step1) >>> 0;
  console.log("step2: " + step2)
  // eslint-enable no-bitwise /

  return step2 % 0x64;
};
var today = new Date();

*/

uint32_t getWeatherMagicNumber(std::chrono::system_clock::time_point time) {
	uint64_t unixtime = floor(time.time_since_epoch().count() / 10000000);
    
	// Get Eorzea hour for weather start
    const uint32_t bell = unixtime / 175;
    
	// Do the magic 'cause for calculations 16:00 is 0, 00:00 is 8 and 08:00 is 16
    const int32_t increment = (bell + 8 - (bell % 8)) % 24;

	// Take Eorzea days since unix epoch
	int32_t totalDays = unixtime / 4200;
	const int32_t calcBase = totalDays * 0x64 + increment;
	const int32_t step1 = ((calcBase << 0xb) ^ calcBase) >> 0;
	const int32_t step2 = ((step1 >> 8) ^ step1) >> 0;

	return step2 % 0x64;
};

void printTime(const std::chrono::system_clock::time_point tp) {
	std::chrono::system_clock::duration dur = tp.time_since_epoch();
	std::chrono::days d = std::chrono::duration_cast<std::chrono::days>(dur);
    dur -= d;
    std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(dur);
    dur -= h;
    std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>(dur);
    dur -= m;
    std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(dur);
    dur -= s;
	std::cout << h.count() << ":" << m.count() << ":" << s.count();
};

auto getNextHour(const std::chrono::system_clock::time_point tp) {
	std::chrono::system_clock::duration dur = tp.time_since_epoch();
	std::chrono::days d = std::chrono::duration_cast<std::chrono::days>(dur);
    dur -= d;
    std::chrono::hours h = std::chrono::duration_cast<std::chrono::hours>(dur);
	return h.count() + 1;
};

/*
int main() {
	// All the standard sights
	constexpr auto sightNum = 80;
	Sight sights[sightNum] = {
		// Set 1
		{ "Barracuda Piers", Zone::LimsaLominsaUpperDecks, 9.5, 7.8, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Lookout, "Located northwest out of The Bismarck, there are two sets of bricks set into the wall there. The western set of bricks is the Vista location.", true},
		{ "The Astalicia", Zone::LimsaLominsaLowerDecks, 7, 15, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Climb to the top of The Astalicia (the ship there), and go east towards the bow of the ship. Climb the pole extending from the ship and go to the very tip.", true},
		{ "Seasong Grotto", Zone::MiddleLaNoscea, 20.3, 19.1, Weather::Rain, Weather::Undefined, Period(5,8), Emote::Pray, "In the Seasong Grotto, by the entrance.", true},
		{ "The Skylift", Zone::MiddleLaNoscea, 16.0, 17.3, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "By the Skylift, overlooking the pier.", true},
		{ "La Thagran Eastroad", Zone::MiddleLaNoscea, 25.3, 27.5, Weather::Clouds, Weather::Undefined, Period(8,12), Emote::Lookout, "Looking at the gate into Lower La Noscea, go up the stairs on the right hand side and jump up onto the fence immediately to the left. The vista is on the fencepost closest to the stairs.", true},
		{ "The Salt Strand", Zone::LowerLaNoscea, 23, 40, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Jump onto the base of the rock near the cliff west of the farmer's house.", true},
		{ "Red Rooster Stead", Zone::LowerLaNoscea, 33, 19, Weather::Fog, Weather::Undefined, Period(5,8), Emote::Lookout, "Jump on the top of the gate structure for the portal that leads to The Mist.", true},
		{ "Brewer's Beacon", Zone::WesternLaNoscea, 29, 30, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Lookout, "Go behind the lighthouse on the left side. The vista is located where the wooden barrier and the lighthouse's wall meet.", true},
		{ "The Leatherworkers' Guild", Zone::OldGridania, 12.8, 7.8, Weather::Clouds, Weather::Undefined, Period(12,17), Emote::Lookout, "From inside the guild you go up the steps in the back, jump on the table against the right wall, jump again to get onto the higher shelf. Face the room and use /lookout.", true},
		{ "Apkallu Falls", Zone::OldGridania, 10, 6, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Near Apkallu Falls, there are 3 lamp posts. You have to climb onto the cliff on the southeast and from there use sprint and jump onto the top of the lamp post closest to the waterfall. The lamp post lights must be on for it to complete (after sunset).", true},
		{ "Bentbranch Meadows", Zone::CentralShroud, 21.8, 21.8, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Sit, "The Vista is right next to the Aetheryte. There are three stumps across the Moogle mail carrier. A woman is sitting on the first one. Hop up onto the third one to reach the Vista.", true},
		{ "The Sanctum of the Twelve", Zone::EastShroud, 17.6, 18.2, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Pray, "At the entrance to the chamber to the garden around the Sanctum of the Twelve.", true},
		{ "Little Solace", Zone::EastShroud, 22.3, 26.2, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Just behind the Sylph Vendor NPC, on the top of the tree branch extending from the quest NPC platform.", true},
		{ "Royal Promenade", Zone::UlDah, 11.1, 11.6, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Salute, "There are three silver squares in front of the Royal Promenade (players can get there from the Chamber of Rule Aetheryte Shard). The Vista is on the tip of the triangle. Face the stairs and guards then use /salute.", true},
		{ "The Gold Court", Zone::UlDah, 11.5, 11.2, Weather::Clouds, Weather::Undefined, Period(12,17), Emote::Lookout, "Jump from Hustings Strip balcony down onto the eastern-most lamp.", true},
		{ "The Jewel of the Desert", Zone::WesternThanalan, 22.3, 22.3, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Use your mount and jump from the boulder to the awning (the cloth roof) at the beginning of the staircase.", true},
		{ "The Ruins of Sil'dih", Zone::CentralThanalan, 15.9, 22.9, Weather::Fog, Weather::Undefined, Period(8,12), Emote::Lookout, "About half way down the cliff, where the cliff meets the creek.", true},
		{ "The Lonely Giant", Zone::EasternThanalan, 19.5, 24.7, Weather::Rain, Weather::Showers, Period(17,18), Emote::Comfort, "It is located under the base of the tree clump across from the Goobbue.", true},
		{ "The Invisible City", Zone::EasternThanalan, 14.3, 18.5, Weather::Clouds, Weather::Undefined, Period(8,12), Emote::Lookout, "At the tip of the ruin/roof that overlooks the area.", true},
		{ "Highbridge", Zone::EasternThanalan, 21.0, 20.7, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Pray, "The Vista is on the small platform that sticks out from underneath the north side of the bridge. It is closest to the NPC located in the carved area on the side of the canyon.", true},
		// Set 2
		{ "Woad Whisper Canyon", Zone::MiddleLaNoscea, 20.0, 13.1, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "Edge of the path, before you pass under the rocky archways.", true},
		{ "Summerford Farms", Zone::MiddleLaNoscea, 25.7, 17, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Lookout, "Second floor of Inn. Top of lamp to left of door. Jump on pot plant, then to partition, then to top of lamp.", true},
		{ "The Grey Fleet", Zone::LowerLaNoscea, 31.5, 12.7, Weather::Rain, Weather::Undefined, Period(12,17), Emote::Lookout, "On top of the house of sticks. Use the rocks behind the house to get onto the roof.", true},
		{ "Hidden Falls", Zone::EasternLaNoscea, 32.6, 23.5, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Sit, "/sit on chair at end of dock.", true},
		{ "Gullperch Tower", Zone::EasternLaNoscea, 29.6, 33.8, Weather::Rain, Weather::Undefined, Period(18,5), Emote::Lookout, "On top of Gullperch Tower. Located on the edge of the wall to the left of the two lookout NPCs.", true},
		{ "The Navigator", Zone::WesternLaNoscea, 26.9, 26.6, Weather::FairSkies, Weather::ClearSkies, Period(17,18), Emote::Pray, "To the left hand side along the railing (if lookout out towards the sea).", true},
		{ "The Ship Graveyard", Zone::WesternLaNoscea, 17.1, 36.2, Weather::Gales, Weather::Undefined, Period(18,5), Emote::Lookout, "Bottom SE corner of Isle of Umbral. Stand on top of the pot in the sand.", true},
		{ "Camp Skull Valley", Zone::WesternLaNoscea, 22.8, 22.4, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Lookout, "On top of the front-right spike (if facing) of the tents on the top of the fort. Jump on canvas roof then on spike.", true},
		{ "Tidegate", Zone::WesternLaNoscea, 19.4, 23.0, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "On the top of the center pole on the round tent (just after three tents). Jump onto the smaller pole then BACKWARDS HOP onto the higher bit. From there sprint jump to the top/middle pole.", true},
		{ "Camp Bronze Lake", Zone::UpperLaNoscea, 30.8, 22.4, Weather::FairSkies, Weather::ClearSkies, Period(17,18), Emote::Lookout, "Go to the side of the house and jump up on the barrels between the two awnings (jump at the barrels head on, not from the side). Jump up onto the right awning and then onto the rocky ledge. Walk along the edge and jump onto the small part of the roof that juts out. The vista is on the highest point at the front of the house.", true},
		{ "Thalaos", Zone::UpperLaNoscea, 12.9, 22.0, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "Very tip of biggest bone/spire. Base of spire starts in (x13,y21). Vista log message did not appear until correct time.", true},
		{ "Jijiroon's Trading Post", Zone::UpperLaNoscea, 29, 25, Weather::ThunderStorms, Weather::Undefined, Period(18,5), Emote::Lookout, "Climb a wall and jump over to the next ruin.", true},
		{ "The Floating City of Nym", Zone::OuterLaNoscea, 12, 15, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Cliff overlooking Nym.", true},
		{ "Camp Overlook", Zone::OuterLaNoscea, 17, 16, Weather::Clouds, Weather::Undefined, Period(5,8), Emote::Lookout, "Crumbling arch. Climb from the North side. Jump over gap and hop up on highest part. Kind of hidden by bushes.", true},
		{ "U'Ghamaro Mines", Zone::OuterLaNoscea, 23, 11, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "On top of the high furnace. Jump from the smaller one to the bigger one. There's a smokestack sticking out of the small one that kind of looks like the exhaust stack on a semi-truck/tractor trailer. If you try to run forward towards the big one, it blocks you. So jump on top of it, and then jump across to the big one.", true},
		{ "The Hermit's Hovel", Zone::OuterLaNoscea, 15, 9, Weather::Rain, Weather::Undefined, Period(18,5), Emote::Sit, "Inside the house jump on the table -> bookshelf -> area with bed and table. stand on the stool and then /sit.", true},
		{ "The Carline Canopy", Zone::NewGridania, 14, 14, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Lookout, "Blue Badger Gate on the left gate (facing the exit). Jump on railing from stairs. From there sprint jump to door. Then jump from door to door.", true},
		{ "The Lancer's Guild", Zone::OldGridania, 14.2, 5.9, Weather::Rain, Weather::Undefined, Period(5,8), Emote::Lookout, "Jump on bookshelf then onto weapons to make your way to the corner.", true},
		{ "The Bannock", Zone::CentralShroud, 23.4, 19.9, Weather::Rain, Weather::Undefined, Period(5,8), Emote::Lookout, "Jump onto the canvas above the commander's heads by first jumping up and along the tree. The vista is on top of the wooden arch.", true},
		{ "Haukke Manor", Zone::CentralShroud, 13, 23, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Climb onto the roots from left side just walk up. Hop onto top. Root are coming off of cliff into a small pond with a view of the mansion.", true},
		{ "The Guardian Tree", Zone::CentralShroud, 16, 22, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "On tree bridge.", true},
		{ "Rainbow Bridge", Zone::CentralShroud, 26.5, 18.8, Weather::FairSkies, Weather::ClearSkies, Period(11,13), Emote::Lookout, "On top and center of waterfall side of railing on bridge.", true},
		{ "The Seedbed", Zone::EastShroud, 20, 10, Weather::Thunder, Weather::Undefined, Period(18,5), Emote::Lookout, "Right in front of giant glowing mushroom.", true},
		{ "Buscarron's Druthers", Zone::SouthShroud, 17.8, 20.1, Weather::ThunderStorms, Weather::Undefined, Period(8,12), Emote::Lookout, "On balcony over main bar. Get there by jumping from wall on Eastern back corner of the bar, and onto the roof. Follow it back to the front of the building and sprint jump from roof corner to balcony.", true},
		{ "South Shroud Landing", Zone::SouthShroud, 14.7, 33.9, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Lookout, "On the windowsill beside the hut.", true},
		{ "Urth's Gift", Zone::SouthShroud, 33.3, 23.9, Weather::Fog, Weather::Undefined, Period(12,17), Emote::Lookout, "At the rock wall.", true},
		{ "Quarrymill", Zone::SouthShroud, 25, 21, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Lookout, "On top of chimney on house farthest from Aetheryte (shaped like a mushroom). Jump from balcony.", true},
		{ "Ixali Logging Grounds", Zone::NorthShroud, 18, 19, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "The log-pile at the back of the area. Jump from the northernmost upright to the middle upright on a mount. This is one of the more difficult jumps in the Sightseeing Log; make sure to back up as far as you can to give maximum time for the mount to speed up. Maximum movement speed from a riding map may also help.", true},
		{ "Fallen Neurolink", Zone::NorthShroud, 16, 31, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Near edge of cliff looking at giant arc.", true},
		{ "Alder Springs", Zone::NorthShroud, 15.4, 27.2, Weather::Clouds, Weather::Undefined, Period(8,12), Emote::Lookout, "Drop down from above. Start at stump of tree that broke off near edge of cliff and fall down directly below to another root/branch extending out. Take left fork twice. Go SLOW!", true},
		{ "Castrum Marinum", Zone::WesternThanalan, 8, 5, Weather::FairSkies, Weather::ClearSkies, Period(17,18), Emote::Lookout, "On the lamp.", true},
		{ "Vesper Bay", Zone::WesternThanalan, 12.4, 14.8, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Point, "Top of the building.", true},
		{ "Black Brush Station", Zone::CentralThanalan, 21.4, 17.5, Weather::DustStorms, Weather::Undefined, Period(18,5), Emote::Lookout, "Jump from the top of the building to the lamp post on the left hand side.", true},
		{ "Gate of Nald", Zone::CentralThanalan, 18.5, 26.1, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Sit, "On top of a canvas.", true},
		{ "The Burning Wall", Zone::EasternThanalan, 30.7, 26.5, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "On top of the small crystal, drop down from the ledge just above at (x30.7,y26.7).", true},
		{ "The Golden Bazaar", Zone::EasternThanalan, 10., 16.7, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Lookout, "On top of the small wooden gate building, jump to fence. Use fence to jump to higher platform. Vista on top of platform above 2 NPC at the front.", true},
		{ "Thal's Respite", Zone::EasternThanalan, 25, 14, Weather::Showers, Weather::Undefined, Period(18,5), Emote::Pray, "In front of the statue.", true},
		{ "Nald's Reflection", Zone::SouthernThanalan, 12, 22, Weather::Fog, Weather::Undefined, Period(5,8), Emote::Pray, "In front of the statue.", true},
		{ "Zahar'ak", Zone::SouthernThanalan, 19.3, 20.5, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Lookout, "On top of the stone column. Jump with mount.", true},
		{ "The Sagolii Desert", Zone::SouthernThanalan, 21.3, 38.6, Weather::HeatWaves, Weather::Undefined, Period(12,17), Emote::Lookout, "On top of large mound next to tower ruin on ground.", true},
		{ "The Sunken Temple of Qarn", Zone::SouthernThanalan, 23.8, 11.8, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "Use rocks to jump up on to the sloped building.", true},
		{ "Minotaur Malm", Zone::SouthernThanalan, 14.6, 26.5, Weather::HeatWaves, Weather::Undefined, Period(5,8), Emote::Psych, "Stand beside the drill sergeant near the exercising recruits.", true},
		{ "East Watchtower", Zone::NorthernThanalan, 22.2, 25.7, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Salute, "/salute on top of the tower, on the flagpole.", true},
		{ "Ceruleum Pipeline", Zone::NorthernThanalan, 20, 29, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "On top of the gate, north side.", true},
		{ "Bluefog", Zone::NorthernThanalan, 20.8, 22.5, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "On the fence.", true},
		{ "Raubahn's Push", Zone::NorthernThanalan, 20.0, 17.6, Weather::Clouds, Weather::Undefined, Period(8,12), Emote::Lookout, "On one of the southwestern spires.", true},
		{ "Abandoned Amajina Mythril Mine", Zone::NorthernThanalan, 26, 22, Weather::Fog, Weather::Undefined, Period(18,5), Emote::Lookout, "On a little ledge attached to a broken pillar near stairs. Very tricky jump! Use sprint or mount from roof to ledge. Stand on broken gap in railing when you jump.", true},
		{ "The Nail", Zone::CoerthasCentralHighlands, 25.4, 29.8, Weather::FairSkies, Weather::ClearSkies, Period(17,18), Emote::Lookout, "Top of the Observatorium on the ladder under the telescope. Jump onto the lamp closest to the ladder and then onto the ladder itself.", true},
		{ "The Observatorium", Zone::CoerthasCentralHighlands, 25, 29, Weather::Fog, Weather::Undefined, Period(18,5), Emote::Lookout, "Take a couple of steps down from the first floor and walk/fall off into the center of the tower, landing on the highest chandelier.", true},
		{ "The Frozen Fang", Zone::CoerthasCentralHighlands, 11.7, 15.8, Weather::Blizzards, Weather::Undefined, Period(8,12), Emote::Lookout, "Go out onto the bridge towards the Stone Vigil. At the end of the bridge turn right and walk along the small ledge that sticks out until you're at the middle of the semi-circle part of the bridge.", true},
		{ "The Holy See of Ishgard", Zone::CoerthasCentralHighlands, 12.8, 17.3, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Lookout, "Top of the tower on the over-arch. After climbing the stone spiral staircase, enter the small room and use the wooden stairs to get all the way up.", true},
		{ "Boulder Downs", Zone::CoerthasCentralHighlands, 7, 28, Weather::FairSkies, Weather::ClearSkies, Period(17,18), Emote::Lookout, "Top of monument tower next to the NPC standing next to the top of the stairs.", true},
		{ "The Fury's Gaze", Zone::CoerthasCentralHighlands, 7.9, 31.3, Weather::Blizzards, Weather::Undefined, Period(18,5), Emote::Lookout, "Inside the cave before you reach the plasmoids.", true},
		{ "Snowcloak", Zone::CoerthasCentralHighlands, 2.2, 21.4, Weather::FairSkies, Weather::ClearSkies, Period(8,12), Emote::Lookout, "Climb up to the highest ledge.", true},
		{ "Camp Dragonhead", Zone::CoerthasCentralHighlands, 26.5, 17.7, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "Climb up to the eastern battlements and head south to draw parallel to the green-roofed building. Jump up onto a higher crenelation that's in line with a buttress opposite and sprint one step and jump over to the building.", true},
		{ "The Steel Vigil", Zone::CoerthasCentralHighlands, 28.2, 10.3, Weather::FairSkies, Weather::ClearSkies, Period(5,8), Emote::Lookout, "On the broken arch of the ruins. Start climbing from the most South Eastern edge of the broken wall. The vista is just on the other side of the steeple.", true},
		{ "Castrum Centri", Zone::MorDhona, 9.8, 13.5, Weather::Gloom, Weather::Undefined, Period(12,17), Emote::Lookout, "On top of red light just past four cylinders. Jump up onto the smaller ledge and then onto the ledge leading towards the light.", true},
		{ "The Crystal Tower", Zone::MorDhona, 27.4, 8.0, Weather::FairSkies, Weather::ClearSkies, Period(18,5), Emote::Lookout, "Follow path that curves to the left to go to the upper level. Vista is near a tree by the edge.", true},
		{ "Rathefrost", Zone::MorDhona, 18.6, 17.7, Weather::FairSkies, Weather::ClearSkies, Period(12,17), Emote::Lookout, "On top of rock near crystal tree.", true},
		{ "The Keeper of the Lake", Zone::MorDhona, 26.1, 11.2, Weather::FairSkies, Weather::ClearSkies, Period(17,18), Emote::Sit, "/sit on top of tree. Climb the back of the red metallic wreckage near a smaller red cylinder. Walk up and jump on small metal rib. From there jump onto back of Big broken red metallic hull. It's also possible, with maximum mount speed, to jump from the branch of the next-closest tree.", true},
	};

	constexpr auto fishingPointNum = 107;
	FishingPoint fishingPoints[fishingPointNum] = {
		{1, "Zephyr Drift", Zone::MiddleLaNoscea, FishingType::Ocean, 19, 22, 5},
		{1, "Rogue River", Zone::MiddleLaNoscea, FishingType::Fresh, 22, 22, 5},
		{1, "West Agelyss River", Zone::MiddleLaNoscea, FishingType::Fresh, 20, 18, 5},
		{5, "Nym River", Zone::MiddleLaNoscea, FishingType::Fresh, 18, 15, 5},
		{5, "Summerford", Zone::MiddleLaNoscea, FishingType::Ocean, 15, 15, 5},
		{15, "Woad Whisper Canyon", Zone::MiddleLaNoscea, FishingType::Fresh, 21, 12, 5},
		{1, "The Mourning Widow", Zone::LowerLaNoscea, FishingType::Fresh, 25, 23, 5},
		{5, "Moraby Bay", Zone::LowerLaNoscea, FishingType::Ocean, 26, 26, 5},
		{10, "Cedarwood", Zone::LowerLaNoscea, FishingType::Ocean, 35, 18, 5},
		{10, "Candlekeep Quay", Zone::LowerLaNoscea, FishingType::Ocean, 20, 38, 5},
		{10, "Oschon's Torch", Zone::LowerLaNoscea, FishingType::Ocean, 24, 39, 5},
		{15, "Empty Heart", Zone::LowerLaNoscea, FishingType::Fresh, 22, 35, 5},
		{15, "Moraby Drydocks", Zone::LowerLaNoscea, FishingType::Ocean, 26, 35, 5},
		{20, "Blind Iron Mines", Zone::LowerLaNoscea, FishingType::Fresh, 27, 16, 5},
		{20, "The Salt Strand", Zone::LowerLaNoscea, FishingType::Ocean, 17, 36, 5},
		{25, "South Bloodshore", Zone::EasternLaNoscea, FishingType::Ocean, 33, 33, 5},
		{30, "Costa del Sol", Zone::EasternLaNoscea, FishingType::Ocean, 33, 30, 5},
		{35, "Hidden Falls", Zone::EasternLaNoscea, FishingType::Fresh, 31, 23, 5},
		{35, "North Bloodshore", Zone::EasternLaNoscea, FishingType::Salt, 32, 24, 5},
		{40, "East Agelyss River", Zone::EasternLaNoscea, FishingType::Fresh, 21, 26, 5},
		{40, "Raincatcher Gully", Zone::EasternLaNoscea, FishingType::Fresh, 20, 30, 5},
		{40, "The Juggernaut", Zone::EasternLaNoscea, FishingType::Fresh, 17, 31, 5},
		{45, "Red Mantis Falls", Zone::EasternLaNoscea, FishingType::Fresh, 15, 27, 5},
		{50, "North Isle of Endless Summer", Zone::EasternLaNoscea, FishingType::Ocean, 36, 25, 5},
		{50, "Rhotano Sea (Priveteer Forecastle)", Zone::EasternLaNoscea, FishingType::Ocean, 39, 24, 5},
		{50, "Rhotano Sea (Priveteer Sterncastle)", Zone::EasternLaNoscea, FishingType::Ocean, 38, 25, 5},
		{10, "Swiftperch", Zone::WesternLaNoscea, FishingType::Ocean, 34, 32, 5},
		{15, "Skull Valley", Zone::WesternLaNoscea, FishingType::Ocean, 27, 27, 5},
		{15, "The Brewer's Beacon", Zone::WesternLaNoscea, FishingType::Ocean, 30, 30, 5},
		{35, "Halfstone", Zone::WesternLaNoscea, FishingType::Ocean, 16, 21, 5},
		{40, "Isles of Umbra Northshore", Zone::WesternLaNoscea, FishingType::Ocean, 15, 29, 5},
		{45, "Sapsa Spawning Grounds", Zone::WesternLaNoscea, FishingType::Salt, 17, 16, 5},
		{45, "The Ship Graveyard", Zone::WesternLaNoscea, FishingType::Ocean, 15, 40, 5},
		{50, "Isles of Umbra Southshore", Zone::WesternLaNoscea, FishingType::Ocean, 12, 36, 5},
		{50, "Reaver Hide", Zone::WesternLaNoscea, FishingType::Ocean, 14, 13, 5},
		{20, "Fool Falls", Zone::UpperLaNoscea, FishingType::Fresh, 9, 20, 5},
		{20, "Oakwood", Zone::UpperLaNoscea, FishingType::Fresh, 14, 24, 5},
		{30, "Bronze Lake Shallows", Zone::UpperLaNoscea, FishingType::Fresh, 34, 24, 5},
		{35, "Northeast Bronze Lake", Zone::UpperLaNoscea, FishingType::Fresh, 28, 23, 5},
		{35, "Northwest Bronze Lake", Zone::OuterLaNoscea, FishingType::Fresh, 19.5, 18.3, 5},
		{40, "The Long Climb", Zone::OuterLaNoscea, FishingType::Fresh, 16, 11, 5},
		{30, "Mist", Zone::Mist, FishingType::Ocean, 10, 14, 5},
		{5, "Jadeite Flood", Zone::NewGridania, FishingType::Fresh, 13, 14, 5},
		{5, "Lower Black Tea Brook", Zone::NewGridania, FishingType::Fresh, 11, 11, 5},
		{5, "Upper Black Tea Brook", Zone::OldGridania, FishingType::Fresh, 11, 9, 5},
		{5, "Whispering Gorge", Zone::OldGridania, FishingType::Fresh, 15, 6, 5},
		{5, "The Vein", Zone::CentralShroud, FishingType::Fresh, 23, 23, 5},
		{15, "The Mirror", Zone::CentralShroud, FishingType::Fresh, 28, 29, 5},
		{30, "Everschade", Zone::CentralShroud, FishingType::Fresh, 15, 24, 5},
		{35, "Hopeseed Pond", Zone::CentralShroud, FishingType::Fresh, 12, 22, 5},
		{35, "Haukke Manor", Zone::CentralShroud, FishingType::Fresh, 11, 22, 5},
		{15, "Springripple Brook", Zone::EastShroud, FishingType::Fresh, 22, 24, 5},
		{15, "Sweetbloom Pier", Zone::EastShroud, FishingType::Fresh, 10, 22, 5},
		{20, "Sanctum of the Twelve", Zone::EastShroud, FishingType::Fresh, 17, 17, 5},
		{25, "Verdant Drop", Zone::EastShroud, FishingType::Fresh, 20, 21, 5},
		{45, "Sylphlands", Zone::EastShroud, FishingType::Fresh, 25, 10, 5},
		{20, "Upper Hathoeva River", Zone::SouthShroud, FishingType::Fresh, 18, 19, 5},
		{25, "East Hathoeva River", Zone::SouthShroud, FishingType::Fresh, 24, 22, 5},
		{25, "Lower Hathoeva River", Zone::SouthShroud, FishingType::Fresh, 18, 24, 5},
		{30, "Goblinblood", Zone::SouthShroud, FishingType::Fresh, 27, 21, 5},
		{30, "Middle Hathoeva River", Zone::SouthShroud, FishingType::Fresh, 19, 23, 5},
		{35, "Rootslake", Zone::SouthShroud, FishingType::Fresh, 18, 29, 5},
		{45, "Urth's Gift", Zone::SouthShroud, FishingType::Fresh, 34, 23, 5},
		{15, "Fallgourd Float", Zone::NorthShroud, FishingType::Fresh, 21, 25, 5},
		{15, "Murmur Rills", Zone::NorthShroud, FishingType::Fresh, 26, 25, 5},
		{40, "Proud Creek", Zone::NorthShroud, FishingType::Fresh, 19, 20, 5},
		{50, "Lake Tahtotl", Zone::NorthShroud, FishingType::Fresh, 18.2, 19.7, 5},
		{30, "The Lavender Beds", Zone::TheLavenderBeds, FishingType::Fresh, 11, 15, 5},
		{5, "Nophica's Wells", Zone::WesternThanalan, FishingType::Fresh, 24, 21, 5},
		{10, "The Footfalls", Zone::WesternThanalan, FishingType::Fresh, 18, 16, 5},
		{15, "Vesper Bay", Zone::WesternThanalan, FishingType::Ocean, 12, 13, 5},
		{20, "Crescent Cove", Zone::WesternThanalan, FishingType::Ocean, 15, 19, 5},
		{25, "The Silver Bazaar", Zone::WesternThanalan, FishingType::Ocean, 15, 30, 5},
		{45, "Cape Westwind", Zone::WesternThanalan, FishingType::Ocean, 9, 6, 5},
		{45, "Parata's Peace", Zone::WesternThanalan, FishingType::Fresh, 15, 7, 5},
		{45, "MoonDrip", Zone::WesternThanalan, FishingType::Fresh, 18, 7, 5},
		{5, "Upper Soot Creek", Zone::CentralThanalan, FishingType::Fresh, 24, 18, 5},
		{10, "Lower Soot Creek", Zone::CentralThanalan, FishingType::Fresh, 17, 24, 5},
		{10, "The Clutch", Zone::CentralThanalan, FishingType::Fresh, 29, 22, 5},
		{15, "The Unholy Heir", Zone::CentralThanalan, FishingType::Fresh, 27, 19, 5},
		{15, "North Drybone", Zone::EasternThanalan, FishingType::Fresh, 14, 21, 5},
		{15, "South Drybone", Zone::EasternThanalan, FishingType::Fresh, 17, 25, 5},
		{30, "Yugr'am River", Zone::EasternThanalan, FishingType::Fresh, 26, 23, 5},
		{40, "The Burning Wall", Zone::EasternThanalan, FishingType::Fresh, 30, 27, 5},
		{25, "Burnt Lizard Creek", Zone::SouthernThanalan, FishingType::Fresh, 21, 15, 5},
		{35, "Forgotten Springs", Zone::SouthernThanalan, FishingType::Fresh, 15, 31, 5},
		{35, "Zahar'ak", Zone::SouthernThanalan, FishingType::Fresh, 25.6, 21.3, 5},
		{35, "Sagolii Desert", Zone::SouthernThanalan, FishingType::Dune, 13, 37, 5},
		{35, "Sagolii Dunes", Zone::SouthernThanalan, FishingType::Dune, 25, 36, 5},
		{30, "Ceruleum Field", Zone::NorthernThanalan, FishingType::Fresh, 16, 20, 5},
		{30, "Bluefog", Zone::NorthernThanalan, FishingType::Fresh, 16, 20, 5},
		{30, "The Goblet", Zone::TheGoblet, FishingType::Fresh, 11, 8, 5},
		{35, "Coerthas River", Zone::CoerthasCentralHighlands, FishingType::Fresh, 20.4, 30.7, 5},
		{35, "Daniffen Pass", Zone::CoerthasCentralHighlands, FishingType::Fresh, 13, 23, 5},
		{40, "The Nail", Zone::CoerthasCentralHighlands, FishingType::Fresh, 16, 21, 5},
		{40, "Dragonhead Latrines", Zone::CoerthasCentralHighlands, FishingType::Fresh, 27.5, 17, 5},
		{40, "Exploratory Ice Hole", Zone::CoerthasCentralHighlands, FishingType::Fresh, 6, 22, 5},
		{45, "The Weeping Saint", Zone::CoerthasCentralHighlands, FishingType::Fresh, 31, 7, 5},
		{45, "Snowcloak", Zone::CoerthasCentralHighlands, FishingType::Fresh, 3, 21, 5},
		{45, "Sea of Clouds", Zone::CoerthasCentralHighlands, FishingType::Cloud, 13, 14, 5},
		{50, "Witchdrop", Zone::CoerthasCentralHighlands, FishingType::Cloud, 33.2, 18.8, 5},
		{45, "North Silvertear", Zone::MorDhona, FishingType::Fresh, 24, 13, 5},
		{45, "The Deep Tangle", Zone::MorDhona, FishingType::Fresh, 12, 11, 5},
		{45, "Singing Shards", Zone::MorDhona, FishingType::Fresh, 28.6, 10.6, 5},
		{50, "Rathefrost", Zone::MorDhona, FishingType::Fresh, 18.9, 17.6, 5},
		{50, "The Tangle", Zone::MorDhona, FishingType::Fresh, 16, 12, 5},
		{50, "The North Shards", Zone::MorDhona, FishingType::Fresh, 31.0, 5.9, 5},
	};

	auto currentTime = std::chrono::system_clock::now();
	auto eorzeaTime = getEorzeaTime(currentTime);
	uint_fast64_t eorzeaHour = getNextHour(eorzeaTime);

	std::cout << "Eorzea Time: ";
	printTime(eorzeaTime);
	std::cout << "\n";

	std::cout << "Eorzea Hour: " << eorzeaHour << "\n";

	// Get eorzea time until next weather change


	//0-5, 5-8, 8-12, 12-16, 16-17, 17-18, 18-0
	//3, 6, 11:30 12, 14, 16:30 17, 17:30 18, 21
	const int a[2] = {3, 6};
	const int b[2] = {12, 14};
	const int c[3] = {17, 18, 21};
	const int *weatherPeriodTimes[3] = {a, b, c};
	auto weatherPeriodIndex = 0;
	auto weatherPeriodLength = 2;
	auto weatherPeriodString = "";

	if (eorzeaHour > 0 && eorzeaHour <= 8) {
		weatherPeriodIndex = 0;
		weatherPeriodString = "0:00-8:00";
	} else if (eorzeaHour > 8 && eorzeaHour <= 16) {
		weatherPeriodIndex = 1;
		weatherPeriodString = "8:00-16:00";
	} else {
		weatherPeriodIndex = 2;
		weatherPeriodLength = 3;
		weatherPeriodString = "16:00-24:00";
	}

	auto weatherNumber = getWeatherMagicNumber(currentTime);
	for (auto i = 0; i < 26; i++) {
		std::cout << "Eorzea time period: " << weatherPeriodString << "\n";
		auto watchTimes = weatherPeriodTimes[weatherPeriodIndex];
		for (auto j = 20; j < 80; j++) {
			Sight sight = sights[j];
			Weather currentWeather = sight.GetZoneWeather(weatherNumber);
			for (auto k = 0; k < weatherPeriodLength; k++) {
				if (sight.found == false ) {
					if ( sight.DoesWeatherMatch(currentWeather) && sight.IsTimeInPeriod(watchTimes[k]) ) {
							std::cout << j+1 << " " << sight.FoundSightToString(currentWeather) << "\n";
					}
				}
			}
		}
		switch (weatherPeriodIndex) {
			case 0:
				weatherPeriodString = "8:00-16:00";
				weatherPeriodIndex++;
				break;
			case 1:
				weatherPeriodString = "16:00-24:00";
				weatherPeriodIndex++;
				weatherPeriodLength = 3;
				break;
			default:
				weatherPeriodString = "0:00-8:00";
				weatherPeriodIndex = 0;
				weatherPeriodLength = 2;
				break;
		}

		std::cout << "\n" << ((i+1)*70)/3 << " minutes from now\n";
		currentTime += std::chrono::seconds(1400);
		eorzeaTime = getEorzeaTime(currentTime);

		eorzeaHour = getNextHour(eorzeaTime);
		weatherNumber = getWeatherMagicNumber(currentTime);
		std::time_t newt = std::chrono::system_clock::to_time_t(currentTime);
		std::cout << std::put_time(std::localtime(&newt), "Local time: %F %T.\n");
	}
    return 0;
}*/

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"FF14 Tracker",                // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
	case WM_CREATE:
		{
			CreateWindowEx(0, WC_LISTVIEW, L"",
                 WS_VISIBLE | WS_CHILD | LVS_REPORT | LVS_EDITLABELS,
                 0, 0, 100, 100,        
                 hwnd, (HMENU) 1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
			// HWND hWndComboBox = 
			CreateWindowEx(0, WC_COMBOBOX, L"", 
				CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
				0, 0, 200, 50,
				hwnd, (HMENU) 1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
			HWND checkBox = CreateWindowEx(0, L"button", L"Show Title",
                 WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                 20, 20, 185, 35,        
                 hwnd, (HMENU) 1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
    		CheckDlgButton(checkBox, 1, BST_CHECKED);
			break;
		}
	case WM_CLOSE:
		if (MessageBox(hwnd, L"Are you sure?", L"FF14 Tracker", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hwnd);
		}
		return 0;
	
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

            EndPaint(hwnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}