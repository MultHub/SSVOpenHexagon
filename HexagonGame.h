#ifndef HEXAGONGAME_H_
#define HEXAGONGAME_H_

#include "SSVStart.h"
#include "SSVEntitySystem.h"
#include "LevelSettings.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <map>

using namespace sf;
using namespace ssvs;
using namespace sses;

namespace hg
{
	constexpr float windowSizeX { 1024 };
	constexpr float windowSizeY { 768 };
	constexpr float sizeX { windowSizeX * 1.3f };
	constexpr float sizeY { windowSizeX * 1.3f };
	constexpr float spawnDistance { 800 };

	enum Level { EASY, NORMAL, HARD, LUNATIC };
	enum BackType { DARK, LIGHT, GRAY };

	class PatternManager;

	class HexagonGame
	{
		friend class PatternManager;

		private:
			Game game;
			GameWindow window { (int)windowSizeX, (int)windowSizeY, 1, false };
			Manager manager;
			RenderTexture gameTexture;
			Sprite gameSprite;
			Font font;

			Vector2f centerPos { 0, 0 };

			float radius { 75 };
			float minRadius { 75 };
			float radiusTimer { 0 };

			Color color { Color::Red };
			float colorSwap { 0 };
			BackType backType { BackType::GRAY };
			double hue { 0 };
			float hueIncrement { 1.0f };
			bool rotationDirection { true };

			map<int, LevelSettings> levelMap;
			Level level { Level::EASY };
			PatternManager* pm; // owned
			Timeline timeline;

			float currentTime { 0 };
			float incrementTime { 0 };

			int sides { 6 };
			float speedMult { 1 };
			float delayMult { 1 };
			float speedIncrement { 0 };
			float rotationSpeed { 0.1f };
			float rotationSpeedIncrement { 0 };
			float fastSpin { 0 };

			bool mustRestart { false };

			Entity* createPlayer();
			void update(float);
			inline void updateIncrement();
			inline void updateLevel(float);
			inline void updateColor(float);
			inline void updateRotation(float);
			inline void updateRadius(float);
			inline void updateDebugKeys(float);
			void drawDebugText();
			void drawBackground();

			void initLevelSettings();
			LevelSettings& getLevelSettings();

		public:
			void newGame();
			void death();
			void drawOnTexture(Drawable&);
			void drawOnWindow(Drawable&);

			Vector2f getCenterPos();
			float getRadius();
			int getSides();
			Color getColor();

			HexagonGame();
			~HexagonGame();
	};
}
#endif /* HEXAGONGAME_H_ */
