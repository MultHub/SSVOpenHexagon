/* The MIT License (MIT)
 * Copyright (c) 2012 Vittorio Romeo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ASSETS_H_
#define ASSETS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <SFML/Audio.hpp>
#include <json/json.h>
#include <json/reader.h>
#include "Data/LevelData.h"
#include "Data/MusicData.h"
#include "Data/ProfileData.h"
#include "Data/StyleData.h"
#include "Utils.h"
#include "HexagonGame.h"

using namespace std;
using namespace sf;

namespace hg
{	
	void loadAssets();

	void loadFonts();
	void loadSounds();
	void loadMusic(string mPath);
	void loadMusicData(string mPath);
	void loadStyleData(string mPath);
	void loadLevelData(string mPath);
	void loadProfiles();
	void loadEvents(string mPath);

	void saveCurrentProfile();

	void stopAllMusic();
	void stopAllSounds();
	void playSound(string mId);

	Font& getFont(string mId);
	Sound* getSoundPtr(string mId);
	Music* getMusicPtr(string mId);
	MusicData getMusicData(string mId);
	StyleData getStyleData(string mId);
	LevelData getLevelData(string mId);

	vector<LevelData> getAllLevelData();
	vector<string> getAllMenuLevelDataIds();
	vector<string> getMenuLevelDataIdsByPack(string mPackPath);
	vector<string> getPackPaths();

	float getScore(string mId);
	void setScore(string mId, float mScore);

	void setCurrentProfile(string mName);
	ProfileData& getCurrentProfile();
	string getCurrentProfileFilePath();
	void createProfile(string mName);
	int getProfilesSize();
	vector<string> getProfileNames();
	string getFirstProfileName();

	EventData getEventData(string mId, HexagonGame* mHgPtr);
}

#endif /* ASSETS_H_ */
