// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef HG_STATUS
#define HG_STATUS

#include "SSVOpenHexagon/Global/Common.hpp"

namespace hg
{
    struct HexagonGameStatus
    {
        ssvu::ObfuscatedValue<float> currentTime{0.f};
        float incrementTime{0}, timeStop{100};
        float pulse{75}, pulseDirection{1}, pulseDelay{0}, pulseDelayHalf{0};
        float beatPulse{0}, beatPulseDelay{0};
        float pulse3D{1.f}, pulse3DDirection{1};
        float flashEffect{0};
        float radius{75};
        float fastSpin{0};
        bool hasDied{false}, mustRestart{false};
        bool scoreInvalid{false};
        bool started{false};
        sf::Color overrideColor{sf::Color::Transparent};
        ssvu::ObfuscatedValue<float> lostFrames{0};
    };
}

#endif
